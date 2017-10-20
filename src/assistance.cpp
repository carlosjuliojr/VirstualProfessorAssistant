#include"../include/assistance.h"
#include"databasestructs.h"


/**
 * @brief Assistancce::getIdAssistance
 * @return
 */
unsigned int Assistance::getIdCed() const
{
   return idCed;
}

void Assistance::setIdCed(unsigned int value)
{
   idCed = value;
}

QDateTime Assistance::getFechaAssistance() const
{
   return fechaAssistance;
}

void Assistance::setFechaAssistance(const QDateTime& value)
{
   fechaAssistance = value;
}

unsigned int Assistance::getTotalAssistance() const
{
   return totalAssistance;
}

void Assistance::setTotalAssistance(unsigned int value)
{
   totalAssistance = value;
}

unsigned int Assistance::getPorcentAssistance() const
{
   return porcentAssistance;
}

void Assistance::setPorcentAssistance(unsigned int value)
{
   porcentAssistance = value;
}

Assistance&Assistance::operator =(const typeAssistanceRegister& assistance)
{
   this->setIdCourse(assistance.idCourse);
   this->setIdCed(assistance.idCed);
   this->setTotalAssistance(assistance.totalAssistance);
   this->setFechaAssistance(QDateTime::fromString(assistance.fechaAssistance,"yyyy:MM:dd"));
   this->setPorcentAssistance(assistance.porcentAssistance);
   this->setIdAssistance(assistance.idAssistance);

   return (*this);

}

unsigned int Assistance::getIdCourse() const
{
   return idCourse;
}

void Assistance::setIdCourse(unsigned int value)
{
   idCourse = value;
}

unsigned int Assistance::getIdAssistance() const
{
   return idAssistance;
}

void Assistance::setIdAssistance(unsigned int value)
{
   idAssistance = value;
}

Assistance::Assistance(): idCourse(0),
   idCed(0),
   fechaAssistance(QDateTime::fromString("0000:00:00","yyyy:MM:dd")),
   totalAssistance(0),
   porcentAssistance(0),
   idAssistance(0)
{

}

Assistance::Assistance(const Assistance &a)
{
   idCourse = a.getIdCourse();
   idCed = a. getIdCed();
   fechaAssistance = a.getFechaAssistance();
   totalAssistance = a.getTotalAssistance();
   porcentAssistance = a.getPorcentAssistance();
   idAssistance = a.getIdAssistance();

}

Assistance::Assistance(unsigned int idA, unsigned int idC,
                       QDateTime time, unsigned int tA,
                       unsigned int pA, unsigned int idAssistance):
   idCourse(idA), idCed(idC),
   fechaAssistance(time),totalAssistance(tA),
   porcentAssistance(pA),idAssistance(idAssistance)
{

}



