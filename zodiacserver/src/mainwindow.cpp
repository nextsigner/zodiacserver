﻿#include <QToolBar>
#include <QToolButton>
#include <QMessageBox>
#include <QPushButton>
#include <QStatusBar>
#include <QListWidget>
#include <QKeyEvent>
#include <QShortcut>
#include <QMenu>
#include <QDir>
#include <QApplication>
#include <QComboBox>
#include <QDesktopServices>
#include <QGraphicsBlurEffect>
#include <math.h>
#include <QDebug>
#include <QFile>
#include "../plain/src/plain.h"
#include "../chart/src/chart.h"
#include "../fileeditor/src/fileeditor.h"
#include "../fileeditor/src/geosearch.h"
//#include "../planets/src/planets.h"
//#include "../astroqmlviewv2.h"
#include "../details/src/details.h"
#include "mainwindow.h"


/* =========================== ASTRO FILE INFO ====================================== */

AstroFileInfo :: AstroFileInfo (QWidget *parent) : AstroFileHandler(parent)
{
    currentIndex = 0;
    
    edit   = new QPushButton(this);
    shadow = new QLabel(this);
    QGraphicsBlurEffect* ef = new QGraphicsBlurEffect();
    
    ef->setBlurRadius(5);
    shadow->setGraphicsEffect(ef);
    edit->setFlat(true);
    edit->raise();
    edit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    edit->setCursor(Qt::PointingHandCursor);
    setStatusTip(tr("Input data"));
    
    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(edit,0,0,1,1);
    layout->addWidget(shadow,0,0,1,1);
    
    connect(edit, SIGNAL(clicked()), this, SIGNAL(clicked()));
}

void AstroFileInfo :: refresh()
{
    qDebug() << "AstroFileInfo::refresh";
    QDateTime dt = currentFile()->getLocalTime();
    
    QString date      = dt.date().toString(Qt::DefaultLocaleShortDate);
    QString dayOfWeek = dt.date().toString("ddd");
    QString time      = dt.time().toString();
    
    QString age;
    if (showAge)
    {
        float a1 = dt.daysTo(QDateTime::currentDateTime()) / 365.25;
        char a[7];
        sprintf(a, "%5.2f", a1);
        age = tr(", %1 years").arg(a);
    }
    
    QString timezone;
    if (currentFile()->getTimezone() > 0)
        timezone = QString("GMT +%1").arg(currentFile()->getTimezone());
    else if (currentFile()->getTimezone() < 0)
        timezone = QString("GMT %1").arg(currentFile()->getTimezone());
    else
        timezone = "GMT";
    
    QString place;
    if (currentFile()->getLocationName().isEmpty())
    {
        QString longitude = A::degreeToString(currentFile()->getLocation().x(), A::HighPrecision);
        QString latitude  = A::degreeToString(currentFile()->getLocation().y(), A::HighPrecision);
        place = QString("%1N  %2E").arg(latitude, longitude);
    }
    else
    {
        place = currentFile()->getLocationName();
    }
    
    setText( QString("%1\n").arg(currentFile()->getName()) +
             tr("%1 %2 %3 (%4)%5\n").arg(date, dayOfWeek, time, timezone, age) +
             place );
}

void AstroFileInfo :: filesUpdated(MembersList m)
{
    if (currentIndex >= filesCount())
    {
        setText("");
        return;
    }
    
    if (m[currentIndex] & (AstroFile::Name | AstroFile::GMT | AstroFile::Timezone |
                           AstroFile::Location | AstroFile::LocationName))
        refresh();
}

void AstroFileInfo :: setText(const QString& str)
{
    edit->setText(str);
    shadow->setText(str);
}

AppSettings AstroFileInfo :: defaultSettings ()
{
    AppSettings s;
    s.setValue ( "age", true );
    return s;
}

AppSettings AstroFileInfo :: currentSettings ()
{
    AppSettings s;
    s.setValue ( "age", showAge );
    return s;
}

void AstroFileInfo :: applySettings       ( const AppSettings& s )
{
    showAge = s.value ( "age" ).toBool();
    if (currentIndex < filesCount()) refresh();
}

void AstroFileInfo :: setupSettingsEditor ( AppSettingsEditor* ed )
{
    ed -> addCheckBox("age", tr("Show age:"));
}


/* =========================== ASTRO WIDGET ========================================= */

