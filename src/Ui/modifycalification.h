#ifndef MODIFYCALIFICATION_H
#define MODIFYCALIFICATION_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QGridLayout>
#include <QComboBox>
#include "calification.h"

class ModifyCalification : public QWidget
{
      Q_OBJECT
   public:

      QLabel* idCalificationQLabel;
      QLabel* idCedulaQLabel;
      QLabel* idEvaluationQLabel;
      QLabel* idCourseQLabel;
      QLabel* descriptionQLabel;
      QLabel* calificationQLabel;

      QLineEdit* idCalificationQLineEdit;
      QLineEdit* idCedulaQLineEdit;
      QLineEdit* idEvaluationLineEdit;
      QLineEdit* idCourseLineEdit;
      QLineEdit* descriptionLineEdit;
      QLineEdit* calificationLineEdit;

      QLabel* selectEvaluationQLabel;
      QLabel* selectStudentQLabel;
      QComboBox* selectEvaluationQComboBox;
      QComboBox* selectStudentComboBox;

      QPushButton* btnEdit;
      Calification* calificationToModify;
      bool bandera;
      QPushButton* btnOk;
      QPushButton* btnAddCalification;
      QPushButton* btnCancel;
      QGridLayout* qgLayout;

      explicit ModifyCalification(QWidget *parent = 0);
      ~ModifyCalification();

   signals:

   public slots:
};

#endif // MODIFYCALIFICATION_H
