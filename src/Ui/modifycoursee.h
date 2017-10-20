#ifndef MODIFYCOURSE_H
#define MODIFYCOURSE_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
class ModifyCourse : public QWidget
{
      Q_OBJECT
   public:

        QLabel* nameCourseQLabel;
        QLineEdit* nameCourseQLineEdit;

        QLabel* idCourseQLabel;
        QLineEdit* idCourseQLineEdit;
        QGridLayout* qgLayout;

        QPushButton* btnOk;
        QPushButton* btnCancel;
        QPushButton* btnCourse;

        int bandera;

      explicit ModifyCourse(QWidget *parent = 0);
        ~ModifyCourse();

   signals:

   public slots:
};

#endif // MODIFYCOURSE_H
