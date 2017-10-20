#include"../src/libs/dataBaseGenerator/databasegenerator.h"
#include"model.h"
#include<gtest/gtest.h>

/**
 * @brief TEST about generator data base. comparation between fichero in and binary fichero.
 *
 */
TEST(test1_readCourse, test_readCourse)
{
   Model model;
   model.setModel(new Dbhandler);

   model.getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                            );
   Course* course = model.readCourse(2);

   ASSERT_EQ(course->getIdCourse(), 2);
   ASSERT_STREQ(course->getNameCourse().toStdString().c_str(),"fisica");

   course = model.readCourse(3);

   ASSERT_EQ(course->getIdCourse(), 3);
   ASSERT_STREQ(course->getNameCourse().toStdString().c_str(),"ipq");

   course = model.readCourse(8);


   ASSERT_EQ(course->getIdCourse(), 8);
   ASSERT_STREQ(course->getNameCourse().toStdString().c_str(),"sistemas");


}

TEST(test2_readStudent, test_readStudent)
{
   Model model;
   model.setModel(new Dbhandler);

   model.getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                            );
   Student* student;
   student = model.readStudent(1);

   ASSERT_STREQ(student->getNombre().toStdString().c_str(),"nombre");
   ASSERT_STREQ(student->getApellido().toStdString().c_str(),"apellido");
   ASSERT_STREQ(student->getCorreoElectronico().toStdString().c_str(),"correoElectronico");
   ASSERT_EQ(student->getCedula(),1);

   student = model.readStudent(8);

   ASSERT_STREQ(student->getNombre().toStdString().c_str(),"sebastian");
   ASSERT_STREQ(student->getApellido().toStdString().c_str(),"maleo");
   ASSERT_STREQ(student->getCorreoElectronico().toStdString().c_str(),"pueleo@otmamsml.com");
   ASSERT_EQ(student->getCedula(),8);

}

TEST(test3_readEvaluation, testEvaluation)
{
   Model model;
   model.setModel(new Dbhandler);

   model.getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                            );

   Evaluation* evaluation;
   evaluation = model.readEvalutation(2);

   ASSERT_EQ(evaluation->getIdEvaluation(), 2);
   ASSERT_EQ(evaluation->getIdCourse(), 1);
   ASSERT_STREQ(evaluation->getDescription().toStdString().c_str(), "grabe dictadura");
   ASSERT_EQ(evaluation->getPorcent(),20);


}



TEST(test4_readAssistance, test_readAssistance)
{
   Model model;
   model.setModel(new Dbhandler);

   model.getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                            );

   Assistance* assistance;
   assistance = model.readAssistance(1);


   ASSERT_EQ(assistance->getIdCourse(),1);
   ASSERT_EQ(assistance->getIdCed(),1);
   ASSERT_STREQ(assistance->getFechaAssistance().toString("yyyy:MM:dd").toStdString().c_str(),"2020:01:01");
   ASSERT_EQ(assistance->getTotalAssistance(),1);
   ASSERT_EQ(assistance->getPorcentAssistance(),10);
   ASSERT_EQ(assistance->getIdAssistance(), 1);

}

TEST(test5_readCalification, readCalification)
{
   Model model;
   model.setModel(new Dbhandler);

   model.getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                            );
   Calification* calification ;
   calification = model.readCalification(2);

   ASSERT_STREQ(calification->getObservation().toStdString().c_str(),"esta bm");
   ASSERT_EQ(calification->getIdEvaluation(), 1);
   ASSERT_EQ(calification->getIdCourse(), 1);
   ASSERT_EQ(calification->getCalification(), 10);
   ASSERT_EQ(calification->getIdCed(), 1);
   ASSERT_EQ(calification->getIdCalification(), 2);

}

