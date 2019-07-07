#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QtThemeManager.h"
#include "globaldefines.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_customContextMenuRequested(const QPoint &pos);

    void on_checkBox_customContextMenuRequested(const QPoint &pos);

    void on_plainTextEdit_customContextMenuRequested(const QPoint &pos);

    void on_MainWindow_customContextMenuRequested(const QPoint &pos);

public slots:
    void OnPushButtonEdit();
    void OnCheckBoxEdit();
    void OnPlainTextEditEdit();
    void OnWidgetEdit();
    void OnStyleSheetUpdated(QString &ss);
    void OnNotify(QString &msg);
private:
    Ui::MainWindow *ui;
    QtThemeManager *test_style_mgr_;
};

#endif // MAINWINDOW_H
