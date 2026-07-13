

#include <QtGui>

#include "mainwindow.h"
#include <QListWidget>
#include <QTreeWidget>
#include <QStackedWidget>
#include <QPushButton>
#include <QLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QAction>
#include <QMenuBar>
#include <QSpacerItem>
#include  "pages.h"
#include "commondata.h"
#include <QGraphicsEffect>

MainWindow::MainWindow(QWidget *parent)
{

    cData=new commonData();

    cData->langCombo = new QComboBox;

    cData->langCombo->addItem(("English"));
    cData->langCombo->addItem(("Russian"));

    
    SettingsTab *settingstab=new SettingsTab(0,cData);
    
    QGroupBox* langGroup = new QGroupBox(tr(""));

    langGroup->setContentsMargins(0,0,0,0);
    QLabel* langLabelpic = new QLabel("");
    langLabelpic->setPixmap(QPixmap(":/images/lang_verysmall.png"));

    QLabel* langLabel = new QLabel(tr("UI Language:"));
    langLabel->setStyleSheet("color: #666666");
    QFont font = langLabel->font();
    font.setBold(true);
    font.setPointSize(10);
    langLabel->setFont(font);



    QHBoxLayout *langLayout = new QHBoxLayout;

    langLayout->addWidget(langLabelpic);
    langLayout->addWidget(langLabel);
    langLayout->addWidget(cData->langCombo);


    langLayout->setContentsMargins(10, 10, 10, 10);
    langGroup->setLayout(langLayout);
    QWidget *widget=new QWidget;
    widget->setObjectName("the_central_widget");
    QWidget *widgetup=new QWidget;

    QVBoxLayout *mainLayout = new QVBoxLayout;
    QVBoxLayout *verticalLayout = new QVBoxLayout;
    QHBoxLayout *horizontalLayout = new QHBoxLayout;

    mainLayout->setContentsMargins( cData->marg, cData->marg, cData->marg, cData->marg );
    verticalLayout->setContentsMargins( cData->marg, cData->marg, cData->marg, cData->marg );
    horizontalLayout->setContentsMargins( cData->marg, cData->marg, cData->marg, cData->marg );

    NavButton *primaryLoc=new NavButton("Primary location");primaryLoc->setObjectName("addnew_Button");
    NavButton *exit=new NavButton("Exit");exit->setObjectName("exitnew_Button");exit->setFixedWidth(100);
    connect(exit, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
    widgetup->setObjectName("top_large_navbar");
    widgetup->setLayout(horizontalLayout);
    widgetup->setMaximumHeight(50);
    horizontalLayout->SetMinimumSize;
    horizontalLayout->addWidget(primaryLoc);
    horizontalLayout->addStretch(20);
    horizontalLayout->addWidget(langGroup);
    horizontalLayout->addWidget(exit);
    widget->setLayout(verticalLayout);
    verticalLayout->addWidget(widgetup);
    verticalLayout->addWidget(settingstab);
    mainLayout->setSizeConstraint(QLayout::SetNoConstraint);
    mainLayout->addWidget(widget);
    setLayout(mainLayout);
    setWindowTitle(tr("Form Generator UI"));
    createActions();
    createMenus();


    setCentralWidget(widget);
}


MainWindow::~MainWindow()
{
}


void MainWindow::createActions()
{
    newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));

    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));

    saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document to disk"));

    printAct = new QAction(tr("&Print..."), this);
    printAct->setShortcuts(QKeySequence::Print);
    printAct->setStatusTip(tr("Print the document"));

    exitAct = new QAction(tr("&Exit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, &QAction::triggered, this, &QWidget::close);


}

void MainWindow::createMenus()
{


    


}
ValidateTab::ValidateTab(QWidget *parent, commonData *Data)
    : QWidget(parent)
{
    cData=Data;
}
SettingsTab::SettingsTab(QWidget *parent,commonData *Data)
    : QWidget(parent)
{

    cData=Data;

    contentsWidget = new QListWidget;
    contentsWidget->setViewMode(QListView::ListMode);//QListView::IconMode);
    contentsWidget->setIconSize(QSize(96/2, 84/2));
    contentsWidget->setMovement(QListView::Static);
    contentsWidget->setMaximumWidth(160);
    contentsWidget->setMinimumWidth(160);
    contentsWidget->setSpacing(0);

    pagesWidget = new QStackedWidget;

    pagesWidget->setObjectName("pages_widget");
    genpage =new GenerateFormsPage(this,cData);
    tablepage= new EditTablesPage(this,cData);
    QWidget *empty=new QWidget;


    pagesWidget->addWidget(tablepage);
    pagesWidget->addWidget(genpage);
    pagesWidget->addWidget(empty);
    pagesWidget->setStyleSheet("background-color: #ffffff");
    genpage->setStyleSheet("background-color: #ffffff;border-color: grey;    border-width: 1px; border-style: solid; border-radius: 3px;");
    tablepage->setStyleSheet("background-color: #ffffff");
    genpage->update_view_sing();


    createIcons();
    contentsWidget->setCurrentRow(0);
    edittab= new NavButton(tr("Edit Database v"));edittab->setObjectName("addButton");
    edittab->setIcon(QIcon(":/images/edit_white.png"));


    edittab->setFixedWidth(180);
    edittab->activate();
    genf= new NavButton(tr("Generate Forms"));genf->setObjectName("addButton");
    genf->setIcon(QIcon(":/images/table-edit-icon.png"));
    genf->setFixedWidth(180);
    genf->setMinimumHeight(35);
    genf->deactivate();
    file=new NavButton(tr("File >"));file->setObjectName("menuButton");
    loadForm=new NavButton(tr("Load Forms"));loadForm->setObjectName("addButton");
    formList=new NavButton(tr("Form List"));formList->setObjectName("addButton");

    genReports=new NavButton(tr("Generate Reports"));genReports->setObjectName("menuButton");
    Logs=new NavButton(tr("Logs >"));Logs->setObjectName("menuButton");
    ActLog=new NavButton(tr("Act log"));ActLog->setObjectName("addButton");
    AudLog=new NavButton(tr("Aud log"));AudLog->setObjectName("addButton");
    Settings=new NavButton(tr("Settings >"));Settings->setObjectName("menuButton");
    file->setFixedWidth(180);
    loadForm->setFixedWidth(180);
    formList->setFixedWidth(180);
    genReports->setFixedWidth(180);
    Logs->setFixedWidth(180);
    ActLog->setFixedWidth(180);
    AudLog->setFixedWidth(180);
    Settings->setFixedWidth(180);
    QSize a;
    a.setHeight(15);
    a.setWidth(15);
    edittab->setIconSize(a);
    genf->setIconSize(a);

    cData->tab1= new NavButton("- Form type and answer");cData->tab1->setObjectName("menuButton");

    cData->edit1= new NavButton("Edit"); cData->edit1->setObjectName("editnew_Button");cData->edit1->setFixedWidth(150);
    cData->tab1->setFixedWidth(180);
    cData->add1= new NavButton("Add new"); cData->add1->setObjectName("addnew_Button");cData->add1->setFixedWidth(150);
    cData->rem1= new NavButton("Remove"); cData->rem1->setObjectName("removenew_Button");cData->rem1->setFixedWidth(150);
    cData->tab2= new NavButton("- Location and area"); cData->tab2->setObjectName("menuButton");
    cData->tab2->setFixedWidth(180);
    cData->edit2= new NavButton("Edit"); cData->edit2->setObjectName("editnew_Button");cData->edit2->setFixedWidth(150);
    cData->rem_area2= new NavButton("Remove area"); cData->rem_area2->setObjectName("removenew_Button");cData->rem_area2->setFixedWidth(150);
    cData->rem_loc2= new NavButton("Remove location"); cData->rem_loc2->setObjectName("removenew_Button");cData->rem_loc2->setFixedWidth(150);
    cData->add_area2= new NavButton("Add new area"); cData->add_area2->setObjectName("addnew_Button");cData->add_area2->setFixedWidth(150);
    cData->add_loc2= new NavButton("Add new location"); cData->add_loc2->setObjectName("addnew_Button");cData->add_loc2->setFixedWidth(150);

    cData->genff= new NavButton("Generate form"); cData->genff->setObjectName("addnew_Button");cData->genff->setFixedWidth(150);
    cData->printforms= new NavButton("Print form"); cData->printforms->setObjectName("editnew_Button");cData->printforms->setFixedWidth(150);
    cData->filterButton1->setObjectName("filternew_Button");
    cData->filterButton4->setObjectName("filternew_Button");

    pagesWidget->setCurrentIndex(2);
    QGridLayout *gridLayout = new QGridLayout;

    QVBoxLayout *verticalLayout = new QVBoxLayout;
    QHBoxLayout *horizontalLayout = new QHBoxLayout;


    gridLayout->setContentsMargins( cData->marg, cData->marg, cData->marg, cData->marg );
    verticalLayout->setContentsMargins( cData->marg, cData->marg, cData->marg, cData->marg );
    horizontalLayout->setContentsMargins( 10, 10, 10, 10 );
    pagesWidget->setContentsMargins( 0, 0, 0, 0 );
    QWidget * widUp= new QWidget;

    QWidget * left_navbar= new QWidget(this);
    verticalLayout->addWidget(file);
    verticalLayout->addWidget(loadForm);
    verticalLayout->addWidget(formList);
    verticalLayout->addWidget(genReports);
    verticalLayout->addWidget(Logs);
    verticalLayout->addWidget(ActLog);
    verticalLayout->addWidget(AudLog);
    verticalLayout->addWidget(Settings);





    verticalLayout->addWidget(genf);
    verticalLayout->addWidget(edittab);
    verticalLayout->addWidget(cData->tab1);
    
    verticalLayout->addWidget(cData->tab2);
    



    left_navbar->setLayout(verticalLayout);
    left_navbar->setObjectName("left_navbar");

    horizontalLayout->addWidget(cData->add1);
    horizontalLayout->addWidget(cData->edit1);
    horizontalLayout->addWidget(cData->rem1);

    horizontalLayout->addWidget(cData->add_area2);
    horizontalLayout->addWidget(cData->add_loc2);
    horizontalLayout->addWidget(cData->edit2);
    horizontalLayout->addWidget(cData->rem_area2);
    horizontalLayout->addWidget(cData->rem_loc2);
    horizontalLayout->addWidget(cData->genff);
    horizontalLayout->addWidget(cData->printforms);
    horizontalLayout->addWidget(cData->filterCombo1);
    horizontalLayout->addWidget(cData->filterEdit1);
    horizontalLayout->addWidget(cData->filterButton1);
    horizontalLayout->addWidget(cData->filterCombo4);
    horizontalLayout->addWidget(cData->filterEdit4);
    horizontalLayout->addWidget(cData->filterButton4);//data->filterButton1->setObjectName("filterButton");
    horizontalLayout->addStretch(20);
    loadForm->setVisible(false);
    formList->setVisible(false);
    ActLog->setVisible(false);
    AudLog->setVisible(false);
    edittab->setVisible(false);
    genf->setVisible(false);
    cData->tab1->setVisible(false);
    cData->tab2->setVisible(false);
    cData-> edit1->setVisible(false);
    cData->add1->setVisible(false);
    cData->rem1->setVisible(false);
    cData->edit2->setVisible(false);
    cData->rem_area2->setVisible(false);
    cData->rem_loc2->setVisible(false);
    cData->add_area2->setVisible(false);
    cData->add_loc2->setVisible(false);
    cData->genff->setVisible(false);
    cData->printforms->setVisible(false);
    cData->filterCombo1->setVisible(false);
    cData->filterEdit1->setVisible(false);
    cData->filterButton1->setVisible(false);
    cData->filterCombo4->setVisible(false);
    cData->filterEdit4->setVisible(false);
    cData->filterButton4->setVisible(false);


    verticalLayout->addStretch();
    widUp->setLayout(horizontalLayout);
    widUp->setObjectName("top_small_navbar");
    widUp->setMaximumHeight(50);
    widUp->setMaximumWidth(5000);

    gridLayout->addWidget(left_navbar,0,0,2,1);

    gridLayout->setContentsMargins( cData->marg, cData->marg, cData->marg, cData->marg );
    gridLayout->addWidget(widUp,0,1,1,1);
    gridLayout->addWidget(pagesWidget,1,1,1,1);

    
    setLayout(gridLayout);
    connect(file,
            SIGNAL(clicked(bool)),
            this, SLOT(file_set()));
    connect(genReports,
            SIGNAL(clicked(bool)),
            this, SLOT(genReports_set()));
    connect(Logs,
            SIGNAL(clicked(bool)),
            this, SLOT(Logs_set()));
    connect(ActLog,
            SIGNAL(clicked(bool)),
            this, SLOT(ActLog_set()));
    connect(AudLog,
            SIGNAL(clicked(bool)),
            this, SLOT(AudLog_set()));
    connect(loadForm,
            SIGNAL(clicked(bool)),
            this, SLOT(loadForm_set()));
    connect(formList,
            SIGNAL(clicked(bool)),
            this, SLOT(formList_set()));

    connect(Settings,
            SIGNAL(clicked(bool)),
            this, SLOT(Settings_set()));
    connect(edittab,
            SIGNAL(clicked(bool)),
            this, SLOT(changePage1()));
    connect(genf,
            SIGNAL(clicked(bool)),
            this, SLOT(changePage2()));
    connect(cData->tab1,
            SIGNAL(clicked(bool)),
            this, SLOT(changeTab1()));
    connect(cData->tab2,
            SIGNAL(clicked(bool)),
            this, SLOT(changeTab2()));
    connect(cData->add1, SIGNAL(clicked()), tablepage, SLOT(open_win1()));
    connect(cData->edit1, SIGNAL(clicked()),  tablepage, SLOT(open_win11()));
    connect(cData->rem1, SIGNAL(clicked()),  tablepage, SLOT(remove_selected1()));
    connect(cData->add_area2, SIGNAL(clicked()), tablepage, SLOT(open_win3()));
    connect(cData->rem_area2, SIGNAL(clicked()),  tablepage, SLOT(remove_selected3()));
    connect(cData->add_loc2, SIGNAL(clicked()), tablepage, SLOT(open_win4()));
    connect(cData->edit2, SIGNAL(clicked()), tablepage, SLOT(open_win44()));
    connect(cData->rem_loc2, SIGNAL(clicked()),  tablepage, SLOT(remove_selected4()));
    connect(cData->genff, SIGNAL(clicked()),genpage , SLOT(gen_forms()));
    connect(cData->printforms, SIGNAL(clicked()), genpage, SLOT(print_forms()));


}

void SettingsTab::createIcons()
{

    QFont font;
    font.setBold(true);


    
    


    

    



    

}

void SettingsTab::changePage(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (!current)
        current = previous;

    pagesWidget->setCurrentIndex(contentsWidget->row(current));


}
void SettingsTab::changePage1()
{
    genf->deactivate();




    if (cData->tab1->isVisible()==false)
    {
        pagesWidget->setCurrentIndex(0);
        cData->tableStack->setCurrentIndex(0);
        setInvisible1();
        cData->tab1->activate2();
        cData->tab1->setVisible(true);
        cData->tab2->setVisible(true);
        cData-> edit1->setVisible(true);
        cData->add1->setVisible(true);
        cData->rem1->setVisible(true);
        cData->edit2->setVisible(false);
        cData->rem_area2->setVisible(false);
        cData->rem_loc2->setVisible(false);
        cData->add_area2->setVisible(false);
        cData->add_loc2->setVisible(false);
        cData->filterCombo1->setVisible(true);
        cData->filterEdit1->setVisible(true);
        cData->filterButton1->setVisible(true);
        cData->filterCombo4->setVisible(false);
        cData->filterEdit4->setVisible(false);
        cData->filterButton4->setVisible(false);

        edittab->setText(tr("Edit Database v"));


    }else
    {
        pagesWidget->setCurrentIndex(2);
        setInvisible1();
        cData->tab1->setVisible(false);
        cData->tab2->setVisible(false);
        edittab->setText(tr("Edit Database >"));
    }
    edittab->activate1();



}
void SettingsTab::changePage2()
{
    setInvisible1();
    edittab->deactivate();
    pagesWidget->setCurrentIndex(1);
    genf->activate1();

    edittab->setVisible(true);
    genf->setVisible(true);
    cData->genff->setVisible(true);
    cData->printforms->setVisible(true);
    cData-> edit1->setVisible(false);
    cData->add1->setVisible(false);
    cData->rem1->setVisible(false);
    cData->edit2->setVisible(false);
    cData->rem_area2->setVisible(false);
    cData->rem_loc2->setVisible(false);
    cData->add_area2->setVisible(false);
    cData->add_loc2->setVisible(false);


}
void SettingsTab::changeTab1()
{

    cData->tab1->activate2();
    cData->tab2->deactivate();
    pagesWidget->setCurrentIndex(0);
    cData->tableStack->setCurrentIndex(0);
    cData-> edit1->setVisible(true);
    cData->add1->setVisible(true);
    cData->rem1->setVisible(true);
    cData->edit2->setVisible(false);
    cData->rem_area2->setVisible(false);
    cData->rem_loc2->setVisible(false);
    cData->add_area2->setVisible(false);
    cData->add_loc2->setVisible(false);
    cData->genff->setVisible(false);
    cData->printforms->setVisible(false);
    cData->filterCombo1->setVisible(true);
    cData->filterEdit1->setVisible(true);
    cData->filterButton1->setVisible(true);
    cData->filterCombo4->setVisible(false);
    cData->filterEdit4->setVisible(false);
    cData->filterButton4->setVisible(false);


}
void SettingsTab::changeTab2()
{

    cData->tab1->deactivate();
    cData->tab2->activate2();
    pagesWidget->setCurrentIndex(0);
    cData->tableStack->setCurrentIndex(1);
    cData-> edit1->setVisible(false);
    cData->add1->setVisible(false);
    cData->rem1->setVisible(false);
    cData->edit2->setVisible(true);
    cData->rem_area2->setVisible(true);
    cData->rem_loc2->setVisible(true);
    cData->add_area2->setVisible(true);
    cData->add_loc2->setVisible(true);
    cData->genff->setVisible(false);
    cData->printforms->setVisible(false);
    cData->filterCombo1->setVisible(false);
    cData->filterEdit1->setVisible(false);
    cData->filterButton1->setVisible(false);
    cData->filterCombo4->setVisible(true);
    cData->filterEdit4->setVisible(true);
    cData->filterButton4->setVisible(true);

}
void SettingsTab::file_set()
{

    pagesWidget->setCurrentIndex(2);

    if (loadForm->isVisible()==false)
    {
        setInvisible();
        loadForm->setVisible(true);
        formList->setVisible(true);
        file->setText(tr("File v"));


    }else
    {
        setInvisible();

        file->setText(tr("File >"));
        file->deactivate();
    }
    file->activate();

}
void SettingsTab::loadForm_set()
{
    loadForm->activate1();
    formList->deactivate();
}
void SettingsTab::formList_set()
{
    formList->activate1();
    loadForm->deactivate();
}
void SettingsTab::genReports_set()
{
    pagesWidget->setCurrentIndex(2);
    setInvisible();
    genReports->activate();

}
void SettingsTab::Logs_set()
{
    pagesWidget->setCurrentIndex(2);
    if (ActLog->isVisible()==false)
    {
        setInvisible();
        ActLog->setVisible(true);
        AudLog->setVisible(true);
        Logs->setText(tr("Logs v"));


    }else
    {
        setInvisible();

        Logs->setText(tr("Logs >"));
        Logs->deactivate();
    }
    Logs->activate();
}
void SettingsTab::ActLog_set()
{
    ActLog->activate1();
    AudLog->deactivate();
}
void SettingsTab::AudLog_set()
{
    AudLog->activate1();
    ActLog->deactivate();
}
void SettingsTab::Settings_set()
{
    pagesWidget->setCurrentIndex(2);
    if (edittab->isVisible()==false)
    {
        setInvisible();
        edittab->setVisible(true);
        genf->setVisible(true);
        Settings->setText(tr("Settings v"));


    }else
    {
        setInvisible();

        Settings->setText(tr("Settings >"));
        Settings->deactivate();
    }
    Settings->activate();
}
void SettingsTab::setInvisible()
{


    loadForm->setVisible(false);
    formList->setVisible(false);
    ActLog->setVisible(false);
    AudLog->setVisible(false);
    edittab->setVisible(false);
    genf->setVisible(false);
    cData->tab1->setVisible(false);
    cData->tab2->setVisible(false);
    cData-> edit1->setVisible(false);
    cData->add1->setVisible(false);
    cData->rem1->setVisible(false);
    cData->edit2->setVisible(false);
    cData->rem_area2->setVisible(false);
    cData->rem_loc2->setVisible(false);
    cData->add_area2->setVisible(false);
    cData->add_loc2->setVisible(false);
    cData->genff->setVisible(false);
    cData->printforms->setVisible(false);
    cData->filterCombo1->setVisible(false);
    cData->filterEdit1->setVisible(false);
    cData->filterButton1->setVisible(false);
    cData->filterCombo4->setVisible(false);
    cData->filterEdit4->setVisible(false);
    cData->filterButton4->setVisible(false);
    edittab->setText("Edit Database >");

    file->setText("File >");

    Logs->setText("Logs >");
    edittab->deactivate();

    genf->deactivate();
    file->deactivate();
    Logs->deactivate();
    Settings->deactivate();
    genReports->deactivate();
    cData->tab1->deactivate();
    cData->tab2->deactivate();
    formList->deactivate();
    loadForm->deactivate();
    AudLog->deactivate();
    ActLog->deactivate();

}
void SettingsTab::setInvisible1()
{


    loadForm->setVisible(false);
    formList->setVisible(false);
    ActLog->setVisible(false);
    AudLog->setVisible(false);
    cData->tab1->setVisible(false);
    cData->tab2->setVisible(false);
    cData-> edit1->setVisible(false);
    cData->add1->setVisible(false);
    cData->rem1->setVisible(false);
    cData->edit2->setVisible(false);
    cData->rem_area2->setVisible(false);
    cData->rem_loc2->setVisible(false);
    cData->add_area2->setVisible(false);
    cData->add_loc2->setVisible(false);
    cData->genff->setVisible(false);
    cData->printforms->setVisible(false);
    cData->filterCombo1->setVisible(false);
    cData->filterEdit1->setVisible(false);
    cData->filterButton1->setVisible(false);
    cData->filterCombo4->setVisible(false);
    cData->filterEdit4->setVisible(false);
    cData->filterButton4->setVisible(false);
    edittab->setText("Edit Database >");

    file->setText("File >");

    Logs->setText("Logs >");
    edittab->deactivate();
    genf->deactivate();
    file->deactivate();
    Logs->deactivate();
    genReports->deactivate();
    cData->tab1->deactivate();
    cData->tab2->deactivate();

}


