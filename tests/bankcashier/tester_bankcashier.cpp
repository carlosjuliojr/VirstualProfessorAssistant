#include "../include/bankcashier.h"
#include<gtest/gtest.h>


TEST(test1, loadUser)
{
   BankCashier b;
   b.loadUser("/home/julio/Documentos/Qt/Proyectos/CajeroBancario/tests/bankcashier/prueba.dat");

   QMap<int, Usuario*> user= b.getMapUser();

   Usuario * prueba;
   char linea[128];
   ifstream archivo("/home/julio/Documentos/Qt/Proyectos/CajeroBancario/tests/generatorDB/persona.txt");

   tipoRegistro pepe;

   if(archivo.fail())
      cerr << "Error al abrir el archivo Pruebas.txt" << endl;
   else
   {
      foreach (prueba, user) {
         archivo.getline(linea, sizeof(linea));
         QString lineaCompleta(linea);
         QStringList md = lineaCompleta.split(",");

         memcpy(pepe.nombre, md[0].toStdString().c_str() ,md[0].size()+1);
         memcpy(pepe.apellido, md[1].toStdString().c_str() ,md[1].size()+1);
         memcpy(pepe.direccion, md[2].toStdString().c_str() ,md[2].size()+1);
         memcpy(pepe.correoElectronico, md[3].toStdString().c_str() ,md[3].size()+1);
         pepe.cedula= md[4].toInt();
         memcpy(pepe.fechaNacimiento, md[5].toStdString().c_str() ,md[5].size()+1);


         ASSERT_STREQ(prueba->getNombre().toStdString().c_str(),pepe.nombre);
         ASSERT_STREQ(prueba->getApellido().toStdString().c_str(),pepe.apellido);
         ASSERT_STREQ(prueba->getDireccion().toStdString().c_str(),pepe.direccion);
         ASSERT_STREQ(prueba->getCorreoElectronico().toStdString().c_str(),pepe.correoElectronico);
         ASSERT_EQ(prueba->getCedula(),pepe.cedula);
         ASSERT_STREQ(prueba->getFechaNacimiento().toString("yyyy:MM:dd").toStdString().c_str(),pepe.fechaNacimiento);

      }

   }


}

TEST(test2, loadAccount)
{
   BankCashier b;
   b.loadAccount("/home/julio/Documentos/Qt/Proyectos/CajeroBancario/tests/bankcashier/account.dat");

   QMap<int, Cuenta*> cuenta = b.getMapAccount();

   Cuenta * prueba;
   char linea[128];
   ifstream archivo("/home/julio/Documentos/Qt/Proyectos/CajeroBancario/tests/generatorDB/account.txt");

   tipoRegistroAccount pepe;

   if(archivo.fail())
      cerr << "Error al abrir el archivo account.txt" << endl;
   else
   {
      foreach (prueba, cuenta) {
         archivo.getline(linea, sizeof(linea));


         QString lineaCompleta(linea);
         QStringList md = lineaCompleta.split(",");

         pepe.numeroDeCuenta = md[0].toInt();
         pepe.iDCed = md[1].toInt();
         pepe.tipoDeCuenta = md[2].toInt();
         pepe.montoTotal = md[3].toDouble();
         pepe.montoDiferido = md[4].toDouble();
         pepe.numeroDeTransacciones = md[5].toInt();

         ASSERT_EQ(prueba->getNumeroDeCuenta(),pepe.numeroDeCuenta);
         ASSERT_EQ(prueba->getIDCed(),pepe.iDCed);
         ASSERT_EQ(prueba->getMontoTotal(),pepe.montoTotal);
         ASSERT_EQ(prueba->getMontoDiferido(),pepe.montoDiferido);
         ASSERT_EQ(prueba->getNumeroDeTransacciones(),pepe.numeroDeTransacciones);

         if(pepe.tipoDeCuenta == 0)
            ASSERT_EQ(prueba->getTipoDeCuenta(),TC_ELECTRONICA_AHORRO);
         else if(pepe.tipoDeCuenta == 1)
            ASSERT_EQ(prueba->getTipoDeCuenta(),TC_ELECRTONCA_CORRIENTE);
         else if( pepe.tipoDeCuenta == 2)
            ASSERT_EQ(prueba->getTipoDeCuenta(),TC_CORRIENTE);
         else
            ASSERT_EQ(prueba->getTipoDeCuenta(),TC_AHORRO);
      }

   }

}

