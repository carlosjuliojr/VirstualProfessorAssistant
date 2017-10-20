#ifndef ASSISTANCESWIDGET_H
#define ASSISTANCESWIDGET_H

#include <QObject>
#include <QWidget>
#include <QTableView>
#include <QPushButton>
#include <QHBoxLayout>
#include <QStandardItemModel>
#include <QHeaderView>

class AssistancesWidget : public QWidget
{
      Q_OBJECT
   public:

        QTableView* qTableAssistancesView;
        QStandardItemModel* model;
        int row;
        int bandera;
        QVBoxLayout* qhLayout;
        QPushButton* btnBack;
        QPushButton* btnAddAssistance;
        QPushButton* btnDeleteAssistance;
        QPushButton* btnModifiedAssistance;
        QMap<QPushButton*,QPair<int, int>* >* qMapDeleteAssistance;
        QMap<QPushButton*,QPair<int, int>* >* qMapEditAssistance;

      explicit AssistancesWidget(QWidget *parent = 0);
        ~AssistancesWidget();

   signals:

   public slots:
};

#endif // ASSISTANCESWIDGET_H
