#include "controllerview.h"

ControllerView::ControllerView()
{
   model = new Model;
   model->setModel(new Dbhandler);


   model->getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                             "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                             "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                             "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                             "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                             "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                             );

   view = new QStackedWidget;
   layoutWidgets = new QVBoxLayout;
   mainwidget = new MainWidget(view);
   qlistCourse = new QListCoursesWidget(model->getMapCourseAll(),view);
   courseWidget = new CoursesWidget(view);
   studentsWidget = new StudentsWidget(model->getMapStudentAll(),view);
   evaluationsWidget = new EvaluationsWidget(view);
   assistancesWidget = new AssistancesWidget(view);
   calificationsWidget = new CalificationsWidget(view);
   modifyStudent = new ModifyStudent(view);
   modifyEvaluation = new ModifyEvaluation(view);
   modifyCalification = new ModifyCalification(view);
   modifyAssistance = new ModifyAssistance(view);
   modifyCourse = new ModifyCourse(view);



   view->addWidget(mainwidget); //0 windows inicial
   view->addWidget(qlistCourse); //1   list Courses
   view->addWidget(courseWidget);//2   Course  Widget
   view->addWidget(studentsWidget);//3 Student widget
   view->addWidget(evaluationsWidget);//4 evaluation widget
   view->addWidget(assistancesWidget);//5 assistance widget
   view->addWidget(calificationsWidget);//6  calification widget
   view->addWidget(modifyStudent);//7  modify student wodget
   view->addWidget(modifyEvaluation);//8 modify evaluation widget
   view->addWidget(modifyCalification);//9 modify calification Widget
   view->addWidget(modifyAssistance);//10 modify Assistance widget
   view->addWidget(modifyCourse);//11 modify Assistance widget
   layoutWidgets->addWidget(view);

   scroll = new QScrollArea;
//   this->mainwidget->qvLayout->addWidget(scroll);
//   mainwidget->qvLayout->addWidget(scroll);
//   scroll->setWidgetResizable(true);
//   scroll->horizontalScrollBarPolicy();
//   scroll->setWidget(this->qlistCourse);

   this->setLayoutWidgets(layoutWidgets);
/************Size widgets*****************************************************************/
//   this->view->resize(50,50);
//   this->view->setFixedHeight(500);
//   this->view->setFixedWidth(850);


//   this->mainwidget->qvLayout->setAlignment(Qt:: AlignHCenter);
//   this->mainwidget->qvLayout->setSpacing(50);
//   this->mainwidget->btnCourses->setFixedSize(120,40);
//   this->mainwidget->btnStudents->setFixedSize(120,40);
//   this->mainwidget->btnEvaluations->setFixedSize(120,40);
//   this->mainwidget->btnAssistances->setFixedSize(120,40);
//   this->mainwidget->btnCalifications->setFixedSize(120,40);


//   this->qlistCourse->l->setAlignment(Qt:: AlignHCenter);
//   this->qlistCourse->l->setSpacing(150);
//   this->qlistCourse->btnBack->setFixedSize(100,40);
//   this->qlistCourse->btnAddCourse->setFixedSize(100,40);


//   this->mainwidget->qvLayout->;


   view->setCurrentIndex(0);

   QObject::connect(this->mainwidget->btnCourses,SIGNAL(clicked(bool)),
                    this,SLOT(showListCourses()));

   QObject::connect(this->mainwidget->btnStudents,SIGNAL(clicked(bool)),
                    this, SLOT(showStudentsAll()));


   QObject::connect(this->mainwidget->btnEvaluations,SIGNAL(clicked(bool)),
                    this, SLOT(showEvaluationsAll()));

   QObject::connect(this->mainwidget->btnAssistances,SIGNAL(clicked(bool)),
                    this, SLOT(showAssistancesAll()));

   QObject::connect(this->mainwidget->btnCalifications,SIGNAL(clicked(bool)),
                    this, SLOT(showCalificationsAll()));

   QObject::connect(this->courseWidget->btnBack,SIGNAL(released()),
                    this,SLOT(showListCourses()));

   QObject::connect(this->qlistCourse,SIGNAL(clickedSignalButton(QPushButton*)),
                    this,SLOT(showCourseQPushBWieget(QPushButton*)));

   QObject::connect(this->qlistCourse->btnBack,SIGNAL(released()),
                    this,SLOT(showInit()));

   QObject::connect(this->evaluationsWidget->btnBack,SIGNAL(released()),
                    this,SLOT(showInit()));

   QObject::connect(this,SIGNAL(signalShowStudentsModifiedAll()),
                    this,SLOT(showStudentsAll()));

   QObject::connect(this,SIGNAL(signalShowStudentsModifiedCourse()),
                    this,SLOT(showStudents()));

   QObject::connect(this->modifyStudent->ok,SIGNAL(clicked(bool)),
                    this,SLOT(modifyStudentAllInMemory()));

   QObject::connect(this,SIGNAL(signalShowEvaluaitonsModifiedAll()),
                    this,SLOT(showEvaluationsAll()));

   QObject::connect(this,SIGNAL(signalShowEvaluationsModifiedCourse()),
                    this,SLOT(showEvaluations()));

   QObject::connect(this->modifyEvaluation->btnOk,SIGNAL(clicked(bool)),
                    this,SLOT(modifyEvaluationInMemory()));

   QObject::connect(this,SIGNAL(signalShowCalificationsModifiedAll()),
                    this,SLOT(showCalificationsAll()));

   QObject::connect(this,SIGNAL(signalShowCalificationsModifiedCourse()),
                    this,SLOT(showCalifications()));

   QObject::connect(this->modifyCalification->btnOk,SIGNAL(clicked(bool)),
                    this,SLOT(modifyCalificationInMemory()));

   QObject::connect(this,SIGNAL(signalShowAssistancesModifiedCourse()),
                    this,SLOT(showAssistances()));

   QObject::connect(this,SIGNAL(signalShowAssistancesModifiedAll()),
                    this,SLOT(showAssistancesAll()));

   QObject::connect(this->modifyAssistance->btnOk,SIGNAL(clicked(bool)),
                    this,SLOT(modifyAssistanceInMemory()));

   QObject::connect(this->modifyStudent->btnOkStudent,SIGNAL(clicked(bool)),
                    this,SLOT(addStudentOk()));

   QObject::connect(this->modifyAssistance->btnAddAssistance,SIGNAL(clicked(bool)),
                    this,SLOT(addAssistanceOk()));

   QObject::connect(this->modifyEvaluation->btnAddEvaluationok,SIGNAL(clicked(bool)),
                    this,SLOT(addEvaluationOk()));

   QObject::connect(this->modifyCalification->btnAddCalification,SIGNAL(clicked(bool)),
                    this,SLOT(addCalificationOk()));

   QObject::connect(this->courseWidget->btnEditCourse,SIGNAL(clicked(bool)),
                    this,SLOT(modifyOnlyCourse()));

   QObject::connect(this->modifyCourse->btnOk,SIGNAL(clicked(bool)),
                    this,SLOT(modifyCourseInMemory()));


   QObject::connect(this->modifyCourse->btnCourse,SIGNAL(clicked(bool)),
                    this,SLOT(addCourseOk()));

   QObject::connect(this->courseWidget->btnEditCourse,SIGNAL(clicked(bool)),
                    this,SLOT(modifyOnlyCourse()));

   QObject::connect(this,SIGNAL(signalShowModifiedCourse()),
                    this,SLOT(showCourse()));

   QObject::connect(this,SIGNAL(signalShowCreatedCourse()),
                    this,SLOT(showListCourses()));

   QObject::connect(this->qlistCourse->btnAddCourse,SIGNAL(clicked(bool)),
                    this,SLOT(addCourse()));



}

ControllerView::~ControllerView()
{
   delete view;
   delete model;
}


QStackedWidget* ControllerView::getView() const
{
   return view;
}

void ControllerView::modelStudentWidgetClear()
{
   this->studentsWidget->model->clear();
   this->studentsWidget->model->setHorizontalHeaderItem(0,new QStandardItem(QString("Name")));
   this->studentsWidget->model->setHorizontalHeaderItem(1,new QStandardItem(QString("Last Name")));
   this->studentsWidget->model->setHorizontalHeaderItem(2,new QStandardItem(QString("# Identification")));
   this->studentsWidget->model->setHorizontalHeaderItem(3,new QStandardItem(QString("Email")));
   this->studentsWidget->model->setHorizontalHeaderItem(4, new QStandardItem(QString("Modify")));
   this->studentsWidget->model->setHorizontalHeaderItem(5, new QStandardItem(QString("Delete")));
}

void ControllerView::modelEvaluationWidgetClear()
{
   this->evaluationsWidget->model->clear();

   this->evaluationsWidget->model->setHorizontalHeaderItem(0,new QStandardItem(QString("iDEvaluation")));
   this->evaluationsWidget->model->setHorizontalHeaderItem(1,new QStandardItem(QString("IdCourse")));
   this->evaluationsWidget->model->setHorizontalHeaderItem(2,new QStandardItem(QString("Description")));
   this->evaluationsWidget->model->setHorizontalHeaderItem(3,new QStandardItem(QString("Porcent")));
   this->evaluationsWidget->model->setHorizontalHeaderItem(4, new QStandardItem(QString("Modify")));
   this->evaluationsWidget->model->setHorizontalHeaderItem(5, new QStandardItem(QString("Delete")));
}