AstroWidget :: AstroWidget(QWidget *parent) : QWidget(parent)
{
    editor = 0;
    
    toolBar = new QToolBar(tr("Slides"), this);
    actionGroup = new QActionGroup(this);
    
    geoWdg      = new GeoSearchWidget;
    slides      = new SlideWidget;
    fileView    = new AstroFileInfo;
    fileView2nd = new AstroFileInfo;
    
    toolBar     -> setObjectName("slides");
    actionGroup -> setExclusive(true);
    slides      -> setTransitionEffect(SlideWidget::Transition_HorizontalSlide);
    fileView2nd -> setStatusTip(tr("Background data"));
    fileView2nd -> setCurrentIndex(1);
    fileView2nd -> setObjectName("secondFile");
    
    QGridLayout* layout = new QGridLayout(this);
    layout->setMargin(0);
    layout->addWidget(slides,      0,0, 1,1);
    layout->addWidget(fileView,    0,0, 1,1, Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(fileView2nd, 0,0, 1,1, Qt::AlignRight|Qt::AlignTop);
    
    addDockWidget(new Details, tr("Details"), true);
    addSlide(new Chart,   QIcon("style/natal.png"),   tr("Chart"));
    //addSlide(new Planets, QIcon("style/planets.png"), tr("Planets"));
    addSlide(new Plain,   QIcon("style/plain.png"),   tr("Text"));
    addHoroscopeControls();
    
    connect(fileView,    SIGNAL(clicked()), this, SLOT(openEditor()));
    connect(fileView2nd, SIGNAL(clicked()), this, SLOT(openEditor()));
    connect(slides,      SIGNAL(currentSlideChanged()), this, SLOT(currentSlideChanged()));
}

void AstroWidget :: setupFile (AstroFile* file, bool suspendUpdate)
{
    if (!file) return;
    bool hasChanges = file->hasUnsavedChanges();
    file->suspendUpdate();
    
    if (file->getGMT() == QDateTime::fromTime_t(0))  // set current date, time, timezone
    {
        QDateTime current = QDateTime::currentDateTime();
        QDateTime currentUTC = QDateTime(current.toUTC().date(), current.toUTC().time());
        file->setGMT(currentUTC);
        file->setTimezone(currentUTC.secsTo(current) / 3600);
        //qDebug()<<"::::::::::::::::::"<<currentUTC.toString("hh:mm:ss");
    }
    
    
    if (file->getLocation().isNull())                // set default location
    {
        file->setLocation(geoWdg->location());
        file->setLocationName(geoWdg->locationName());
    }
    
    file->setZodiac      (zodiacSelector->itemData(zodiacSelector->currentIndex()).toInt());   // set zodiac
    file->setHouseSystem (hsystemSelector->itemData(hsystemSelector->currentIndex()).toInt()); // set house system
    file->setAspectSet   (aspectsSelector->itemData(aspectsSelector->currentIndex()).toInt()); // set aspect set
    
    
    if (!hasChanges) file->clearUnsavedState();
    if (!suspendUpdate) file->resumeUpdate();
    
    connect(file, SIGNAL(destroyRequested()), this, SLOT(destroyingFile()));
}

void AstroWidget :: switchToSingleAspectSet()
{
    aspectsSelector->blockSignals(true);
    A::AspectSetId set = aspectsSelector->itemData(aspectsSelector->currentIndex()).toInt();
    A::AspectSetId set2 = sqrtf(set);
    int itemIndex = aspectsSelector->findData(set2);
    if (set2 * set2 == set && itemIndex >= 0)
    {
        qDebug() << "AstroWidget::restore aspect set to single";
        aspectsSelector->setCurrentIndex(itemIndex);
    }
    aspectsSelector->blockSignals(false);
}

void AstroWidget :: switchToSynastryAspectSet()
{
    aspectsSelector->blockSignals(true);
    A::AspectSetId set = aspectsSelector->itemData(aspectsSelector->currentIndex()).toInt();
    A::AspectSetId set2 = set * set;
    int itemIndex = aspectsSelector->findData(set2);
    if (itemIndex >= 0)
    {
        qDebug() << "AstroWidget::replace aspect set to synastry";
        aspectsSelector->setCurrentIndex(itemIndex);
    }
    aspectsSelector->blockSignals(false);
}

void AstroWidget :: setFiles (const AstroFileList& files)
{
    if (files.count() == 2)
        switchToSynastryAspectSet();
    else if (files.count() == 1)
        switchToSingleAspectSet();
    
    foreach(AstroFile* i, files)
        setupFile(i, true);
    
    fileView->setFiles(files);
    fileView2nd->setFiles(files);
    if (editor) editor->setFiles(files);
    foreach (AstroFileHandler* h, handlers)
        h->setFiles(files);
    
    foreach(AstroFile* i, files)
        i->resumeUpdate();
    
    fileView->resumeUpdate();
    fileView2nd->resumeUpdate();
    if (editor) editor->resumeUpdate();
    foreach (AstroFileHandler* h, handlers)
        if (h->isVisible()) h->resumeUpdate();
}

void AstroWidget :: openEditor()
{
    if (editor)
    {
        editor->raise();
    }
    else
    {
        editor = new AstroFileEditor();
        editor->setFiles(files());
        editor->move((topLevelWidget()->width()  - editor->width())  / 2 + topLevelWidget()->geometry().left(),
                     (topLevelWidget()->height() - editor->height()) / 2 + topLevelWidget()->geometry().top());
        editor->show();
        connect(editor, SIGNAL(appendFile()),   this, SIGNAL(appendFileRequested()));
        connect(editor, SIGNAL(swapFiles(int,int)), this, SIGNAL(swapFilesRequested(int,int)));
        connect(editor, SIGNAL(windowClosed()), this, SLOT(destroyEditor()));
    }
    
    if (sender() == fileView)
        editor->setCurrentFile(0);
    else if (sender() == fileView2nd)
        editor->setCurrentFile(1);
}

void AstroWidget :: destroyingFile()
{
    AstroFile* file = (AstroFile*)sender();
    if (!files().contains(file) || files().count() > 2) return;
    switchToSingleAspectSet();
}

void AstroWidget :: destroyEditor()
{
    editor->deleteLater();
    editor = 0;
}

void AstroWidget :: addSlide(AstroFileHandler* w, const QIcon& icon, QString title)
{
    QAction* act = toolBar->addAction(icon, title, this, SLOT(toolBarActionClicked()));
    act->setCheckable(true);
    act->setActionGroup(actionGroup);
    if (!slides->count()) act->setChecked(true);
    slides->addSlide(w);
    attachHandler(w);
    
    foreach (AstroFileHandler* wdg, dockHandlers)
        connect(w, SIGNAL(planetSelected(A::PlanetId, int)), wdg, SLOT(setCurrentPlanet(A::PlanetId, int)));
    
    foreach (QDockWidget* d, docks)
        connect(w, SIGNAL(planetSelected(A::PlanetId, int)), d, SLOT(show()));
}

void AstroWidget :: addDockWidget(AstroFileHandler* w, QString title, bool scrollable, QString objectName)
{
    if (objectName.isEmpty()) objectName = w->metaObject()->className();
    QDockWidget* dock = new QDockWidget(title);
    dock->setObjectName(objectName);
    
    if (scrollable)
    {
        /*QScrollArea* area = new QScrollArea;
        area->setWidget(w);
        area->setWidgetResizable(true);
        dock->setWidget(area);*/
    }
    else
    {
        dock->setWidget(w);
    }
    docks << dock;
    dockHandlers << w;
    attachHandler(w);
}

void AstroWidget :: attachHandler(AstroFileHandler* w)
{
    handlers << w;
    connect(w, SIGNAL(requestHelp(QString)), this, SIGNAL(helpRequested(QString)));
}

void AstroWidget :: addHoroscopeControls()
{
    zodiacSelector  = new QComboBox;
    hsystemSelector = new QComboBox;
    aspectsSelector   = new QComboBox;
    
    zodiacSelector  -> setToolTip(tr("Sign"));
    hsystemSelector -> setToolTip(tr("House system"));
    aspectsSelector -> setToolTip(tr("Aspect sets\n(by A.Podvodny)"));
    
    foreach (const A::Zodiac& z, A::getZodiacs())
        zodiacSelector->addItem(z.name, z.id);                  // create combo box with zodiacs
    
    foreach (const A::HouseSystem& sys, A::getHouseSystems())
        hsystemSelector->addItem(sys.name, sys.id);             // create combo box with house systems
    
    foreach (const A::AspectsSet& s, A::getAspectSets())
        aspectsSelector->addItem(s.name, s.id);                 // create combo box with aspect sets
    
    horoscopeControls << zodiacSelector << hsystemSelector << aspectsSelector;
    
    foreach (QComboBox* c, horoscopeControls)
    {
        c->setEditable(false);
        connect (c, SIGNAL(currentIndexChanged(int)), this, SLOT(horoscopeControlChanged()));
    }
}

void AstroWidget :: toolBarActionClicked()
{
    QAction* s = (QAction*)sender();
    int i = toolBar->actions().indexOf(s);
    slides->setSlide(i);
}

void AstroWidget :: currentSlideChanged()
{
    fileView2nd->setVisible(slides->currentIndex() == 0);   // show background data only in chart view
}

void AstroWidget :: applyGeoSettings(AppSettings& s)
{
    qDebug()<<":::::::::::::::::::::::::::"<<geoWdg->location();
    qDebug()<<":::::::::::::::::::::::::::"<<geoWdg->locationName();
    s.setValue("Scope/defaultLocation",     vectorToString(geoWdg->location()));
    s.setValue("Scope/defaultLocationName", geoWdg->locationName());
}

QString AstroWidget :: vectorToString (const QVector3D& v)
{
    return QString("%1 %2 %3").arg(v.x()).arg(v.y()).arg(v.z());
}

QVector3D AstroWidget :: vectorFromString (const QString& str)
{
    QVector3D ret;
    ret.setX(str.section(" ", 0, 0).toFloat());
    ret.setY(str.section(" ", 1, 1).toFloat());
    ret.setZ(str.section(" ", 2, 2).toFloat());
    return ret;
}

void AstroWidget :: horoscopeControlChanged()
{
    foreach(AstroFile* i, files())
        setupFile(i, true);
    
    foreach(AstroFile* i, files())
        i->resumeUpdate();
}

AppSettings AstroWidget :: defaultSettings ()
{  
    AppSettings s;
    
    s << fileView->defaultSettings();
    
    foreach (AstroFileHandler* h, handlers)
        s << h->defaultSettings();
    
    s.setValue("Scope/defaultLocation",     "37.6184 55.7512 0");
    s.setValue("Scope/defaultLocationName", "Moscow, Russia");
    s.setValue("Scope/zodiac",              0);          // indexes of ComboBox items, not values itself
    s.setValue("Scope/houseSystem",         0);
    s.setValue("Scope/aspectSet",           0);
    s.setValue("slide", slides->currentIndex());    // чтобы не возвращалась к первому слайду после сброса настроек
    return s;
}

AppSettings AstroWidget :: currentSettings ()
{ 
    AppSettings s;
    
    s << fileView->currentSettings();
    
    foreach (AstroFileHandler* h, handlers)
        s << h->currentSettings();
    
    applyGeoSettings(s);
    
    s.setValue("Scope/zodiac",      zodiacSelector  -> currentIndex());
    s.setValue("Scope/houseSystem", hsystemSelector -> currentIndex());
    s.setValue("Scope/aspectSet",   aspectsSelector -> currentIndex());
    s.setValue("slide",             slides          -> currentIndex());
    return s;
}

void AstroWidget :: applySettings      ( const AppSettings& s )
{
    geoWdg -> setLocation     ( vectorFromString(s.value("Scope/defaultLocation").toString()) );
    geoWdg -> setLocationName ( s.value("Scope/defaultLocationName").toString() );
    
    zodiacSelector  -> setCurrentIndex (s.value("Scope/zodiac").toInt());
    hsystemSelector -> setCurrentIndex (s.value("Scope/houseSystem").toInt());
    aspectsSelector -> setCurrentIndex (s.value("Scope/aspectSet").toUInt());
    slides          -> setSlide        (s.value("slide").toInt() );
    toolBar         -> actions()[slides->currentIndex()]->setChecked(true);
    
    fileView->applySettings(s);
    fileView2nd->applySettings(s);
    
    foreach(AstroFile* i, files())
        setupFile(i);
    
    foreach (AstroFileHandler* h, handlers)
        h->applySettings(s);
}

void AstroWidget :: setupSettingsEditor ( AppSettingsEditor* ed )
{
    //ed->addTab(tr("Data"));
    
    fileView->setupSettingsEditor(ed);
    ed->addCustomWidget(geoWdg, tr("Default location:"), SIGNAL(locationChanged()));
    
    foreach (AstroFileHandler* h, handlers)
        h->setupSettingsEditor(ed);
    
    connect(ed, SIGNAL(apply(AppSettings&)), this, SLOT(applyGeoSettings(AppSettings&)));
}


/* =========================== ASTRO FILE DATABASE ================================== */

AstroDatabase :: AstroDatabase (QWidget *parent) : QFrame(parent)
{
    QPushButton* refresh = new QPushButton;
    
    fileList   = new QListWidget;
    search     = new QLineEdit;
    
    refresh->setIcon(QIcon("style/update.png"));
    refresh->setToolTip(tr("Refresh"));
    refresh->setCursor(Qt::PointingHandCursor);
    fileList->setSelectionMode(QAbstractItemView::ExtendedSelection);
    fileList->viewport()->installEventFilter(this);       // for handling middle mouse button clicks
    search->setPlaceholderText(tr("Search"));
    setMinimumWidth(200);
    setContextMenuPolicy(Qt::CustomContextMenu);
    setWindowTitle(tr("Database"));
    setWindowFlags(Qt::WindowStaysOnTopHint);
    
    QHBoxLayout* l = new QHBoxLayout;
    l->addWidget(search);
    l->addWidget(refresh);
    
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addLayout(l);
    layout->addWidget(fileList);
    
    
    connect(refresh, SIGNAL(clicked()), this, SLOT(updateList()));
    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));
    connect(fileList, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(openSelected()));
    connect(search, SIGNAL(textChanged(QString)), this, SLOT(searchFilter(QString)));
    
    updateList();
}

