#include"../include/course.h"
#include"student.h"
#include"databasestructs.h"

QString Course::getNameCourse() const
{
   return nameCourse;
}

void Course::setNameCourse(const QString& value)
{
   nameCourse = value;
}

QList<Student*> & Course::getStudents()
{
   return students;
}

void Course::setStudents(const QList<Student*>& value)
{
   students = value;
}

void Course::addStudentOnly(Student* student)
{
   this->students.append(student);
}

void Course::addEvaluation(Evaluation* evaluation)
{
   evaluations.append(evaluation);
}

void Course::addAssistance(Assistance* assistance)
{
   assistances.append(assistance);
}




Course&Course::operator=(const typeCourseRegister& course)
{
   this->setIdCourse(course.idCourse);
   this->setNameCourse(course.nameCourse);

   return (*this);
}

QList<Evaluation*> & Course::getEvaluations()
{
    return evaluations;
}

void Course::setEvaluations(const QList<Evaluation*>& value)
{
    evaluations = value;
}

QList<Assistance*> &Course::getAssistances()
{
    return assistances;
}

void Course::setAssistances(const QList<Assistance*>& value)
{
    assistances = value;
}

Course::Course():idCourse(0),nameCourse("")
{
    
}

Course::Course(unsigned int idC, QString nameCourse): idCourse(idC), nameCourse(nameCourse)
{
    
}

unsigned int Course::getIdCourse() const
{
   return idCourse;
}

void Course::setIdCourse(unsigned int value)
{
   idCourse = value;
}