void ControllerView::modelAssistanceWidgetClear()
{
   this->assistancesWidget->model->clear();

   this->assistancesWidget->model->setHorizontalHeaderItem(0,new QStandardItem(QString("iDAssistance")));
   this->assistancesWidget->model->setHorizontalHeaderItem(1,new QStandardItem(QString("IdCedula")));
   this->assistancesWidget->model->setHorizontalHeaderItem(2,new QStandardItem(QString("IdCourse")));
   this->assistancesWidget->model->setHorizontalHeaderItem(3,new QStandardItem(QString("Data")));
   this->assistancesWidget->model->setHorizontalHeaderItem(4,new QStandardItem(QString("Porcent")));
   this->assistancesWidget->model->setHorizontalHeaderItem(5,new QStandardItem(QString("Assistance")));
   this->assistancesWidget->model->setHorizontalHeaderItem(6, new QStandardItem(QString("Modify")));
   this->assistancesWidget->model->setHorizontalHeaderItem(7, new QStandardItem(QString("Delete")));
}

void ControllerView::modelCalificationWidgetClear()
{ qDebug()<<"verificando entrada";
   this->calificationsWidget->model->clear();
   this->calificationsWidget->model->setHorizontalHeaderItem(0,new QStandardItem(QString("iDCalification")));
   this->calificationsWidget->model->setHorizontalHeaderItem(1,new QStandardItem(QString("IdCedula")));
   this->calificationsWidget->model->setHorizontalHeaderItem(2,new QStandardItem(QString("IdCourse")));
   this->calificationsWidget->model->setHorizontalHeaderItem(3,new QStandardItem(QString("IdEvaluation")));
   this->calificationsWidget->model->setHorizontalHeaderItem(4,new QStandardItem(QString("Calification")));
   this->calificationsWidget->model->setHorizontalHeaderItem(5,new QStandardItem(QString("Description")));
   this->calificationsWidget->model->setHorizontalHeaderItem(6, new QStandardItem(QString("Modify")));
   this->calificationsWidget->model->setHorizontalHeaderItem(7, new QStandardItem(QString("Delete")));
}

void ControllerView::showListCourses()
{
   view->setWindowTitle("Courses");
   view->setCurrentIndex(1);
}

void ControllerView::showCourseQPushBWieget(QPushButton* a)
{
   this->modifyCourse->btnCourse = a;
   Course* course = this->qlistCourse->qPushBCourses->find(a).value();
   this->courseWidget->idCourse = course->getIdCourse();
   QString idCourse = QString::number(course->getIdCourse());
   view->setWindowTitle(course->getNameCourse()+" idCourse:" + idCourse );

   QObject::connect(this->courseWidget->btnStudents,SIGNAL(released()),
                    this,SLOT(showStudents()));


   QObject::connect(this->courseWidget->btnEvaluations,SIGNAL(released()),
                    this,SLOT(showEvaluations()));

   QObject::connect(this->courseWidget->btnAssistances,SIGNAL(released()),
                    this,SLOT(showAssistances()));

   QObject::connect(this->courseWidget->btnCalifications,SIGNAL(released()),
                    this,SLOT(showCalifications()));

   QObject::connect(this->courseWidget->btnDeleteCourse,SIGNAL(clicked(bool)),
                    this,SLOT(deleteCourse()));


   view->setCurrentIndex(2);
}

void ControllerView::addCourse()
{
   this->modifyCourse->bandera== 0;
   this->modifyCourse->idCourseQLineEdit->setDisabled(false);
   this->modifyCourse->btnOk->setVisible(true);
this->modifyCourse->btnOk->setVisible(false);
   this->modifyCourse->idCourseQLabel->setVisible(false);
this->modifyCourse->idCourseQLineEdit->setVisible(false);



   if(!this->modifyCourse->bandera == 0){
      QObject::connect(this->modifyCourse->btnCancel,SIGNAL(clicked(bool)),
                       this,SLOT(showListCourses()));
   }else{
      QObject::connect(this->modifyCourse->btnCancel,SIGNAL(clicked(bool)),
                       this,SLOT(showCourse()));
   }
   view->setCurrentIndex(11);
}

void ControllerView::addCourseOk()
{

   if(this->model->createCourse(this->modifyCourse->nameCourseQLineEdit->text()))
   {
      Course* course = this->model->getMapCourseAll().last();
      QPushButton* button = new QPushButton(course->getNameCourse(),this->qlistCourse);
//     button->setFixedSize(100,40);
      this->qlistCourse->qPushBCourses->insert(button,course);
      this->qlistCourse->l->addWidget(button);

      QObject::connect(button, SIGNAL(clicked(bool)),
      this->qlistCourse, SLOT(pointerwindowCourse()));

      emit(signalShowCreatedCourse());

   }else
   {
      QMessageBox::information(this->qlistCourse,"Observation","The Course was not created");

   }

}

void ControllerView::deleteStudent()
{
   //   emit(clickedSignalButtonDeleteStudent((QPushButton*)this->sender()));

   QPushButton* button = (QPushButton*)this->sender();
   const QPair<int,int>* data =  this->studentsWidget->qMapDeleteStudent->find(button).value();
   Student* student = this->model->getMapStudentAll().find(data->second).value();

   QMessageBox::StandardButton reply;
   reply = QMessageBox::question(button, "Warning", "Are you sure to eliminate the student? "
                                                    "\n Name: "+student->getNombre()+
                                 "\n Last Name: "+student->getApellido()+
                                 " \n idCed: "  +QString::number(student->getCedula())+
                                 "\n Email: "+student->getCorreoElectronico(),

                                 QMessageBox::Yes|QMessageBox::No);

   if (reply == QMessageBox::Yes)
   {
      if(this->model->deleteStudent(data->second))
      {
         studentsWidget->model->removeRow(data->first);
         if(this->studentsWidget->qMapDeleteStudent->remove(button))
            qDebug()<<"Pair delete to the qMapDeleteStudent";
         else
            qDebug()<<"Pair does not delete to the qMapDeleteStudent";

         QMap<QPushButton*, QPair<int, int>* >::iterator itQmapPushBPair = this->studentsWidget->qMapDeleteStudent->begin();

         while(itQmapPushBPair != this->studentsWidget->qMapDeleteStudent->end())
         {
            if((*itQmapPushBPair)->first > data->first)
               (*itQmapPushBPair)->first--;

            itQmapPushBPair++;
         }

         delete button; // free memory

      }else{
         QMessageBox::information(button,"Observation","The student was not erased");
      }
   } else {
      //      QMessageBox::information(button,"Observation","The student was not erased");
   }

}


void ControllerView::deleteCourse()
{
   const QMap<int, Course*> & qmC =this->model->getMapCourseAll();
   if(this->model->getMapCourseAll().contains(this->courseWidget->idCourse))
   {
      Course* course = qmC.find(this->courseWidget->idCourse).value();
      QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this->courseWidget->btnDeleteCourse, "Warning", "Are you sure to eliminate the course? "
                                                                                    "\n Name: "+course->getNameCourse()+
                                    " \n idCed: "  +QString::number(this->courseWidget->idCourse),
                                    QMessageBox::Yes|QMessageBox::No);

      if (reply == QMessageBox::Yes)
      {
         if(this->model->deleteCourse(this->courseWidget->idCourse))
         {
            QMap<QPushButton*, Course*>::iterator itQpusCourse = this->qlistCourse->qPushBCourses->begin();
            while (itQpusCourse != this->qlistCourse->qPushBCourses->end())
            {
               QPushButton* pPushButton = itQpusCourse.key();
               itQpusCourse = this->qlistCourse->qPushBCourses->erase(itQpusCourse);
               delete pPushButton;
            }

            this->qlistCourse->addButtons(this->model->getMapCourseAll());
            view->setCurrentIndex(0);
         }
      }
      else
      {
         QMessageBox::information(this->courseWidget->btnDeleteCourse,"Observation","The student was not erased");
      }

   }
}

void ControllerView::deleteEvaluation()
{
   QPushButton* button = (QPushButton*)this->sender();
   const QPair<int,int>* data =  this->evaluationsWidget->qMapDeleteEvaluation->find(button).value();
   Evaluation* evaluation = this->model->getMapEvaluationAll().find(data->second).value();

   QMessageBox::StandardButton reply;
   reply = QMessageBox::question(button, "Warning", "Are you sure to eliminate the evaluation? "
                                                    " \n idEvaluation: "  +QString::number(evaluation->getIdEvaluation())+
                                 " \n idCourse: "  +QString::number(evaluation->getIdCourse())+
                                 "\n Porcent: "+QString::number(evaluation->getPorcent())+
                                 "\n Description: "+evaluation->getDescription(),
                                 QMessageBox::Yes|QMessageBox::No);

   if (reply == QMessageBox::Yes)
   {
      if(this->model->deleteEvaluation(data->second))
      {
         evaluationsWidget->model->removeRow(data->first);
         if(this->evaluationsWidget->qMapDeleteEvaluation->remove(button))
            qDebug()<<"Pair delete to the qMapDeleteStudent";
         else
            qDebug()<<"Pair does not delete to the qMapDeleteStudent";

         QMap<QPushButton*, QPair<int, int>* >::iterator itQmapPushBPair = this->evaluationsWidget->qMapDeleteEvaluation->begin();

         while(itQmapPushBPair != this->evaluationsWidget->qMapDeleteEvaluation->end())
         {
            if((*itQmapPushBPair)->first > data->first)
               (*itQmapPushBPair)->first--;

            itQmapPushBPair++;
         }

         delete button; // free memory

      }else{
         QMessageBox::information(button,"Observation","The evaluation was not erased");
      }
   } else {
      //      QMessageBox::information(button,"Observation","The student was not erased");
   }
}


