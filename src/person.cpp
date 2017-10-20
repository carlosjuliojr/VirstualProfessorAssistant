/**
  *
  *
  */

#include "person.h"

QString Person::getCorreoElectronico() const
{
   return correoElectronico;
}

void Person::setCorreoElectronico(const QString& value)
{
   correoElectronico = value;
}


Person::Person() :nombre(""), apellido(""), cedula(-1), correoElectronico("")
{
    
}

Person::Person(const Person& p)
{
   nombre = p.getNombre();
   apellido = p.getApellido();
   cedula = p.cedula;
   correoElectronico = p.getCorreoElectronico();
}

Person::Person(QString n, QString ap, int ced, QString email):
   nombre(n), apellido(ap), cedula(ced), correoElectronico(email)
{

}

Person::~Person()
{

}

void Person::setApellido(const QString& value)
{
   apellido = value;
}

int Person::getCedula() const
{
   return cedula;
}



void Person::setCedula(int value)
{
   cedula = value;
}



QString Person::getNombre() const
{
   return nombre;
}

QString Person::getApellido() const
{
   return apellido;
}

void Person::setNombre(const QString& value)
{
   nombre = value;
}

void Person::agregarPersona()
{

}

