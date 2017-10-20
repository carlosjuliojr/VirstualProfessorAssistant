#ifndef STUDENT_H
#define STUDENT_H
#include"person.h"
#include"course.h"


//Fordward declarations
class Course;
struct typePersonRegister;

class Student :public Person
{
   private:

      QList<Course *> courses;

   public:

      Student();
      Student(QString nombre, QString apellido, int cedula, QString correoElectronico);
      ~Student(){};
      /**
       * @brief getCourses
       * @return
       */
      QList<Course*> & getCourses();
      /**
       * @brief setCourses
       * @param value
       */
      void setCourses(const QList<Course*>& value);

      void addCourseOnly(Course * course);

       Student &operator=(const typePersonRegister &usuario);


};

#endif // STUDENT_H