TEST(test3, loadCards)
{
   BankCashier b;
   b.loadCard("/home/julio/Documentos/Qt/Proyectos/CajeroBancario/tests/bankcashier/cards.dat");

   QMap<int, Tarjeta*> tarjeta= b.getMapCards();

   Tarjeta * prueba;
   char linea[128];
   ifstream archivo("/home/julio/Documentos/Qt/Proyectos/CajeroBancario/tests/generatorDB/cards.txt");


   QMap<int, Tarjeta*>::iterator i;

   tipoRegistroCards pepe;

   if(archivo.fail())
      cerr << "Error al abrir el archivo cards.txt" << endl;
   else
   {
      foreach(prueba,tarjeta){


         archivo.getline(linea, sizeof(linea));

         QString lineaCompleta(linea);
         QStringList md = lineaCompleta.split(",");

         pepe.iDCed = md[0].toInt();
         pepe.iDCuenta = md[1].toInt();
         pepe.numeroDeTarjeta = md[2].toInt();
         pepe.codigoDeTarjeta = md[3].toInt();
         pepe.pinDeTarjeta = md[4].toInt();
         pepe.tipoDeTardeja = md[5].toInt();

         strcpy(pepe.fechaDeCreacion, md[6].toStdString().c_str());
         strcpy(pepe.fechaDeVencimiento,md[7].toStdString().c_str());

         ASSERT_EQ(prueba->getIdCed(),pepe.iDCed);
         ASSERT_EQ(prueba->getIdCuenta(),pepe.iDCuenta);
         ASSERT_EQ(prueba->getNumeroDeTarjeta(),pepe.numeroDeTarjeta);
         ASSERT_EQ(prueba->getCodigoDeTarjeta(),pepe.codigoDeTarjeta);
         ASSERT_EQ(prueba->getTipoDeTardeja(),pepe.tipoDeTardeja);
         ASSERT_STREQ(prueba->getFechaDeCreacion().toString("yyyy:MM:dd").toStdString().c_str(),pepe.fechaDeCreacion);
         ASSERT_STREQ(prueba->getFechaDeVencimiento().toString("yyyy:MM:dd").toStdString().c_str(),pepe.fechaDeVencimiento);

      }

   }
}

TEST(test3, loadTransaction)
{
   BankCashier b;
   b.loadTransaction("/home/julio/Documentos/Qt/Proyectos/CajeroBancario/tests/bankcashier/transactions.dat");

   QMap<int, Movimientos*> transactions= b.getMapTransactions();

   Movimientos * prueba;
   char linea[128];
   ifstream archivo("/home/julio/Documentos/Qt/Proyectos/CajeroBancario/tests/generatorDB/transactions.txt");

   tipoRegistroTransactions pepe;

   if(archivo.fail())
      cerr << "Error al abrir el archivo transactions.txt" << endl;
   else
   {
      foreach(prueba,transactions){


         archivo.getline(linea, sizeof(linea));

         QString lineaCompleta(linea);
         QStringList md = lineaCompleta.split(",");

         strcpy(pepe.fechaTransaccion, md[0].toStdString().c_str());
         strcpy(pepe.descripcion, md[1].toStdString().c_str());
         pepe.referencia = md[2].toInt();
         pepe.montoMovimiento = md[3].toDouble();
         pepe.totalEncuenta = md[4].toDouble();
         pepe.idNumeroCuenta = md[5].toInt();

         ASSERT_STREQ(prueba->getFechaTransaccion().toString("yyyy:MM:dd").toStdString().c_str(),pepe.fechaTransaccion);
         ASSERT_STREQ(prueba->getDescripcion().toStdString().c_str(),pepe.descripcion);
         ASSERT_EQ(prueba->getReferencia(),pepe.referencia);
         ASSERT_EQ(prueba->getMontoMovimiento(),pepe.montoMovimiento);
         ASSERT_EQ(prueba->getTotalEncuenta(),pepe.totalEncuenta);
         ASSERT_EQ(prueba->getNumeroDeCuenta(),pepe.idNumeroCuenta);

      }

   }
}


