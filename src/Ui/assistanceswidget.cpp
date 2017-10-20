#include "assistanceswidget.h"

AssistancesWidget::AssistancesWidget(QWidget *parent) : QWidget(parent), row(0)
{
    qTableAssistancesView = new QTableView(this);
    model = new QStandardItemModel(row,8,this);
    qhLayout = new QVBoxLayout(this);
    btnBack = new QPushButton("Back",this);
    btnAddAssistance = new QPushButton("AddAssistance",this);
    btnDeleteAssistance = new QPushButton("delete");
    btnModifiedAssistance = new QPushButton("Modified");
    qMapDeleteAssistance= new QMap<QPushButton*,QPair<int, int>* >;
   qMapEditAssistance= new QMap<QPushButton*,QPair<int, int>* > ;

    model->setHorizontalHeaderItem(0,new QStandardItem(QString("iDAssistance")));
    model->setHorizontalHeaderItem(1,new QStandardItem(QString("IdCedula")));
    model->setHorizontalHeaderItem(2,new QStandardItem(QString("IdCourse")));
    model->setHorizontalHeaderItem(3,new QStandardItem(QString("Data")));
    model->setHorizontalHeaderItem(4,new QStandardItem(QString("Porcent")));
    model->setHorizontalHeaderItem(5,new QStandardItem(QString("TotalAssistance")));
    model->setHorizontalHeaderItem(6, new QStandardItem(QString("Modified")));
    model->setHorizontalHeaderItem(7, new QStandardItem(QString("Delete")));


    qTableAssistancesView->setModel(model);
    qhLayout->addWidget(btnBack);
    qhLayout->addWidget(btnAddAssistance);
    qhLayout->addWidget(qTableAssistancesView);
    this->setLayout(qhLayout);
}

AssistancesWidget::~AssistancesWidget()
{
    delete qTableAssistancesView;
    delete model;
    delete btnDeleteAssistance;
    delete btnModifiedAssistance;
    delete qhLayout;
    delete btnBack;
   delete qMapDeleteAssistance;
   delete qMapEditAssistance;
}
