#ifndef QLISTCOURSESWIDGET_H
#define QLISTCOURSESWIDGET_H
#include <QObject>
#include <QWidget>
#include<QPushButton>
#include <QTextEdit>
#include<QVBoxLayout>
#include<QtGui>
#include<QListView>
#include<QMap>
#include"model.h"
#include"coursewidget.h"

/**
 * @brief The QListCoursesWidget class
 */

class QListCoursesWidget : public QWidget
{
      Q_OBJECT

   public:

      QPushButton* btnBack;
      int nroCourse;
      QVBoxLayout *l;
      QList<QPushButton*> p;
      int bandera;
      QPushButton* btnAddCourse;
      QMap<QPushButton*, Course*> *qPushBCourses;

      QListCoursesWidget(const QMap<int, Course* > &,QWidget* parent=0);
      ~QListCoursesWidget();

      QMap<QPushButton*, Course*>* getQPushBCourses() const;
      void setQPushBCourses(QMap<QPushButton*, Course*>* value);

      void addButtons(const QMap<int, Course*> & qmapPushButton);

   public slots:
      void signalEmit();


      void newPruebaWidgetCourse(/*Course* course*/);
      void pointerwindowCourse() ;

   signals:
      void clickedSignal(QWidget*);
      void clickedSignalButton(QPushButton*);
      void signalCourseWindows(/*Course * course*/);

};

#endif // QLISTCOURSESWIDGET_H
