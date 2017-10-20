#ifndef CONTROLLERVIEW_H
#define CONTROLLERVIEW_H

#include <QObject>
#include <QWidget>
#include <QStackedWidget>
#include "coursewidget.h"
#include "mainwidget.h"
#include "qlistcourseswidget.h"
#include"model.h"
#include"studentswidget.h"
#include "evaluationswidget.h"
#include "evaluation.h"
#include "assistanceswidget.h"
#include "calificationswidget.h"
#include "modifystudent.h"
#include "modifyevaluation.h"
#include "modifycalification.h"
#include "modifyassistance.h"
#include "modifycoursee.h"
#include <QScrollArea>
#include "QMessageBox"

class ControllerView : public QObject
{
      Q_OBJECT


   private:// Data members

      Model* model;

      QStackedWidget* view;

      QVBoxLayout* layoutWidgets;

      QScrollArea* scroll;

      MainWidget* mainwidget;

      QListCoursesWidget* qlistCourse;

      CoursesWidget* courseWidget;

      StudentsWidget* studentsWidget;

      EvaluationsWidget* evaluationsWidget;

      AssistancesWidget* assistancesWidget;

      CalificationsWidget* calificationsWidget;

      ModifyCourse* modifyCourse;

      ModifyStudent* modifyStudent;

      ModifyEvaluation* modifyEvaluation;

      ModifyCalification* modifyCalification;

      ModifyAssistance* modifyAssistance;





   private: // internal methods

      void setControllerview(QStackedWidget* value);

      QVBoxLayout* getLayoutWidgets() const;
      void setLayoutWidgets(QVBoxLayout* value);

      MainWidget* getMainwidget() const;
      void setMainwidget(MainWidget* value);

      QListCoursesWidget* getQlistCourse() const;
      void setQlistCourse(QListCoursesWidget* value);

      CoursesWidget* getCourseWidget() const;
      void setCourseWidget(CoursesWidget* value);


   public: //methods

      ControllerView();

      ~ControllerView();

      QStackedWidget* getView() const;

      void modelStudentWidgetClear();

      void modelEvaluationWidgetClear();

      void modelAssistanceWidgetClear();

      void modelCalificationWidgetClear();


   signals:

      void signalShowStudentsModifiedAll();

      void signalShowStudentsModifiedCourse();

      void signalShowEvaluaitonsModifiedAll();

      void signalShowEvaluationsModifiedCourse();

      void signalShowCalificationsModifiedAll();

      void signalShowCalificationsModifiedCourse();

      void signalShowAssistancesModifiedAll();

      void signalShowAssistancesModifiedCourse();

       void signalShowModifiedCourse();

             void signalShowCreatedCourse();



   public slots:

      /*********************Show ALL*****************************/
      void showInit();

      void showListCourses();

      void showCourse();

      void showStudents();

      void showStudentsAll();

      void showEvaluations();

      void showEvaluationsAll();

      void showAssistances();

      void showAssistancesAll();

      void showCalifications();

      void showCalificationsAll();

      void showCourseQPushBWieget(QPushButton*);
      /****************create All************************/

      void addCourse();

      void addCourseOk();

      void addStudent();

      void addStudentOk();

      void addAssistance();

      void addAssistanceOk();

      void addEvaluation();

      void addEvaluationOk();

      void addCalification();

      void addCalificationOk();
      /***********************************************/
      void deleteStudent();

      void deleteEvaluation();

      void deleteCourse();

      void deleteCalification();

      void deleteAssistance();

      /******************************************/

      void modifiedCalification();

      void modifyCalificationInMemory();


      void modifiedAssistance();

      void modifyAssistanceInMemory();

      void  modifyStudentAll();

      void modifyStudentAllInMemory();

      void modifiyEvaluation();

      void modifyEvaluationInMemory();

      void modifyOnlyCourse();

      void modifyCourseInMemory();









};

#endif // CONTROLLERVIEW_H
