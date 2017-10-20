#ifndef CALIFICATIONSWIDGET_H
#define CALIFICATIONSWIDGET_H

#include <QObject>
#include <QWidget>
#include <QTableView>
#include <QPushButton>
#include <QHBoxLayout>
#include <QStandardItemModel>
#include <QHeaderView>

class CalificationsWidget : public QWidget
{
      Q_OBJECT
   public:

        QTableView* qTableCalificationsView;
        QStandardItemModel* model;
        int row;
        QVBoxLayout* qhLayout;
        QPushButton* btnBack;
        QPushButton* btnDeleteCalification;
        QPushButton* btnModifiedCalification;
        QPushButton* btnAddCalification;
        QMap<QPushButton*,QPair<int, int>* >* qMapDeleteCalification;
        QMap<QPushButton*,QPair<int, int>* >* qMapEditCalification;

      explicit CalificationsWidget(QWidget *parent = 0);
        ~CalificationsWidget();

   signals:

   public slots:
};

#endif // CALIFICATIONSWIDGET_H
