#include "modifyassistance.h"

ModifyAssistance::ModifyAssistance(QWidget *parent) : QWidget(parent)
{
   fechaQLabel = new QLabel("Fecha (dd:MM:yyyy) :",this);
   idCourseQLabel = new QLabel("idCourse:",this);
   porcentAssistanceQLabel = new QLabel("Porcent:",this);
   totalAssistanceQLabel = new QLabel("Assistance:",this);
   idAssistanceQLabel = new QLabel("IdAssistance",this);
   idCedulaQLabel = new QLabel("IdCedula",this);
   btnOk = new QPushButton("Ok",this);
   btnCancel = new QPushButton("Cancel",this);
   btnAddAssistance = new QPushButton("AddAssistance",this);
   selectStudentQLabel = new QLabel("Select Student",this);
   assistanceQRadioButton = new QRadioButton("",this);

   qComboBoxStudent = new QComboBox(this);
   qComboBoxStudent->setWindowTitle("Select Student");

   fechaLineEdit = new QLineEdit(this);
   idAssistanceQLineEdit = new  QLineEdit(this);
   idCedulaQLineEdit = new QLineEdit(this);
   idCourseLineEdit = new QLineEdit(this);
   porcentAssistanceLineEdit = new QLineEdit(this);
   totalAssistanceLineEdit = new QLineEdit(this);

//   QPixmap pixmapBack("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/images/ic_skip_previous_black_24dp.png");
//   QIcon ButtonIconBack(pixmapBack);

//   QPixmap pixmapOk("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/images/check-symbol.png");
//   QIcon ButtonIconOk(pixmapBack);

//   btnCancel->setIcon(ButtonIconBack);
//   btnCancel->setIconSize(pixmapBack.rect().size());

//   btnOk->setIcon(ButtonIconOk);
//   btnOk->setIconSize(pixmapOk.rect().size());


//   btnAddAssistance->setIcon(ButtonIconOk);
//   btnAddAssistance->setIconSize(pixmapOk.rect().size());


   qgLayout = new QGridLayout(this);

   qgLayout->addWidget(idAssistanceQLabel,0,0);
   qgLayout->addWidget(idAssistanceQLineEdit,0,1);
   qgLayout->addWidget(idCourseQLabel,1,0);
   qgLayout->addWidget(idCourseLineEdit,1,1);
   qgLayout->addWidget(idCedulaQLabel,2,0);
   qgLayout->addWidget(idCedulaQLineEdit,2,1);
   qgLayout->addWidget(totalAssistanceQLabel,3,0);
//   qgLayout->addWidget(totalAssistanceLineEdit,3,1);
   qgLayout->addWidget(assistanceQRadioButton,3,1);
   qgLayout->addWidget(fechaQLabel,4,0);
   qgLayout->addWidget(fechaLineEdit,4,1);
   qgLayout->addWidget(porcentAssistanceQLabel,5,0);
   qgLayout->addWidget(porcentAssistanceLineEdit,5,1);
   qgLayout->addWidget(selectStudentQLabel,6,0);
   qgLayout->addWidget(qComboBoxStudent,6,1);


   qgLayout->addWidget(btnCancel,7,0);
   qgLayout->addWidget(btnOk,7,1);
   qgLayout->addWidget(btnAddAssistance,7,2);

   this->setLayout(qgLayout);

}

ModifyAssistance::~ModifyAssistance()
{
   delete fechaQLabel ;
   delete idCourseQLabel ;
   delete porcentAssistanceQLabel;
   delete totalAssistanceQLabel;
   delete idAssistanceQLabel;
   delete idCedulaQLabel;
   delete selectStudentQLabel;
   delete btnOk;
   delete btnCancel;
   delete qComboBoxStudent;

   delete fechaLineEdit;
   delete idAssistanceQLineEdit;
   delete idCedulaQLineEdit;
   delete idCourseLineEdit;
   delete porcentAssistanceLineEdit;
   delete totalAssistanceLineEdit;

   delete qgLayout;
}
