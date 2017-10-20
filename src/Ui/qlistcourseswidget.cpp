#include "qlistcourseswidget.h"

QListCoursesWidget::QListCoursesWidget(const QMap<int, Course* > & qmCourse,QWidget* parent):
   QWidget(parent)
{

   l = new QVBoxLayout(this);
   btnBack = new QPushButton("Back",this);
   btnAddCourse = new QPushButton("AddCourse",this);
   qPushBCourses = new QMap<QPushButton*, Course*>;

   l->addWidget(btnBack);
   l->addWidget(btnAddCourse);
   this->addButtons(qmCourse);


   this->setLayout(l);
}

QMap<QPushButton*, Course*>* QListCoursesWidget::getQPushBCourses() const
{
   return qPushBCourses;
}

void QListCoursesWidget::setQPushBCourses(QMap<QPushButton*, Course*>* value)
{
   qPushBCourses = value;
}

void QListCoursesWidget::addButtons(const QMap<int, Course*>& qmapCourse)
{

   /*
    * Este if se usa para no volver a crear news botones e insertar en el mapa ya que
    * solo se debe crear el nuevoo boton si y solo si el course es new.
    *
    * */

   if(qPushBCourses->size() > 0)//es porque si existe un boton no podemos volver a crearlo
   {


//      QMap<QPushButton*, Course*>::iterator itqmButton = qPushBCourses->begin();
//      while( itqmButton != qPushBCourses->end()) {

//            QPushButton *b = itqmButton.key();
////            p.erase(course->getIdCourse(),b);
//            itqmButton = this->qPushBCourses->erase(itqmButton);
//            delete b;
//      }




      foreach (Course* course , qmapCourse)
      {

         QMap<QPushButton*, Course*>::iterator itqmButton = qPushBCourses->begin();
         while( itqmButton != qPushBCourses->end()) {

            if((*itqmButton)->getIdCourse() != course->getIdCourse())
            {
               QPushButton *b = new QPushButton(course->getNameCourse(),this);
//                 b->setFixedSize(100,40);
               p.insert(course->getIdCourse(),b);
               this->qPushBCourses->insert(b,course);
               QObject::connect(b, SIGNAL(clicked(bool)),
                                this, SLOT(pointerwindowCourse()));
               l->addWidget(b);

               itqmButton++;
            }else
               itqmButton++;
         }



      }

   }else
   {
      foreach (Course* course, qmapCourse)
      {


      QPushButton *b = new QPushButton(course->getNameCourse(),this);
//      b->setFixedSize(100,40);
      p.insert(course->getIdCourse(),b);
      this->qPushBCourses->insert(b,course);
      QObject::connect(b, SIGNAL(clicked(bool)),
                       this, SLOT(pointerwindowCourse()));
       l->addWidget(b);

      }
   }
}

void QListCoursesWidget::signalEmit()
{
   emit signalCourseWindows();
}

void QListCoursesWidget::newPruebaWidgetCourse(/*Course* course*/)
{
   CoursesWidget* courseWidget = new CoursesWidget(this) ;
   courseWidget->show();
}

void QListCoursesWidget::pointerwindowCourse()
{
   emit(clickedSignalButton((QPushButton*)this->sender()));
}



QListCoursesWidget::~QListCoursesWidget()
{
   delete btnBack;
   delete qPushBCourses;
}
