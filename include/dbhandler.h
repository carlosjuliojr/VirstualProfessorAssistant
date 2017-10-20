#ifndef DBHANDLER_H
#define DBHANDLER_H
#include<qmap.h>
#include"../include/student.h"
#include"../include/course.h"
#include"../include/assistance.h"
#include"../include/calification.h"
#include"../include/databasestructs.h"

#include<fstream>
class Evaluation;
class Dbhandler {

   private:
      /**
       * @brief mapUser
       * @brief mapAccount
       * @brief mapTransactions
       @brief mapCards
       */
      QMap<int, Student * > mapStudent;
      QMap<int, Course*> mapCourse;
      QMap<int, Assistance*> mapAssistance;
      QMap<int, Calification*> mapCalification;
      QMap<int, Evaluation*> mapEvaluation;

   public:

      /**
       * @brief BankCashier
       */
      Dbhandler();
      /**
       * @brief Destroyer BankCashier
       */

      ~Dbhandler();


      /**
       * @brief loadDB
       * @param dir_file_person_binary
       * @param dir_file_course_binary
       * @param dir_file_calification_binary
       * @param dir_file_assistance_binary
       */


      void loadDB(string dir_file_person_binary,
                   string dir_file_course_binary,
                   string dir_file_calification_binary,
                   string dir_file_assistance_binary,
                   string dir_file_relationsc_binary,
                   string dir_file_evaluation_binary);

      /**
       * @brief loadUser
       * @param dir_file_person_binary_out
       */
      void loadStudent(string dir_file_person_binary_out);

      void generateDbQmapCourseToBinary() ;
      void generateDbQmapStudentToBinary() ;
      void generateDbQmapEvaluationToBinary() ;
      void generateDbQmapCalificationToBinary() ;
      void generateDbQmapAssistanceToBinary() ;
      void generateDbQmapCourseRelationStudentToBinary() ;
      void generateDbQmapStudentRelationCourseToBinary() ;


      /**
       * @brief loadCourse
       * @param dir_file_course_binary_out
       */
      void loadCourse(string dir_file_course_binary_out);
      /**
       * @brief loadTransaction
       * @param dir_file_transaction_binary_out
       */
      void loadCalification(string dir_file_calification_binary_out);
      /**
       * @brief loadCard
       * @param dir_file_card_binary_out
       */
      void loadAssistance(string dir_file_assistant_binary_out);

      /**
       * @brief getMapStudent
       * @return
       */

      void loadEvaluation(string dir_file_evaluation_binary_out);

       QMap<int, Student*> & getMapStudent() ;
      /**
       * @brief setMapStudent
       * @param value
       */
      void setMapStudent(const QMap<int, Student*>& value);
      /**
       * @brief getMapCourse
       * @return
       */
      QMap<int, Course*> & getMapCourse() ;
      /**
       * @brief setMapCourse
       * @param value
       */
      void setMapCourse(const QMap<int, Course*>& value);
      /**
       * @brief getMapAssistance
       * @return
       */
       QMap<int, Assistance*> & getMapAssistance() ;
      /**
       * @brief setMapAssistance
       * @param value
       */
      void setMapAssistance(const QMap<int, Assistance*>& value);
      /**
       * @brief getMapCalification
       * @return
       */
      QMap<int, Calification*> & getMapCalification() ;
      /**
       * @brief setMapCalification
       * @param value
       */
      void setMapCalification(const QMap<int, Calification*>& value);
      /**
       * @brief getMapEvaluation
       * @return
       */
      QMap<int, Evaluation*>& getMapEvaluation() ;
      /**
       * @brief setMapEvaluation
       * @param value
       */
      void setMapEvaluation(const QMap<int, Evaluation*>& value);
      /**
       * @brief addCourseToQmap
       * @param course
       */
      void addCourseToQmap( Course * course);
      /**
       * @brief addStudentToQmap
       * @param student
       */
      void addStudentToQmap(Student * student);
      /**
       * @brief addEvaluationToQmap
       * @param evaluation
       */
      void addEvaluationToQmap(Evaluation* evaluation);
      /**
       * @brief addCalificationToQmap
       * @param calification
       */
      void addCalificationToQmap(Calification* calification);
      /**
       * @brief addAssistanceToQmap
       * @param assistance
       */
      void addAssistanceToQmap(Assistance* assistance);

};


#endif // DBHANDLER_H
