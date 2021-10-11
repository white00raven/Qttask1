#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include <QLineEdit>
class dialog:public QDialog
{
//double R,r,d,o;
    Q_OBJECT
QLineEdit* lineR,*liner,*lined,*lineo,*linedelo;
public:
    dialog(QDialog *parent = nullptr);
    double R(){QString str=lineR->text();if(str.isEmpty())return 1;return str.toDouble();};
    double r(){QString str=liner->text();if(str.isEmpty())return 1;return str.toDouble();};
    double d(){QString str=lined->text();if(str.isEmpty())return 1;return str.toDouble();};
    double o(){QString str=lineo->text();if(str.isEmpty())return 0;return str.toDouble();};
    double delo(){QString str=linedelo->text();if(str.isEmpty())return 1;return str.toDouble();};
};
#endif // DIALOG_H
