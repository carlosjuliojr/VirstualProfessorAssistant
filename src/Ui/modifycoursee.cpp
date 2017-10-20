#include "modifycoursee.h"

ModifyCourse::ModifyCourse(QWidget *parent) : QWidget(parent)
{

     nameCourseQLabel = new QLabel("Name",this);
     nameCourseQLineEdit = new QLineEdit(this);

     idCourseQLabel = new QLabel ("idCourse",this);
     idCourseQLineEdit = new QLineEdit(this);

     btnCancel = new QPushButton("Cancel",this);
     btnOk = new QPushButton("Ok",this);
     btnCourse = new QPushButton("Ok",this);


//     QPixmap pixmapBack("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/images/ic_skip_previous_black_24dp.png");
//     QIcon ButtonIconBack(pixmapBack);

//     QPixmap pixmapOk("/home/julio/Descargas/check-symbol.png");
//     QIcon ButtonIconOk(pixmapBack);

//     btnCancel->setIcon(ButtonIconBack);
//     btnCancel->setIconSize(pixmapBack.rect().size());

//     btnOk->setIcon(ButtonIconOk);
//     btnOk->setIconSize(pixmapOk.rect().size());

     qgLayout = new QGridLayout(this);

     qgLayout->addWidget(nameCourseQLabel,0,0);
     qgLayout->addWidget(nameCourseQLineEdit,0,1);
     qgLayout->addWidget(idCourseQLabel,1,0);
     qgLayout->addWidget(idCourseQLineEdit,1,1);

     qgLayout->addWidget(btnCancel,2,0);
     qgLayout->addWidget(btnOk,2,1);
     qgLayout->addWidget(btnCourse,2,2);

     this->setLayout(qgLayout);

}

ModifyCourse::~ModifyCourse()
{
    delete nameCourseQLabel;
    delete nameCourseQLineEdit;

    delete idCourseQLabel;
    delete idCourseQLineEdit ;

    delete qgLayout;
}
