#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QApplication>
#include <QAction>
#include<QPixmap>
#include<QWidget>
#include <QResizeEvent>
#include <QPaintEvent>
#include <QPainter>
#include <cmath>
void MainWindow::sledit(bool checked)
{
    dialog*dial=new dialog();
    if(dial->exec()==QDialog::Accepted)
    {

        R=dial->R();
        r=dial->r();
        if(R<r)
        {
            double temp =R;
            R=r;
            r=temp;
        }
        d=dial->d();
        o=dial->o();
        delo=dial->delo();
        pix=QPixmap(this->size());
        QString str="radius of the cut circle: ";
         str+="\n";
        str+=QString::number(R);
        str+="\n";
        str+="radius of the inner circle: ";
         str+="\n";
        str+=QString::number(r);
        str+="\n";
        str+="distance: ";
         str+="\n";
        str+=QString::number(d);
        str+="\n";
        str+="equation parameter: ";
         str+="\n";
        str+=QString::number(o);
        str+="\n";
        str+="step: ";
         str+="\n";
        str+=QString::number(delo);
        str+="\n";
        pix.fill(Qt::green);
        QPen pen(Qt::black);
        pen.setWidth(2);
        pen.setStyle(Qt::SolidLine);
        QPainter *p=new QPainter(&pix);
        p->drawText(0,20,150,170, Qt::AlignLeft|Qt::AlignTop,str);
        p->setPen(pen);
        int x,y,hei=this->height()/2,wid=this->width()/2;
        for(double i=0;i<o;i+=delo)
        {
            x=(R-r)*std::cos(i)+d*std::cos(((R-r)/r)*i)+wid;
            y=(R-r)*std::sin(i)+d*std::sin(((R-r)/r)*i)+hei;
            p->drawPoint(x,y);
       }
        p->end();
        repaint();
    }
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setAttribute(Qt::WA_NoSystemBackground, true);
    this->setMinimumSize(500,500);
   dialog*dial=new dialog();
   if(dial->exec()==QDialog::Accepted)
   {
       R=dial->R();
       r=dial->r();
       d=dial->d();
       o=dial->o();
       delo=dial->delo();
       QAction *actex=new QAction("&Exit",this);
      QMenu *f=menuBar()->addMenu("&File");
      f->addAction(actex);
      connect (actex,&QAction::triggered,qApp,QApplication::quit);
      QAction *actin=new QAction("&input data",this);
     f=menuBar()->addMenu("&Edit");
     f->addAction(actin);
     connect (actin, &QAction::triggered,this, &MainWindow::sledit);
     QAction *actab=new QAction("&About Qt",this);
    f=menuBar()->addMenu("&Help");
    f->addAction(actab);
    connect(actab,&QAction::triggered,qApp, QApplication::aboutQt);

   }
   else
   {
     exit(0);
   }

}
void MainWindow::resizeEvent(QResizeEvent *pEvent)
{
    pix=QPixmap(pEvent->size());
    pix.fill(Qt::green);
    QString str="radius of the cut circle: ";
     str+="\n";
    str+=QString::number(R);
    str+="\n";
    str+="radius of the inner circle: ";
     str+="\n";
    str+=QString::number(r);
    str+="\n";
    str+="distance: ";
     str+="\n";
    str+=QString::number(d);
    str+="\n";
    str+="equation parameter: ";
     str+="\n";
    str+=QString::number(o);
    str+="\n";
    str+="step: ";
     str+="\n";
    str+=QString::number(delo);
    str+="\n";
    QPen pen(Qt::black);
    pen.setWidth(2);
    pen.setStyle(Qt::SolidLine);
    QPainter *p=new QPainter(&pix);
    p->setPen(pen);
    p->drawText(0,20,150,170, Qt::AlignLeft|Qt::AlignTop,str);
    int x,y,hei=this->height()/2,wid=this->width()/2;
    for(double i=0;i<o;i+=delo)
    {
        x=(R-r)*std::cos(i)+d*std::cos(((R-r)/r)*i)+wid;
        y=(R-r)*std::sin(i)+d*std::sin(((R-r)/r)*i)+hei;
        p->drawPoint(x,y);
   }
    p->end();

}
void MainWindow::paintEvent(QPaintEvent *pEvent)
{
      QPainter  p1(this);
      p1.drawPixmap(0, 0, pix);
      p1.end();
}
MainWindow::~MainWindow()
{
}