TEST(test6_readStudentsByIdCourse,  test_readStudentsByIdCourse)
{
   Model model;
   model.setModel(new Dbhandler);


   model.getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                            );


   //para variar las pruebas solo debes cambiar el valor de idCourse


   int tam = model.getMapCourseAll().size();

   std::cout <<"tam: "<< tam <<std::endl;
   int idCourse = 1;
   while(idCourse <= tam)
   {


      typeRelationStudentCourseRegister tPrueba;

      ifstream fentrada("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",ios::binary);
      fentrada.read(reinterpret_cast<char *>(&tPrueba),sizeof(typeRelationStudentCourseRegister));

      while(!fentrada.eof())
      {      QList<Student*> students = model.readStudentsByIdCourse(tPrueba.idCourse);
         QList<Student*>::iterator itStudent = students.begin();

         while(itStudent != students.end())
         {
            if(tPrueba.idCourse == idCourse && tPrueba.idCed == (*itStudent)->getCedula())
            {
               ifstream fentradaPerson("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",ios::binary);
               typePersonRegister tPerson;

               fentradaPerson.read(reinterpret_cast<char *>(&tPerson),sizeof(typePersonRegister));
               while(!fentradaPerson.eof())
               {
                  if(tPerson.cedula == (*itStudent)->getCedula())
                  {
                     std::cout<<(*itStudent)->getNombre().toStdString()<<"  ";
                     std::cout<<(*itStudent)->getApellido().toStdString()<<"  ";
                     std::cout<<(*itStudent)->getCedula()<<"  ";
                     std::cout<<(*itStudent)->getCorreoElectronico().toStdString()<<std::endl;
                     ASSERT_STREQ(tPerson.nombre,(*itStudent)->getNombre().toStdString().c_str());
                     ASSERT_STREQ(tPerson.apellido,(*itStudent)->getApellido().toStdString().c_str());
                     ASSERT_STREQ(tPerson.correoElectronico,(*itStudent)->getCorreoElectronico().toStdString().c_str());
                     ASSERT_EQ(tPerson.cedula, (*itStudent)->getCedula());

                     fentradaPerson.close();
                     break;
                  }else
                  {

                     fentradaPerson.read(reinterpret_cast<char *>(&tPerson),
                                         sizeof(typePersonRegister));
                  }

               }

               itStudent++;
               fentrada.read(reinterpret_cast<char *>(&tPrueba),sizeof(typeRelationStudentCourseRegister));
            }else
               itStudent++;

         }
         fentrada.read(reinterpret_cast<char *>(&tPrueba),sizeof(typeRelationStudentCourseRegister));

      }
      fentrada.close();
      idCourse++;
   }

}

TEST(test7_readEvaluationByIdCourse, test7_readEvaluationByIdCours)
{
   Model model;
   model.setModel(new Dbhandler);


   model.getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                            );


   //para variar las pruebas solo debes cambiar el valor de idCourse


   int tam = model.getMapCourseAll().size();

   int idCourse = 1;
   while(idCourse <= tam)
   {


      typeEvaluationRegister tPrueba;

      ifstream fentrada("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat",ios::binary);
      fentrada.read(reinterpret_cast<char *>(&tPrueba),sizeof(typeEvaluationRegister));

      while(!fentrada.eof())
      {  QList<Evaluation*> evaluations = model.readEvaluationsByIdCourse(tPrueba.idCourse);
         QList<Evaluation*>::iterator itEvaluation = evaluations.begin();

         while(itEvaluation!= evaluations.end())
         {
            if(tPrueba.idCourse == idCourse && tPrueba.idEvaluation == (*itEvaluation)->getIdEvaluation())
            {
               std::cout<<(*itEvaluation)->getIdEvaluation()<<"  ";
               std::cout<<(*itEvaluation)->getIdCourse()<<"  ";
               std::cout<<(*itEvaluation)->getDescription().toStdString()<<"  ";
               std::cout<<(*itEvaluation)->getPorcent()<<std::endl;
               ASSERT_EQ(tPrueba.idEvaluation,(*itEvaluation)->getIdEvaluation());
               ASSERT_EQ(tPrueba.idCourse,(*itEvaluation)->getIdCourse());
               ASSERT_STREQ(tPrueba.description,(*itEvaluation)->getDescription().toStdString().c_str());
               ASSERT_EQ(tPrueba.porcent, (*itEvaluation)->getPorcent());

               fentrada.read(reinterpret_cast<char *>(&tPrueba),
                             sizeof(typeEvaluationRegister));

               itEvaluation++;
            }else
               itEvaluation++;

         }
         fentrada.read(reinterpret_cast<char *>(&tPrueba),sizeof(typeEvaluationRegister));

      }
      fentrada.close();
      fentrada.read(reinterpret_cast<char *>(&tPrueba),sizeof(typeEvaluationRegister));
      idCourse++;
   }

}

