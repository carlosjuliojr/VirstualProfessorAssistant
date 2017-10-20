#ifndef MODIFYSTUDENT_H
#define MODIFYSTUDENT_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QGridLayout>
#include "student.h"
class ModifyStudent : public QWidget
{
      Q_OBJECT
   public:

        QLabel* name;
        QLabel* lastName;
        QLabel* idCed;
        QLabel* email;
        QLineEdit* nameLineEdit;
        QLineEdit* lastNameLineEdit;
        QLineEdit* idCedLineEdit;
        QLineEdit* emailLineEdit;

        QPushButton* btnEdit;
        Student* studentToModify;
         bool bandera;
         int idCourse;
        QPushButton* ok;
        QPushButton* btnOkStudent;
        QPushButton* cancel;
        QGridLayout* qgLayout;

      explicit ModifyStudent(QWidget *parent = 0);
        ~ModifyStudent();

   signals:

   public slots:
};

#endif // MODIFYSTUDENT_H
