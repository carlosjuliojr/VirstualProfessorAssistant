#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QObject>
#include<QWidget>
#include<QVBoxLayout>
#include<QPushButton>
#include<QListView>

class MainWidget : public QWidget
{
      Q_OBJECT



   public:

      QVBoxLayout* qvLayout;

      QPushButton* btnCourses;

      QPushButton* btnStudents;

      QPushButton* btnEvaluations;

      QPushButton* btnAssistances;

      QPushButton* btnCalifications;




      explicit MainWidget(QWidget *parent = 0);
      ~MainWidget();

      QPushButton* getBtnCourses() const;
      void setBtnCourses(QPushButton* value);

      QPushButton* getBtnStudents() const;
      void setBtnStudents(QPushButton* value);

      QPushButton* getBtnEvaluations() const;
      void setBtnEvaluations(QPushButton* value);

      QPushButton* getBtnAssistances() const;
      void setBtnAssistances(QPushButton* value);

      QPushButton* getBtnCalifications() const;
      void setBtnCalifications(QPushButton* value);

   signals:

   public slots:
};

#endif // MAINWIDGET_H
