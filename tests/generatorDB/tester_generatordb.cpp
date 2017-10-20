#include"../src/libs/dataBaseGenerator/databasegenerator.h"
#include<gtest/gtest.h>

/**
 * @brief TEST about generator data base. comparation between fichero in and binary fichero.
 *
 */
TEST(test1_data_base_generator_person, test_person){

   GeneratorDB generator;
   generator.generatorPerson("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/utilityAplication/generatorDB/persona.txt","prueba.dat");
   char linea[128];
   typePersonRegister tPrueba,pepe;
   ifstream fentrada("prueba.dat",ios::binary);
   ifstream archivo("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/utilityAplication/generatorDB/persona.txt");

   fentrada.read(reinterpret_cast<char *>(&tPrueba),sizeof(typePersonRegister));
   archivo.getline(linea,sizeof(linea));

   while(!fentrada.eof())
   {
      QString lineaCompleta(linea);
      QStringList md = lineaCompleta.split(",");

      memcpy(pepe.nombre, md[0].toStdString().c_str() ,md[0].size()+1);
      memcpy(pepe.apellido, md[1].toStdString().c_str() ,md[1].size()+1);
      pepe.cedula= md[2].toInt();
      strcpy(pepe.correoElectronico,md[3].toStdString().c_str());


      ASSERT_STREQ(tPrueba.nombre,pepe.nombre);
      ASSERT_STREQ(tPrueba.apellido,pepe.apellido);
      ASSERT_STREQ(tPrueba.correoElectronico,pepe.correoElectronico);
      ASSERT_EQ(tPrueba.cedula, pepe.cedula);
      fentrada.read(reinterpret_cast<char *>(&tPrueba),
                    sizeof(typePersonRegister));

      archivo.getline(linea,sizeof(linea));

   }
   fentrada.clear();
   fentrada.close();
   archivo.close();
}


/**
 * @brief TEST about generator data base. comparation between fichero in and binary fichero.
 *
 */
TEST(test1_data_base_generator_assistance, test_assistance){

   GeneratorDB generator;
   generator.generatorAssistance("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/utilityAplication/generatorDB/assistance.txt","assistance.dat");
   char linea[128];
   typeAssistanceRegister tPrueba,pepe;
   ifstream fentrada("assistance.dat",ios::binary);
   ifstream archivo("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/utilityAplication/generatorDB/assistance.txt");

   fentrada.read(reinterpret_cast<char *>(&tPrueba),sizeof(typeAssistanceRegister));
   archivo.getline(linea,sizeof(linea));

   while(!fentrada.eof())
   {

      QString lineaCompleta(linea);
      QStringList md = lineaCompleta.split(",");

      pepe.idCourse = md[0].toInt();
      pepe.idCed = md[1].toInt();
      strcpy(pepe.fechaAssistance, md[2].toStdString().c_str());
      pepe.totalAssistance = md[3].toInt();
      pepe.porcentAssistance = md[4].toInt();
      pepe.idAssistance = md[5].toInt();

      ASSERT_EQ(tPrueba.idCourse,pepe.idCourse);
      ASSERT_EQ(tPrueba.idCed,pepe.idCed);
      ASSERT_STREQ(tPrueba.fechaAssistance,pepe.fechaAssistance);
      ASSERT_EQ(tPrueba.totalAssistance,pepe.totalAssistance);
      ASSERT_EQ(tPrueba.porcentAssistance, pepe.porcentAssistance);
      ASSERT_EQ(tPrueba.idAssistance, pepe.idAssistance);

      fentrada.read(reinterpret_cast<char *>(&tPrueba),sizeof(typeAssistanceRegister));
      archivo.getline(linea,sizeof(linea));

   }
   fentrada.close();
   archivo.close();
}


/**
 * @brief TEST about generator data base. comparation between fichero in and binary fichero.
 *
 */
TEST(test1_data_base_generator_course, test_course){

   GeneratorDB generator;
   generator.generatorCourse("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/utilityAplication/generatorDB/course.txt","course.dat");

   char linea[128];
   typeCourseRegister tPrueba,pepe;

   ifstream fentrada("course.dat",ios::binary);
   ifstream archivo("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/utilityAplication/generatorDB/course.txt");

   fentrada.read(reinterpret_cast<char *>(&tPrueba),sizeof(typeCourseRegister));
   archivo.getline(linea,sizeof(linea));

   while(!fentrada.eof())
   {

      QString lineaCompleta(linea);
      QStringList md = lineaCompleta.split(",");

      pepe.idCourse =md[0].toInt();
      strcpy(pepe.nameCourse,md[1].toStdString().c_str());

      /**
       * @brief ASSERT_EQ test all.
       */

      ASSERT_EQ(tPrueba.idCourse,pepe.idCourse);
      ASSERT_STREQ(tPrueba.nameCourse,pepe.nameCourse);

      fentrada.read(reinterpret_cast<char *>(&tPrueba),sizeof(typeCourseRegister));
      archivo.getline(linea,sizeof(linea));

   }

   fentrada.close();
   archivo.close();
}


