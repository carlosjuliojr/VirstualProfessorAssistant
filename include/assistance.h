#ifndef ASSISTANCE_H
#define ASSISTANCE_H
#include<QDateTime>

//Fordward declarations
struct typeAssistanceRegister;

class Assistance
{
    private:

    unsigned int idCourse;
    unsigned int idCed;
    QDateTime fechaAssistance;
    unsigned int totalAssistance;
    unsigned int porcentAssistance;
    unsigned int idAssistance;

    public:

    Assistance();

    ~Assistance(){};

    Assistance(const Assistance &a);

    Assistance(unsigned int idA,unsigned int idC,QDateTime time, unsigned int tA, unsigned int pA, unsigned int idAssistance);

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
     * @brief getFechaAssistance
     * @return
     */
    QDateTime getFechaAssistance() const;
    /**
     * @brief setFechaAssistance
     * @param value
     */
    void setFechaAssistance(const QDateTime& value);
    /**
     * @brief getTotalAssistance
     * @return
     */
    unsigned int getTotalAssistance() const;
    /**
     * @brief setTotalAssistance
     * @param value
     */
    void setTotalAssistance(unsigned int value);
    /**
     * @brief getPorcentAssistance
     * @return
     */
    unsigned int getPorcentAssistance() const;
    /**
     * @brief setPorcentAssistance
     * @param value
     */
    void setPorcentAssistance(unsigned int value);
    /**
     * @brief operator =
     * @param assistance
     * @return
     */
    Assistance& operator =(const typeAssistanceRegister& assistance);

    unsigned int getIdCourse() const;
    void setIdCourse(unsigned int value);
    unsigned int getIdAssistance() const;
    void setIdAssistance(unsigned int value);
};

#endif // ASSISTANCE_H