void ControllerView::deleteCalification()
{
   QPushButton* button = (QPushButton*)this->sender();
   const QPair<int,int>* data =  this->calificationsWidget->qMapDeleteCalification->find(button).value();
   Calification* calification = this->model->getMapCalificationAll().find(data->second).value();

   QMessageBox::StandardButton reply;
   reply = QMessageBox::question(button, "Warning", "Are you sure to eliminate the calification? "
                                                    "\n IdCalification: "+QString::number(calification->getIdCalification())+
                                 " \n idEvaluation: "  +QString::number(calification->getIdEvaluation())+
                                 " \n idCourse: "  +QString::number(calification->getIdCourse())+
                                 " \n idCedula: "  +QString::number(calification->getIdCed())+
                                 " \n Calification: "  +QString::number(calification->getCalification())+
                                 "\n Description: "+calification->getObservation(),
                                 QMessageBox::Yes|QMessageBox::No);

   if (reply == QMessageBox::Yes)
   {
      if(this->model->deleteCalification(data->second))
      {
         calificationsWidget->model->removeRow(data->first);
         if(this->calificationsWidget->qMapDeleteCalification->remove(button))
            qDebug()<<"Pair delete to the qMapDeleteStudent";
         else
            qDebug()<<"Pair does not delete to the qMapDeleteStudent";

         QMap<QPushButton*, QPair<int, int>* >::iterator itQmapPushBPair = this->calificationsWidget->qMapDeleteCalification->begin();

         while(itQmapPushBPair != this->calificationsWidget->qMapDeleteCalification->end())
         {
            if((*itQmapPushBPair)->first > data->first)
               (*itQmapPushBPair)->first--;

            itQmapPushBPair++;
         }

         delete button; // free memory

      }else{
         QMessageBox::information(button,"Observation","The evaluation was not erased");
      }
   } else {
      //      QMessageBox::information(button,"Observation","The student was not erased");
   }
}


void ControllerView::deleteAssistance()
{
   QPushButton* button = (QPushButton*)this->sender();
   const QPair<int,int>* data =  this->assistancesWidget->qMapDeleteAssistance->find(button).value();
   Assistance* assistance = this->model->getMapAssistanceAll().find(data->second).value();

   QMessageBox::StandardButton reply;
   reply = QMessageBox::question(button, "Warning", "Are you sure to eliminate the assistance? "
                                                    " \n idAssistance: "  +QString::number(assistance->getIdAssistance())+
                                 " \n idCourse: "  +QString::number(assistance->getIdCourse())+
                                 " \n idCedula: "  +QString::number(assistance->getIdCed())+
                                 " \n Calification: "  +QString::number(assistance->getPorcentAssistance())+
                                 "\n IdCalification: "+QString::number(assistance->getTotalAssistance())+
                                 "\n Description: "+assistance->getFechaAssistance().toString("yyyy:MM:dd"),
                                 QMessageBox::Yes|QMessageBox::No);

   if (reply == QMessageBox::Yes)
   {
      if(this->model->deleteAssistance(data->second))
      {
         assistancesWidget->model->removeRow(data->first);
         if(this->assistancesWidget->qMapDeleteAssistance->remove(button))
            qDebug()<<"Pair delete to the qMapDeleteAssistance";
         else
            qDebug()<<"Pair does not delete to the qMapDeleteAssistance";

         QMap<QPushButton*, QPair<int, int>* >::iterator itQmapPushBPair = this->assistancesWidget->qMapDeleteAssistance->begin();

         while(itQmapPushBPair != this->assistancesWidget->qMapDeleteAssistance->end())
         {
            if((*itQmapPushBPair)->first > data->first)
               (*itQmapPushBPair)->first--;

            itQmapPushBPair++;
         }

         delete button; // free memory

      }else{
         QMessageBox::information(button,"Observation","The Assistance was not erased");
      }
   } else {
      //      QMessageBox::information(button,"Observation","The student was not erased");
   }
}

void ControllerView::modifyStudentAll()
{
   this->modifyStudent->btnOkStudent->setVisible(false);
   this->modifyStudent->ok->setVisible(true);
   view->setCurrentIndex(7);
   QPushButton* button = (QPushButton*)this->sender();
   const QPair<int,int>* data =  this->studentsWidget->qMapEditStudent->find(button).value();

   Student* student = this->model->getMapStudentAll().find(data->second).value();

   this->modifyStudent->nameLineEdit->setText(student->getNombre());
   this->modifyStudent->lastNameLineEdit->setText(student->getApellido());
   this->modifyStudent->idCedLineEdit->setText(QString::number(student->getCedula()));
   this->modifyStudent->emailLineEdit->setText(student->getCorreoElectronico());


   this->modifyStudent->btnEdit = button;
   this->modifyStudent->studentToModify = student;

   if(this->modifyStudent->bandera == 0){
      QObject::connect(this->modifyStudent->cancel,SIGNAL(clicked(bool)),
                       this,SLOT(showStudentsAll()));
   }
   else
      QObject::connect(this->modifyStudent->cancel,SIGNAL(clicked(bool)),
                       this,SLOT(showStudents()));

}

void ControllerView::modifiedCalification()
{

   this->modifyCalification->btnAddCalification->setVisible(false);
   this->modifyCalification->btnOk->setVisible(true);
   view->setCurrentIndex(9);
   QPushButton* button = (QPushButton*)this->sender();
   const QPair<int,int>* data =  this->calificationsWidget->qMapEditCalification->find(button).value();

   Calification* calification = this->model->getMapCalificationAll().find(data->second).value();

   this->modifyCalification->idEvaluationLineEdit->setText(QString::number(calification->getIdEvaluation()));
   this->modifyCalification->idCalificationQLineEdit->setText(QString::number(calification->getIdCalification()));
   this->modifyCalification->idCalificationQLineEdit->setDisabled(true);
   this->modifyCalification->idCedulaQLineEdit->setText(QString::number(calification->getIdCed()));
   this->modifyCalification->idCourseLineEdit->setText(QString::number(calification->getIdCourse()));
   this->modifyCalification->calificationLineEdit->setText(QString::number(calification->getCalification()));
   this->modifyCalification->descriptionLineEdit->setText(calification->getObservation());


   this->modifyCalification->btnEdit = button;
   this->modifyCalification->calificationToModify = calification;

   if(this->modifyCalification->bandera == 0){
      QObject::connect(this->modifyCalification->btnCancel,SIGNAL(clicked(bool)),
                       this,SLOT(showCalificationsAll()));
   }
   else
      QObject::connect(this->modifyCalification->btnCancel,SIGNAL(clicked(bool)),
                       this,SLOT(showCalifications()));
}
void ControllerView::modifiedAssistance()
{
   this->modifyAssistance->btnAddAssistance->setVisible(false);
   this->modifyAssistance->selectStudentQLabel->setVisible(false);
   this->modifyAssistance->totalAssistanceQLabel->setVisible(true);
   this->modifyAssistance->qComboBoxStudent->setVisible(false);
   this->modifyAssistance->totalAssistanceQLabel->setVisible(true);
   this->modifyAssistance->totalAssistanceLineEdit->setVisible(false);
   this->modifyAssistance->btnOk->setVisible(true);
   view->setCurrentIndex(10);
   QPushButton* button = (QPushButton*)this->sender();
   const QPair<int,int>* data =  this->assistancesWidget->qMapEditAssistance->find(button).value();

   Assistance* assistance = this->model->getMapAssistanceAll().find(data->second).value();

   this->modifyAssistance->idAssistanceQLineEdit->setText(QString::number(assistance ->getIdAssistance()));
   //   this->modifyAssistance->totalAssistanceLineEdit->setText(QString::number(assistance ->getTotalAssistance()));
   this->modifyAssistance->idAssistanceQLineEdit->setDisabled(true);
   this->modifyAssistance->idCedulaQLineEdit->setText(QString::number(assistance ->getIdCed()));
   this->modifyAssistance->idCourseLineEdit->setText(QString::number(assistance ->getIdCourse()));
   this->modifyAssistance->porcentAssistanceLineEdit->setText(QString::number(assistance ->getPorcentAssistance()));
   this->modifyAssistance->fechaLineEdit->setText(assistance ->getFechaAssistance().toString("dd:MM:yyyy"));


   this->modifyAssistance->btnEdit = button;
   this->modifyAssistance->assistanceToModify = assistance ;

   if(this->modifyAssistance->bandera == 0){
      QObject::connect(this->modifyAssistance->btnCancel,SIGNAL(clicked(bool)),
                       this,SLOT(showAssistancesAll()));
   }
   else
      QObject::connect(this->modifyAssistance->btnCancel,SIGNAL(clicked(bool)),
                       this,SLOT(showAssistances()));
}