void AstroDatabase :: searchFilter(QString s)
{
    for (int i = 0; i < fileList->count(); i++)
    {
        QListWidgetItem* item = fileList->item(i);
        item->setHidden(!item->text().contains(s, Qt::CaseInsensitive));
    }
}

void AstroDatabase :: updateList()
{
    QDir dir("user/");
    
    QStringList list = dir.entryList(QStringList("*.dat"), QDir::Files, QDir::Name|QDir::IgnoreCase);
    list.replaceInStrings(".dat", "");
    
    QStringList selectedItems;
    foreach(QListWidgetItem* item, fileList->selectedItems())
    {
        if (item->isSelected()) selectedItems << item->text();
    }
    
    fileList->clear();
    
    foreach(QString itemString, list)
    {
        QListWidgetItem* item = new QListWidgetItem(itemString, fileList);
        if (selectedItems.contains(itemString))
            item->setSelected(true);
    }
    
    
    searchFilter(search->text());
}

void AstroDatabase :: deleteSelected()
{
    int count = fileList->selectedItems().count();
    if (!count) return;
    
    QMessageBox msgBox;
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    
    if (count == 1)
        msgBox.setText(tr("Delete '%1' from list?").arg(fileList->selectedItems()[0]->text()));
    else
        msgBox.setText(tr("Delete %1 files from list?").arg(count));
    
    
    int ret = msgBox.exec();
    if (ret == QMessageBox::Cancel) return;
    
    foreach (QListWidgetItem* item, fileList->selectedItems())
    {
        QString file = "user/" + item->text() + ".dat";
        QFile::remove(file);
        emit fileRemoved(item->text());
        fileList->removeItemWidget(item);
        delete item;
    }
}