TEST(test8_readAssistancesByIdCourse, test8_readAssisyancesByIdCours)
{
   Model model;
   model.setModel(new Dbhandler);


   model.getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                            );


   //para variar las pruebas solo debes cambiar el valor de idCourse


   int tam = model.getMapCourseAll().size();

   int idCourse = 1;
   while(idCourse <= tam)
   {


      typeAssistanceRegister tPrueba;

      ifstream fentrada("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",ios::binary);
      fentrada.read(reinterpret_cast<char *>(&tPrueba),sizeof(typeAssistanceRegister));

      while(!fentrada.eof())
      {
         QList<Assistance*> assistances = model.readAssistancesByIdCourse(tPrueba.idCourse);
         QList<Assistance*>::iterator itAssistance= assistances.begin();

         while(itAssistance!= assistances.end())
         {
            if(tPrueba.idCourse == idCourse && tPrueba.idAssistance== (*itAssistance)->getIdAssistance())
            {/*
               std::cout<<(*itEvaluation)->getIdEvaluation()<<"  ";
               std::cout<<(*itEvaluation)->getIdCourse()<<"  ";
               std::cout<<(*itEvaluation)->getDescription().toStdString()<<"  ";
               std::cout<<(*itEvaluation)->getPorcent()<<std::endl;*/

               ASSERT_EQ(tPrueba.idCourse,(*itAssistance)->getIdCourse());
               ASSERT_EQ(tPrueba.idCed,(*itAssistance)->getIdCed());
               ASSERT_STREQ(tPrueba.fechaAssistance,(*itAssistance)->getFechaAssistance().toString("yyyy:MM:dd").toStdString().c_str());
               ASSERT_EQ(tPrueba.totalAssistance, (*itAssistance)->getTotalAssistance());
               ASSERT_EQ(tPrueba.porcentAssistance, (*itAssistance)->getPorcentAssistance());
               ASSERT_EQ(tPrueba.idAssistance, (*itAssistance)->getIdAssistance());


               fentrada.read(reinterpret_cast<char *>(&tPrueba),
                             sizeof(typeAssistanceRegister));

               itAssistance++;
            }else
               itAssistance++;

         }
         fentrada.read(reinterpret_cast<char *>(&tPrueba),sizeof(typeAssistanceRegister));

      }
      fentrada.close();
      fentrada.read(reinterpret_cast<char *>(&tPrueba),sizeof(typeAssistanceRegister));
      idCourse++;
   }
}

TEST(test9_readCoursesByIdCed, test_readCoursesByIdCed)
{

   Model model;
   model.setModel(new Dbhandler);


   model.getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                            );


   //para variar las pruebas solo debes cambiar el valor de idCourse


   int tam = model.getMapStudentAll().size();
   QList<Course*> courses;
   std::cout <<"tam: "<< tam <<std::endl;
   int idCedula = 1;
   while(idCedula <= tam)
   {
      typeRelationStudentCourseRegister tPrueba;
      ifstream fentrada("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",ios::binary);
      fentrada.read(reinterpret_cast<char *>(&tPrueba),sizeof(typeRelationStudentCourseRegister));





      while(!fentrada.eof())
      {  courses = model.readCoursesByIdCed(tPrueba.idCed);
         QList<Course*>::iterator itCourse= courses.begin();

         while(itCourse != courses.end())
         {
            if(tPrueba.idCed == idCedula && tPrueba.idCourse == (*itCourse)->getIdCourse())
            {
               ifstream fentradaCourse("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",ios::binary);
               typeCourseRegister tCourse;

               fentradaCourse.read(reinterpret_cast<char *>(&tCourse),sizeof(typeCourseRegister));
               while(!fentradaCourse.eof())
               {
                  if(tCourse.idCourse == (*itCourse)->getIdCourse())
                  {
                     ASSERT_STREQ(tCourse.nameCourse,(*itCourse)->getNameCourse().toStdString().c_str());
                     ASSERT_EQ(tCourse.idCourse, (*itCourse)->getIdCourse());

                     fentradaCourse.close();
                     break;
                  }else
                  {

                     fentradaCourse.read(reinterpret_cast<char *>(&tCourse),
                                         sizeof(typeCourseRegister));
                  }

               }

               itCourse++;
               fentrada.read(reinterpret_cast<char *>(&tPrueba),sizeof(typeRelationStudentCourseRegister));
            }else
               itCourse++;

         }
         fentrada.read(reinterpret_cast<char *>(&tPrueba),sizeof(typeRelationStudentCourseRegister));

      }
      fentrada.close();
      idCedula++;
   }
}

