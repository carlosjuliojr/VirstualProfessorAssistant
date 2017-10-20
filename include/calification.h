#ifndef CALIFICATION_H
#define CALIFICATION_H
#include<QString>

struct typeCalificationRegister;

class Calification
{

   private:

      unsigned int idEvaluation;

      unsigned int idCourse;

      float calification;

      QString observation;

      unsigned int idCed;

      unsigned int idCalification;


public:

      Calification();

      ~Calification(){

      };

      Calification(const Calification &c);

      Calification(unsigned int idEvaluation,
                   unsigned int idCourse,
                   float calification,
                   QString observation,
                   unsigned int idC,
                   unsigned int idCalification);
      /**
       * @brief getIdEvaluation
       * @return
       */
      unsigned int getIdEvaluation() const;
      /**
       * @brief setIdEvaluation
       * @param value
       */
      void setIdEvaluation(unsigned int value);

      /**
       * @brief getCalification
       * @return
       */
      float getCalification() const;
      /**
       * @brief setCalification
       * @param value
       */
      void setCalification(float value);


      /**
       * @brief getObservation
       * @return
       */
      QString getObservation() const;
      /**
       * @brief setObservation
       * @param value
       */
      void setObservation(const QString& value);
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

      Calification & operator =(const typeCalificationRegister &calification);
      /**
       * @brief getIdCed
       * @return
       */
      unsigned int getIdCed() const;
      /**
       * @brief setIdCed
       * @param value
       */
      void setIdCed(unsigned int value);
      /**
       * @brief getIdCalification
       * @return
       */
      unsigned int getIdCalification() const;
      /**
       * @brief setIdCalification
       * @param value
       */
      void setIdCalification(unsigned int value);
};

#endif // CALIFICATION_H
