#include "modifystudent.h"

ModifyStudent::ModifyStudent(QWidget *parent) : QWidget(parent)
{
   name = new QLabel("Name:",this);
   lastName = new QLabel("Last Name:",this);
   idCed = new QLabel("IdCed:",this);
   email = new QLabel("Email:",this);
   ok = new QPushButton("Ok",this);
   cancel = new QPushButton("Cancel",this);
   btnOkStudent = new QPushButton("OkStudent");


//   QPixmap pixmapBack("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/images/ic_skip_previous_black_24dp.png");
//   QIcon ButtonIconBack(pixmapBack);

//   QPixmap pixmapOk("/home/julio/Descargas/check-symbol.png");
//   QIcon ButtonIconOk(pixmapBack);

//   cancel->setIcon(ButtonIconBack);
//   cancel->setIconSize(pixmapBack.rect().size());

//   btnOkStudent->setIcon(ButtonIconOk);
//   btnOkStudent->setIconSize(pixmapOk.rect().size());


//   ok->setIcon(ButtonIconOk);
//   ok->setIconSize(pixmapOk.rect().size());


   nameLineEdit = new QLineEdit(this);
   lastNameLineEdit = new QLineEdit(this);
   idCedLineEdit = new QLineEdit(this);
   emailLineEdit = new QLineEdit(this);

   qgLayout = new QGridLayout(this);

   qgLayout->addWidget(name,0,0);
   qgLayout->addWidget(nameLineEdit,0,1);
   qgLayout->addWidget(lastName,1,0);
   qgLayout->addWidget(lastNameLineEdit,1,1);
   qgLayout->addWidget(idCed,2,0);
   qgLayout->addWidget(idCedLineEdit,2,1);
   qgLayout->addWidget(email,3,0);
   qgLayout->addWidget(emailLineEdit,3,1);
   qgLayout->addWidget(cancel,4,0);
   qgLayout->addWidget(ok,4,1);
   qgLayout->addWidget(btnOkStudent,4,2);

   this->setLayout(qgLayout);

}

ModifyStudent::~ModifyStudent()
{
   delete name;
   delete lastName;
   delete idCed;
   delete email;
   delete nameLineEdit;
   delete lastNameLineEdit;
   delete idCedLineEdit;
   delete emailLineEdit;

   delete ok;
   delete btnOkStudent;
   delete cancel;
   delete qgLayout;
}