TEST(test10_readCalificationsByIdEvaluation, test_readCalificationsByIdEvaluation)
{
   Model model;
   model.setModel(new Dbhandler);

   model.getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                            );

   int tam = model.getMapEvaluationAll().size();

   int idEvaluation = 1;
   while(idEvaluation <= tam)
   {

      typeCalificationRegister tPrueba;

      ifstream fentrada("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",ios::binary);
      fentrada.read(reinterpret_cast<char *>(&tPrueba),sizeof(typeCalificationRegister));

      while(!fentrada.eof())
      {
         QList<Calification*> califications= model.readCalificationsByIdEvaluation(tPrueba.idEvaluation);

         QList<Calification*>::iterator itCalification= califications.begin();

         while(itCalification!= califications.end())
         {
            if(tPrueba.idEvaluation== idEvaluation&& tPrueba.idCalification== (*itCalification)->getIdCalification())
            {/*
               std::cout<<(*itEvaluation)->getIdEvaluation()<<"  ";
               std::cout<<(*itEvaluation)->getIdCourse()<<"  ";
               std::cout<<(*itEvaluation)->getDescription().toStdString()<<"  ";
               std::cout<<(*itEvaluation)->getPorcent()<<std::endl;*/

               ASSERT_EQ(tPrueba.idEvaluation, (*itCalification)->getIdEvaluation());
               ASSERT_EQ(tPrueba.idCourse,(*itCalification)->getIdCourse());
               ASSERT_STREQ(tPrueba.observation,(*itCalification)->getObservation().toStdString().c_str());
               ASSERT_EQ(tPrueba.idCed,(*itCalification)->getIdCed());
               ASSERT_EQ(tPrueba.idCalification, (*itCalification)->getIdCalification());



               fentrada.read(reinterpret_cast<char *>(&tPrueba),
                             sizeof(typeCalificationRegister));

               itCalification++;
            }else
               itCalification++;

         }
         fentrada.read(reinterpret_cast<char *>(&tPrueba),sizeof(typeCalificationRegister));

      }
      fentrada.close();
      fentrada.read(reinterpret_cast<char *>(&tPrueba),sizeof(typeCalificationRegister));
      idEvaluation++;
   }
}
/**
 * @brief TETS
 */
TEST(test11_readCalificationsByIdCourse, test_readCalificationsByIdCourse)
{

   Model model;
   model.setModel(new Dbhandler);


   model.getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                            );

   int tam = model.getMapCourseAll().size();

   int idCourse = 1;

   while(idCourse <= tam)
   {
      QList<Calification*> califications= model.readCalificationsByIdCourse(idCourse);
      if(califications.size() == 0)
         break;

      typeCalificationRegister tPrueba;

      ifstream fentrada("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",ios::binary);
      fentrada.read(reinterpret_cast<char *>(&tPrueba),sizeof(typeCalificationRegister));

      while(!fentrada.eof())
      {
         QList<Calification*>::const_iterator itCalification= califications.begin();

         while(itCalification!= califications.end())
         {
            if(tPrueba.idCourse == idCourse && tPrueba.idCalification == (*itCalification)->getIdCalification())
            {
               ASSERT_EQ(tPrueba.idEvaluation, (*itCalification)->getIdEvaluation());
               ASSERT_EQ(tPrueba.idCourse,(*itCalification)->getIdCourse());
               ASSERT_STREQ(tPrueba.observation,(*itCalification)->getObservation().toStdString().c_str());
               ASSERT_EQ(tPrueba.idCed,(*itCalification)->getIdCed());
               ASSERT_EQ(tPrueba.idCalification, (*itCalification)->getIdCalification());

               fentrada.read(reinterpret_cast<char *>(&tPrueba),
                             sizeof(typeCalificationRegister));

               itCalification++;
            }else
               itCalification++;

         }
         fentrada.read(reinterpret_cast<char *>(&tPrueba),sizeof(typeCalificationRegister));

      }
      fentrada.close();
      fentrada.read(reinterpret_cast<char *>(&tPrueba),sizeof(typeCalificationRegister));
      idCourse++;
   }
}
TEST(test12_createCourse, test_createCourse)
{
   Model model;
   model.setModel(new Dbhandler);


   model.getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                            );
   if(model.createCourse("Arquitectura de Computadores"))
   {

      Course* course = model.getMapCourseAll().last();

      ASSERT_STREQ(course->getNameCourse().toStdString().c_str(),"Arquitectura de Computadores");

      std::cout << "Course added" <<std::endl;
   }else
      std::cout<<"Course does not added" << std::endl;
}

