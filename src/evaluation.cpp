#include"../include/evaluation.h"
#include "databasestructs.h"
unsigned int Evaluation::getIdEvaluation() const
{
    return idEvaluation;
}

void Evaluation::setIdEvaluation(unsigned int value)
{
    idEvaluation = value;
}

unsigned int Evaluation::getIdCourse() const
{
    return idCourse;
}

void Evaluation::setIdCourse(unsigned int value)
{
    idCourse = value;
}

QString Evaluation::getDescription() const
{
    return description;
}

void Evaluation::setDescription(const QString& value)
{
    description = value;
}

float Evaluation::getPorcent() const
{
    return porcent;
}

void Evaluation::setPorcent(float value)
{
    porcent = value;
}

QList<Calification*> &Evaluation::getCalifications()
{
    return califications;
}

void Evaluation::setCalifications(const QList<Calification*>& value)
{
   califications = value;
}

Evaluation&Evaluation::operator=(const typeEvaluationRegister& r)
{
   this->idEvaluation = r.idEvaluation;
   this->idCourse = r.idCourse;
   this->setDescription(r.description);
   this->porcent = r.porcent;
}

void Evaluation::addCalification(Calification* c)
{
   this->califications.append(c);
}

Evaluation::Evaluation():idEvaluation(0),idCourse(0),
    description(""),porcent(0)
{

}

Evaluation::Evaluation(const Evaluation& evaluation)

{
    this->idEvaluation = evaluation.getIdEvaluation();
    this->idCourse = evaluation.getIdCourse();
    this->description = evaluation.getDescription();
   this->porcent = evaluation.getPorcent();
}

Evaluation::Evaluation(unsigned int idEvaluation, unsigned int idCourse, QString descipcion, float porcent)
{
   this->setIdEvaluation(idEvaluation);
   this->setIdCourse(idCourse);
   this->setDescription(descipcion);
   this->setPorcent(porcent);

}