void AstroDatabase :: openSelected()
{
    int count = fileList->selectedItems().count();
    if (!count) return;
    
    if (count == 1)
        emit openFile(fileList->selectedItems()[0]->text());
    else
        foreach (QListWidgetItem* item, fileList->selectedItems())
            emit openFileInNewTab(item->text());
}

void AstroDatabase :: openSelectedInNewTab()
{
    foreach (QListWidgetItem* item, fileList->selectedItems())
        emit openFileInNewTab(item->text());
}

void AstroDatabase :: openSelectedAsSecond()
{
    QListWidgetItem* item = fileList->selectedItems().first();
    emit openFileAsSecond(item->text());
}

void AstroDatabase :: showContextMenu(QPoint p)
{
    QMenu* mnu = new QMenu(this);
    QPoint pos = ((QWidget*)sender())->mapToGlobal(p);
    
    mnu -> addAction(tr("Open"), this, SLOT(openSelected()));
    mnu -> addAction(tr("Open in new tab"), this, SLOT(openSelectedInNewTab()));
    mnu -> addAction(tr("Synastry view"), this, SLOT(openSelectedAsSecond()));
    mnu -> addSeparator();
    mnu -> addAction(QIcon("style/delete.png"), tr("Delete"),this, SLOT(deleteSelected()));
    
    mnu -> exec(pos);
    mnu -> deleteLater();
}

void AstroDatabase :: keyPressEvent(QKeyEvent* e)
{
    if (e->key() == Qt::Key_Delete)
        deleteSelected();
}

bool AstroDatabase :: eventFilter(QObject *o, QEvent *e)
{
    if (e->type() == QEvent::MouseButtonRelease &&
            ((QMouseEvent*)e)->button() == Qt::MiddleButton)
    {
        openSelectedInNewTab();
        return true;
    }
    return QObject::eventFilter(o, e);
}


/* =========================== FILES BAR ============================================ */

FilesBar :: FilesBar(QWidget *parent) : QTabBar(parent)
{
    setTabsClosable(true);
    setMovable(true);
    setDocumentMode(true);
    //setStyleSheet("color: red;");
    connect(this, SIGNAL(tabMoved(int,int)),      this, SLOT(swapTabs(int,int)));
    connect(this, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));
}

int FilesBar  :: getTabIndex(AstroFile* f, bool seekFirstFileOnly)
{
    for (int i = 0; i < count(); i++)
        for (int j = 0; j < (seekFirstFileOnly ? 1 : files[i].count()); j++)
            if (f == files[i][j])
                return i;
    return -1;
}

int FilesBar  :: getTabIndex(QString name, bool seekFirstFileOnly)
{
    for (int i = 0; i < count(); i++)
        for (int j = 0; j < (seekFirstFileOnly ? 1 : files[i].count()); j++)
            if (name == files[i][j]->getName())
                return i;
    return -1;
}

void FilesBar :: addFile (AstroFile* file)
{
    if (!file)
    {
        qWarning() << "FilesBar::addFile: failed to add an empty file";
        return;
    }
    
    AstroFileList list;
    list << file;
    files << list;
    file->setParent(this);
    addTab("new");
    updateTab(count() - 1);
    setCurrentIndex(count() - 1);
    
    connect(file, SIGNAL(changed(AstroFile::Members)), this, SLOT(fileUpdated(AstroFile::Members)));
    connect(file, SIGNAL(destroyRequested()),          this, SLOT(fileDestroyed()));
}

void FilesBar :: updateTab(int index)
{
    if (index >= count()) return;
    QStringList names;
    
    foreach (AstroFile* i, files[index])
        if (i) names << i->getName() + (i->hasUnsavedChanges() ? "*" : "");
    
    setTabText(index, names.join(" | "));
}

void FilesBar :: fileUpdated(AstroFile::Members m)
{
    if (!(m & (AstroFile::Name|AstroFile::ChangedState))) return;
    qDebug() << "FilesBar::updateTab";
    AstroFile* file = (AstroFile*)sender();
    updateTab(getTabIndex(file));
}

void FilesBar :: fileDestroyed()                // called when AstroFile going to be destroyed
{
    AstroFile* file = (AstroFile*)sender();
    int tab = getTabIndex(file);
    if (tab == -1) return;                        // tab with the single file has been removed already
    int index = files[tab].indexOf(file);
    files[tab].removeAt(index);
    updateTab(tab);
    file->deleteLater();
}

void FilesBar :: swapTabs(int f1,int f2)
{
    AstroFileList temp = files[f1];
    files[f1] = files[f2];
    files[f2] = temp;
}

void FilesBar :: swapCurrentFiles(int i,int j)
{
    AstroFile* temp = files[currentIndex()][i];
    files[currentIndex()][i] = files[currentIndex()][j];
    files[currentIndex()][j] = temp;
    updateTab(currentIndex());
    currentChanged(currentIndex());
}

bool FilesBar :: closeTab(int index)
{
    AstroFileList f = files[index];
    AstroFile* file = 0;
    if (f.count()) file = f[0];
    
    if (askToSave && file && file->hasUnsavedChanges())
    {
        QMessageBox msgBox;
        msgBox.setText(tr("Save changes in '%1' before closing?").arg(file->getName()));
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();
        
        switch (ret)
        {
        case QMessageBox::Yes: file->save(); break;
        case QMessageBox::Cancel: return false;
        default: break;
        }
    }
    else if (count() == 1)
    {
        return false;                               // TODO: make an empty file instead last tab
    }
    
    files.removeAt(index);
    ((QTabBar*)this)->removeTab(index);
    foreach (AstroFile* i, f)
        i->destroy();                     // delete AstroFiles, because we do not need it
    if (!count()) addNewFile();
    return true;
}

void FilesBar :: openFile(QString name)
{
    int i = getTabIndex(name, true);
    if (i != -1) return setCurrentIndex(i);            // focus if the file is currently opened
    
    /*if (currentFile()->hasUnsavedChanges())
    openFileInNewTab(name);
  else*/
    currentFiles()[0]->load(name);
    
}

void FilesBar :: openFileInNewTab(QString name)
{
    //int i = getTabIndex(name, true);
    //if (i != -1) return setCurrentIndex(i);
    
    AstroFile* file = new AstroFile;
    file->load(name);
    addFile(file);
}

void FilesBar :: openFileAsSecond(QString name)
{
    if (files[currentIndex()].count() < 2)
    {
        AstroFile* file = new AstroFile;
        file->load(name);
        file->setParent(this);
        files[currentIndex()] << file;
        updateTab(currentIndex());
        connect(file, SIGNAL(changed(AstroFile::Members)), this, SLOT(fileUpdated(AstroFile::Members)));
        connect(file, SIGNAL(destroyRequested()),          this, SLOT(fileDestroyed()));
        emit currentChanged(currentIndex());
    }
    else
    {
        files[currentIndex()][1]->load(name);
    }
}