TEST(test1_data_base_generator_calification, test_calification){

   GeneratorDB generator;
   generator.generatorCalification("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/utilityAplication/generatorDB/calification.txt","calification.dat");

   char linea[128];
   typeCalificationRegister tPrueba,pepe;
   ifstream fentrada("calification.dat",
                     ios::binary);

   ifstream archivo("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/utilityAplication/generatorDB/calification.txt");


   fentrada.read(reinterpret_cast<char *>(&tPrueba),sizeof(typeCalificationRegister));
   archivo.getline(linea,sizeof(linea));


   while(!fentrada.eof())
   {

      QString lineaCompleta(linea);
      QStringList md = lineaCompleta.split(",");

      pepe.idEvaluation =md[0].toInt();
      pepe.idCourse = md[1].toInt();
      pepe.calification = md[2].toFloat();
      strcpy(pepe.observation,md[3].toStdString().c_str());
      pepe.idCed = md[4].toInt();
      pepe.idCalification = md[5].toInt();

      /**
       * @brief ASSERT_EQ test all.
       */
      ASSERT_STREQ(tPrueba.observation,pepe.observation);
      ASSERT_EQ(tPrueba.idEvaluation, pepe.idEvaluation);
      ASSERT_EQ(tPrueba.idCourse, pepe.idCourse);
      ASSERT_EQ(tPrueba.calification, pepe.calification);
      ASSERT_EQ(tPrueba.idCed, pepe.idCed);
      ASSERT_EQ(tPrueba.idCalification, pepe.idCalification);

      fentrada.read(reinterpret_cast<char *>(&tPrueba),sizeof(typeCalificationRegister));
      archivo.getline(linea,sizeof(linea));

   }

   fentrada.close();
   archivo.close();
}

TEST(test1_data_base_generator_relation, test_relation){

   GeneratorDB generator;
   generator.generatorRelationSC("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/utilityAplication/generatorDB/relationSC.txt","relationSC.dat");

   char linea[128];
   typeRelationStudentCourseRegister tPrueba,pepe;
   ifstream fentrada("relationSC.dat",
                     ios::binary);

   ifstream archivo("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/utilityAplication/generatorDB/relationSC.txt");


   fentrada.read(reinterpret_cast<char *>(&tPrueba),sizeof(typeRelationStudentCourseRegister));
   archivo.getline(linea,sizeof(linea));


   while(!fentrada.eof())
   {

      QString lineaCompleta(linea);
      QStringList md = lineaCompleta.split(",");


      pepe.idCed =md[0].toInt();
      pepe.idCourse = md[1].toInt();

      /**
       * @brief ASSERT_EQ test all.
       */

      ASSERT_EQ(tPrueba.idCourse, pepe.idCourse);
      ASSERT_EQ(tPrueba.idCed, pepe.idCed);

      fentrada.read(reinterpret_cast<char *>(&tPrueba),sizeof(typeRelationStudentCourseRegister));
      archivo.getline(linea,sizeof(linea));

   }

   fentrada.close();
   archivo.close();
}

TEST(test1_data_base_generator_evaluation, test_evaluation){

   GeneratorDB generator;
   generator.generatorEvaluation("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/utilityAplication/generatorDB/evaluation.txt","evaluation.dat");

   char linea[128];
   typeEvaluationRegister tPrueba,pepe;
   ifstream fentrada("evaluation.dat",
                     ios::binary);

   ifstream archivo("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/utilityAplication/generatorDB/evaluation.txt");


   fentrada.read(reinterpret_cast<char *>(&tPrueba),sizeof(typeEvaluationRegister));
   archivo.getline(linea,sizeof(linea));


   while(!fentrada.eof())
   {

      QString lineaCompleta(linea);
      QStringList md = lineaCompleta.split(",");


      pepe.idEvaluation =md[0].toInt();
      pepe.idCourse= md[1].toInt();
      strcpy(pepe.description, md[2].toStdString().c_str());
      pepe.porcent = md[3].toFloat();
      /**
       * @brief ASSERT_EQ test all.
       */

      ASSERT_EQ(tPrueba.idCourse, pepe.idCourse);
      ASSERT_EQ(tPrueba.idEvaluation, pepe.idEvaluation);
      ASSERT_STREQ(tPrueba.description, pepe.description);
      ASSERT_EQ(tPrueba.porcent, pepe.porcent);

      fentrada.read(reinterpret_cast<char *>(&tPrueba),sizeof(typeEvaluationRegister));
      archivo.getline(linea,sizeof(linea));

   }

   fentrada.close();
   archivo.close();
}