void ControllerView::modifyAssistanceInMemory()
{
   QPushButton* button=this->modifyAssistance->btnEdit;
   Assistance* assistance= this->modifyAssistance->assistanceToModify;
   const QPair<int,int>* data =  this->assistancesWidget->qMapEditAssistance->find(button).value();

   if(assistance->getIdAssistance() == this->modifyAssistance->idAssistanceQLineEdit->text().toInt())
   {

      int ass;
      if(this->modifyAssistance->assistanceQRadioButton->isChecked())
         ass = 1;
      else
         ass = 0;

      if( this->model->updateAssistance(this->modifyAssistance->idCourseLineEdit->text().toInt(),
                                        this->modifyAssistance->idCedulaQLineEdit->text().toInt(),
                                        QDateTime::fromString(this->modifyAssistance->fechaLineEdit->text(),"dd:MM:yyyy"),
                                        ass,
                                        this->modifyAssistance->porcentAssistanceLineEdit->text().toInt(),
                                        this->modifyAssistance->idAssistanceQLineEdit->text().toInt()))
      {
         if(this->modifyAssistance->bandera == 0)
            emit(signalShowAssistancesModifiedAll());
         else
            emit(signalShowAssistancesModifiedCourse());
      }//aqui me falta un else por si retorna que no lo agrega
      else
      {
         QMessageBox::information(this->modifyAssistance->btnOk,"Warning","Assistance was not modified");
      }

   }

   return;
}

void ControllerView::modifyCalificationInMemory()
{
   QPushButton* button=this->modifyCalification->btnEdit;
   Calification* calification= this->modifyCalification->calificationToModify;
   const QPair<int,int>* data =  this->calificationsWidget->qMapEditCalification->find(button).value();

   if(calification->getIdCalification() == this->modifyCalification->idCalificationQLineEdit->text().toInt())
   {

      if( this->model->updateCalification(this->modifyCalification->idEvaluationLineEdit->text().toInt(),
                                          this->modifyCalification->idCourseLineEdit->text().toInt(),
                                          this->modifyCalification->calificationLineEdit->text().toFloat(),
                                          this->modifyCalification->descriptionLineEdit->text(),
                                          this->modifyCalification->idCedulaQLineEdit->text().toInt(),
                                          this->modifyCalification->idCalificationQLineEdit->text().toInt()))
      {
         if(this->modifyEvaluation->bandera == 0)
            emit(signalShowCalificationsModifiedAll());
         else
            emit(signalShowCalificationsModifiedCourse());
      }//aqui me falta un else por si retorna que no lo agrega
      else
      {
         QMessageBox::information(this->modifyCalification->btnOk,"Warning","Calification was not modified");
      }

   }

   return;
}



void ControllerView::modifiyEvaluation()
{
   this->modifyEvaluation->btnAddEvaluationok->setVisible(false);
   this->modifyEvaluation->btnOk->setVisible(true);

   view->setCurrentIndex(8);
   QPushButton* button = (QPushButton*)this->sender();
   const QPair<int,int>* data =  this->evaluationsWidget->qMapEditEvaluaiton->find(button).value();

   Evaluation* evaluation = this->model->getMapEvaluationAll().find(data->second).value();

   this->modifyEvaluation->idEvaluationLineEdit->setText(QString::number(evaluation->getIdEvaluation()));
   this->modifyEvaluation->idEvaluationLineEdit->setDisabled(true);
   this->modifyEvaluation->idCourseLineEdit->setText(QString::number(evaluation->getIdCourse()));
   this->modifyEvaluation->portcentLineEdit->setText(QString::number(evaluation->getPorcent()));
   this->modifyEvaluation->descriptionLineEdit->setText(evaluation->getDescription());


   this->modifyEvaluation->btnEdit = button;
   this->modifyEvaluation->evaluationToModify = evaluation;

   if(this->modifyEvaluation->bandera == 0){
      QObject::connect(this->modifyEvaluation->btnCancel,SIGNAL(clicked(bool)),
                       this,SLOT(showEvaluationsAll()));
   }
   else
      QObject::connect(this->modifyEvaluation->btnCancel,SIGNAL(clicked(bool)),
                       this,SLOT(showEvaluations()));

}

void ControllerView::modifyEvaluationInMemory()
{
   QPushButton* button=this->modifyEvaluation->btnEdit;
   Evaluation* evaluation = this->modifyEvaluation->evaluationToModify;
   const QPair<int,int>* data =  this->evaluationsWidget->qMapEditEvaluaiton->find(button).value();

   if(evaluation->getIdEvaluation() == this->modifyEvaluation->idEvaluationLineEdit->text().toInt())
   {

      if( this->model->updateEvaluation(this->modifyEvaluation->idEvaluationLineEdit->text().toInt(),
                                        this->modifyEvaluation->idCourseLineEdit->text().toInt(),
                                        this->modifyEvaluation->descriptionLineEdit->text(),
                                        this->modifyEvaluation->portcentLineEdit->text().toFloat()))
      {
         if(this->modifyEvaluation->bandera == 0)
            emit(signalShowEvaluaitonsModifiedAll());
         else
            emit(signalShowEvaluationsModifiedCourse());
      }//aqui me falta un else por si retorna que no lo agrega
      else
      {
         QMessageBox::information(this->modifyEvaluation->btnOk,"Warning","Evaluation was not modified");
      }

   }

   return;

}
void ControllerView::modifyStudentAllInMemory()
{
   QPushButton* button=this->modifyStudent->btnEdit;
   Student* student = this->modifyStudent->studentToModify;
   const QPair<int,int>* data =  this->studentsWidget->qMapEditStudent->find(button).value();

   if(student->getCedula() == this->modifyStudent->idCedLineEdit->text().toInt())
   {

      if( this->model->updateStudent(this->modifyStudent->nameLineEdit->text(),
                                     this->modifyStudent->lastNameLineEdit->text(),
                                     this->modifyStudent->idCedLineEdit->text().toInt(),
                                     this->modifyStudent->emailLineEdit->text()))
      {
         if(this->modifyStudent->bandera == 0)
            emit(signalShowStudentsModifiedAll());
         else
            emit(signalShowStudentsModifiedCourse());
      }//aqui me falta un else por si retorna que no lo agrega
      else
      {
         QMessageBox::information(this->modifyStudent->ok,"Warning","Student no modified");
      }

   }else if(!this->model->getMapStudentAll().contains(this->modifyStudent->idCedLineEdit->text().toInt()))
   {
      if(this->model->deleteStudent(student->getCedula()))
      {
         if(this->model->createStudent(this->modifyStudent->nameLineEdit->text(),
                                       this->modifyStudent->lastNameLineEdit->text(),
                                       this->modifyStudent->idCedLineEdit->text().toInt(),
                                       this->modifyStudent->emailLineEdit->text()))
         {
            if(this->modifyStudent->bandera == 0)
               emit(signalShowStudentsModifiedAll());
            else
               emit(signalShowStudentsModifiedCourse());
         }else
            QMessageBox::information(this->modifyStudent,"Warning","Student no modified");

      }
      return;
   }else
      QMessageBox::information(this->modifyStudent,"Warning","The id number: "+QString::number(student->getCedula())+
                               " can not be modified to: "+this->modifyStudent->idCedLineEdit->text()+
                               "because a student already exists with id number iqual to: "+
                               this->modifyStudent->idCedLineEdit->text()
                               );


   return;


}




void ControllerView::modifyOnlyCourse()
{
   this->modifyCourse->bandera = 1;
   this->modifyCourse->idCourseQLabel->setVisible(true);
this->modifyCourse->idCourseQLineEdit->setVisible(true);

   if(this->modifyCourse->bandera == 0){
      QObject::connect(this->modifyCourse->btnCancel,SIGNAL(clicked(bool)),
                       this,SLOT(showListCourses()));
   }else{
      QObject::connect(this->modifyCourse->btnCancel,SIGNAL(clicked(bool)),
                       this,SLOT(showCourse()));
   }


   this->modifyCourse->nameCourseQLineEdit->setText(this->model->getMapCourseAll().find(this->courseWidget->idCourse).value()->getNameCourse());
   this->modifyCourse->idCourseQLineEdit->setText(QString::number(this->courseWidget->idCourse));
   this->modifyCourse->idCourseQLineEdit->setDisabled(true);
   this->modifyCourse->btnOk->setVisible(true);
this->modifyCourse->btnOk->setVisible(false);

   view->setCurrentIndex(11);


}

void ControllerView::modifyCourseInMemory()
{

   this->model->updateCourse(this->courseWidget->idCourse,this->modifyCourse->nameCourseQLineEdit->text());
// this->qlistCourse->p.at(this->courseWidget->idCourse)->setText(this->modifyCourse->nameCourseQLineEdit->text());
// this->qlistCourse->qPushBCourses->clear();
//   this->qlistCourse->addButtons(this->model->getMapCourseAll());
   //aqui regresamos a showCourse

   QString idCourse = QString::number(this->courseWidget->idCourse);
   view->setWindowTitle(this->modifyCourse->nameCourseQLineEdit->text()+" idCourse:" + idCourse );
   this->modifyCourse->btnCourse->setText(this->modifyCourse->nameCourseQLineEdit->text());

   emit(signalShowModifiedCourse());
}


