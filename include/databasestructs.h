#ifndef DATABASESTRUCTS_H
#define DATABASESTRUCTS_H

//Fordward declarations
class Assistance;
class Calification;
class Evaluation;
class Student;
class Course;

using namespace std;

/**
 * @brief The tipoRegistro struct
 */
struct typePersonRegister
{
      char  nombre[128];
      /**
       * @brief apellido
       */
      char apellido[128];
      /**
       * @brief cedula
       */
      int cedula;
      /**
       * @brief correoElectronico
       */
      char correoElectronico[128];

            typePersonRegister& operator =(const Student &student);

};

struct typeCalificationRegister
{
      unsigned int idEvaluation;

      unsigned int idCourse;

      float calification;

      char observation[128];

      unsigned int idCed;

      unsigned int idCalification;

      typeCalificationRegister& operator=(const Calification& calification);


};


struct typeCourseRegister
{
      unsigned int idCourse;

      char nameCourse[128];

      typeCourseRegister& operator=(const Course& course);

};

struct typeAssistanceRegister
{
      unsigned int idCourse;
      unsigned int idCed;
      char fechaAssistance[11];
      unsigned int totalAssistance;
      unsigned int porcentAssistance;
      unsigned int idAssistance;

      typeAssistanceRegister& operator =(const Assistance &assistance);

};

struct typeRelationStudentCourseRegister
{
      unsigned int idCed;
      unsigned int idCourse;
};

struct typeEvaluationRegister
{
      unsigned int idEvaluation;
      unsigned int idCourse;
      char description[128];
      float porcent;
      typeEvaluationRegister& operator=(const Evaluation& evaluation);
};


#endif // DATABASESTRUCTS_H

