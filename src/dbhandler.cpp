#include "../include/dbhandler.h"
#include"evaluation.h"




void Dbhandler::setMapStudent(const QMap<int, Student*>& value)
{
   mapStudent = value;
}

QMap<int, Course*> &Dbhandler::getMapCourse()
{
   return mapCourse;
}

void Dbhandler::setMapCourse(const QMap<int, Course*>& value)
{
   mapCourse = value;
}

QMap<int, Assistance*> &Dbhandler::getMapAssistance()
{
   return mapAssistance;
}

void Dbhandler::setMapAssistance(const QMap<int, Assistance*>& value)
{
   mapAssistance = value;
}

QMap<int, Calification*> & Dbhandler::getMapCalification()
{
   return mapCalification;
}

void Dbhandler::setMapCalification(const QMap<int, Calification*>& value)
{
   mapCalification = value;
}

QMap<int, Evaluation*> &Dbhandler::getMapEvaluation()
{
   return mapEvaluation;
}

void Dbhandler::setMapEvaluation(const QMap<int, Evaluation*>& value)
{
   mapEvaluation = value;
}

void Dbhandler::addCourseToQmap( Course* course)
{

   mapCourse.insert(course->getIdCourse(),course);
}

void Dbhandler::addStudentToQmap(Student* student)
{
   mapStudent.insert(student->getCedula(),student);
}

void Dbhandler::addEvaluationToQmap(Evaluation* evaluation)
{

   mapEvaluation.insert(evaluation->getIdEvaluation(),evaluation);
}

void Dbhandler::addCalificationToQmap(Calification* calification)
{
   mapCalification.insert(calification->getIdCalification(), calification);
}

void Dbhandler::addAssistanceToQmap(Assistance* assistance)
{
   mapAssistance.insert(assistance->getIdAssistance(), assistance);
}

Dbhandler::Dbhandler()
{

}

Dbhandler::~Dbhandler()
{
   foreach (Course *course, mapCourse) {
      //      QMap<int, Course*>::iterator it = mapCourse.find(course->getIdCourse());
      //      mapCourse.erase(it);
      delete course;
   }

   foreach(Student *student, mapStudent)
   {
      delete student;
   }

   foreach (Calification *calification, mapCalification) {
      delete calification;
   }

   foreach (Evaluation * evaluation, mapEvaluation) {
      delete evaluation;
   }

   foreach (Assistance *assistance, mapAssistance) {
      delete assistance;
   }

}



/**
 * @brief BankCashier::loadUser
 * @param dir_file_person_binary_out
 */
void Dbhandler::loadStudent(string dir_file_person_binary_out)
{
   typePersonRegister pepe2;

   ifstream fentrada(dir_file_person_binary_out,
                     ios::binary);

   fentrada.read(reinterpret_cast<char *>(&pepe2),
                 sizeof(typePersonRegister));

   while(!fentrada.eof())
   {
      Student * user= new Student;
      (*user) = pepe2;

      mapStudent.insert(user->getCedula(),user);
      fentrada.read(reinterpret_cast<char *>(&pepe2),
                    sizeof(typePersonRegister));
   }

   fentrada.close();
}

void Dbhandler::generateDbQmapCourseToBinary()
{
   typeCourseRegister pepe;
   ofstream fsalida("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",
                    ios::out | ios::binary);
   foreach (Course* course, this->getMapCourse())
   {
      pepe = (*course);
      fsalida.write(reinterpret_cast<char *>(&pepe),sizeof(typeCourseRegister));
   }

   fsalida.close();
}

