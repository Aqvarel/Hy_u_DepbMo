#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "appcontext.h"


extern "C" {
    #include "entrypoint.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    struct AppContext context;

    void getData();
    void errors();
    void onConvertClicked();
    void showAnswer();
    void update();
};
#endif // MAINWINDOW_H