TEST(test13_createStudent, test_createStudent)
{
   Model model;
   model.setModel(new Dbhandler);


   model.getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                            );
   if(model.createStudent("Pedro", "Zambrano",25,"quesera@hotmail.com"))
   {

      Student* prueba= model.getMapStudentAll().find(25).value();


      ASSERT_STREQ(prueba->getNombre().toStdString().c_str(),"Pedro");
      ASSERT_STREQ(prueba->getApellido().toStdString().c_str(),"Zambrano");
      ASSERT_STREQ(prueba->getCorreoElectronico().toStdString().c_str(),"quesera@hotmail.com");
      ASSERT_EQ(prueba->getCedula(), 25);

      std::cout << "Student added" <<std::endl;
   }else
      std::cout<<"Student does not added" << std::endl;
}

TEST(test14_createEvaluation, test_createEvaluation)
{
   Model model;
   model.setModel(new Dbhandler);


   model.getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                            );
   if(model.createEvaluation(1, "Primera evaluacion",25))
   {

      Evaluation* prueba= model.getMapEvaluationAll().last();

      ASSERT_STREQ(prueba->getDescription().toStdString().c_str(),"Primera evaluacion");
      ASSERT_EQ(prueba->getIdCourse(),1);
      ASSERT_EQ(prueba->getPorcent(),25);
      std::cout << "Evaluation added" <<std::endl;
   }else
      std::cout<<"Evaluation does not added" << std::endl;
}

TEST(test15_createCalification, test_createCalification)
{
   Model model;
   model.setModel(new Dbhandler);


   model.getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                            );
   if(model.createCalification(1, 1,20,"estipido",1))
   {

      Calification* prueba= model.getMapCalificationAll().last();

      ASSERT_EQ(prueba->getIdEvaluation(),1);
      ASSERT_EQ(prueba->getIdCourse(),1);
      ASSERT_EQ(prueba->getCalification(),20);
      ASSERT_EQ(prueba->getIdCed(),1);
      ASSERT_STREQ(prueba->getObservation().toStdString().c_str(),"estipido");

      std::cout << "Calification added" <<std::endl;
   }else
      std::cout<<"Calification does not added" << std::endl;
}

TEST(test16_createAssistance, test_createAssistance)
{
   Model model;
   model.setModel(new Dbhandler);


   model.getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                            );

   if(model.createAssistance(2, 1,QDateTime::currentDateTime(),0,40))
   {

      Assistance* prueba= model.getMapAssistanceAll().last();

      //      ASSERT_STREQ(prueba->getFechaAssistance().toString("yyyy:MM:dd").toStdString().c_str(),"2017:04:05");
      ASSERT_EQ(prueba->getIdCed(),1);
      ASSERT_EQ(prueba->getIdCourse(),2);
      ASSERT_EQ(prueba->getTotalAssistance(),0);
      ASSERT_EQ(prueba->getPorcentAssistance(),40);

      std::cout << "Calification added" <<std::endl;
   }else
      std::cout<<"Calification does not added" << std::endl;
}