void Dbhandler::generateDbQmapStudentToBinary()
{
   typePersonRegister tStudentR;
   ofstream fsalida3("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                     ios::out | ios::binary);
   foreach (Student* student, this->getMapStudent())
   {
      tStudentR = (*student);
      fsalida3.write(reinterpret_cast<char *>(&tStudentR),sizeof(typePersonRegister));
   }
   fsalida3.close();
}

void Dbhandler::generateDbQmapEvaluationToBinary()
{
   typeEvaluationRegister pepe2;
   ofstream fsalida2("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat",
                     ios::out | ios::binary);
   foreach (Evaluation* eval, this->getMapEvaluation())
   {
      pepe2 = (*eval);
      fsalida2.write(reinterpret_cast<char *>(&pepe2),sizeof(typeEvaluationRegister));
   }
   fsalida2.close();
}

void Dbhandler::generateDbQmapCalificationToBinary()
{
   typeCalificationRegister pepe1;
   ofstream fsalida1("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                     ios::out | ios::binary);
   foreach (Calification* cali, this->getMapCalification())
   {
      pepe1 = (*cali);
      fsalida1.write(reinterpret_cast<char *>(&pepe1),sizeof(typeCalificationRegister));
   }

   fsalida1.close();
}

void Dbhandler::generateDbQmapAssistanceToBinary()
{
   typeAssistanceRegister pepe;
   ofstream fsalida("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                    ios::out | ios::binary);
   foreach (Assistance* assistance, this->getMapAssistance())
   {
      pepe = (*assistance);
      fsalida.write(reinterpret_cast<char *>(&pepe),sizeof(typeAssistanceRegister));
   }

   fsalida.close();
}

void Dbhandler::generateDbQmapCourseRelationStudentToBinary()
{
   typeRelationStudentCourseRegister tStudent;
   ofstream fsalidar("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                     ios::out | ios::binary);

   foreach (Course* course, this->getMapCourse())
   {
      QList<Student* > students = course->getStudents();
      QList<Student*>::iterator it = students.begin();
      while(it != students.end())
      {
         tStudent.idCed = (*it)->getCedula();
         tStudent.idCourse = course->getIdCourse();
         fsalidar.write(reinterpret_cast<char *>(&tStudent),sizeof(typeRelationStudentCourseRegister));
         ++it;
      }
   }
   fsalidar.close();
}

void Dbhandler::generateDbQmapStudentRelationCourseToBinary()
{
   typeRelationStudentCourseRegister tStudent;
   ofstream fsalidar("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                     ios::out | ios::binary);

   foreach (Student* student, this->getMapStudent())
   {
      QList<Course* > courses = student->getCourses();
      QList<Course*>::iterator it = courses.begin();
      while(it != courses.end())
      {
         tStudent.idCed = student->getCedula();
         tStudent.idCourse = (*it)->getIdCourse();
         fsalidar.write(reinterpret_cast<char *>(&tStudent),sizeof(typeRelationStudentCourseRegister));
         ++it;
      }
   }
   fsalidar.close();
}
/**
 * @brief BankCashier::loadAccount
 * @param dir_file_account_binary_out
 */
void Dbhandler::loadCourse(string dir_file_course_binary_out)
{
   typeCourseRegister pepe2;

   ifstream fentrada(dir_file_course_binary_out,
                     ios::binary);

   fentrada.read(reinterpret_cast<char *>(&pepe2),
                 sizeof(typeCourseRegister));

   while(!fentrada.eof())
   {
      Course * course= new Course();
      (*course) = pepe2;

      mapCourse.insert(course->getIdCourse(),course);
      fentrada.read(reinterpret_cast<char *>(&pepe2),
                    sizeof(typeCourseRegister));

   }

   fentrada.close();

}

void Dbhandler::loadCalification(string dir_file_calification_binary_out)
{
   typeCalificationRegister pepe2;

   ifstream fentrada(dir_file_calification_binary_out,
                     ios::binary);

   fentrada.read(reinterpret_cast<char *>(&pepe2),
                 sizeof(typeCalificationRegister));

   while(!fentrada.eof())
   {
      Calification * calification= new Calification();
      (*calification) = pepe2;

      mapCalification.insert(calification->getIdCalification(),calification);
      fentrada.read(reinterpret_cast<char *>(&pepe2),
                    sizeof(typeCalificationRegister));
   }

   fentrada.close();
}

void Dbhandler::loadAssistance(string dir_file_assistance_binary_out)
{
   typeAssistanceRegister pepe2;

   ifstream fentrada(dir_file_assistance_binary_out,
                     ios::binary);

   fentrada.read(reinterpret_cast<char *>(&pepe2),
                 sizeof(typeAssistanceRegister));

   while(!fentrada.eof())
   {
      Assistance * assistance= new Assistance();
      (*assistance) = pepe2;
      mapAssistance.insert(assistance->getIdAssistance(),assistance);
      fentrada.read(reinterpret_cast<char *>(&pepe2),
                    sizeof(typeAssistanceRegister));
   }

   fentrada.close();
}

void Dbhandler::loadEvaluation(string dir_file_evaluation_binary_out)
{
   typeEvaluationRegister pepe2;

   ifstream fentrada(dir_file_evaluation_binary_out,
                     ios::binary);

   fentrada.read(reinterpret_cast<char *>(&pepe2),
                 sizeof(typeEvaluationRegister));

   while(!fentrada.eof())
   {
      Evaluation * evaluation= new Evaluation();
      (*evaluation) = pepe2;

      mapEvaluation.insert(evaluation->getIdEvaluation(),evaluation);
      fentrada.read(reinterpret_cast<char *>(&pepe2),
                    sizeof(typeEvaluationRegister));
   }

   fentrada.close();
}

QMap<int, Student*>&Dbhandler::getMapStudent()
{
   return mapStudent;
}

void Dbhandler::loadDB(string dir_file_person_binary,
                       string dir_file_course_binary,
                       string dir_file_calification_binary,
                       string dir_file_assistance_binary,
                       string dir_file_relationsc_binary,
                       string dir_file_evaluation_binary)
{
   loadStudent(dir_file_person_binary);
   loadCourse(dir_file_course_binary);
   loadCalification(dir_file_calification_binary);
   loadAssistance(dir_file_assistance_binary);
   loadEvaluation(dir_file_evaluation_binary);

   int id;

   Student *student;
   Course *course;
   Evaluation *evaluation;
   Assistance *assistance;
   Calification *calification;

   typeRelationStudentCourseRegister pepe2;

   ifstream fentrada(dir_file_relationsc_binary,
                     ios::binary);

   fentrada.read(reinterpret_cast<char *>(&pepe2),
                 sizeof(typeRelationStudentCourseRegister));

   while(!fentrada.eof())
   {

      //      evaluation = mapEvaluation.find(pepe2.idCourse).value();
      //      assistance = mapAssistance.find(pepe2.idCed).value();
      //      calification = mapCalification.find(pepe2.idCed).value();

      if((mapCourse.contains(pepe2.idCourse)) && (mapStudent.contains(pepe2.idCed)))
      {
         course = mapCourse.find(pepe2.idCourse).value();
         student = mapStudent.find(pepe2.idCed).value();
         student->addCourseOnly(course);
         course->addStudentOnly(student);

      }

      fentrada.read(reinterpret_cast<char *>(&pepe2),
                    sizeof(typeRelationStudentCourseRegister));
   }

   fentrada.close();

   /**
 * relation beetwen course and evaluation.
 *
 **/
   foreach (Evaluation* evaluation, mapEvaluation)
   {

      id =  evaluation->getIdCourse();
      if(mapCourse.contains(id))
      {
         Course* course1 = mapCourse.find(id).value();
         if(course1->getIdCourse() == id)
            course1->addEvaluation(evaluation);

      }

   }

   /**
      *relation between Assistance and course
      *
      */
   foreach (Assistance* assistance, mapAssistance)
   {

      id =  assistance->getIdCourse();
      if(mapCourse.contains(id))
      {
         Course* course1 = mapCourse.find(id).value();
         if(course1->getIdCourse() == id)
            course1->addAssistance(assistance);


      }

   }
   /**
      *relation between Calification and evaluation
      *
      */
   foreach (Calification * calification, mapCalification)
   {
      id =  calification->getIdEvaluation(); //creo que no hace falta

      if(mapEvaluation.contains(id))
      {
         Evaluation* evaluation =  mapEvaluation.find(id).value();
         if(evaluation->getIdEvaluation() == id)
         evaluation->addCalification(calification);
      }

   }

}
