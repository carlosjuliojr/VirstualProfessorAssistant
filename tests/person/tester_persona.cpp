#include "../include/person.h"
#include<gtest/gtest.h>


TEST(test1, test)
{

   Person p;

   p.setApellido("hola");
   p.setNombre("julio j");
   p.setCorreoElectronico("carlosjuliojr@gmail.com");
   p.setCedula(12);

   ASSERT_EQ("hola",p.getApellido());
   ASSERT_EQ("julio j",p.getNombre());
//   ASSERT_EQ("Res. Domingo Salazar R.",p.getDireccion());

}

TEST(test2, test2)
{

   Person p;
   p.setCedula(2);
   ASSERT_EQ(2,p.getCedula());

   p.setCedula(23);
   ASSERT_NE(22,p.getCedula());

}
