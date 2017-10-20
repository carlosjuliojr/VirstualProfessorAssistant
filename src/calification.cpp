#include"../include/calification.h"
#include"databasestructs.h"


float Calification::getCalification() const
{
   return calification;
}

void Calification::setCalification(float value)
{
   calification = value;
}


QString Calification::getObservation() const
{
   return observation;
}

void Calification::setObservation(const QString& value)
{
   observation = value;
}

unsigned int Calification::getIdCourse() const
{
   return idCourse;
}

void Calification::setIdCourse(unsigned int value)
{
   idCourse = value;
}

Calification&Calification::operator =(const typeCalificationRegister& calification)
{
   this->setIdEvaluation(calification.idEvaluation);
   this->setIdCourse(calification.idCourse);
   this->setCalification(calification.calification);
   this->setObservation(calification.observation);
   this->setIdCed(calification.idCed);
   this->setIdCalification(calification.idCalification);

   return *this;
}

unsigned int Calification::getIdEvaluation() const
{
    return idEvaluation;
}

void Calification::setIdEvaluation(unsigned int value)
{
    idEvaluation = value;
}

unsigned int Calification::getIdCed() const
{
   return idCed;
}

void Calification::setIdCed(unsigned int value)
{
   idCed = value;
}

unsigned int Calification::getIdCalification() const
{
   return idCalification;
}

void Calification::setIdCalification(unsigned int value)
{
   idCalification = value;
}

Calification::Calification():idEvaluation(0),idCourse(0),
   calification(0),observation(""),idCalification(0)
{

}

Calification::Calification(const Calification& c):idEvaluation(c.getIdEvaluation()),
                                                   idCourse(c.getIdCourse()),
                                                   calification(c.getCalification()),
                                                   observation(c.getObservation()),
                                                   idCed(c.getIdCed()),
                                                   idCalification(c.getIdCalification())
{

}

Calification::Calification(unsigned int idEvaluation,
                           unsigned int idCourse,
                           float calification,
                           QString observation,
                           unsigned int idC,
                           unsigned int idCalification)
{
   this->idEvaluation = idEvaluation;
   this->idCourse = idCourse;
   this->calification = calification;
   this->observation = observation;
   this->idCed = idC;
   this->idCalification = idCalification;
}

