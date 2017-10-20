#include "studentswidget.h"


QMap<QPushButton*, QPair<int, int>*>* StudentsWidget::getQMapDeleteStudent() const
{
   return qMapDeleteStudent;
}

void StudentsWidget::setQMapDeleteStudent(QMap<QPushButton*, QPair<int, int>*>* value)
{
   qMapDeleteStudent = value;
}

QMap<QPushButton*, QPair<int, int>*>* StudentsWidget::getQMapEditStudent() const
{
   return qMapEditStudent;
}

void StudentsWidget::setQMapEditStudent(QMap<QPushButton*, QPair<int, int>*>* value)
{
   qMapEditStudent = value;
}

StudentsWidget::StudentsWidget(const QMap<int, Student*>& qmStudent,QWidget *parent):
   QWidget(parent),row(1)
{

   qTableStudentView = new QTableView(this);
   model = new QStandardItemModel(row,6,this);
   qhLayout = new QVBoxLayout(this);
   btnBack = new QPushButton("Back",this);
   btnBack->setFixedSize(100,30);
   btnDeleteStudent = new QPushButton("delete");
   btnModifiedStudent = new QPushButton("Modified");
   btnAddStudent = new QPushButton("AddStudent",this);
   qMapDeleteStudent = new QMap<QPushButton*, QPair<int,int>* >;
   qMapEditStudent = new QMap<QPushButton*, QPair<int,int>* >;

   model->setHorizontalHeaderItem(0,new QStandardItem(QString("Name")));
   model->setHorizontalHeaderItem(1,new QStandardItem(QString("Last Name")));
   model->setHorizontalHeaderItem(2,new QStandardItem(QString("# Identification")));
   model->setHorizontalHeaderItem(3,new QStandardItem(QString("Email")));
   model->setHorizontalHeaderItem(4, new QStandardItem(QString("Modified")));
   model->setHorizontalHeaderItem(5, new QStandardItem(QString("Delete")));


   qTableStudentView->setModel(model);
   qhLayout->addWidget(btnBack);
   qhLayout->addWidget(btnAddStudent);
   qhLayout->addWidget(qTableStudentView);
   this->setLayout(qhLayout);
}

StudentsWidget::~StudentsWidget()
{
   delete qTableStudentView;
   delete model;
   delete btnDeleteStudent;
   delete btnModifiedStudent;
   delete qhLayout;
   delete btnBack;
   delete btnAddStudent;
}

void StudentsWidget::addBtnDeleteAndEdit(const QMap<int, Student*>& qmapStudent)
{

   /*
       * Este if se usa para no volver a crear news botones e insertar en el mapa ya que
       * solo se debe crear el nuevoo boton si y solo si el course es new.
       *
       * */


//   if(qPushBCourses->size() > 0)//es porque si existe un boton no podemos volver a crearlo
//   {
//      foreach (Course* course , qmapCourse)
//      {

//         QMap<QPushButton*, Course*>::iterator itqmButton = qPushBCourses->begin();
//         while( itqmButton != qPushBCourses->end()) {

//            if((*itqmButton)->getIdCourse() != course->getIdCourse())
//            {
//               QPushButton *b = new QPushButton(course->getNameCourse(),this);
//               p.insert(course->getIdCourse(),b);
//               this->qPushBCourses->insert(b,course);
//               QObject::connect(b, SIGNAL(clicked(bool)),
//                                this, SLOT(pointerwindowCourse()));
//               l->addWidget(b);

//               itqmButton++;
//            }else
//               itqmButton++;
//         }



//      }
//   }else
//   {
//      foreach (Course* course, qmapCourse)
//      {


//         QPushButton *b = new QPushButton(course->getNameCourse(),this);
//         p.insert(course->getIdCourse(),b);
//         this->qPushBCourses->insert(b,course);
//         QObject::connect(b, SIGNAL(clicked(bool)),
//                          this, SLOT(pointerwindowCourse()));
//         l->addWidget(b);

//      }
//   }

}
