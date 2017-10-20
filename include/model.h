#ifndef MODEL_H
#define MODEL_H
#include"dbhandler.h"

class Model{

   private:
      Dbhandler * model;

   public:


      // method by read

      Course* readCourse(const unsigned int idCourse);
      Student* readStudent(const unsigned int idStudent);
      Assistance* readAssistance(const unsigned int idAssistance);
      Evaluation* readEvalutation(const unsigned int idEvaluation);
      Calification* readCalification(const unsigned int idCedStudent);
      /**
       * @brief readAssistanceOnlyStudent
       * @param idCedAssistance
       * @return
       */
      //la comente porque esta mal implementada. ya que el find del qmap solo funciona por la clave
      //      Assistance* readAssistanceOnlyStudent(const unsigned int idCedAssistance);

      /**
       * @brief getMapCourseAll
       * @return
       */
      const QMap<int, Course*> & getMapCourseAll() const;

      /**
        * @brief getMapStudentAll
        * @return
        */
      const QMap<int, Student *> & getMapStudentAll() const;
      /**
        * @brief getMapEvaluationAll
        * @return
        */
      const QMap<int, Evaluation *> & getMapEvaluationAll() const;
      /**
        * @brief getMapCalificationAll
        * @return
        */
      const QMap<int, Calification*> & getMapCalificationAll() const;
      /**
        * @brief getMapAssistanceAll
        * @return
        */
      const QMap<int, Assistance*>& getMapAssistanceAll() const;
      /**
       * @brief getModel
       * @return
       */

      Dbhandler* getModel() const;

      /**
       * @brief setModel
       * @param value
       */
      void setModel(Dbhandler* value);
      /**
       * @brief readStudentsByIdCourse
       * @param idCourse
       * @return
       */
      const QList<Student* > readStudentsByIdCourse(const unsigned int idCourse) const;
      /**
       * @brief readEvaluationsByIdCourse
       * @param idCourse
       * @return
       */
      const QList<Evaluation*> readEvaluationsByIdCourse(const unsigned int idCourse) const;
      /**
       * @brief readAssistancesByIdCourse
       * @param idCourse
       * @return
       */
      const QList<Assistance* > readAssistancesByIdCourse(const unsigned int idCourse) const;
      /**
       * @brief readCoursesByIdCed
       * @param idCed
       * @return
       */
      const QList<Course* > readCoursesByIdCed(const unsigned int idCed) const;
      /**
       * @brief readCalificationsByIdEvaluation
       * @param idEv
       * @return
       */
      const QList<Calification*> readCalificationsByIdEvaluation(const unsigned int idEv) const;
      /**
       * @brief readCalificationsByIdCourse
       * @param idCourse
       * @return
       */
      const QList<Calification*> &readCalificationsByIdCourse(const unsigned int idCourse) const;


      /**
       * @brief createCourse
       * @param nameCourse
       * @return 0 if fail or 1 if correct
       */
      bool createCourse(const QString nameCourse);
      /**
       * @brief createStudent
       * @param nombre
       * @param apellido
       * @param cedula
       * @param correoElectronico
       * @return 0 fail 1 correct
       */
      bool createStudent(QString nombre,
                         QString apellido,
                         int cedula,
                         QString correoElectronico);
      /**
       * @brief createEvaluation if there is already idCedula will be update or reemplaced
       * @param idEvaluation
       * @param idCourse
       * @param description
       * @param porcen
       * @return 0 fail 1 correct
       */
      bool createEvaluation(
            unsigned int idCourse,
            QString description,
            float porcen);
      /**
       * @brief createCalification
       * @param idEvaluation
       * @param idCourse
       * @param calification
       * @param observation
       * @param idCed
       * @param idCalification
       * @return  0 if fail, 1 correct
       */
      bool createCalification( unsigned int idEvaluation,
                               unsigned int idCourse,
                               float calification,
                               QString observation,
                               unsigned int idCed);
      /**
       * @brief createAssistance
       * @param idCourse
       * @param idCed
       * @param fechaAssistance
       * @param totalAssistance
       * @param porcentAssistance
       * @return 0 if fail. 1 correct
       */
      bool createAssistance(unsigned int idCourse,
                            unsigned int idCed,
                            QDateTime fechaAssistance,
                            unsigned int totalAssistance,
                            unsigned int porcentAssistance);
      // or an Course to Student
      /**
       * @brief addStudentToCourse
       * @param idCed
       * @param idCourse
       * @return
       */
      bool addStudentToCourse(const unsigned int idCed,const  unsigned int idCourse);
      /**
       * @brief addEvaluationToCourse
       * @param idEvaluation
       * @param idCourse
       * @return
       */
      bool addEvaluationToCourse(const unsigned int idEvaluation,const  unsigned int idCourse);
      /**
       * @brief addAssistanceToCourse
       * @param idCourse
       * @param idCed
       * @param assistanceStudent
       * @param idAssistance
       * @return
       */
      bool addAssistanceToCourse(const unsigned int idCourse,
                                 const unsigned int idCed,
                                 const unsigned int idAssistance);
      /**
       * @brief addCalificationToEvaluation
       * @param idCalification
       * @param idEvaluation
       * @return
       */
      bool addCalificationToEvaluation(const unsigned int idCalification,
                                       const unsigned int idEvaluation);

      /**
       * @brief updateCourse
       * @param idCourse
       * @param nameCourse
       * @return 0 if fail, 1 update
       */
      bool updateCourse(const unsigned int idCourse, const QString nameCourse);
      /**
       * @brief updateStudent
       * @param nombre
       * @param apellido
       * @param cedula
       * @param correoElectronico
       * @return 0 if fail, 1 update
       */
      bool updateStudent(const QString nombre,
                         const QString apellido,
                         const int cedula,
                         const QString correoElectronico);
      /**
       * @brief updateEvaluation
       * @param idEvaluation
       * @param idCourse
       * @param description
       * @param porcent
       * @return
       */
      bool updateEvaluation(const unsigned int idEvaluation,
                            const unsigned int idCourse,
                            const QString description,
                            const float porcent);
      /**
       * @brief updateCalification
       * @param idEvaluation
       * @param idCourse
       * @param calification
       * @param observation
       * @param idCed
       * @param idCalification
       * @return
       */
      bool updateCalification(const unsigned int idEvaluation,
                              const unsigned int idCourse,
                              const float calification,
                              const QString observation,
                              const unsigned int idCed,
                              const unsigned int idCalification);

      bool updateAssistance(const unsigned int idCourse,
                            const unsigned int idCed,
                            const QDateTime fechaAssistance,
                            const unsigned int totalAssistance,
                            const unsigned int porcentAssistance,
                            const unsigned int idAssistance);
      /**
       * @brief deleteCourse by idCourse
       * @param idCourse
       * @return
       */
      bool deleteCourse(const unsigned int idCourse);
      /**
       * @brief deleteStudent
       * @param idCedula
       * @return
       */
      bool deleteStudent(const unsigned int idCedula);
      /**
       * @brief deleteEvaluation
       * @param idEvaluation
       * @return
       */
      bool deleteEvaluation(const unsigned int idEvaluation);
      /**
       * @brief deleteCalification
       * @param idCalification
       * @return
       */
      bool deleteCalification(const unsigned int idCalification);
      /**
       * @brief deleteAssistance
       * @param idAssistance
       * @return
       */
      bool deleteAssistance(const unsigned int idAssistance);

};


#endif // MODEL_H
