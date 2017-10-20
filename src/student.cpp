#include "student.h"
#include"course.h"
#include"databasestructs.h"

Student::Student()
{

}

Student::Student(QString nombre, QString apellido, int cedula, QString correoElectronico):
                 Person(nombre, apellido, cedula, correoElectronico)
{

}

QList<Course*> & Student::getCourses()
{
   return courses;
}

void Student::setCourses(const QList<Course*>& value)
{
   courses = value;
}

void Student::addCourseOnly(Course* course)
{
   this->courses.append(course);
}

Student& Student::operator =(const typePersonRegister& usuario)
{
   this->setNombre(usuario.nombre);
   this->setApellido(usuario.apellido);
   this->setCedula(usuario.cedula);
   this->setCorreoElectronico(usuario.correoElectronico);

   return *this;
}
