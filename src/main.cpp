#include"Ui/mainwidget.h"
#include"Ui/qlistcourseswidget.h"
#include <QApplication>
#include"Ui/coursewidget.h"
#include"Ui/controllerview.h"

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   ControllerView w;
   w.getView()->show();
   return a.exec();
}