void ControllerView::showInit()
{
   view->setCurrentIndex(0);
}

void ControllerView::showCourse()
{
   QObject::connect(this->courseWidget->btnEvaluations,SIGNAL(released()),
                    this,SLOT(showEvaluations()));

   QObject::connect(this->courseWidget->btnStudents,SIGNAL(released()),
                    this,SLOT(showStudents()));

   QObject::connect(this->courseWidget->btnAssistances,SIGNAL(clicked(bool)),
                    this,SLOT(showAssistances()));

   QObject::connect(this->courseWidget->btnCalifications,SIGNAL(released()),
                    this,SLOT(showCalifications()));


   view->setCurrentIndex(2);
}

void ControllerView::showStudents()
{
   Course* course = this->model->getMapCourseAll().find(this->courseWidget->idCourse).value();
   QList<Student* >::iterator itStudent = course->getStudents().begin();

   int i = 0;
   int menor =0;

   this->modelStudentWidgetClear(); // clean model.

   this->studentsWidget->qMapDeleteStudent->clear();
   this->studentsWidget->qMapEditStudent->clear();
   while(itStudent != course->getStudents().end())
   {
      this->studentsWidget->model->setItem(i,0, new QStandardItem((*itStudent)->getNombre()));
      this->studentsWidget->model->setItem(i,1, new QStandardItem((*itStudent)->getApellido()));
      this->studentsWidget->model->setItem(i,2, new QStandardItem(QString::number((*itStudent)->getCedula())));
      this->studentsWidget->model->setItem(i,3, new QStandardItem((*itStudent)->getCorreoElectronico()));

      QPushButton * btnModified = new QPushButton("edit");
      QPushButton* btnDelete = new QPushButton("Delete");

      this->studentsWidget->qTableStudentView->setIndexWidget(this->studentsWidget->model->index(i,4),btnModified);
      this->studentsWidget->qTableStudentView->setIndexWidget(this->studentsWidget->model->index(i,5),btnDelete);

      /*Agrego en el mapa correspondiente para borrar o eliminar un estudiante*/

      this->studentsWidget->qMapDeleteStudent->insert(btnDelete,new QPair<int, int>(i,(*itStudent)->getCedula()));
      this->studentsWidget->qMapEditStudent->insert(btnModified,new QPair<int, int>(i,(*itStudent)->getCedula()));


      /*NOTA aqui va el connect para los botones edit y delete*/

      QObject::connect(btnModified,SIGNAL(clicked(bool)),this,SLOT(modifyStudentAll()));
      QObject::connect(btnDelete,SIGNAL(clicked(bool)),this,SLOT(deleteStudent()));


      /*Add to the size to the table of Students by column email*/
      if(menor <= (*itStudent)->getCorreoElectronico().size())
      {
         this->studentsWidget->qTableStudentView->setColumnWidth(3,(*itStudent)->getCorreoElectronico().size()*10);
         menor = (*itStudent)->getCorreoElectronico().size();
      }

      ++itStudent;
      i++;
   }
   /*Add to the size to the table of Students*/
   this->studentsWidget->qTableStudentView->setColumnWidth(0,100);
   this->studentsWidget->qTableStudentView->setColumnWidth(1,200);
   this->studentsWidget->qTableStudentView->setColumnWidth(2,150);

   QObject::connect(this->studentsWidget->btnBack,SIGNAL(released()),
                    this,SLOT(showCourse()));
   this->modifyStudent->bandera = 1;//emitir la se#al de mostrar los estudiantes de un curso.
   this->studentsWidget->bandera = 1;

   /*************************************************/

   QObject::connect(this->studentsWidget->btnAddStudent,SIGNAL(clicked(bool)),
                    this,SLOT(addStudent()));


   view->setCurrentIndex(3);
}


void ControllerView::showStudentsAll()
{
   int i = 0;
   int menor =0;


   this->modelStudentWidgetClear(); // clean model
   this->studentsWidget->qMapDeleteStudent->clear();
   this->studentsWidget->qMapEditStudent->clear();
   foreach (Student* itStudent, model->getMapStudentAll())
   {
      this->studentsWidget->model->setItem(i,0, new QStandardItem(itStudent->getNombre()));
      this->studentsWidget->model->setItem(i,1, new QStandardItem(itStudent->getApellido()));
      this->studentsWidget->model->setItem(i,2, new QStandardItem(QString::number(itStudent->getCedula())));
      this->studentsWidget->model->setItem(i,3, new QStandardItem(itStudent->getCorreoElectronico()));

      //      this->studentWidget->model->setItemtem(i,5, new QStandardItem(QPushButton p("df")));

      QPushButton * btnModified = new QPushButton("edit");
      QPushButton* btnDelete = new QPushButton("Delete");

      this->studentsWidget->qTableStudentView->setIndexWidget(this->studentsWidget->model->index(i,4),btnModified);
      this->studentsWidget->qTableStudentView->setIndexWidget(this->studentsWidget->model->index(i,5),btnDelete);

      /*Agrego en el mapa correspondiente para borrar o eliminar un estudiante*/

      this->studentsWidget->qMapDeleteStudent->insert(btnDelete,new QPair<int, int>(i,itStudent->getCedula()));
      this->studentsWidget->qMapEditStudent->insert(btnModified,new QPair<int, int>(i,itStudent->getCedula()));

      /*NOTA aqui va el connect para los botones edit y delete*/

      QObject::connect(btnModified,SIGNAL(clicked(bool)),this,SLOT(modifyStudentAll()));
      QObject::connect(btnDelete,SIGNAL(clicked(bool)),this,SLOT(deleteStudent()));

      /*Add to the size to the table of Students by column email*/
      if(menor <= itStudent->getCorreoElectronico().size())
      {
         this->studentsWidget->qTableStudentView->setColumnWidth(3,itStudent->getCorreoElectronico().size()*8);
         menor = itStudent->getCorreoElectronico().size();
      }

      i++;
   }
   QObject::connect(this->studentsWidget->btnBack,SIGNAL(released()),
                    this,SLOT(showInit()));
   this->modifyStudent->bandera = 0;//emitir la se#al de mostrar todos los estudiantes.
   this->studentsWidget->bandera = 0;


   /*************************************************/

   QObject::connect(this->studentsWidget->btnAddStudent,SIGNAL(clicked(bool)),
                    this,SLOT(addStudent()));

   view->setCurrentIndex(3);

}

void ControllerView::addStudent()
{

   this->modifyStudent->ok->setVisible(false);

   if(this->studentsWidget->bandera == 0){
      QObject::connect(this->modifyStudent->cancel,SIGNAL(clicked(bool)),
                       this,SLOT(showStudentsAll()));
   }else{
      QObject::connect(this->modifyStudent->cancel,SIGNAL(clicked(bool)),
                       this,SLOT(showStudents()));
   }
   //qDebug()<<this->modifyStudent->idCourse;

   ////this->modifyStudent-

   view->setCurrentIndex(7);
}

void ControllerView::addStudentOk()
{
   if(this->model->createStudent(this->modifyStudent->nameLineEdit->text(),
                                 this->modifyStudent->lastNameLineEdit->text(),
                                 this->modifyStudent->idCedLineEdit->text().toInt(),
                                 this->modifyStudent->emailLineEdit->text()))
   {

      if(this->studentsWidget->bandera == 0)
      {
         emit(signalShowStudentsModifiedAll());
      }else{

         this->model->addStudentToCourse(this->modifyStudent->idCedLineEdit->text().toInt(),this->courseWidget->idCourse);
         emit(signalShowStudentsModifiedCourse());

      }

   }

   else
      QMessageBox::information(this->modifyStudent->btnOkStudent,"Warning","Student can't be created because\n this student already exist \nwith that id:"+this->modifyStudent->idCedLineEdit->text());
}

