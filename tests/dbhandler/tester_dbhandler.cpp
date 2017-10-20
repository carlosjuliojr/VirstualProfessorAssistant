#include "../include/dbhandler.h"
#include<gtest/gtest.h>


TEST(test1, loadStudent)
{
   Dbhandler b;
   b.loadStudent("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat");

   QMap<int, Student*> user= b.getMapStudent();

   Student * prueba;
   char linea[128];
   ifstream archivo("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/utilityAplication/generatorDB/persona.txt");

   typePersonRegister pepe;

   if(archivo.fail())
      cerr << "Error al abrir el archivo prueba.txt" << endl;
   else
   {
      foreach (prueba, user) {
         archivo.getline(linea, sizeof(linea));
         QString lineaCompleta(linea);
         QStringList md = lineaCompleta.split(",");

         memcpy(pepe.nombre, md[0].toStdString().c_str() ,md[0].size()+1);
         memcpy(pepe.apellido, md[1].toStdString().c_str() ,md[1].size()+1);
         pepe.cedula= md[2].toInt();
         strcpy(pepe.correoElectronico,md[3].toStdString().c_str());

         ASSERT_STREQ(prueba->getNombre().toStdString().c_str(),pepe.nombre);
         ASSERT_STREQ(prueba->getApellido().toStdString().c_str(),pepe.apellido);
         ASSERT_STREQ(prueba->getCorreoElectronico().toStdString().c_str(),pepe.correoElectronico);
         ASSERT_EQ(prueba->getCedula(), pepe.cedula);
      }

   }


}

TEST(test2, loadCourse)
{
   Dbhandler b;
   b.loadCourse("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat");

   QMap<int, Course*> cuenta = b.getMapCourse();

   Course * prueba;
   char linea[128];
   ifstream archivo("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/utilityAplication/generatorDB/course.txt");

   typeCourseRegister pepe;

   if(archivo.fail())
      cerr << "Error al abrir el archivo course.txt" << endl;
   else
   {
      foreach (prueba, cuenta) {
         archivo.getline(linea, sizeof(linea));


         QString lineaCompleta(linea);
         QStringList md = lineaCompleta.split(",");

         pepe.idCourse =md[0].toInt();
         strcpy(pepe.nameCourse,md[1].toStdString().c_str());

         ASSERT_EQ(prueba->getIdCourse(),pepe.idCourse);
         ASSERT_STREQ(prueba->getNameCourse().toStdString().c_str(),pepe.nameCourse);


      }

   }

}

TEST(test3, loadCalification)
{
   Dbhandler b;
   b.loadCalification("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat");

   QMap<int, Calification*> calification= b.getMapCalification();

   Calification * prueba;
   char linea[128];
   ifstream archivo("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/utilityAplication/generatorDB/calification.txt");



   typeCalificationRegister pepe;

   if(archivo.fail())
      cerr << "Error al abrir el archivo calification.txt" << endl;
   else
   {
      foreach(prueba,calification){


         archivo.getline(linea, sizeof(linea));

         QString lineaCompleta(linea);
         QStringList md = lineaCompleta.split(",");

         pepe.idEvaluation =md[0].toInt();
         pepe.idCourse = md[1].toInt();
         pepe.calification = md[2].toFloat();
         strcpy(pepe.observation,md[3].toStdString().c_str());
         pepe.idCed = md[4].toInt();


         ASSERT_EQ(prueba->getIdEvaluation(),pepe.idEvaluation);
         ASSERT_EQ(prueba->getIdCourse(),pepe.idCourse);
         ASSERT_EQ(prueba->getCalification(),pepe.calification);
         ASSERT_EQ(prueba->getIdCed(),pepe.idCed);
         ASSERT_STREQ(prueba->getObservation().toStdString().c_str(),pepe.observation);

      }

   }
}

TEST(test3, loadEvaluation)
{
   Dbhandler b;
   b.loadEvaluation("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat");

   QMap<int, Evaluation*> evaluation= b.getMapEvaluation();

   Evaluation * prueba;
   char linea[128];
   ifstream archivo("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/utilityAplication/generatorDB/evaluation.txt");

   typeEvaluationRegister pepe;

   if(archivo.fail())
      cerr << "Error al abrir el archivo evaluation.txt" << endl;
   else
   {
      foreach(prueba,evaluation){


         archivo.getline(linea, sizeof(linea));

         QString lineaCompleta(linea);
         QStringList md = lineaCompleta.split(",");

         pepe.idEvaluation = md[0].toInt();
         pepe.idCourse = md[1].toInt();
         strcpy(pepe.description, md[2].toStdString().c_str());
         pepe.porcent = md[3].toFloat();

         ASSERT_STREQ(prueba->getDescription().toStdString().c_str(),pepe.description);
         ASSERT_EQ(prueba->getIdEvaluation(),pepe.idEvaluation);
         ASSERT_EQ(prueba->getIdCourse(),pepe.idCourse);
         ASSERT_EQ(prueba->getPorcent(),pepe.porcent);

      }

   }
}

TEST(test3, loadAssistance)
{
   Dbhandler b;
   b.loadAssistance("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat");

   QMap<int, Assistance*> assistance= b.getMapAssistance();

   Assistance * prueba;
   char linea[128];
   ifstream archivo("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/utilityAplication/generatorDB/assistance.txt");

   typeAssistanceRegister pepe;

   if(archivo.fail())
      cerr << "Error al abrir el archivo assistance.txt" << endl;
   else
   {
      foreach(prueba,assistance){


         archivo.getline(linea, sizeof(linea));

         QString lineaCompleta(linea);
         QStringList md = lineaCompleta.split(",");

         pepe.idCourse = md[0].toInt();
         pepe.idCed = md[1].toInt();
         strcpy(pepe.fechaAssistance, md[2].toStdString().c_str());
         pepe.totalAssistance = md[3].toInt();
         pepe.porcentAssistance = md[4].toInt();

         ASSERT_STREQ(prueba->getFechaAssistance().toString("yyyy:MM:dd").toStdString().c_str(),pepe.fechaAssistance);
         ASSERT_EQ(prueba->getIdCed(),pepe.idCed);
         ASSERT_EQ(prueba->getIdCourse(),pepe.idCourse);
         ASSERT_EQ(prueba->getTotalAssistance(),pepe.totalAssistance);
         ASSERT_EQ(prueba->getPorcentAssistance(),pepe.porcentAssistance);

      }

   }
}