/* =========================== MAIN WINDOW ========================================== */

MainWindow :: MainWindow(QWidget *parent) : QMainWindow(parent), Customizable()
{
    HelpWidget* help   = new HelpWidget("text/" + A::usedLanguage(), this);

    filesBar           = new FilesBar(this);
    astroWidget        = new AstroWidget();
    databaseDockWidget = new QDockWidget(this);
    astroDatabase      = new AstroDatabase();
    toolBar            = new QToolBar(tr("File"),     this);
    toolBar2           = new QToolBar(tr("Options"),  this);
    helpToolBar        = new QToolBar(tr("Hint"),  this);
    panelsMenu         = new QMenu;

    
    toolBar            -> setObjectName("toolBar");
    toolBar2           -> setObjectName("toolBar2");
    helpToolBar        -> setObjectName("helpToolBar");
    helpToolBar        -> addWidget(help);
    databaseDockWidget -> setObjectName("dbDockWidget");
    databaseDockWidget -> setWidget(astroDatabase);
    databaseDockWidget -> setWindowTitle(tr("Database"));
    databaseDockWidget -> hide();
    help               -> setFixedHeight(70);
    this               -> setIconSize(QSize(48,48));
    this               -> setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    this               -> setWindowTitle(QApplication::applicationName());
    this               -> setMinimumHeight(480);
    
    
    QWidget* wdg = new QWidget(this);
    wdg->setObjectName("centralWidget");
    wdg->setContextMenuPolicy(Qt::CustomContextMenu);
    QVBoxLayout* layout = new QVBoxLayout(wdg);
    layout->setSpacing(0);
    layout->setMargin(0);
    layout->addWidget(filesBar, 0, Qt::AlignLeft);
    layout->addWidget(astroWidget);

    //Zodiac Server
    if(qApp->applicationFilePath().indexOf("zodiac_server")<0){
        layout->addWidget(astroWidget);
    }

    setCentralWidget(wdg);
    addToolBarActions();
    addToolBar(Qt::TopToolBarArea, toolBar);
    addToolBar(Qt::TopToolBarArea, astroWidget->getToolBar());
    addToolBar(Qt::TopToolBarArea, toolBar2);
    addToolBar(Qt::TopToolBarArea, helpToolBar);
    addDockWidget(Qt::LeftDockWidgetArea, databaseDockWidget);

    foreach(QDockWidget* w, astroWidget->getDockPanels())
    {
        addDockWidget(Qt::RightDockWidgetArea, w);
        w->hide();
        createActionForPanel(w);
    }
    
    foreach(QWidget* w, astroWidget->getHoroscopeControls())
        statusBar()->addPermanentWidget(w);
    
    connect(wdg,           SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenu(QPoint)));
    connect(filesBar,      SIGNAL(currentChanged(int)),          this,     SLOT(currentTabChanged()));
    connect(astroDatabase, SIGNAL(openFile(QString)),            filesBar, SLOT(openFile(QString)));
    connect(astroDatabase, SIGNAL(openFileInNewTab(QString)),    filesBar, SLOT(openFileInNewTab(QString)));
    connect(astroDatabase, SIGNAL(openFileAsSecond(QString)),    filesBar, SLOT(openFileAsSecond(QString)));
    connect(astroWidget,   SIGNAL(appendFileRequested()),        filesBar, SLOT(openFileAsSecond()));
    connect(astroWidget,   SIGNAL(helpRequested(QString)),       help,     SLOT(searchFor(QString)));
    connect(astroWidget,   SIGNAL(swapFilesRequested(int,int)),  filesBar, SLOT(swapCurrentFiles(int,int)));
    connect(statusBar(),   SIGNAL(messageChanged(QString)),      help,     SLOT(searchFor(QString)));
    connect(new QShortcut(QKeySequence("CTRL+TAB"), this), SIGNAL(activated()), filesBar, SLOT(nextTab()));
    
    loadSettings();
    


    /*===================ZODIAC SERVER ====================*/

    //Argumentos esperados
    //fileName 1975 6 20 22 00 -3 -35.484462 -69.5797495 Malargue_Mendoza /home/nextsigner/data.json 15321321 10 "/home/nextsigner/Escritorio/capture.png"
    //fileName año mes día hora minutos gmt lat lon ciudad jsonLocation ms secsTimerQuit captureLocation resCap5120x2880

    //Utilizado en programación Windows 7
    //fileName 1975 6 20 23 00 -3 -35.484462 -69.5797495 Malargue_Mendoza C:/nsp/uda/temp/data.json 15321321 10 "C:/nsp/uda/temp/capture.png" 1280x720 1280x720

    qDebug()<<"Count args: "<<qApp->arguments().size();

    if(qApp->applicationFilePath().indexOf("zodiac_server")>0&&(qApp->arguments().size()==2||qApp->arguments().size()==17)){
        qDebug()<<"Se toman argumentos "<<qApp->arguments();
        QString fileName;
        fileName.append(qApp->arguments().at(1));
        AstroFile nf;
        if(qApp->arguments().size()==17){
            QStringList slResCap=qApp->arguments().at(15).split("x");
            if(slResCap.length()!=2){
                qDebug()<<"Error de resolución de captura.";
                this->close();
            }
            int xCnWidth=slResCap.at(0).toInt();
            int xCnHeight=slResCap.at(1).toInt();
            xCn=new QWidget();
            xCn->setObjectName("xcn");
            xCn->setStyleSheet("#xcn{background-color: red}");
            xCn->setMinimumWidth(xCnWidth);
            xCn->setMinimumHeight(xCnHeight);
            xCn->setMaximumWidth(xCnWidth);
            xCn->setMaximumHeight(xCnHeight);
            xCn->setGeometry(0,0, xCnWidth, xCnHeight);
            xCn->show();
            QVBoxLayout* layoutCn = new QVBoxLayout(xCn);
            layoutCn->setSpacing(0);
            layoutCn->setMargin(0);
            layoutCn->addWidget(astroWidget);

            //Timer Capture
            timerCapture = new QTimer(this);
            connect(timerCapture, SIGNAL(timeout()), this, SLOT(capture()));
            timerCapture->start(1000);

            //Timer Quit
            timerQuit = new QTimer(this);
            connect(timerQuit, SIGNAL(timeout()), qApp, SLOT(quit()));
            timerQuit->start(qApp->arguments().at(13).toInt()*1000);

            QFile docDat(fileName);
            if(!docDat.exists()){
                nf.setName(fileName);
                QDate d(qApp->arguments().at(2).toInt(), qApp->arguments().at(3).toInt(), qApp->arguments().at(4).toInt());
                QTime t(qApp->arguments().at(5).toInt(), qApp->arguments().at(6).toInt(), 0);

                QDateTime dt;
                dt.setDate(d);
                dt.setTime(t);
                int sec;
                if(qApp->arguments().at(7).toInt()<0){
                    sec=(3600*abs(qApp->arguments().at(7).toInt()));
                }else{
                    sec=0-(3600*qApp->arguments().at(7).toInt());
                }

                QString locale_st_HH = QLocale("en_EN").toString(dt, "yyyy MMMM dd HH.mm.ss zzz ap");
                qDebug()<<"Time: "<<locale_st_HH;
                dt=dt.addSecs(sec);
                locale_st_HH = QLocale("en_EN").toString(dt, "yyyy MMMM dd HH.mm.ss zzz ap");
                //qDebug()<<"Time: "<<locale_st_HH;
                nf.setGMT(dt);
                nf.setTimezone(qApp->arguments().at(7).toInt());
                qDebug()<<"NF Time Zone: "<<nf.getTimezone();
                nf.setLocation(QVector3D(qApp->arguments().at(9).toFloat(), qApp->arguments().at(8).toFloat(),0));
                QString nomciu;
                nomciu.append(qApp->arguments().at(10));
                QString ln;
                ln.append(nomciu.replace("_", " "));
                ln.append("\nlat: ");
                ln.append(qApp->arguments().at(8));
                ln.append("\nlon: ");
                ln.append(qApp->arguments().at(9));
                nf.setLocationName(ln);
                nf.save();
            }else{
                nf.load(fileName);
            }
            //nf.getZodiac()



            //qDebug()<<"Time: "<<t.toString();
            //qDebug()<<"Time Zone: "<<nf.getTimezone();
            //qDebug()<<"Time GMT: "<<nf.getGMT();

            filesBar->addNewFile();
            filesBar->openFile(fileName);
            astroWidget->setGeometry(0,0, 800, 600);

            //filesBar->currentFiles().at(0)->get

            //Casas
            QString params;
            params.append("\"params\":{\n");

            params.append("\"ms\":\"");
            params.append(qApp->arguments().at(12));
            params.append("\",");

            params.append("\"n\":\"");
            params.append(qApp->arguments().at(1));
            params.append("\",");

            params.append("\"a\":\"");
            params.append(qApp->arguments().at(2));
            params.append("\",");

            params.append("\"m\":\"");
            params.append(qApp->arguments().at(3));
            params.append("\",");

            params.append("\"d\":\"");
            params.append(qApp->arguments().at(4));
            params.append("\",");

            params.append("\"h\":\"");
            params.append(qApp->arguments().at(5));
            params.append("\",");

            params.append("\"min\":\"");
            params.append(qApp->arguments().at(6));
            params.append("\",");

            params.append("\"gmt\":\"");
            params.append(qApp->arguments().at(7));
            params.append("\",");

            params.append("\"lat\":\"");
            params.append(qApp->arguments().at(8));
            params.append("\",");

            params.append("\"lon\":\"");
            params.append(qApp->arguments().at(9));
            params.append("\",");

            params.append("\"ciudad\":\"");
            params.append(QString(qApp->arguments().at(10)).replace("_", " "));
            params.append("\"");

            params.append("}\n");

            //Planetas en signo y casa
            QString psc;
            psc.append("\"psc\":{\n");
            for (int i=0;i<filesBar->currentFiles().at(0)->horoscope().planets.count();i++) {
                //qDebug()<<"------- "<<A::describePlanet(filesBar->currentFiles().at(0)->horoscope().planets.value(i), filesBar->currentFiles().at(0)->horoscope().zodiac);
                QString d=A::describePlanet(filesBar->currentFiles().at(0)->horoscope().planets.value(i), filesBar->currentFiles().at(0)->horoscope().zodiac);
                QString item;
                //qDebug()<<"["<<d<<"]\n\n";
                QStringList m0=d.replace(" Pole", "").replace("         ", "@").replace("         ", "@").replace("        ", "@").replace("       ", "@").replace("      ", "@").replace("     ", "@").replace("    ", "@").replace("   ", "@").replace("  ", "@").replace(" ", "@").replace(".", "").replace("@@@@", "@").replace("@@@", "@").replace("@@", "@").split("@");

                if(i!=0){
                    item.append(",");
                }

                qDebug()<<"-----"<<m0.at(0)<<"-------\n\n";
                item.append("\"");
                item.append(m0.at(0));
                item.append("\":{");

                item.append("\"g\":");
                item.append(QString::number(m0.at(1).toInt()));
                item.append(",");

                item.append("\"m\":");
                item.append(QString::number(m0.at(3).toInt()));

                item.append(",");
                item.append("\"s\":\"");
                item.append(m0.at(2));
                item.append("\"");

                QString h="-1";
                if(m0.at(4)=="I"){h="1";}
                if(m0.at(4)=="II"){h="2";}
                if(m0.at(4)=="III"){h="3";}
                if(m0.at(4)=="IV"){h="4";}
                if(m0.at(4)=="V"){h="5";}
                if(m0.at(4)=="VI"){h="6";}
                if(m0.at(4)=="VII"){h="7";}
                if(m0.at(4)=="VIII"){h="8";}
                if(m0.at(4)=="IX"){h="9";}
                if(m0.at(4)=="X"){h="10";}
                if(m0.at(4)=="XI"){h="11";}
                if(m0.at(4)=="XII"){h="12";}

                item.append(",");
                item.append("\"h\":");
                item.append(h);
                item.append("");

                item.append(",");
                item.append("\"rh\":\"");
                item.append(m0.at(4));
                item.append("\"");

                item.append("}\n");
                psc.append(item);
            }
            psc.append("}\n");


            //Casas
            QString pc;
            pc.append("\"pc\":{\n");
            QStringList h0=A::describeHouses(filesBar->currentFiles().at(0)->horoscope().houses, filesBar->currentFiles().at(0)->horoscope().zodiac).split("\n");
            for (int i=1;i<h0.length();i++) {
                qDebug()<<h0.at(i);
                QString d;
                d.append(h0.at(i));
                QStringList m0=d.replace("\"", "").replace("         ", "@").replace("         ", "@").replace("        ", "@").replace("       ", "@").replace("      ", "@").replace("     ", "@").replace("    ", "@").replace("   ", "@").replace("  ", "@").replace(" ", "@").replace(".", "").replace("\n", "").split("@");
                qDebug()<<"--->"<<m0;
                QString item;
                if(i!=1){
                    item.append(",");
                }

                item.append("\"h");
                item.append(QString::number(i));
                item.append("\":{");

                item.append("\"s\":\"");
                item.append(m0.at(m0.length()-2));
                item.append("\",");

                item.append("\"g\":");
                item.append(QString::number(m0.at(m0.length()-3).toInt()));
                item.append(",");

                item.append("\"m\":");
                item.append(QString::number(m0.at(m0.length()-1).toInt()));
                //item.append("\"");

                item.append("}\n");
                pc.append(item);
            }
            pc.append("}\n");

            //Aspectos
            int vasp=0;
            QString asp;
            asp.append("\"asp\":{\n");
            for (int i=0;i<filesBar->currentFiles().at(0)->horoscope().aspects.count();i++) {
                QString a1=A::describeAspect(filesBar->currentFiles().at(0)->horoscope().aspects.value(i));
                qDebug()<<"--->"<<a1<<"<---";
                QStringList m0=a1.split(" ");
                QString item;
                QString tipo=m0.at(0);
                if(tipo.contains("Trine")||tipo.contains("Conjunction")||tipo.contains("Opposition")||tipo.contains("Quadrature")){
                    if(vasp!=0){
                        item.append(",");
                    }
                    item.append("\"asp");
                    item.append(QString::number(vasp));
                    item.append("\":{");

                    item.append("\"t\":\"");
                    item.append(tipo);
                    item.append("\",");

                    item.append("\"p\":\"");
                    item.append(m0.at(1));
                    item.append("\"");

                    item.append("}\n");
                    asp.append(item);
                    vasp++;
                }
            }
             asp.append("}\n");




             //qDebug()<<A::describePower(filesBar->currentFiles().at(0)->horoscope().sun, filesBar->currentFiles().at(0)->horoscope());

            //qDebug()<<A::describePlanet(filesBar->currentFiles().at(0)->horoscope().planets.value(i), filesBar->currentFiles().at(0)->horoscope().zodiac);
            //resultado.append(nz.describe(nf->horoscope(), (nf.getZodiac()::Article)articles));

            //qDebug()<<nz.describe(nf->horoscope(), (filesBar->currentFiles().at(0).getZodiac()::Article)articles);


            QString extraData="";
            QFile jsonHades(qApp->arguments().at(16));
            if(jsonHades.open(QIODevice::ReadOnly)){
                extraData.append(jsonHades.readAll());
            }else{
                extraData.append("\"\"");
            }
            QString json;
            json.append("{\n");
            json.append(params);
            json.append(",");
            json.append(psc.toLower());
            json.append(",");
            json.append(asp);
            json.append(",");
            json.append(pc.toLower());
            json.append(",\"jsonHades\":");
            json.append(extraData);
            json.append("}\n");
            //qDebug()<<json;
            QString jsonFileName=QString(qApp->arguments().at(11)).replace("\\", "/");
            qDebug()<<"Saving json file "<<jsonFileName;
            QFile jsonFile(jsonFileName);
            jsonFile.open(QIODevice::WriteOnly);
            jsonFile.write(json.toUtf8());
            jsonFile.close();
        }
        if(qApp->arguments().size()==2){
            qDebug()<<"Abriendo "<<qApp->arguments().at(1)<<" ...";
            QFile docDat(fileName);
            if(docDat.exists()){

                //nf.load(fileName);
                //nf.setName("archivo");
                //nf.save();
                //nf.resumeUpdate();
                QStringList sl0=docDat.fileName().split("/");
                QString fn=sl0.at(sl0.length()-1);
                filesBar->addNewFile();
                filesBar->openFile(fn.replace(".dat", ""));
                //filesBar->openFile(docDat.fileName().split("/").at(docDat.fileName().split("/").length()-1).replace(".dat", ""));
                //filesBar->openFile(fileName);
                //filesBar->files.at(0).
                filesBar->setStyleSheet("color: red;");
                qDebug()<<"Archivo abierto: "<<qApp->arguments().at(1)<<".";
            }else{
                qDebug()<<"No se ha podido abrir el archivo: "<<qApp->arguments().at(1);
            }
        }
    }else{
        if(qApp->applicationFilePath().indexOf("zodiac_server")>0&&qApp->arguments().size()==2){
            QString fn=qApp->arguments().at(1);
            filesBar->addNewFile();
            filesBar->openFile(fn);
            filesBar->setStyleSheet("color: red;");
            this->setWindowTitle(fn);
        }else{
            qDebug()<<"Argumentos insuficientes";
            qDebug()<<"Cantidad de Argumentos: "<<qApp->arguments().length();
            filesBar->setStyleSheet("color: red;");
            filesBar->addNewFile();
        }
    }
}

