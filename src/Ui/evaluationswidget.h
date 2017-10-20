#ifndef EVALUATIONSWIDGET_H
#define EVALUATIONSWIDGET_H

#include <QObject>
#include <QWidget>
#include <QTableView>
#include <QPushButton>
#include <QHBoxLayout>
#include <QStandardItemModel>
#include <QHeaderView>

class EvaluationsWidget : public QWidget
{
      Q_OBJECT
   public:

      QTableView* qTableEvaluationView;
      QStandardItemModel* model;
      int row;
      QVBoxLayout* qhLayout;
      QPushButton* btnBack;
      QPushButton* btnDeleteEvaluation;
      QPushButton* btnModifiedEvaluation;
      QPushButton* btnAddEvaluation;
      int bandera;
      QMap<QPushButton*,QPair<int, int>* >* qMapDeleteEvaluation;
      QMap<QPushButton*,QPair<int, int>* >* qMapEditEvaluaiton;

      explicit EvaluationsWidget(QWidget *parent = 0);
      ~EvaluationsWidget();

   signals:

   public slots:
};

#endif // EVALUATIONSWIDGET_H
