#include "calificationswidget.h"

CalificationsWidget::CalificationsWidget(QWidget *parent) : QWidget(parent),row(0)
{
   qTableCalificationsView = new QTableView(this);
   model = new QStandardItemModel(row,8,this);
   qhLayout = new QVBoxLayout(this);
   btnBack = new QPushButton("Back",this);
//   btnDeleteCalification = new QPushButton("delete",this);
//   btnModifiedCalification = new QPushButton("Modified",this);
   btnAddCalification = new QPushButton("AddCalification",this);
   qMapDeleteCalification = new QMap<QPushButton*,QPair<int, int>* >;
   qMapEditCalification = new QMap<QPushButton*,QPair<int, int>* > ;

   model->setHorizontalHeaderItem(0,new QStandardItem(QString("iDCalification")));
   model->setHorizontalHeaderItem(1,new QStandardItem(QString("IdCedula")));
   model->setHorizontalHeaderItem(2,new QStandardItem(QString("IdCourse")));
   model->setHorizontalHeaderItem(3,new QStandardItem(QString("IdEvaluation")));
   model->setHorizontalHeaderItem(4,new QStandardItem(QString("Calification")));
   model->setHorizontalHeaderItem(5,new QStandardItem(QString("Description")));
   model->setHorizontalHeaderItem(6, new QStandardItem(QString("Modified")));
   model->setHorizontalHeaderItem(7, new QStandardItem(QString("Delete")));


   qTableCalificationsView->setModel(model);
   qhLayout->addWidget(btnBack);
   qhLayout->addWidget(btnAddCalification);
   qhLayout->addWidget(qTableCalificationsView);
   this->setLayout(qhLayout);
}

CalificationsWidget::~CalificationsWidget()
{
   delete qTableCalificationsView;
   delete model;
   delete btnDeleteCalification;
   delete btnModifiedCalification;
   delete qhLayout;
   delete btnBack;
   delete qMapDeleteCalification;
   delete qMapEditCalification;
}
