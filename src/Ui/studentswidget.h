#ifndef STUDENTSWIDGET_H
#define STUDENTSWIDGET_H

#include <QObject>
#include <QWidget>
#include <QTableView>
#include <QPushButton>
#include <QHBoxLayout>
#include <QStandardItemModel>
#include <QHeaderView>
#include "student.h"

class StudentsWidget : public QWidget
{
        Q_OBJECT
    public:

        QTableView* qTableStudentView;
        QStandardItemModel* model;
        int row;
        bool bandera;
        int idCourse;
        QVBoxLayout* qhLayout;
        QPushButton* btnBack;
        QPushButton* btnAddStudent;
        QPushButton* btnDeleteStudent;
        QPushButton* btnModifiedStudent;
        QMap<QPushButton*,QPair<int, int>* >* qMapDeleteStudent;
        QMap<QPushButton*,QPair<int, int>* >* qMapEditStudent;

        explicit StudentsWidget(const QMap<int, Student*>&,QWidget *parent = 0);

        ~StudentsWidget();

        void addBtnDeleteAndEdit(const QMap<int, Student*>& qmapStudent);

        QMap<QPushButton*, QPair<int, int>*>* getQMapDeleteStudent() const;
        void setQMapDeleteStudent(QMap<QPushButton*, QPair<int, int>*>* value);

        QMap<QPushButton*, QPair<int, int>*>* getQMapEditStudent() const;
        void setQMapEditStudent(QMap<QPushButton*, QPair<int, int>*>* value);

   signals:

   public slots:
};

#endif // STUDENTSWIDGET_H