TEST(test17_addStudentToCourse, test_addStudentToCourse)
{
   Model model;
   model.setModel(new Dbhandler);


   model.getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                            );


   int idCourse, idCedula;

   if(!model.getMapCourseAll().isEmpty() && !model.getMapStudentAll().isEmpty()){
      idCourse = model.getMapCourseAll().begin().value()->getIdCourse();
      idCedula = model.getMapStudentAll().last()->getCedula();
   }


   if(model.addStudentToCourse(idCedula,idCourse)
         &&idCourse == model.getMapCourseAll().begin().value()->getIdCourse()
         && idCedula == model.getMapStudentAll().last()->getCedula())

   {

      typeRelationStudentCourseRegister tPrueba;

      ifstream fentrada("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",ios::binary);

      fentrada.seekg(0,ios::end);
      fentrada.seekg((long unsigned int)fentrada.tellg()-sizeof(typeRelationStudentCourseRegister));

      fentrada.read(reinterpret_cast<char *>(&tPrueba),sizeof(typeRelationStudentCourseRegister));

      ASSERT_EQ(tPrueba.idCed,idCedula);
      ASSERT_EQ(tPrueba.idCourse,idCourse);

      std::cout << "Student added to the course" <<std::endl;
      fentrada.close();

   }else
      std::cout<<"Student does not added to the course" << std::endl;


}

TEST(test18_addEvaluationToCourse, test_addEvaluationToCourse)
{
   Model model;
   model.setModel(new Dbhandler);


   model.getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                            );


   int idCourse, idEvaluation;

   if(!model.getMapCourseAll().isEmpty() && !model.getMapEvaluationAll().isEmpty()){
      idCourse = model.getMapCourseAll().begin().value()->getIdCourse();
      idEvaluation= model.getMapEvaluationAll().last()->getIdEvaluation();
   }


   if(model.addEvaluationToCourse(idEvaluation,idCourse)
         &&idCourse == model.getMapCourseAll().begin().value()->getIdCourse()
         && idEvaluation == model.getMapEvaluationAll().last()->getIdEvaluation())

   {

      QList<Evaluation*> listEvaluation = model.getMapCourseAll().find(idCourse).value()->getEvaluations();
      QList<Evaluation*>::iterator itEvaluation = listEvaluation.begin();

      while(itEvaluation != listEvaluation.end())
      {
         if((*itEvaluation)->getIdEvaluation() == idEvaluation)
         {
            ASSERT_EQ((*itEvaluation)->getIdCourse(),idCourse);
            ASSERT_EQ((*itEvaluation)->getIdEvaluation(),idEvaluation);
            break;
         }else
            itEvaluation++;

      }

   }

}

TEST(test19_addAssistanceToCourse, test19_addAssistanceToCourse)
{
   Model model;
   model.setModel(new Dbhandler);


   model.getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                            );


   int idCedula, idCourse, idAssistance;



   if(!model.getMapCourseAll().isEmpty() && !model.getMapStudentAll().isEmpty()
         && !model.getMapAssistanceAll().isEmpty()){
      idCourse = model.getMapCourseAll().begin().value()->getIdCourse();
      idAssistance= model.getMapAssistanceAll().last()->getIdAssistance();
      idCedula = model.getMapStudentAll().last()->getCedula();
   }


   if(model.addAssistanceToCourse(idCourse,idCedula,idAssistance))
   {
      //      idCourse = model.getMapAssistanceAll().find(idAssistance).value()->getIdCourse();
      //      idAssistance = model.getMapAssistanceAll().find(idAssistance)->getIdAssistance();
      //      idCedula = model.getMapAssistanceAll().find(idAssistance)->getCedula();

      QList<Assistance*> listAssistance= model.getMapCourseAll().find(idCourse).value()->getAssistances();
      QList<Assistance*>::iterator itAssistance = listAssistance.begin();

      while(itAssistance != listAssistance.end())
      {
         if((*itAssistance)->getIdAssistance() == idAssistance)
         {
            ASSERT_EQ((*itAssistance)->getIdCourse(),idCourse);
            ASSERT_EQ((*itAssistance)->getIdAssistance(),idAssistance);
            ASSERT_EQ((*itAssistance)->getIdCed(),idCedula);
            break;
         }else
            itAssistance++;

      }

   }
}

TEST(test20_addCalificationToEvaluation, test20_addCalificationToEvaluation)
{
   Model model;
   model.setModel(new Dbhandler);


   model.getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                            );


   int idCalification, idEvaluation;



   if(!model.getMapCalificationAll().isEmpty() && !model.getMapEvaluationAll().isEmpty()
         )
   {
      idCalification = model.getMapCalificationAll().begin().value()->getIdCalification();
      idEvaluation= model.getMapEvaluationAll().last()->getIdEvaluation();
   }


   if(model.addCalificationToEvaluation(idCalification, idEvaluation))
   {
      QList<Calification*> listCalification= model.getMapEvaluationAll().find(idEvaluation).value()->getCalifications();
      QList<Calification*>::iterator itCalification= listCalification.begin();

      while(itCalification!= listCalification.end())
      {
         if((*itCalification)->getIdCalification() == idCalification)
         {
            ASSERT_EQ((*itCalification)->getIdCalification(),idCalification);
            ASSERT_EQ((*itCalification)->getIdEvaluation(),idEvaluation);
            break;
         }else
            itCalification++;

      }

   }
}

