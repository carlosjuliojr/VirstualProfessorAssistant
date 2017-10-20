#include"databasegenerator.h"

GeneratorDB::GeneratorDB()
{

}

GeneratorDB::~GeneratorDB()
{

}

/**
 * @brief GeneratorDB::generatorPerson
 * @param dir_file_txt_in
 * @param dir_file_binary_out
 */

void GeneratorDB::generatorPerson(string dir_file_txt_in, string dir_file_binary_out)
{
   ifstream archivo(dir_file_txt_in);
   ofstream fsalida(dir_file_binary_out,ios::out | ios::binary);

   char linea[128];
   typePersonRegister pepe;

   if(archivo.fail())
      cerr << "Error al abrir el archivo Pruebas.txt" << endl;
   else
   {
      while(archivo.getline(linea, sizeof(linea)))
      {


         QString lineaCompleta(linea);
         QStringList md = lineaCompleta.split(",");

         memcpy(pepe.nombre, md[0].toStdString().c_str() ,md[0].size()+1);
         memcpy(pepe.apellido, md[1].toStdString().c_str() ,md[1].size()+1);
         pepe.cedula= md[2].toInt();
         strcpy(pepe.correoElectronico,md[3].toStdString().c_str());
         fsalida.write(reinterpret_cast<char *>(&pepe),sizeof(typePersonRegister));

      }
   }
   archivo.close();
   fsalida.close();

}
/**
 * @brief GeneratorDB::generatorAccount
 * @param dir_file_txt_in
 * @param dir_file_binary_out
 */
void GeneratorDB::generatorCourse(string dir_file_txt_in, string dir_file_binary_out)
{
   ifstream archivo(dir_file_txt_in);
   ofstream fsalida(dir_file_binary_out,ios::out | ios::binary);

   char linea[128];
   typeCourseRegister pepe;

   if(archivo.fail())
      cerr << "Error al abrir el archivo account.txt" << endl;
   else
   {
      while(archivo.getline(linea, sizeof(linea)))
      {

         QString lineaCompleta(linea);
         QStringList md = lineaCompleta.split(",");

         pepe.idCourse =md[0].toInt();
         strcpy(pepe.nameCourse,md[1].toStdString().c_str());

         fsalida.write(reinterpret_cast<char *>(&pepe),sizeof(typeCourseRegister));

      }
   }
   archivo.clear();
   archivo.close();
   fsalida.close();
}
/**
 * @brief GeneratorDB::generatorCards
 * @param dir_file_txt_in
 * @param dir_file_binary_out
 */
void GeneratorDB::generatorCalification(string dir_file_txt_in, string dir_file_binary_out)
{
   ifstream archivo(dir_file_txt_in);
   ofstream fsalida(dir_file_binary_out,ios::out | ios::binary);

   char linea[256];
   typeCalificationRegister pepe;

   if(archivo.fail())
      cerr << "Error al abrir el archivo calification.txt" << endl;
   else
   {
      while(archivo.getline(linea, sizeof(linea)))
      {

         QString lineaCompleta(linea);
         if(lineaCompleta.isEmpty())
         {
            break;
         }
         QStringList md = lineaCompleta.split(",");

         pepe.idEvaluation =md[0].toInt();
         pepe.idCourse = md[1].toInt();
         pepe.calification = md[2].toFloat();
         strcpy(pepe.observation,md[3].toStdString().c_str());
         pepe.idCed = md[4].toInt();
         pepe.idCalification = md[5].toInt();

         fsalida.write(reinterpret_cast<char *>(&pepe),sizeof(typeCalificationRegister));

      }
   }
   archivo.close();
   fsalida.close();
}

/**
 * @brief GeneratorDB::generatorBankTransactions
 * @param dir_file_txt_in string contain to addres for file in and its name example /home/entrada.txt.
 * @param dir_file_binary_out string contain addres for file out example /home/something/outside.dat
 */
