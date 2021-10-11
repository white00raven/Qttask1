#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <dialog.h>
#include <QMainWindow>
#include <QPixmap>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    protected :
    void resizeEvent(QResizeEvent *pEvent);
    void paintEvent(QPaintEvent *pEvent);
    QPixmap pix;
    double R,r,d,o,delo;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void sledit(bool checked=false);
};
#endif // MAINWINDOW_H
