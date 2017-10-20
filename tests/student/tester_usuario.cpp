#include<gtest/gtest.h>
#include<QDebug>
#include"../../include/usuario.h"


TEST(test1, test)
{
    Usuario p;
    tipoRegistro r;

      strcpy(r.nombre,"julio");
      strcpy(r.apellido,"rodriguez");
      strcpy(r.direccion,"residencias domingo salazar");
      r.cedula=23;
      strcpy(r.correoElectronico,"carlosjuliojr@hotmail.com");
      strcpy(r.fechaNacimiento,"1992:09:12");

//      p.setNombre(r.nombre);
//      p.setApellido(r.apellido);
//      p.setDireccion(r.direccion);
//      p.setCedula(r.cedula);
//      p.setCorreoElectronico(r.correoElectronico);

//      p.setFechaNacimiento(QDateTime::fromString(r.fechaNacimiento,"yyyy:MM:dd"));


     p=r;


//      qDebug << p.getFechaNacimiento().toString("yyyy:MM:dd");

        qDebug() << "date: " << p.getFechaNacimiento().toString("yyyy:MM:dd");

      //qDebug <<(QString)p.getFechaNacimiento();

   ASSERT_STREQ(p.getNombre().toStdString().c_str(),r.nombre);
   ASSERT_STREQ(p.getApellido().toStdString().c_str(),r.apellido);
   ASSERT_STREQ(p.getDireccion().toStdString().c_str(),r.direccion);
   ASSERT_EQ(p.getCedula(),r.cedula);
   ASSERT_STREQ(p.getCorreoElectronico().toStdString().c_str(),r.correoElectronico);
   QString s(p.getFechaNacimiento().toString("yyyy:MM:dd"));
   ASSERT_STREQ(s.toStdString().c_str(),r.fechaNacimiento);

}