void GeneratorDB::generatorAssistance(string dir_file_txt_in, string dir_file_binary_out)
{
   ifstream archivo(dir_file_txt_in);
   ofstream fsalida(dir_file_binary_out,ios::out | ios::binary);

   char linea[128];
   typeAssistanceRegister pepe;

   if(archivo.fail())
      cerr << "Error al abrir el archivo assistance.txt" << endl;
   else
   {
      while(archivo.getline(linea, sizeof(linea)))
      {
         QString lineaCompleta(linea);

         if(lineaCompleta.isEmpty())
         {
            break;
         }
         QStringList md = lineaCompleta.split(",");

         pepe.idCourse = md[0].toInt();
         pepe.idCed = md[1].toInt();
         strcpy(pepe.fechaAssistance, md[2].toStdString().c_str());
         pepe.totalAssistance = md[3].toInt();
         pepe.porcentAssistance = md[4].toInt();
         pepe.idAssistance = md[5].toInt();

         fsalida.write(reinterpret_cast<char *>(&pepe),sizeof(typeAssistanceRegister));

      }
   }
   archivo.close();
   fsalida.close();

}

void GeneratorDB::generatorRelationSC(string dir_file_txt_in, string dir_file_binary_out)
{
   ifstream archivo(dir_file_txt_in);
   ofstream fsalida(dir_file_binary_out,ios::out | ios::binary);

   char linea[128];
   typeRelationStudentCourseRegister pepe;

   if(archivo.fail())
      cerr << "Error al abrir el archivo relationSC.txt" << endl;
   else
   {
      while(archivo.getline(linea, sizeof(linea)))
      {
         QString lineaCompleta(linea);

         if(lineaCompleta.isEmpty())
         {
            break;
         }
         QStringList md = lineaCompleta.split(",");

         pepe.idCed = md[0].toInt();
         pepe.idCourse = md[1].toInt();

         fsalida.write(reinterpret_cast<char *>(&pepe),sizeof(typeRelationStudentCourseRegister));

      }
   }
   archivo.close();
   fsalida.close();

}

void GeneratorDB::generatorEvaluation(string dir_file_txt_in, string dir_file_binary_out)
{
   ifstream archivo(dir_file_txt_in);
   ofstream fsalida(dir_file_binary_out,ios::out | ios::binary);

   char linea[128];
   typeEvaluationRegister pepe;

   if(archivo.fail())
      cerr << "Error al abrir el archivo relationSC.txt" << endl;
   else
   {
      while(archivo.getline(linea, sizeof(linea)))
      {
         QString lineaCompleta(linea);

         if(lineaCompleta.isEmpty())
         {
            break;
         }
         QStringList md = lineaCompleta.split(",");

         pepe.idEvaluation = md[0].toInt();
         pepe.idCourse = md[1].toInt();
         strcpy(pepe.description, md[2].toStdString().c_str());
         pepe.porcent = md[3].toFloat();

         fsalida.write(reinterpret_cast<char *>(&pepe),sizeof(typeEvaluationRegister));
      }
   }
   archivo.close();
   fsalida.close();
}

void GeneratorDB::generatorAll(string dir_file_person_txt_in, string dir_file_person_binary_out,
                               string dir_file_course_txt_in, string dir_file_course_binary_out,
                               string dir_file_calification_txt_in, string dir_file_calification_binary_out,
                               string dir_file_assistance_txt_in, string dir_file_assistance_binary_out,
                               string dir_file_relationsc_txt_in, string dir_file_relationsc_binary_out,
                               string dir_file_evaluation_txt_in, string dir_file_evaluation_binary_out)
{
   generatorPerson(dir_file_person_txt_in, dir_file_person_binary_out);
   generatorCourse(dir_file_course_txt_in, dir_file_course_binary_out);
   generatorCalification(dir_file_calification_txt_in, dir_file_calification_binary_out);
   generatorAssistance(dir_file_assistance_txt_in, dir_file_assistance_binary_out);
   generatorRelationSC(dir_file_relationsc_txt_in,dir_file_relationsc_binary_out);
   generatorEvaluation(dir_file_evaluation_txt_in, dir_file_evaluation_binary_out);
}