void MainWindow::capture()
{
    QPixmap pixmap(xCn->geometry().size());
    xCn->render(&pixmap, QPoint(0, 0), QRegion(0,0,xCn->geometry().width(), xCn->geometry().height()));
    pixmap.save(qApp->arguments().at(14));
}

void MainWindow        :: contextMenu         ( QPoint p )
{
    QPoint pos = ((QWidget*)sender())->mapToGlobal(p);
    panelsMenu->exec(pos);
}

void MainWindow        :: addToolBarActions   ( )
{
    toolBar  -> addAction(QIcon("style/file.png"),  tr("New"),  filesBar,    SLOT(addNewFile()));
    toolBar  -> addAction(QIcon("style/save.png"),  tr("Save"), this,        SLOT(saveFile()));
    toolBar  -> addAction(QIcon("style/edit.png"),  tr("Edit"), astroWidget, SLOT(openEditor()));
    //toolBar  -> addAction(QIcon("style/print.png"), tr("Экспорт"));
    
    toolBar  -> actions()[0]->setShortcut(QKeySequence("CTRL+N"));
    toolBar  -> actions()[1]->setShortcut(QKeySequence("CTRL+S"));
    toolBar  -> actions()[2]->setShortcut(QKeySequence("F2"));
    //toolBar  -> actions()[3]->setShortcut(QKeySequence("CTRL+P"));
    
    toolBar  -> actions()[0]->setStatusTip(tr("New data") + "\n Ctrl+N");
    toolBar  -> actions()[1]->setStatusTip(tr("Save data") + "\n Ctrl+S");
    toolBar  -> actions()[2]->setStatusTip(tr("Edit data...") + "\n F2");
    //toolBar  -> actions()[3]->setStatusTip(tr("Печать или экспорт \n Ctrl+P"));
    
    QToolButton* b = new QToolButton;           // panels toggle button
    b -> setText(tr("Panels"));
    b -> setIcon(QIcon("style/panels.png"));
    b -> setToolButtonStyle(toolButtonStyle());
    b -> setMenu(panelsMenu);
    b -> setPopupMode(QToolButton::InstantPopup);
    
    toolBar2 -> addWidget(b);
    toolBar2 -> addAction(QIcon("style/tools.png"),  tr("Options"), this, SLOT(showSettingsEditor()));
    toolBar2 -> addAction(QIcon("style/info.png"),   tr("About"),   this, SLOT(showAbout()));
    //toolBar2 -> addAction(QIcon("style/coffee.png"), tr("Справка"));
    
    QAction* dbToggle = createActionForPanel(databaseDockWidget/*, QIcon("style/database.png")*/);
    dbToggle -> setShortcut(QKeySequence("CTRL+O"));
    dbToggle -> setStatusTip(tr("Toggle database") + "\n Ctrl+O");
    
    createActionForPanel(helpToolBar/*, QIcon("style/help.png")*/);
}

