#ifndef MODIFYASSISTANCE_H
#define MODIFYASSISTANCE_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QGridLayout>
#include "assistance.h"
#include <QComboBox>
#include <QRadioButton>

class ModifyAssistance : public QWidget
{
      Q_OBJECT
   public:
      QLabel* idAssistanceQLabel;
      QLabel* idCedulaQLabel;
      QLabel* fechaQLabel;
      QLabel* idCourseQLabel;
      QLabel* porcentAssistanceQLabel;
      QLabel* totalAssistanceQLabel;
      QLabel* selectStudentQLabel;


      QLineEdit* idAssistanceQLineEdit;
      QLineEdit* idCedulaQLineEdit;
      QLineEdit* fechaLineEdit;
      QLineEdit* idCourseLineEdit;
      QLineEdit* porcentAssistanceLineEdit;
      QLineEdit* totalAssistanceLineEdit;


      QComboBox* qComboBoxStudent;

      QRadioButton* assistanceQRadioButton;

      QPushButton* btnEdit;
      Assistance* assistanceToModify;
      bool bandera;
      QPushButton* btnOk;
      QPushButton* btnAddAssistance;
      QPushButton* btnCancel;
      QGridLayout* qgLayout;
      explicit ModifyAssistance(QWidget *parent = 0);
      ~ModifyAssistance();

   signals:

   public slots:
};

#endif // MODIFYASSISTANCE_H
