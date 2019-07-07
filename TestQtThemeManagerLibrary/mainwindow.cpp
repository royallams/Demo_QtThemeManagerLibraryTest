#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->plainTextEdit->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->pushButton->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->checkBox->setContextMenuPolicy(Qt::CustomContextMenu);

    QString app_path = QCoreApplication::applicationDirPath();
    QString path = app_path+"/StyleSheetsExamples/Default.qss";
    test_style_mgr_= new QtThemeManager(path,kDefaultPath);
    QObject::connect(test_style_mgr_,&QtThemeManager::styleSheetUpdated,this,&MainWindow::OnStyleSheetUpdated);
    QObject::connect(test_style_mgr_,&QtThemeManager::notify,this,&MainWindow::OnNotify);

    test_style_mgr_->Update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_customContextMenuRequested(const QPoint &pos)
{
    QMenu contextMenu(tr("NAME_CONTEXT_MENU_TITLE"), this);
    QAction action("NAME_CONTEXT_MENU_EDIT_THEME", this);
    connect(&action, SIGNAL(triggered()), this, SLOT(OnPushButtonEdit()));
    contextMenu.addAction(&action);
    contextMenu.exec(mapToGlobal(pos));
}

void MainWindow::on_checkBox_customContextMenuRequested(const QPoint &pos)
{
    QMenu contextMenu(tr("NAME_CONTEXT_MENU_TITLE"), this);
    QAction action("NAME_CONTEXT_MENU_EDIT_THEME", this);
    connect(&action, SIGNAL(triggered()), this, SLOT(OnCheckBoxEdit()));
    contextMenu.addAction(&action);
    contextMenu.exec(mapToGlobal(pos));
}

void MainWindow::on_plainTextEdit_customContextMenuRequested(const QPoint &pos)
{
    QMenu contextMenu(tr("NAME_CONTEXT_MENU_TITLE"), this);
    QAction action("NAME_CONTEXT_MENU_EDIT_THEME", this);
    connect(&action, SIGNAL(triggered()), this, SLOT(OnPlainTextEditEdit()));
    contextMenu.addAction(&action);
    contextMenu.exec(mapToGlobal(pos));
}

void MainWindow::on_MainWindow_customContextMenuRequested(const QPoint &pos)
{
    QMenu contextMenu(tr("NAME_CONTEXT_MENU_TITLE"), this);
    QAction action("NAME_CONTEXT_MENU_EDIT_THEME", this);
    connect(&action, SIGNAL(triggered()), this, SLOT(OnWidgetEdit()));
    contextMenu.addAction(&action);
    contextMenu.exec(mapToGlobal(pos));
}

void MainWindow::OnPushButtonEdit()
{
    QString object_name =ui->pushButton->objectName();
    test_style_mgr_->InvokeEditOption(kPushButton,object_name);
}

void MainWindow::OnCheckBoxEdit()
{
    QString object_name =ui->checkBox->objectName();
    test_style_mgr_->InvokeEditOption(kCheckBox,object_name);
}

void MainWindow::OnPlainTextEditEdit()
{
    QString object_name =ui->plainTextEdit->objectName();
    test_style_mgr_->InvokeEditOption(kPlainTextEdit,object_name);

}

void MainWindow::OnWidgetEdit()
{
    QString object_name =ui->centralWidget->objectName();
    test_style_mgr_->InvokeEditOption(kWidget,object_name);
}

void MainWindow::OnStyleSheetUpdated(QString &ss)
{
    this->setStyleSheet(ss);
}

void MainWindow::OnNotify(QString &msg)
{
    ui->plainTextEdit->appendPlainText(msg);
}