void ControllerView::addAssistance()
{
   this->modifyAssistance->btnOk->setVisible(false);
   this->modifyAssistance->idAssistanceQLabel->setVisible(false);
   this->modifyAssistance->idAssistanceQLineEdit->setVisible(false);
   this->modifyAssistance->fechaQLabel->setVisible(false);
   this->modifyAssistance->fechaLineEdit->setVisible(false);
   this->modifyAssistance->selectStudentQLabel->setVisible(true);



   if(modifyAssistance->bandera == 0)
   {
      this->modifyAssistance->qComboBoxStudent->setVisible(false);
      this->modifyAssistance->selectStudentQLabel->setVisible(false);
      this->modifyAssistance->idAssistanceQLabel->setVisible(false);
      this->modifyAssistance->idAssistanceQLineEdit->setVisible(false);
      this->modifyAssistance->idCedulaQLabel->setVisible(true);
      this->modifyAssistance->idCedulaQLineEdit->setVisible(true);
      this->modifyAssistance->totalAssistanceLineEdit->setVisible(false);
      this->modifyAssistance->btnAddAssistance->setVisible(true);

      QObject::connect(this->modifyAssistance->btnCancel,SIGNAL(clicked(bool)),
                       this,SLOT(showAssistancesAll()));
   }else
   {
      QObject::connect(this->modifyAssistance->btnCancel,SIGNAL(clicked(bool)),
                       this,SLOT(showAssistances()));
      this->modifyAssistance->totalAssistanceLineEdit->setVisible(false);
      this->modifyAssistance->qComboBoxStudent->setVisible(true);
      this->modifyAssistance->idAssistanceQLabel->setVisible(false);
      this->modifyAssistance->idAssistanceQLineEdit->setVisible(false);
      this->modifyAssistance->idCedulaQLabel->setVisible(false);
      this->modifyAssistance->idCedulaQLineEdit->setVisible(false);
      this->modifyAssistance->btnAddAssistance->setVisible(true);
      this->modifyAssistance->qComboBoxStudent->clear();
      QList<Student*> student = this->model->readStudentsByIdCourse(this->courseWidget->idCourse);

      foreach (Student* stu, student)
      {
         this->modifyAssistance->qComboBoxStudent->addItem(QString::number(stu->getCedula()));
      }

      this->modifyAssistance->idCourseLineEdit->setText(QString::number(this->courseWidget->idCourse));
      this->modifyAssistance->idCourseLineEdit->setDisabled(true);
   }

   view->setCurrentIndex(10);
}

void ControllerView::addAssistanceOk()
{
   if(modifyAssistance->bandera == 0)
   {
      int ass;
      if(this->modifyAssistance->assistanceQRadioButton->isChecked())
         ass = 1;
      else
         ass = 0;

      if(this->model->createAssistance(this->modifyAssistance->idCourseLineEdit->text().toInt(),
                                       this->modifyAssistance->qComboBoxStudent->currentText().toInt(),//revisar bien esto
                                       QDateTime::currentDateTime(),
                                       ass,
                                       this->modifyAssistance->porcentAssistanceLineEdit->text().toInt()
                                       ))

      {

         //         if(this->modifyAssistance->bandera == 0)
         emit(signalShowAssistancesModifiedAll());
         //         else
         //            emit(signalShowAssistancesModifiedCourse());
      }
      else
         QMessageBox::information(this->modifyAssistance->btnAddAssistance,"Warning","Assistance can't be created because\n this student already exist \n with that id:"+this->modifyAssistance->idAssistanceQLineEdit->text());
   }else
   {

      int ass;
      if(this->modifyAssistance->assistanceQRadioButton->isChecked())
         ass = 1;
      else
         ass = 0;

      if(this->model->createAssistance(this->modifyAssistance->idCourseLineEdit->text().toInt(),
                                       this->modifyAssistance->qComboBoxStudent->currentText().toInt(),
                                       QDateTime::currentDateTime(),
                                       ass,
                                       this->modifyAssistance->porcentAssistanceLineEdit->text().toInt()
                                       ))
      {
         this->model->addAssistanceToCourse(this->modifyAssistance->idCourseLineEdit->text().toInt(), this->modifyAssistance->qComboBoxStudent->currentText().toInt(),this->model->getMapAssistanceAll().last()->getIdAssistance());
         emit(signalShowAssistancesModifiedCourse());
      }
      else
         QMessageBox::information(this->modifyAssistance->btnAddAssistance,"Warning","Assistance can't be created because\n this student already exist \n with that id:"+this->modifyAssistance->idAssistanceQLineEdit->text());

   }
}

void ControllerView::addEvaluation()
{
   this->modifyEvaluation->btnOk->setVisible(false);
   this->modifyEvaluation->btnAddEvaluationok->setVisible(true);
   this->modifyEvaluation->idEvaluationQLabel->setVisible(false);
   this->modifyEvaluation->idEvaluationLineEdit->setVisible(false);

   if(this->modifyEvaluation->bandera == 1){
      this->modifyEvaluation->idCourseLineEdit->setText(QString::number(this->courseWidget->idCourse));
      this->modifyEvaluation->idCourseLineEdit->setDisabled(true);
      this->modifyEvaluation->idCourseQLabel->setDisabled(true);
      QObject::connect(this->modifyEvaluation->btnCancel,SIGNAL(clicked(bool)),
                       this,SLOT(showEvaluations()));
   }
   else{
      this->modifyEvaluation->idCourseLineEdit->setDisabled(false);
      this->modifyEvaluation->idCourseQLabel->setDisabled(false);
      QObject::connect(this->modifyEvaluation->btnCancel,SIGNAL(clicked(bool)),
                       this,SLOT(showEvaluationsAll()));

   }


   view->setCurrentIndex(8);
}

void ControllerView::addEvaluationOk()
{
   if(this->modifyEvaluation->bandera == 0)
   {
      if(this->model->createEvaluation(this->modifyEvaluation->idCourseLineEdit->text().toInt(),
                                       this->modifyEvaluation->descriptionLineEdit->text(),
                                       this->modifyEvaluation->portcentLineEdit->text().toFloat()))

      {
         //      if(this->modifyEvaluation->bandera == 0)
         emit(signalShowEvaluaitonsModifiedAll());
         //      else
         //         emit(signalShowEvaluationsModifiedCourse());
      }
      else
         QMessageBox::information(this->modifyEvaluation->btnAddEvaluationok,"Warning","Evaluation can't be created because\n this evaluation already exist \n with that id:"+this->modifyEvaluation->idEvaluationLineEdit->text());
   }else
   {
      if(this->model->createEvaluation(this->modifyEvaluation->idCourseLineEdit->text().toInt(),
                                       this->modifyEvaluation->descriptionLineEdit->text(),
                                       this->modifyEvaluation->portcentLineEdit->text().toFloat()))

      {
         //      if(this->modifyEvaluation->bandera == 0)
         //            emit(signalShowEvaluaitonsModifiedAll());
         //      else

         this->model->addEvaluationToCourse(model->getMapEvaluationAll().last()->getIdEvaluation(),this->modifyEvaluation->idCourseLineEdit->text().toInt());
         emit(signalShowEvaluationsModifiedCourse());
      }
      else
         QMessageBox::information(this->modifyEvaluation->btnAddEvaluationok,"Warning","Evaluation can't be created because\n this student already exist \n with that id:"+this->modifyEvaluation->idEvaluationLineEdit->text());


   }
}

void ControllerView::addCalification()
{

   this->modifyCalification->btnOk->setVisible(false);
   this->modifyCalification->idCalificationQLabel->setVisible(false);
   this->modifyCalification->idCalificationQLineEdit->setVisible(false);



   if(this->modifyCalification->bandera == 0)
   {
      this->modifyCalification->selectEvaluationQComboBox->setVisible(false);
      this->modifyCalification->selectEvaluationQLabel->setVisible(false);
      this->modifyCalification->selectStudentComboBox->setVisible(false);
      this->modifyCalification->selectStudentQLabel->setVisible(false);

      QObject::connect(this->modifyCalification->btnCancel,SIGNAL(clicked(bool)),
                       this,SLOT(showCalificationsAll()));
   }else
   {
      QObject::connect(this->modifyCalification->btnCancel,SIGNAL(clicked(bool)),
                       this,SLOT(showCalifications()));

      this->modifyCalification->selectEvaluationQComboBox->setVisible(true);
      this->modifyCalification->selectEvaluationQLabel->setVisible(true);
      this->modifyCalification->selectStudentComboBox->setVisible(true);
      this->modifyCalification->selectStudentQLabel->setVisible(true);
      this->modifyCalification->idCourseLineEdit->setText(QString::number(this->courseWidget->idCourse));
      this->modifyCalification->idCourseLineEdit->setDisabled(true);
      this->modifyCalification->idEvaluationLineEdit->setVisible(false);
      this->modifyCalification->idEvaluationQLabel->setVisible(false);
      this->modifyCalification->idCedulaQLabel->setVisible(false);
      this->modifyCalification->idCedulaQLineEdit->setVisible(false);

      // y falta el de evaluation
      QList<Student*> student = this->model->readStudentsByIdCourse(this->courseWidget->idCourse);
      QList<Evaluation*> evaluation = this->model->readEvaluationsByIdCourse(this->courseWidget->idCourse);
      foreach (Student* stu, student)
      {
         this->modifyCalification->selectStudentComboBox->addItem(QString::number(stu->getCedula()));
      }

      this->modifyCalification->selectEvaluationQComboBox->clear();
      this->modifyCalification->selectStudentComboBox->clear();
      foreach (Evaluation* eva, evaluation)
      {
         this->modifyCalification->selectEvaluationQComboBox->addItem(QString::number(eva->getIdEvaluation()));
      }

      foreach (Student* stu, student)
      {
         this->modifyCalification->selectStudentComboBox->addItem(QString::number(stu->getCedula()));
      }

   }

   view->setCurrentIndex(9);
}

