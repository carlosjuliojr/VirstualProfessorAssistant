#include "coursewidget.h"
#include"iostream"

CoursesWidget::CoursesWidget(QWidget* parent):
   QWidget(parent)
{
//      std::cout<<"sera";
//   this->resize(500,500);

//   QString s("NameCourse"+"fdsf");
//   this->setWindowTitle("NameCourse");
   qgridLayout = new QGridLayout(this);
   btnAssistances = new QPushButton("Assistances");
   btnStudents = new QPushButton("Students");
   btnEvaluations = new QPushButton("Evaluations");
   btnCalifications = new QPushButton("Califications");
   btnDeleteCourse = new QPushButton("Delete");

   btnBack = new QPushButton("Back");
   btnEditCourse = new QPushButton("Edit");


//   QPixmap pixmap("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/images/lupa.png");
//   QIcon ButtonIcon(pixmap);


//   QPixmap pixmapDelete("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/images/delete.png");
//   QIcon ButtonIconDelete(pixmapDelete);

//   QPixmap pixmapEdit("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/images/edit.png");
//   QIcon ButtonIconEdit(pixmapEdit);

//   QPixmap pixmapBack("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/images/ic_skip_previous_black_24dp.png");
//   QIcon ButtonIconBack(pixmapBack);

//   btnStudents->setIcon(ButtonIcon);
//   btnStudents->setIconSize(pixmap.rect().size());

//   btnEvaluations->setIcon(ButtonIcon);
//   btnEvaluations->setIconSize(pixmap.rect().size());

//   btnAssistances->setIcon(ButtonIcon);
//   btnAssistances->setIconSize(pixmap.rect().size());

//   btnCalifications->setIcon(ButtonIcon);
//   btnCalifications->setIconSize(pixmap.rect().size());


//   btnDeleteCourse->setIcon(ButtonIconDelete);
//   btnDeleteCourse->setIconSize(pixmapDelete.rect().size());

//   btnEditCourse->setIcon(ButtonIconEdit);
//   btnEditCourse->setIconSize(pixmapEdit.rect().size());


//   btnBack->setIcon(ButtonIconBack);
//   btnBack->setIconSize(pixmapBack.rect().size());
//   /*********************************************************/



   qgridLayout->addWidget(btnStudents,0,0);
   qgridLayout->addWidget(btnEvaluations,0,1);
   qgridLayout->addWidget(btnCalifications,1,0);
   qgridLayout->addWidget(btnAssistances,1,1);
   qgridLayout->addWidget(btnBack,2,0);
   qgridLayout->addWidget(btnDeleteCourse,2,1);
   qgridLayout->addWidget(btnEditCourse,2,2); //falta agregar esta funcionalidad

   this->setLayout(qgridLayout);

}

CoursesWidget::~CoursesWidget()
{
   delete qgridLayout;
   delete btnAssistances;
   delete btnBack;
   delete btnCalifications;
   delete btnEvaluations;
   delete btnStudents;
   delete btnEditCourse;

}
