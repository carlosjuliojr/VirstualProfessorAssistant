#include"../include/cuenta.h"
#include<gtest/gtest.h>

TEST(test1, test){

   Cuenta cuenta;

   cuenta.setIDCed(23042376);

   ASSERT_EQ(23042376,cuenta.getIDCed());

}