QAction* MainWindow    :: createActionForPanel(QWidget* w)
{
    QAction* a = panelsMenu->addAction(/*icon, */w->windowTitle());
    a->setCheckable(true);
    connect(a, SIGNAL(triggered(bool)),         w, SLOT(setVisible(bool)));
    connect(w, SIGNAL(visibilityChanged(bool)), a, SLOT(setChecked(bool)));
    return a;
}

void MainWindow        :: currentTabChanged()
{
    if (!filesBar->count()) return;
    astroWidget->setFiles(filesBar->currentFiles());
}

AppSettings MainWindow :: defaultSettings     ( )
{
    AppSettings s;
    s << astroWidget->defaultSettings();
    s.setValue ( "Window/Geometry",         0 );
    s.setValue ( "Window/State",            0 );
    s.setValue ( "askToSave",           false );
    return s;
}

AppSettings MainWindow :: currentSettings     ( )
{
    AppSettings s;
    s << astroWidget->currentSettings();
    s.setValue ( "Window/Geometry",      this->saveGeometry() );
    s.setValue ( "Window/State",         this->saveState() );
    s.setValue ( "askToSave",            askToSave );
    return s;
}

void MainWindow        :: applySettings       ( const AppSettings& s )
{
    astroWidget->applySettings(s);
    this -> restoreGeometry   ( s.value ( "Window/Geometry" ).toByteArray() );
    this -> restoreState      ( s.value ( "Window/State" ).toByteArray() );
    askToSave = s.value ( "askToSave" ).toBool();
}

