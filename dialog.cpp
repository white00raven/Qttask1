#include "dialog.h"

#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QApplication>

dialog::dialog(QDialog* parent )
{
     lineR=new QLineEdit();
     liner=new QLineEdit();
     lined=new QLineEdit();
     lineo=new QLineEdit();
     linedelo=new QLineEdit();
     QLabel *labelR,*labelr,*labeld,*labelo,*labeldelo;
     labelR=new QLabel(" radius of the cut circle");
     labelr=new QLabel("radius of the inner circle");
     labeld=new QLabel("distance");
     labelo=new QLabel("equation parameter");
     labeldelo=new QLabel("step");
     labelR->setBuddy(lineR);
     labelr->setBuddy(liner);
     labeld->setBuddy(lined);
     labeldelo->setBuddy(linedelo);
     QPushButton* Ok= new QPushButton("&Ok");
     connect(Ok, SIGNAL(clicked() ), SLOT(accept() ));
     QGridLayout *gr=new QGridLayout();
     gr->addWidget(labelR,0,0);
     gr->addWidget(lineR,0,1);
     gr->addWidget(labelr,1,0);
     gr->addWidget(liner,1,1);
     gr->addWidget(labeld,2,0);
     gr->addWidget(lined,2,1);
     gr->addWidget(labelo,3,0);
     gr->addWidget(lineo,3,1);
     gr->addWidget(labeldelo,4,0);
     gr->addWidget(linedelo,4,1);
     gr->addWidget(Ok,5,0);
     setLayout(gr);

}
