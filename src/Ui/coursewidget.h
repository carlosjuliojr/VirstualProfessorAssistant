#ifndef COURSEWIDGET_H
#define COURSEWIDGET_H

#include <QObject>
#include <QWidget>
#include<QPushButton>
#include <QTextEdit>
#include<QVBoxLayout>
#include<QtGui>
#include<QListView>

class CoursesWidget : public QWidget
{
      Q_OBJECT

    public:

      QGridLayout* qgridLayout;

      QPushButton* btnAssistances;

      QPushButton* btnStudents;

      QPushButton* btnEvaluations;

      QPushButton* btnCalifications;

      QPushButton* btnDeleteCourse;

      QPushButton* btnBack;

      QPushButton* btnEditCourse;


      int idCourse;


    CoursesWidget(QWidget* parent=0);
        ~CoursesWidget();

    public slots:

    signals:

};

#endif // COURSEWIDGET_H
