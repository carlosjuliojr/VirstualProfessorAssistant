#ifndef PERSONA_H
#define PERSONA_H
#include<iostream>
#include<QString>

using namespace std;
/**
 * @brief The Persona class
 */
class Person
{

   private:
      /**
       * @brief nombre
       */
      QString nombre;
      /**
       * @brief apellido
       */
      QString apellido;

      /**
       * @brief cedula
       */
      int cedula;
      /**
       * @brief correoElectronico
       */
      QString correoElectronico;




   public:
      /**
       * @brief Persona
       */
      Person();
      /**
       * @brief Persona
       * @param p
       */
      Person(const Person &p);
      /**
       * @brief Person
       * @param n
       * @param ap
       * @param ced
       * @param email
       */
      Person(QString n, QString ap, int ced, QString email );
/**
  @brief Persona
  */
      virtual ~Person();

       //setters and getters
      /**
       * @brief getNombre
       * @return
       */
      QString getNombre() const;
      /**
       * @brief getApellido
       * @return
       */
      QString getApellido() const;
      /**
       * @brief getCedula
       * @return
       */
      int getCedula() const;


      /**
       * @brief setNombre
       * @param value
       */
      void setNombre(const QString& value);
      /**
       * @brief setApellido
       * @param value
       */
      void setApellido(const QString& value);
      /**
       * @brief setCedula
       * @param value
       */
      void setCedula(int value);

      /**
       * @brief getCorreoElectronico
       * @return
       */
      QString getCorreoElectronico() const;
      /**
       * @brief setCorreoElectronico
       * @param value
       */
      void setCorreoElectronico(const QString& value);
      /**
       * @brief agregarPersona
       */
      void agregarPersona();

};

#endif // PERSONA_H