void MainWindow        :: setupSettingsEditor ( AppSettingsEditor* ed )
{
    ed->addControl("askToSave", tr("Ask about unsaved files"));
    astroWidget->setupSettingsEditor(ed);
}

void MainWindow        :: closeEvent          ( QCloseEvent* ev )
{ 
    while (askToSave && filesBar->count() && filesBar->currentFiles().count() &&   // close tabs
           filesBar->currentFiles()[0]->hasUnsavedChanges())
        if (!filesBar->closeTab(filesBar->currentIndex()))
            return ev->ignore();
    
    saveSettings();
    
    QMainWindow::closeEvent(ev);
    QApplication::quit();
}

void MainWindow        :: gotoUrl             ( QString url )
{
    if (url.isEmpty()) url = ((QWidget*)sender())->toolTip();
    QDesktopServices::openUrl(QUrl(url));
}

void MainWindow        :: showAbout           ( )
{
    QDialog* d     = new QDialog(this);
    QLabel* l      = new QLabel;
    QLabel* l2     = new QLabel;
    SlideWidget* s = new SlideWidget;
    QPushButton* b = new QPushButton(tr("Credits"));
    QPushButton* b1 = new QPushButton(tr("Developer's\nblog"));
    QPushButton* b2 = new QPushButton;
    QPushButton* b3 = new QPushButton;
    
    b->setCheckable(true);
    b1->setIconSize(QSize(32,32));
    b2->setIconSize(QSize(32,32));
    b3->setIconSize(QSize(32,32));
    b1->setIcon(QIcon("style/wp.png"));
    b2->setIcon(QIcon("style/github.png"));
    b3->setIcon(QIcon("style/sourceforge.png"));
    b1->setToolTip("http://www.syslog.pro/tag/zodiac");
    b2->setToolTip("http://github.com/atten/zodiac");
    b3->setToolTip("http://sourceforge.net/projects/zodiac-app/");
    b1->setCursor(Qt::PointingHandCursor);
    b2->setCursor(Qt::PointingHandCursor);
    b3->setCursor(Qt::PointingHandCursor);
    d->setObjectName("about");
    l->setWordWrap(true);
    l->setTextInteractionFlags(Qt::LinksAccessibleByMouse|
                               Qt::TextSelectableByMouse);
    l2->setWordWrap(true);
    l2->setTextInteractionFlags(Qt::LinksAccessibleByMouse|
                                Qt::TextSelectableByMouse);
    s->addSlide(l);
    s->addSlide(l2);
    s->setTransitionEffect(SlideWidget::Transition_Overlay);
    
    QHBoxLayout* h = new QHBoxLayout;
    h->setMargin(10);
    h->addWidget(b);
    h->addStretch();
    h->addWidget(b1);
    h->addWidget(b2);
    h->addWidget(b3);
    
    QVBoxLayout* v = new QVBoxLayout(d);
    v->setMargin(0);
    v->addWidget(s);
    v->addLayout(h);
    
    l->setText("<center><b><big>" + QApplication::applicationVersion() + "</big></b>"
                                                                         "<p>" + tr("Astrological software for personal use.") + "</p>"
               //"<p><a style='color:yellow' href=\"http://www.syslog.pro/tag/zodiac\">Watch developer's blog</a>"
               //" | <a style='color:yellow' href=\"https://github.com/atten/zodiac\"><img src=\"style/github.png\">Follow on GitHub</a></p>"
               "<p>Copyright (C) 2012-2014 Artem Vasilev<br>"
               "<a style='color:white' href=\"mailto:atten@syslog.pro\">atten@syslog.pro</a></p><br>" +
               tr("This application is provided AS IS and distributed in the hope that it will be useful,"
                  " but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY"
                  " or FITNESS FOR A PARTICULAR PURPOSE.") + "</center>");
    
    
    l2->setText("<p><b>Swiss Ephemerides library</b><br>"
                "Copyright (C) 1997 - 2008 Astrodienst AG, Switzerland.  All rights reserved.<br>"
                "<a style='color:white' href=\"ftp://www.astro.ch/pub/swisseph/LICENSE\">ftp://www.astro.ch/pub/swisseph/LICENSE</a></p>"
                "<p><b>Primo Icon Set</b> by Webdesigner Depot<br>"
                "<a style='color:white' href=\"https://www.iconfinder.com/iconsets/Primo_Icons#readme\">www.iconfinder.com/iconsets/Primo_Icons#readme</a></p>"
                "<p><b>Almagest True Type Font</b></p>"
                "<p>Additional thanks to authors of <b>\"SymSolon\"</b> project<br>"
                "<a style='color:white' href=\"http://sf.net/projects/symsolon\">sf.net/projects/symsolon</a></p>");
    
    connect(l,  SIGNAL(linkActivated(QString)), this, SLOT(gotoUrl(QString)));
    connect(l2, SIGNAL(linkActivated(QString)), this, SLOT(gotoUrl(QString)));
    connect(b1, SIGNAL(clicked()),              this, SLOT(gotoUrl()));
    connect(b2, SIGNAL(clicked()),              this, SLOT(gotoUrl()));
    connect(b3, SIGNAL(clicked()),              this, SLOT(gotoUrl()));
    connect(b,  SIGNAL(clicked()), s, SLOT(nextSlide()));
    d->exec();
}
