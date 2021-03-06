#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabBar>
#include <QDockWidget>
#include <QTimer>
#include <Astroprocessor/Gui>
#include "help.h"
#include "slidewidget.h"
#include <Astroprocessor/Output>
#include <Astroprocessor/Calc>


class QListWidget;
class QLineEdit;
class QActionGroup;
class AstroFileEditor;
class GeoSearchWidget;
class QComboBox;

/* =========================== ASTRO FILE INFO ====================================== */

class AstroFileInfo : public AstroFileHandler
{
    Q_OBJECT

    private:
        int currentIndex;
        QPushButton* edit;
        QLabel* shadow;
        bool showAge;

        AstroFile* currentFile()             { return file(currentIndex); }
        void setText(const QString& str);
        void refresh();

    protected:
        void filesUpdated(MembersList members);  // AstroFileHandler implementations

    signals:
        void clicked();

    public:
        AstroFileInfo (QWidget *parent = 0);
        void setCurrentIndex(int i)          { currentIndex = i; }

        AppSettings defaultSettings ();
        AppSettings currentSettings ();
        void applySettings       ( const AppSettings& );
        void setupSettingsEditor ( AppSettingsEditor* );
};


/* =========================== ASTRO WIDGET ========================================= */

class AstroWidget : public QWidget
{
    Q_OBJECT

    private:
        AstroFileEditor*  editor;
        GeoSearchWidget*  geoWdg;
        QToolBar*         toolBar;
        QActionGroup*     actionGroup;
        SlideWidget*      slides;
        AstroFileInfo*    fileView, *fileView2nd;
        QComboBox*        zodiacSelector;
        QComboBox*        hsystemSelector;
        QComboBox*        aspectsSelector;
        QList<QComboBox*> horoscopeControls;
        QList<AstroFileHandler*> handlers;
        QList<AstroFileHandler*> dockHandlers;
        QList<QDockWidget*> docks;

        void setupFile (AstroFile* file, bool suspendUpdate = false);
        AstroFileList files()                          { return fileView->files(); }
        QString vectorToString (const QVector3D& v);
        QVector3D vectorFromString (const QString& str);

        void attachHandler(AstroFileHandler* w);
        void addSlide(AstroFileHandler* w, const QIcon& icon, QString title);
        void addDockWidget(AstroFileHandler* w, QString title, bool scrollable, QString objectName = "");
        void addHoroscopeControls();
        void switchToSingleAspectSet();
        void switchToSynastryAspectSet();

    private slots:
        void applyGeoSettings(AppSettings&);
        void toolBarActionClicked();
        void currentSlideChanged();
        void horoscopeControlChanged();
        void destroyingFile();
        void destroyEditor();

    public slots:
        void openEditor();

    signals:
        void helpRequested(QString tag);
        void appendFileRequested();
        void swapFilesRequested(int,int);

    public:
        AstroWidget(QWidget *parent = 0);
        QToolBar* getToolBar()      { return toolBar; }
        const QList<QComboBox*>& getHoroscopeControls() { return horoscopeControls; }
        const QList<QDockWidget*>& getDockPanels()      { return docks; }

        void setFiles (const AstroFileList& files);

        AppSettings defaultSettings ();
        AppSettings currentSettings ();
        void applySettings       ( const AppSettings& );
        void setupSettingsEditor ( AppSettingsEditor* );
};


/* =========================== ASTRO FILE DATABASE ================================== */

class AstroDatabase : public QFrame
{
    Q_OBJECT

    private:
        QListWidget* fileList;
        QLineEdit* search;

    protected:
        virtual void keyPressEvent(QKeyEvent*);
        virtual bool eventFilter(QObject *, QEvent *);

    private slots:
        void showContextMenu(QPoint);
        void openSelected();
        void openSelectedInNewTab();
        void openSelectedAsSecond();
        void deleteSelected();
        void searchFilter(QString);

    public slots:
        void updateList();

    signals:
        void fileRemoved(QString);
        void openFile(QString);
        void openFileInNewTab(QString);
        void openFileAsSecond(QString);

    public:
        AstroDatabase(QWidget *parent = 0);
};


/* =========================== FILES BAR ============================================ */

class FilesBar : public QTabBar
{
    Q_OBJECT

    private:
        bool askToSave;
        QList<AstroFileList> files;

        void updateTab(int index);
        int getTabIndex(AstroFile* f, bool seekFirstFileOnly = false);
        int getTabIndex(QString name, bool seekFirstFileOnly = false);

    private slots:
        void swapTabs(int,int);
        void fileUpdated(AstroFile::Members);
        void fileDestroyed();

    public slots:
        void addNewFile() { addFile(new AstroFile); }
        void swapCurrentFiles(int,int);
        void openFile(QString name);
        void openFileInNewTab(QString name);
        void openFileAsSecond(QString name = "");
        void nextTab()            { setCurrentIndex((currentIndex() + 1) % count()); }
        bool closeTab(int);

    public:
        FilesBar(QWidget *parent = 0);

        void addFile(AstroFile* file);
        void setAskToSave(bool b) { askToSave = b; }
        const AstroFileList& currentFiles()  { if (count() && currentIndex() < count()) return files[currentIndex()]; }
};


/* =========================== MAIN WINDOW ========================================== */

class MainWindow : public QMainWindow, public Customizable
{
    Q_OBJECT

    private:
        bool askToSave;

        FilesBar*      filesBar;
        AstroWidget*   astroWidget;
        AstroDatabase* astroDatabase;
        QDockWidget*   databaseDockWidget;
        QToolBar       *toolBar, *toolBar2, *helpToolBar;
        QMenu*         panelsMenu;

        //Zodiac Server
        QTimer *timerQuit;
        QTimer *timerCapture;

        void addToolBarActions();
        QAction* createActionForPanel(QWidget* w/*, const QIcon &icon*/);

    private slots:
        void saveFile()             { filesBar->currentFiles()[0]->save(); astroDatabase->updateList(); }
        void currentTabChanged();
        void showSettingsEditor()   { openSettingsEditor(); }
        void showAbout();
        void gotoUrl(QString url = "");
        void contextMenu(QPoint);

        //Zodiac Server
        void capture();

    protected:
        AppSettings defaultSettings ();      // 'Customizable' class implementations
        AppSettings currentSettings ();
        void applySettings        ( const AppSettings& );
        void setupSettingsEditor  ( AppSettingsEditor* );

        void closeEvent ( QCloseEvent* );

    public:
        MainWindow(QWidget *parent = 0);

        //Zodiac Server
        QWidget *xCn;

};

#endif // MAINWINDOW_H
