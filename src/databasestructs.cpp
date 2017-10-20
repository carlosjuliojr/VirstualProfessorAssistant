#include "databasestructs.h"
#include "assistance.h"
#include "calification.h"
#include "evaluation.h"
#include "student.h"
#include "course.h"

typeAssistanceRegister& typeAssistanceRegister::operator = (const Assistance& assistance)
{
   this->idAssistance = assistance.getIdAssistance();
   this->idCed = assistance.getIdCed();
   this->idCourse = assistance.getIdCourse();
   strcpy(this->fechaAssistance,assistance.getFechaAssistance().toString("yyyy:MM:dd").toStdString().c_str());
   this->totalAssistance = assistance.getTotalAssistance();
   this->porcentAssistance = assistance.getPorcentAssistance();
   return (*this);
}

typePersonRegister&typePersonRegister::operator =(const Student& student)
{
   strcpy(this->nombre,student.getNombre().toStdString().c_str());
   strcpy(this->apellido, student.getApellido().toStdString().c_str());
   strcpy(this->correoElectronico, student.getCorreoElectronico().toStdString().c_str());
   this->cedula = student.getCedula();
   return (*this);
}

typeCalificationRegister&typeCalificationRegister::operator=(const Calification& calification)
{
   this->idCalification = calification.getIdCalification();
   this->idCed = calification.getIdCed();
   this->idCourse = calification.getIdCourse();
   this->idEvaluation = calification.getIdEvaluation();
   this->calification = calification.getCalification();
   strcpy(this->observation, calification.getObservation().toStdString().c_str());
   return (*this);
}

typeEvaluationRegister&typeEvaluationRegister::operator=(const Evaluation& evaluation)
{
   this->idCourse = evaluation.getIdCourse();
   this->idEvaluation =evaluation.getIdEvaluation();
   strcpy(this->description, evaluation.getDescription().toStdString().c_str());
   this->porcent = evaluation.getPorcent();
   return (*this);
}

typeCourseRegister&typeCourseRegister::operator=(const Course& course)
{
   this->idCourse = course.getIdCourse();
   strcpy(this->nameCourse, course.getNameCourse().toStdString().c_str());
   return(*this);
}
