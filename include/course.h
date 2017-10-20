#ifndef COURSE_H
#define COURSE_H
#include"evaluation.h"
#include<QString>

#include<QList>
#include"assistance.h"

//Fordward declarations
class Student;
struct typeCourseRegister;

class Course
{

   private:
      unsigned int idCourse;
      QString nameCourse;
      QList<Student *> students;
      QList<Evaluation *> evaluations;
      QList<Assistance * > assistances;

   public:
      /**
        * @brief Course
        */
       Course();


       ~Course(){};

       /**
        * @brief Course
        * @param idC
        * @param nameCourse
        */
       Course(unsigned int idC, QString nameCourse);
       /**
        * @brief getIdCourse
        * @return
        */
       unsigned int getIdCourse() const;
      /**
       * @brief setIdCourse
       * @param value
       */
      void setIdCourse(unsigned int value);
      /**
       * @brief getNameCourse
       * @return
       */
      QString getNameCourse() const;
      /**
       * @brief setNameCourse
       * @param value
       */
      void setNameCourse(const QString& value);
      /**
       * @brief getStudents
       * @return
       */
      QList<Student*> & getStudents() ;
      /**
       * @brief setStudents
       * @param value
       */
      void setStudents(const QList<Student*>& value);
      /**
       * @brief addStudentOnly
       * @param student
       */
      void addStudentOnly(Student * student);
      /**
       * @brief addEvaluation
       * @param evaluation
       */
      void addEvaluation(Evaluation * evaluation);
      /**
       * @brief addAssistance
       * @param assistance
       */
      void addAssistance(Assistance * assistance);



      /**
       * @brief operator =
       * @param course
       * @return
       */
      Course &operator=(const typeCourseRegister &course);
      /**
       * @brief getEvaluations
       * @return
       */
      QList<Evaluation*> & getEvaluations() ;
      /**
       * @brief setEvaluations
       * @param value
       */
      void setEvaluations(const QList<Evaluation*>& value);
      /**
       * @brief getAssistances
       * @return
       */
      QList<Assistance*> &getAssistances() ;
      /**
       * @brief setAssistances
       * @param value
       */
      void setAssistances(const QList<Assistance*>& value);
};

#endif // COURSE_H
