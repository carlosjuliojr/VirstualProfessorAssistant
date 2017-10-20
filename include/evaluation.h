#ifndef EVALUATION_H
#define EVALUATION_H
#include<QList>
#include<QString>
#include"calification.h"

//Fordward declarations
struct typeEvaluationRegister;

class Evaluation
{
    private:

        unsigned int idEvaluation;
        unsigned int idCourse;
        QString description;
        float porcent;
        QList<Calification * > califications;

    public:
        /**
         * @brief Evaluation
         */
        Evaluation();

        ~Evaluation(){};
        /**
         * @brief Evaluation
         * @param evaluation
         */
        Evaluation(const Evaluation & evaluation);
        /**
         * @brief Evaluation
         * @param idEvaluation
         * @param idCourse
         * @param descipcion
         * @param porcent
         */
        Evaluation(unsigned int idEvaluation,
                   unsigned int idCourse,
                   QString descipcion,
                   float porcent);
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
         * @brief getDescription
         * @return
         */
        QString getDescription() const;
        /**
         * @brief setDescription
         * @param value
         */
        void setDescription(const QString& value);
        /**
         * @brief getPorcent
         * @return
         */
        float getPorcent() const;
        /**
         * @brief setPorcent
         * @param value
         */
        void setPorcent(float value);
        /**
         * @brief getCalifications
         * @return
         */
        QList<Calification*> &getCalifications() ;
        /**
         * @brief setCalifications
         * @param value
         */
        void setCalifications(const QList<Calification*>& value);

        Evaluation &operator=(const typeEvaluationRegister &r);

        void addCalification(Calification* c);
};

#endif // EVALUATION_H