TEST(test21_updateCourse, test_updateCourse)
{
   Model model;
   model.setModel(new Dbhandler);


   model.getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                            );

   if(model.getMapCourseAll().empty())
      std::cout<<"Course vacio" <<std::endl;
   else
   {
      int idCourse = model.getMapCourseAll().begin().value()->getIdCourse();
      std::cout << idCourse<<"courseeeeeeeeeee" <<std::endl;
      QString nameCourse = "Religion";
      if(model.updateCourse(idCourse,nameCourse))
      {
         Course* course = model.getMapCourseAll().find(idCourse).value();
         ASSERT_EQ(course->getIdCourse(),idCourse);
         ASSERT_STREQ(course->getNameCourse().toStdString().c_str(),nameCourse.toStdString().c_str());

      }
   }
}

TEST(test22_updateStudent, test22_updateStudent)
{
   Model model;
   model.setModel(new Dbhandler);


   model.getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                            );

   if(model.getMapStudentAll().empty())
      std::cout<<"Student vacio" <<std::endl;
   else
   {
      int idCedula = model.getMapStudentAll().find(7).value()->getCedula();
      std::cout <<"Cedula: " << idCedula<<std::endl;
      QString name = "modificacion";
      QString app = "modificacion";
      QString email = "modificacion";
      if(model.updateStudent(name, app, idCedula, email))
      {
         Student* student = model.getMapStudentAll().find(idCedula).value();
         ASSERT_STREQ(student->getNombre().toStdString().c_str(),name.toStdString().c_str());
         ASSERT_STREQ(student->getApellido().toStdString().c_str(),app.toStdString().c_str());
         ASSERT_STREQ(student->getCorreoElectronico().toStdString().c_str(),email.toStdString().c_str());
         ASSERT_EQ(student->getCedula(), idCedula);
      }
      else
         cout<<"student no modified" << std::endl;
   }
}

TEST(test23_updateEvaluation, test23_updateEvaluation)
{
   Model model;
   model.setModel(new Dbhandler);


   model.getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                            );

   if(model.getMapEvaluationAll().empty())
      std::cout<<"Evaluation is vacio" <<std::endl;
   else
   {
      const unsigned int idEvaluation= model.getMapEvaluationAll().find(7).value()->getIdEvaluation();
      const unsigned int idCourse = 1;
      const QString description ="modificado";
      const float porcent = 100;
      if(model.updateEvaluation(idEvaluation, idCourse, description, porcent))
      {

         Evaluation* evaluation = model.getMapEvaluationAll().find(idEvaluation).value();
         ASSERT_EQ(evaluation->getIdEvaluation(), idEvaluation);
         ASSERT_EQ(evaluation->getIdCourse(), idCourse);
         ASSERT_STREQ(evaluation->getDescription().toStdString().c_str(),description.toStdString().c_str());
         ASSERT_EQ(evaluation->getPorcent(), porcent);

      }
      else
         cout<<"Evaluation no modified" << std::endl;
   }
}

TEST(test24_updateCalification, test24_updateCalification)
{
   Model model;
   model.setModel(new Dbhandler);


   model.getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                            );

   if(model.getMapCalificationAll().empty())
      std::cout<<"Calification is vacio" <<std::endl;
   else
   {


      const unsigned int idEvaluation = 1;
      const unsigned int idCourse = 1;
      const float calification = 01;
      const QString observation = "modificado ok";
      const unsigned int idCed = 1;
      const unsigned int idCalification = 6;

      if(model.updateCalification(idEvaluation, idCourse, calification,observation,idCed,idCalification))
      {

         Calification* cal= model.getMapCalificationAll().find(idCalification).value();
         ASSERT_EQ(cal->getIdEvaluation(), idEvaluation);
         ASSERT_EQ(cal->getIdCourse(), idCourse);
         ASSERT_EQ(cal->getCalification(), calification);
         ASSERT_STREQ(cal->getObservation().toStdString().c_str(),observation.toStdString().c_str());
         ASSERT_EQ(cal->getIdCed(), idCed);
         ASSERT_EQ(cal->getIdCalification(), idCalification);

      }
      else
         cout<<"calification no modified" << std::endl;
   }
}

