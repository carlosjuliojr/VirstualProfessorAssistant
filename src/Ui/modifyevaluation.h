#ifndef MODIFYEVALUATION_H
#define MODIFYEVALUATION_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QGridLayout>
#include "student.h"


class ModifyEvaluation : public QWidget
{
      Q_OBJECT
   public:

        QLabel* idEvaluationQLabel;
        QLabel* idCourseQLabel;
        QLabel* descriptionQLabel;
        QLabel* porcentQLabel;

        QLineEdit* idEvaluationLineEdit;
        QLineEdit* idCourseLineEdit;
        QLineEdit* descriptionLineEdit;
        QLineEdit* portcentLineEdit;

        QPushButton* btnEdit;
        Evaluation* evaluationToModify;
         bool bandera;
        QPushButton* btnOk;
        QPushButton* btnAddEvaluationok;
        QPushButton* btnCancel;
        QGridLayout* qgLayout;
      explicit ModifyEvaluation(QWidget *parent = 0);
        ~ModifyEvaluation();

   signals:

   public slots:
};

#endif // MODIFYEVALUATION_H