void ControllerView::addCalificationOk()
{



   if(modifyCalification->bandera == 0)
   {
      if(this->model->createCalification(this->modifyCalification->idEvaluationLineEdit->text().toInt(),
                                         this->modifyCalification->idCourseLineEdit->text().toInt(),
                                         this->modifyCalification->calificationLineEdit->text().toFloat(),
                                         this->modifyCalification->descriptionLineEdit->text(),
                                         this->modifyCalification->idCedulaQLineEdit->text().toInt()
                                         ))
      {

         emit(signalShowCalificationsModifiedAll());
      }
      else
         QMessageBox::information(this->modifyCalification->btnAddCalification,"Warning","Calification can't be created because\n this student already exist \n with that id:"+this->modifyCalification->idCalificationQLineEdit->text());
   }else
   {
      if(this->model->createCalification(this->modifyCalification->selectEvaluationQComboBox->currentText().toInt(),
                                         this->modifyCalification->idCourseLineEdit->text().toInt(),
                                         this->modifyCalification->calificationLineEdit->text().toFloat(),
                                         this->modifyCalification->descriptionLineEdit->text(),
                                         this->modifyCalification->selectStudentComboBox->currentText().toInt()
                                         ))
      {
         emit(signalShowCalificationsModifiedCourse());
         this->model->addCalificationToEvaluation(this->model->getMapCalificationAll().last()->getIdCalification(), this->modifyCalification->selectEvaluationQComboBox->currentText().toInt());
         //aqui creo q va la relacion entre Calification y estudent
      }
      else
         QMessageBox::information(this->modifyCalification->btnAddCalification,"Warning","Calification can't be created because\n this student already exist \n with that id:"+this->modifyCalification->idCalificationQLineEdit->text());

   }

}
void ControllerView::showEvaluations()
{
   Course* course = this->model->getMapCourseAll().find(this->courseWidget->idCourse).value();
   QList<Evaluation* >::iterator itEvaluation = course->getEvaluations().begin();
   int i = 0;
   int menor =0;

   this->modelEvaluationWidgetClear(); // clan evaluatiosWidget's model

   while(itEvaluation != course->getEvaluations().end())
   {

      this->evaluationsWidget->model->setItem(i,0, new QStandardItem(QString::number((*itEvaluation)->getIdEvaluation())));
      this->evaluationsWidget->model->setItem(i,1, new QStandardItem(QString::number((*itEvaluation)->getIdCourse())));
      this->evaluationsWidget->model->setItem(i,2, new QStandardItem((*itEvaluation)->getDescription()));
      this->evaluationsWidget->model->setItem(i,3, new QStandardItem(QString::number((*itEvaluation)->getPorcent())));
      //      this->studentWidget->model->setItemtem(i,5, new QStandardItem(QPushButton p("df")));
      QPushButton * btnModified = new QPushButton("edit");
      QPushButton* btnDelete = new QPushButton("Delete");
      this->evaluationsWidget->qTableEvaluationView->setIndexWidget(this->evaluationsWidget->model->index(i,4),btnModified);
      this->evaluationsWidget->qTableEvaluationView->setIndexWidget(this->evaluationsWidget->model->index(i,5),btnDelete);

      /*NOTA aqui va el connect para los botones edit y delete*/
      /*Agrego en el mapa correspondiente para borrar o eliminar un estudiante*/

      this->evaluationsWidget->qMapDeleteEvaluation->insert(btnDelete,new QPair<int, int>(i,(*itEvaluation)->getIdEvaluation()));
      this->evaluationsWidget->qMapEditEvaluaiton->insert(btnModified,new QPair<int, int>(i,(*itEvaluation)->getIdEvaluation()));

      /*NOTA aqui va el connect para los botones edit y delete*/

      QObject::connect(btnModified,SIGNAL(clicked(bool)),this,SLOT(modifiyEvaluation()));
      QObject::connect(btnDelete,SIGNAL(clicked(bool)),this,SLOT(deleteEvaluation()));

      /*Add to the size to the table of Students by column email*/
      if(menor <= (*itEvaluation)->getDescription().size())
      {
         this->evaluationsWidget->qTableEvaluationView->setColumnWidth(2,(*itEvaluation)->getDescription().size()*8);
         menor = (*itEvaluation)->getDescription().size();
      }

      ++itEvaluation;
      i++;
   }
   /*Add to the size to the table of Students*/

   QObject::connect(this->evaluationsWidget->btnBack,SIGNAL(released()),
                    this,SLOT(showCourse()));

   this->modifyEvaluation->bandera = 1;///emitir la se#al de mostrar las Evaluations.
   this->studentsWidget->bandera = 1;

   /*************************************************/

   QObject::connect(this->evaluationsWidget->btnAddEvaluation,SIGNAL(clicked(bool)),
                    this,SLOT(addEvaluation()));

   view->setCurrentIndex(4);
}

void ControllerView::showEvaluationsAll()
{

   int i = 0;
   int menor =0;

   this->modelEvaluationWidgetClear(); // clan evaluatiosWidget's model

   foreach (Evaluation* evaluation, model->getMapEvaluationAll())
   {
      this->evaluationsWidget->model->setItem(i,0, new QStandardItem(QString::number(evaluation->getIdEvaluation())));
      this->evaluationsWidget->model->setItem(i,1, new QStandardItem(QString::number(evaluation->getIdCourse())));
      this->evaluationsWidget->model->setItem(i,2, new QStandardItem(evaluation->getDescription()));
      this->evaluationsWidget->model->setItem(i,3, new QStandardItem(QString::number(evaluation->getPorcent())));
      //      this->studentWidget->model->setItemtem(i,5, new QStandardItem(QPushButton p("df")));
      QPushButton * btnModified = new QPushButton("edit");
      QPushButton* btnDelete = new QPushButton("Delete");
      this->evaluationsWidget->qTableEvaluationView->setIndexWidget(this->evaluationsWidget->model->index(i,4),btnModified);
      this->evaluationsWidget->qTableEvaluationView->setIndexWidget(this->evaluationsWidget->model->index(i,5),btnDelete);

      /*NOTA aqui va el connect para los botones edit y delete*/
      /*Agrego en el mapa correspondiente para borrar o eliminar un estudiante*/

      this->evaluationsWidget->qMapDeleteEvaluation->insert(btnDelete,new QPair<int, int>(i,evaluation->getIdEvaluation()));
      this->evaluationsWidget->qMapEditEvaluaiton->insert(btnModified,new QPair<int, int>(i,evaluation->getIdEvaluation()));

      /*NOTA aqui va el connect para los botones edit y delete*/

      QObject::connect(btnModified,SIGNAL(clicked(bool)),this,SLOT(modifiyEvaluation()));
      QObject::connect(btnDelete,SIGNAL(clicked(bool)),this,SLOT(deleteEvaluation()));

      /*Add to the size to the table of Students by column email*/
      if(menor <= evaluation->getDescription().size())
      {
         this->evaluationsWidget->qTableEvaluationView->setColumnWidth(2,evaluation->getDescription().size()*8);
         menor = evaluation->getDescription().size();
      }

      i++;
   }

   QObject::connect(this->evaluationsWidget->btnBack,SIGNAL(released()),
                    this,SLOT(showInit()));
   this->modifyEvaluation->bandera = 0;//emitir la se#al de mostrar todos los evaluations.
   this->evaluationsWidget->bandera = 0;

   QObject::connect(this->evaluationsWidget->btnAddEvaluation,SIGNAL(clicked(bool)),
                    this,SLOT(addEvaluation()));

   view->setCurrentIndex(4);

}

void ControllerView::showAssistances()
{
   Course* course = this->model->readCourse(this->courseWidget->idCourse);
   QList<Assistance* >::iterator itAssistance= course->getAssistances().begin();
   int i = 0;


   this->modelAssistanceWidgetClear(); // clan assistanceWidget's model

   while(itAssistance != course->getAssistances().end())
   {

      this->assistancesWidget->model->setItem(i,0, new QStandardItem(QString::number((*itAssistance)->getIdAssistance())));
      this->assistancesWidget->model->setItem(i,1, new QStandardItem(QString::number((*itAssistance)->getIdCed())));
      this->assistancesWidget->model->setItem(i,2, new QStandardItem(QString::number((*itAssistance)->getIdCourse())));
      this->assistancesWidget->model->setItem(i,3, new QStandardItem((*itAssistance)->getFechaAssistance().toString("dd:MM:yyyy")));
      this->assistancesWidget->model->setItem(i,4, new QStandardItem(QString::number((*itAssistance)->getPorcentAssistance())));
      this->assistancesWidget->model->setItem(i,5, new QStandardItem(QString::number((*itAssistance)->getTotalAssistance())));
      //      this->studentWidget->model->setItemtem(i,5, new QStandardItem(QPushButton p("df")));
      QPushButton * btnModified = new QPushButton("edit");
      QPushButton* btnDelete = new QPushButton("Delete");
      this->assistancesWidget->qTableAssistancesView->setIndexWidget(this->assistancesWidget->model->index(i,6),btnModified);
      this->assistancesWidget->qTableAssistancesView->setIndexWidget(this->assistancesWidget->model->index(i,7),btnDelete);

      /*NOTA aqui va el connect para los botones edit y delete*/
      /*Agrego en el mapa correspondiente para borrar o eliminar un estudiante*/

      this->assistancesWidget->qMapDeleteAssistance->insert(btnDelete,new QPair<int, int>(i,(*itAssistance)->getIdAssistance()));
      this->assistancesWidget->qMapEditAssistance->insert(btnModified,new QPair<int, int>(i,(*itAssistance)->getIdAssistance()));


      /*NOTA aqui va el connect para los botones edit y delete*/

      QObject::connect(btnModified,SIGNAL(clicked(bool)),this,SLOT(modifiedAssistance()));
      QObject::connect(btnDelete,SIGNAL(clicked(bool)),this,SLOT(deleteAssistance()));

      ++itAssistance;
      i++;
   }
   /*Add to the size to the table of Students*/

   QObject::connect(this->assistancesWidget->btnBack,SIGNAL(released()),
                    this,SLOT(showCourse()));
   this->modifyAssistance->bandera = 1;//emitir la se#al de mostrar todos los evaluations.
   this->assistancesWidget->bandera =1;



   QObject::connect(this->assistancesWidget->btnAddAssistance,SIGNAL(clicked(bool)),
                    this,SLOT(addAssistance()));


   view->setCurrentIndex(5);
}