TEST(test25_updateAssistance, test25_updateAssistance)
{
   Model model;
   model.setModel(new Dbhandler);


   model.getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                            );

   if(model.getMapAssistanceAll().empty())
      std::cout<<"Assistance is vacio" <<std::endl;
   else
   {

      unsigned int idCourse = 1;
      unsigned int idCed = 1;
      QDateTime fechaAssistance = QDateTime::currentDateTime();
      unsigned int totalAssistance= 0;
      unsigned int porcentAssistance= 10;
      unsigned int idAssistance = 3;

      if(model.updateAssistance(idCourse, idCed, fechaAssistance ,totalAssistance,porcentAssistance,idAssistance))
      {

         Assistance* cal= model.getMapAssistanceAll().find(idAssistance).value();
         ASSERT_EQ(cal->getIdCourse(), idCourse);
         ASSERT_EQ(cal->getIdCed(), idCed);
         ASSERT_EQ(cal->getFechaAssistance(), fechaAssistance);
         ASSERT_EQ(cal->getTotalAssistance(), totalAssistance);
         ASSERT_EQ(cal->getPorcentAssistance(),porcentAssistance);
         ASSERT_EQ(cal->getIdAssistance(), idAssistance);

      }
      else
         cout<<"Assistance no modified" << std::endl;
   }
}

TEST(test26_deleteCourse, test26_deleteCourse)
{
   Model model;
   model.setModel(new Dbhandler);


   model.getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                            );

   if(model.getMapCourseAll().empty())
      std::cout<<"Course is vacio" <<std::endl;
   else
   {

      unsigned int idCourse = 4;


      if(model.deleteCourse(idCourse))
      {

         std::cout<< "Course deleted"<<std::endl;
      }
      else
         cout<<"Course does not deleted" << std::endl;
   }
}

TEST(test27_deleteStudent, test27_deleteStudent)
{
   Model model;
   model.setModel(new Dbhandler);


   model.getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                            );

   if(model.getMapStudentAll().empty())
      std::cout<<"there is not Student " <<std::endl;
   else
   {

      unsigned int idCedula = 2;

      if(model.deleteStudent(idCedula))
      {
         std::cout<< "Student deleted"<<std::endl;
      }
      else
         cout<<"Student does not deleted" << std::endl;
   }
}

TEST(test28_deleteEvaluation, test28_deleteEvaluation)
{
   Model model;
   model.setModel(new Dbhandler);


   model.getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                            );

   if(model.getMapEvaluationAll().empty())
      std::cout<<"there is not Evaluaitons " <<std::endl;
   else
   {

      unsigned int idEvaluation = 7;

      if(model.deleteEvaluation(idEvaluation))
      {
         std::cout<< "Evaluation deleted"<<std::endl;
      }
      else
         cout<<"Evaluation does not deleted" << std::endl;
   }
}

TEST(test29_deleteCalification, test29_deleteCalification)
{
   Model model;
   model.setModel(new Dbhandler);


   model.getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                            );

   if(model.getMapCalificationAll().empty())
      std::cout<<"there is not Califications" <<std::endl;
   else
   {

      unsigned int idCalification = 5;

      if(model.deleteCalification(idCalification))
      {
         std::cout<< "Calification deleted"<<std::endl;
      }
      else
         cout<<"Calification does not deleted" << std::endl;
   }
}

TEST(test30_deleteAssistance, test30_deleteAssistance)
{
   Model model;
   model.setModel(new Dbhandler);


   model.getModel()->loadDB("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                            "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat"
                            );

   if(model.getMapAssistanceAll().empty())
      std::cout<<"there is not Assistance" <<std::endl;
   else
   {

      unsigned int idAssistance = 6;

      if(model.deleteAssistance(idAssistance))
      {
         std::cout<< "Assistance deleted"<<std::endl;
      }
      else
         cout<<"Assistance does not deleted" << std::endl;
   }
}
