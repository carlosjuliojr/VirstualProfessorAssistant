#include "evaluationswidget.h"

EvaluationsWidget::EvaluationsWidget(QWidget *parent) : QWidget(parent), row(1)
{
    qTableEvaluationView = new QTableView(this);
    model = new QStandardItemModel(row,4,this);
    qhLayout = new QVBoxLayout(this);
    btnBack = new QPushButton("Back",this);
    btnDeleteEvaluation = new QPushButton("delete");
    btnModifiedEvaluation = new QPushButton("Modified");
    btnAddEvaluation = new QPushButton("AddEvaluation",this);
    qMapDeleteEvaluation = new QMap<QPushButton*, QPair<int,int>* >;
    qMapEditEvaluaiton = new QMap<QPushButton*, QPair<int,int>* >;

    model->setHorizontalHeaderItem(0,new QStandardItem(QString("iDEvaluation")));
    model->setHorizontalHeaderItem(1,new QStandardItem(QString("IdCourse")));
    model->setHorizontalHeaderItem(2,new QStandardItem(QString("Description")));
    model->setHorizontalHeaderItem(3,new QStandardItem(QString("Porcent")));
    model->setHorizontalHeaderItem(4, new QStandardItem(QString("Modified")));
    model->setHorizontalHeaderItem(5, new QStandardItem(QString("Delete")));


    qTableEvaluationView->setModel(model);
    qhLayout->addWidget(btnBack);
    qhLayout->addWidget(btnAddEvaluation);
    qhLayout->addWidget(qTableEvaluationView);
    this->setLayout(qhLayout);
}

EvaluationsWidget::~EvaluationsWidget()
{
    delete qTableEvaluationView;
    delete model;
    delete btnDeleteEvaluation;
    delete btnModifiedEvaluation;
    delete qhLayout;
    delete btnBack;
   delete qMapDeleteEvaluation;//nota debo recorrer el mapa
   delete qMapEditEvaluaiton;
   delete btnAddEvaluation;
}
