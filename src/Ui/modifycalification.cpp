#include "modifycalification.h"

ModifyCalification::ModifyCalification(QWidget *parent) : QWidget(parent)
{
   idEvaluationQLabel = new QLabel("idEvaluation",this);
   idCourseQLabel = new QLabel("idCourse",this);
   descriptionQLabel = new QLabel("Decription",this);
   calificationQLabel = new QLabel("Calification",this);
   idCalificationQLabel = new QLabel("IdCalification",this);
   idCedulaQLabel = new QLabel("IdCedula",this);
   btnOk = new QPushButton("Ok",this);
   btnCancel = new QPushButton("Cancel",this);
   btnAddCalification = new QPushButton("Ok",this);

   idEvaluationLineEdit = new QLineEdit(this);
   idCalificationQLineEdit = new  QLineEdit(this);
   idCedulaQLineEdit = new QLineEdit(this);
   idCourseLineEdit = new QLineEdit(this);
   descriptionLineEdit = new QLineEdit(this);
   calificationLineEdit = new QLineEdit(this);


   selectEvaluationQLabel = new QLabel("Select Evaluation",this);
   selectStudentQLabel= new QLabel("Select Student",this);
   selectEvaluationQComboBox = new QComboBox(this);
   selectStudentComboBox = new QComboBox(this);



//   QPixmap pixmapBack("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/images/ic_skip_previous_black_24dp.png");
//   QIcon ButtonIconBack(pixmapBack);

//   QPixmap pixmapOk("/home/julio/Descargas/check-symbol.png");
//   QIcon ButtonIconOk(pixmapBack);

//   btnCancel->setIcon(ButtonIconBack);
//   btnCancel->setIconSize(pixmapBack.rect().size());

//   btnOk->setIcon(ButtonIconOk);
//   btnOk->setIconSize(pixmapOk.rect().size());


//   btnAddCalification->setIcon(ButtonIconOk);
//   btnAddCalification->setIconSize(pixmapOk.rect().size());

   qgLayout = new QGridLayout(this);

   qgLayout->addWidget(idEvaluationQLabel,0,0);
   qgLayout->addWidget(idEvaluationLineEdit,0,1);
   qgLayout->addWidget(idCourseQLabel,1,0);
   qgLayout->addWidget(idCourseLineEdit,1,1);
   qgLayout->addWidget(descriptionQLabel,2,0);
   qgLayout->addWidget(descriptionLineEdit,2,1);
   qgLayout->addWidget(calificationQLabel,3,0);
   qgLayout->addWidget(calificationLineEdit,3,1);
   qgLayout->addWidget(idCalificationQLabel,4,0);
   qgLayout->addWidget(idCalificationQLineEdit,4,1);
   qgLayout->addWidget(idCedulaQLabel,5,0);
   qgLayout->addWidget(idCedulaQLineEdit,5,1);
   qgLayout->addWidget(selectStudentQLabel,6,0);
   qgLayout->addWidget(selectStudentComboBox,6,1);
   qgLayout->addWidget(selectEvaluationQLabel,7,0);
   qgLayout->addWidget(selectEvaluationQComboBox,7,1);


   qgLayout->addWidget(btnCancel,8,0);
   qgLayout->addWidget(btnOk,8,1);
   qgLayout->addWidget(btnAddCalification,8,2);

   this->setLayout(qgLayout);
}

ModifyCalification::~ModifyCalification()
{

   delete idCalificationQLabel;
   delete idCedulaQLabel;
   delete idEvaluationQLabel;
   delete idCourseQLabel;
   delete descriptionQLabel;
   delete calificationQLabel;

   delete idCalificationQLineEdit;
   delete idCedulaQLineEdit;
   delete idEvaluationLineEdit;
   delete idCourseLineEdit;
   delete descriptionLineEdit;
   delete calificationLineEdit;
   delete btnAddCalification;


   delete selectEvaluationQLabel;
   delete selectStudentQLabel;
   delete  selectEvaluationQComboBox;
   delete selectStudentComboBox;


   delete btnEdit;
   delete btnOk;
   delete btnCancel;
   delete qgLayout;
}