void ControllerView::showAssistancesAll()
{

   int i = 0;
   this->modelAssistanceWidgetClear(); // clan evaluatiosWidget's model

   foreach (Assistance* assistance, model->getMapAssistanceAll())
   {

      this->assistancesWidget->model->setItem(i,0, new QStandardItem(QString::number(assistance->getIdAssistance())));
      this->assistancesWidget->model->setItem(i,1, new QStandardItem(QString::number(assistance->getIdCed())));
      this->assistancesWidget->model->setItem(i,2, new QStandardItem(QString::number(assistance->getIdCourse())));
      this->assistancesWidget->model->setItem(i,3, new QStandardItem(assistance->getFechaAssistance().toString("dd:MM:yyyy")));
      this->assistancesWidget->model->setItem(i,4, new QStandardItem(QString::number(assistance->getPorcentAssistance())));
      this->assistancesWidget->model->setItem(i,5, new QStandardItem(QString::number(assistance->getTotalAssistance())));
      //      this->studentWidget->model->setItemtem(i,5, new QStandardItem(QPushButton p("df")));
      QPushButton * btnModified = new QPushButton("edit");
      QPushButton* btnDelete = new QPushButton("Delete");
      this->assistancesWidget->qTableAssistancesView->setIndexWidget(this->assistancesWidget->model->index(i,6),btnModified);
      this->assistancesWidget->qTableAssistancesView->setIndexWidget(this->assistancesWidget->model->index(i,7),btnDelete);

      /*NOTA aqui va el connect para los botones edit y delete*/
      /*Agrego en el mapa correspondiente para borrar o eliminar un estudiante*/

      this->assistancesWidget->qMapDeleteAssistance->insert(btnDelete,new QPair<int, int>(i,(assistance)->getIdAssistance()));
      this->assistancesWidget->qMapEditAssistance->insert(btnModified,new QPair<int, int>(i,(assistance)->getIdAssistance()));


      /*NOTA aqui va el connect para los botones edit y delete*/

      QObject::connect(btnModified,SIGNAL(clicked(bool)),this,SLOT(modifiedAssistance()));
      QObject::connect(btnDelete,SIGNAL(clicked(bool)),this,SLOT(deleteAssistance()));


      i++;
   }

   QObject::connect(this->assistancesWidget->btnBack,SIGNAL(released()),
                    this,SLOT(showInit()));
   this->modifyAssistance->bandera = 0;//emitir la se#al de mostrar todos los evaluations.
   this->assistancesWidget->bandera =0;//emitir la se#al de mostrar todos los evaluations.

   QObject::connect(this->assistancesWidget->btnAddAssistance,SIGNAL(clicked(bool)),
                    this,SLOT(addAssistance()));

   view->setCurrentIndex(5);
}

void ControllerView::showCalifications()
{

   int i = 0;

   this->modelCalificationWidgetClear(); // clan evaluatiosWidget's model
   const    QList<Calification* > & qListCalification = this->model->readCalificationsByIdCourse(this->courseWidget->idCourse);

   foreach(Calification* itCalification, qListCalification)
   {

      this->calificationsWidget->model->setItem(i,0, new QStandardItem(QString::number((itCalification)->getIdCalification())));
      this->calificationsWidget->model->setItem(i,1, new QStandardItem(QString::number((itCalification)->getIdCed())));
      this->calificationsWidget->model->setItem(i,2, new QStandardItem(QString::number((itCalification)->getIdCourse())));
      this->calificationsWidget->model->setItem(i,3, new QStandardItem(QString::number((itCalification)->getIdEvaluation())));
      this->calificationsWidget->model->setItem(i,4, new QStandardItem(QString::number((itCalification)->getCalification())));
      this->calificationsWidget->model->setItem(i,5, new QStandardItem((itCalification)->getObservation()));

      QPushButton * btnModified = new QPushButton("edit");
      QPushButton* btnDelete = new QPushButton("Delete");

      this->calificationsWidget->qTableCalificationsView->setIndexWidget(this->calificationsWidget->model->index(i,6),btnModified);
      this->calificationsWidget->qTableCalificationsView->setIndexWidget(this->calificationsWidget->model->index(i,7),btnDelete);

      /*NOTA aqui va el connect para los botones edit y delete*/
      /*Agrego en el mapa correspondiente para borrar o eliminar un estudiante*/

      this->calificationsWidget->qMapDeleteCalification->insert(btnDelete,new QPair<int, int>(i,(itCalification)->getIdCalification()));
      this->calificationsWidget->qMapEditCalification->insert(btnModified,new QPair<int, int>(i,(itCalification)->getIdCalification()));

      /*NOTA aqui va el connect para los botones edit y delete*/

      QObject::connect(btnModified,SIGNAL(clicked(bool)),this,SLOT(modifiedCalification()));
      QObject::connect(btnDelete,SIGNAL(clicked(bool)),this,SLOT(deleteCalification()));

      //      ++itCalification;
      i++;
   }
   /*Add to the size to the table of Students*/

   QObject::connect(this->calificationsWidget->btnBack,SIGNAL(released()),
                    this,SLOT(showCourse()));
   this->modifyCalification->bandera = 1;
   view->setCurrentIndex(6);
}

void ControllerView::showCalificationsAll()
{
   int i = 0;
   this->modelCalificationWidgetClear(); // clan evaluatiosWidget's model

   foreach (Calification* calification, model->getMapCalificationAll())
   {
      this->calificationsWidget->model->setItem(i,0, new QStandardItem(QString::number(calification->getIdCalification())));
      this->calificationsWidget->model->setItem(i,1, new QStandardItem(QString::number(calification->getIdCed())));
      this->calificationsWidget->model->setItem(i,2, new QStandardItem(QString::number(calification->getIdCourse())));
      this->calificationsWidget->model->setItem(i,3, new QStandardItem(QString::number(calification->getIdEvaluation())));
      this->calificationsWidget->model->setItem(i,4, new QStandardItem(QString::number(calification->getCalification())));
      this->calificationsWidget->model->setItem(i,5, new QStandardItem(calification->getObservation()));

      QPushButton * btnModified = new QPushButton("edit");
      QPushButton* btnDelete = new QPushButton("Delete");

      this->calificationsWidget->qTableCalificationsView->setIndexWidget(this->calificationsWidget->model->index(i,6),btnModified);
      this->calificationsWidget->qTableCalificationsView->setIndexWidget(this->calificationsWidget->model->index(i,7),btnDelete);

      /*NOTA aqui va el connect para los botones edit y delete*/
      /*Agrego en el mapa correspondiente para borrar o eliminar un estudiante*/

      this->calificationsWidget->qMapEditCalification->insert(btnModified,new QPair<int, int>(i,(calification)->getIdCalification()));
      this->calificationsWidget->qMapDeleteCalification->insert(btnDelete,new QPair<int, int>(i,(calification)->getIdCalification()));

      /*NOTA aqui va el connect para los botones edit y delete*/

      QObject::connect(btnModified,SIGNAL(clicked(bool)),this,SLOT(modifiedCalification()));
      QObject::connect(btnDelete,SIGNAL(clicked(bool)),this,SLOT(deleteCalification()));

      i++;
   }

   QObject::connect(this->calificationsWidget->btnBack,SIGNAL(released()),
                    this,SLOT(showInit()));
   this->modifyCalification->bandera = 0;


   QObject::connect(this->calificationsWidget->btnAddCalification,SIGNAL(clicked(bool)),
                    this,SLOT(addCalification()));

   view->setCurrentIndex(6);

}

void ControllerView::setControllerview(QStackedWidget* value)
{
   view = value;
}

QVBoxLayout* ControllerView::getLayoutWidgets() const
{
   return layoutWidgets;
}

void ControllerView::setLayoutWidgets(QVBoxLayout* value)
{
   layoutWidgets = value;
}

MainWidget* ControllerView::getMainwidget() const
{
   return mainwidget;
}

void ControllerView::setMainwidget(MainWidget* value)
{
   mainwidget = value;
}

QListCoursesWidget* ControllerView::getQlistCourse() const
{
   return qlistCourse;
}

void ControllerView::setQlistCourse(QListCoursesWidget* value)
{
   qlistCourse = value;
}

CoursesWidget* ControllerView::getCourseWidget() const
{
   return courseWidget;
}

void ControllerView::setCourseWidget(CoursesWidget* value)
{
   courseWidget = value;
}
