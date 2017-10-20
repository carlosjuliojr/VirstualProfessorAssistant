#include "modifyevaluation.h"

ModifyEvaluation::ModifyEvaluation(QWidget *parent) : QWidget(parent)
{
    idEvaluationQLabel = new QLabel("idEvaluation:",this);
    idCourseQLabel = new QLabel("idCourse:",this);
    descriptionQLabel = new QLabel("Decription:",this);
    porcentQLabel = new QLabel("Porcenet:",this);
    btnOk = new QPushButton("Ok",this);
     btnAddEvaluationok = new QPushButton("ok",this);
    btnCancel = new QPushButton("Cancel",this);

    idEvaluationLineEdit = new QLineEdit(this);
    idCourseLineEdit = new QLineEdit(this);
    descriptionLineEdit = new QLineEdit(this);
    portcentLineEdit = new QLineEdit(this);


//    QPixmap pixmapBack("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/images/ic_skip_previous_black_24dp.png");
//    QIcon ButtonIconBack(pixmapBack);

//    QPixmap pixmapOk("/home/julio/Descargas/check-symbol.png");
//    QIcon ButtonIconOk(pixmapBack);

//    btnCancel->setIcon(ButtonIconBack);
//    btnCancel->setIconSize(pixmapBack.rect().size());

//    btnOk->setIcon(ButtonIconOk);
//    btnOk->setIconSize(pixmapOk.rect().size());


//    btnAddEvaluationok->setIcon(ButtonIconOk);
//    btnAddEvaluationok->setIconSize(pixmapOk.rect().size());



    qgLayout = new QGridLayout(this);

    qgLayout->addWidget(idEvaluationQLabel,0,0);
    qgLayout->addWidget(idEvaluationLineEdit,0,1);
    qgLayout->addWidget(idCourseQLabel,1,0);
    qgLayout->addWidget(idCourseLineEdit,1,1);
    qgLayout->addWidget(descriptionQLabel,2,0);
    qgLayout->addWidget(descriptionLineEdit,2,1);
    qgLayout->addWidget(porcentQLabel,3,0);
    qgLayout->addWidget(portcentLineEdit,3,1);
    qgLayout->addWidget(btnCancel,4,0);
    qgLayout->addWidget(btnOk,4,1);
    qgLayout->addWidget(btnAddEvaluationok,4,2);

    this->setLayout(qgLayout);
}

ModifyEvaluation::~ModifyEvaluation()
{
   delete idEvaluationQLabel;
   delete idCourseQLabel;
   delete descriptionQLabel;
   delete porcentQLabel;

   delete idEvaluationLineEdit;
   delete idCourseLineEdit;
   delete descriptionLineEdit;
   delete portcentLineEdit;

   delete btnEdit;
   delete btnOk;
   delete btnCancel;
   delete btnAddEvaluationok;
   delete qgLayout;
}
