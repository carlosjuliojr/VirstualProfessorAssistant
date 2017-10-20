#include "mainwidget.h"
#include <QScrollArea>



MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{


//   this->resize(500,1000);

   qvLayout = new QVBoxLayout();

   btnCourses = new QPushButton("Courses");

   btnStudents = new QPushButton("Students");
   btnEvaluations = new QPushButton("Evaluations");
   btnAssistances = new QPushButton("Assistances");
   btnCalifications = new QPushButton("Califications");
/********************************************************************/
//   QPixmap pixmap("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/images/lupa.png");
//   QIcon ButtonIcon(pixmap);

//   btnCourses->setIcon(ButtonIcon);
//   btnCourses->setIconSize(pixmap.rect().size());

//   btnStudents->setIcon(ButtonIcon);
//   btnStudents->setIconSize(pixmap.rect().size());

//   btnEvaluations->setIcon(ButtonIcon);
//   btnEvaluations->setIconSize(pixmap.rect().size());

//   btnAssistances->setIcon(ButtonIcon);
//   btnAssistances->setIconSize(pixmap.rect().size());

//   btnCalifications->setIcon(ButtonIcon);
//   btnCalifications->setIconSize(pixmap.rect().size());
   /*********************************************************/
   qvLayout->addWidget(btnCourses);
   qvLayout->addWidget(btnStudents);
   qvLayout->addWidget(btnEvaluations);
   qvLayout->addWidget(btnAssistances);
   qvLayout->addWidget(btnCalifications);


   this->setLayout(qvLayout);

//   this->show();

}

MainWidget::~MainWidget()
{
   delete qvLayout;

   delete btnCourses;

   delete btnStudents;

   delete btnEvaluations;

   delete btnAssistances;

   delete btnCalifications;

}




QPushButton* MainWidget::getBtnCourses() const
{
   return btnCourses;
}

void MainWidget::setBtnCourses(QPushButton* value)
{
   btnCourses = value;
}

QPushButton* MainWidget::getBtnStudents() const
{
   return btnStudents;
}

void MainWidget::setBtnStudents(QPushButton* value)
{
   btnStudents = value;
}

QPushButton* MainWidget::getBtnEvaluations() const
{
   return btnEvaluations;
}

void MainWidget::setBtnEvaluations(QPushButton* value)
{
   btnEvaluations = value;
}

QPushButton* MainWidget::getBtnAssistances() const
{
   return btnAssistances;
}

void MainWidget::setBtnAssistances(QPushButton* value)
{
   btnAssistances = value;
}

QPushButton* MainWidget::getBtnCalifications() const
{
   return btnCalifications;
}

void MainWidget::setBtnCalifications(QPushButton* value)
{
   btnCalifications = value;
}


