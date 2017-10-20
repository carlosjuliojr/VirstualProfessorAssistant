#include"../include/model.h"
#include <QDebug>

Course* Model::readCourse(const unsigned int idCourse)
{
   return model->getMapCourse().find(idCourse).value();
}

Student*Model::readStudent(const unsigned int idStudent)
{
   return model->getMapStudent().find(idStudent).value();
}

Assistance*Model::readAssistance(const unsigned int idAssistance)
{
   return model->getMapAssistance().find(idAssistance).value();
}

//Assistance*Model::readAssistanceOnlyStudent(const unsigned int idCedAssistance)
//{
//   return model->getMapAssistance().find(idCedAssistance).value();
//}

Evaluation* Model::readEvalutation(const unsigned int idEvaluation)
{
   return model->getMapEvaluation().find(idEvaluation).value();
}

Calification*Model::readCalification(const unsigned int idCedStudent)
{
   return model->getMapCalification().find(idCedStudent).value();
}

const QMap<int, Student*>& Model::getMapStudentAll() const
{
   return (model->getMapStudent());
}

const QMap<int, Evaluation*>& Model::getMapEvaluationAll() const
{
   return model->getMapEvaluation();
}

const QMap<int, Calification*>& Model::getMapCalificationAll() const
{
   return model->getMapCalification();
}

const QMap<int, Assistance*>& Model::getMapAssistanceAll() const
{
   return model->getMapAssistance();
}

const QList<Student*>Model::readStudentsByIdCourse(const unsigned int idCourse) const
{

   return model->getMapCourse().find(idCourse).value()->getStudents();

}

const QList<Evaluation*> Model::readEvaluationsByIdCourse(const unsigned int idCourse) const
{
   return model->getMapCourse().find(idCourse).value()->getEvaluations();

}

const QList<Assistance*> Model::readAssistancesByIdCourse(const unsigned int idCourse) const
{
   return model->getMapCourse().find(idCourse).value()->getAssistances();

}

const QList<Course*> Model::readCoursesByIdCed(const unsigned int idCed) const
{
   return model->getMapStudent().find(idCed).value()->getCourses();
}

const QList<Calification*> Model::readCalificationsByIdEvaluation(const unsigned int idEv) const
{
   return model->getMapEvaluation().find(idEv).value()->getCalifications();
}

const QList<Calification*>& Model::readCalificationsByIdCourse(const unsigned int idCourse) const
{
   QList<Calification*>* qlC = new QList<Calification*>;


   foreach (Calification* cal, model->getMapCalification()) {
      if(cal->getIdCourse() == idCourse)
         qlC->append(cal);
   }
   return (*qlC);
}

bool Model::createCourse(const QString nameCourse)
{
   int cont = model->getMapCourse().size();
   while(model->getMapCourse().contains(cont))
      cont++;

   if(model->getMapCourse().contains(cont))
      return false;
   else
   {

      Course * course = new Course( cont, nameCourse);
      typeCourseRegister pepe;

      ofstream fsalida("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",ios::app | ios::binary);

      model->addCourseToQmap(course);

      pepe.idCourse = course->getIdCourse();
      strcpy(pepe.nameCourse, course->getNameCourse().toStdString().c_str());

      fsalida.write(reinterpret_cast<char *>(&pepe),sizeof(typeCourseRegister));
      fsalida.close();
      return true;
   }

}

bool Model::createStudent(QString nombre, QString apellido, int cedula, QString correoElectronico)
{

   if(model->getMapStudent().contains(cedula))
      return false;
   else
   {

      typePersonRegister pepe;
      Student * student= new Student(nombre, apellido, cedula, correoElectronico);

      ofstream fsalida("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",ios::app | ios::binary);

      model->addStudentToQmap(student);

      strcpy(pepe.nombre, nombre.toStdString().c_str());
      strcpy(pepe.apellido,apellido.toStdString().c_str());
      pepe.cedula= cedula;
      strcpy(pepe.correoElectronico,correoElectronico.toStdString().c_str());

      fsalida.write(reinterpret_cast<char *>(&pepe),sizeof(typePersonRegister));
      fsalida.close();
      return true;
   }
}

bool Model::createEvaluation( unsigned int idCourse, QString description, float porcen)
{
   int cont = model->getMapEvaluation().size();
   while(model->getMapEvaluation().contains(cont))
      cont++;

   if(model->getMapEvaluation().contains(cont))
      return false;
   else
   {

      typeEvaluationRegister pepe;
      Evaluation * evaluation= new Evaluation(cont, idCourse, description, porcen);

      ofstream fsalida("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat",ios::app | ios::binary);

      model->addEvaluationToQmap(evaluation);

      pepe.idEvaluation = cont;
      pepe.idCourse = idCourse;
      strcpy(pepe.description, description.toStdString().c_str());
      pepe.porcent = porcen;

      fsalida.write(reinterpret_cast<char *>(&pepe),sizeof(typeEvaluationRegister));
      fsalida.close();
      return true;
   }
}

bool Model::createCalification(unsigned int idEvaluation, unsigned int idCourse, float calification, QString observation, unsigned int idCed)
{
   int cont = model->getMapCalification().size();
   while(model->getMapCalification().contains(cont))
      cont++;

   if(model->getMapCalification().contains(cont))
      return false;
   else
   {

      typeCalificationRegister pepe;

      Calification * calification1= new Calification(idEvaluation, idCourse, calification, observation, idCed, cont);

      ofstream fsalida("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",ios::app | ios::binary);

      model->addCalificationToQmap(calification1);

      pepe.idEvaluation = idEvaluation;
      pepe.idCourse = idCourse;
      pepe.calification = calification;
      strcpy(pepe.observation, observation.toStdString().c_str());
      pepe.idCed = idCed;
      pepe.idCalification = cont;

      fsalida.write(reinterpret_cast<char *>(&pepe),sizeof(typeCalificationRegister));
      fsalida.close();
   }
}

bool Model::createAssistance(unsigned int idCourse, unsigned int idCed, QDateTime fechaAssistance, unsigned int totalAssistance, unsigned int porcentAssistance)
{
   int cont = model->getMapAssistance().size();
   while(model->getMapAssistance().contains(cont))
      cont++;

   if(model->getMapAssistance().contains(cont))
      return false;
   else
   {

      typeAssistanceRegister pepe;
      Assistance* assistance= new Assistance(idCourse, idCed, fechaAssistance, totalAssistance, porcentAssistance, cont);

      ofstream fsalida("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",ios::app | ios::binary);

      model->addAssistanceToQmap(assistance);

      pepe.idCourse = idCourse;
      pepe.idCed = idCed;
      strcpy(pepe.fechaAssistance, fechaAssistance.toString("yyyy:MM:dd").toStdString().c_str());
      pepe.totalAssistance = totalAssistance;
      pepe.porcentAssistance = porcentAssistance;
      pepe.idAssistance = cont;

      fsalida.write(reinterpret_cast<char *>(&pepe),sizeof(typeAssistanceRegister));
      fsalida.close();
      return true;
   }
}

bool Model::addStudentToCourse(const unsigned int idCed,const unsigned int idCourse)
{
   typeRelationStudentCourseRegister pepe2, pepe;

   ifstream fentrada("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",
                     ios::binary);
   ofstream fsalida("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/relationSC.dat",ios::app | ios::binary);

   fentrada.read(reinterpret_cast<char *>(&pepe2),
                 sizeof(typeRelationStudentCourseRegister));

   while(!fentrada.eof())
   {

      if(pepe2.idCed == idCed && pepe2.idCourse == idCourse){

         fsalida.close();
         fentrada.close();
         return false;
      }

      fentrada.read(reinterpret_cast<char *>(&pepe2),
                    sizeof(typeRelationStudentCourseRegister));
   }

   //   if(!model->getMapCourse().contains(idCourse) || !model->getMapStudent().contains(idCed))

   Student*  student = model->getMapStudent().find(idCed).value();
   Course*  course  = model->getMapCourse().find(idCourse).value();

   student->addCourseOnly(course);
   course->addStudentOnly(student);
   pepe.idCed = idCed;
   pepe.idCourse = idCourse;

   fentrada.close();

   fsalida.write(reinterpret_cast<char *>(&pepe),
                 sizeof(typeRelationStudentCourseRegister));

   //   std::cout<<"cedulaRFuntion: "<<pepe.idCed <<" CourseRFuntion: " << pepe.idCourse <<std::endl;


   fsalida.close();

   return true;
}

bool Model::addEvaluationToCourse(const unsigned int idEvaluation,
                                  const unsigned int idCourse)
{


   if(model->getMapEvaluation().contains(idEvaluation) == false || model->getMapCourse().contains(idCourse) == false)
   {
      return false;
   }
   else
   {
      Evaluation* evaluation = model->getMapEvaluation().find(idEvaluation).value();
      model->getMapCourse().find(idCourse).value()->addEvaluation(evaluation);
      return true;
   }
}

bool Model::addAssistanceToCourse(const unsigned int idCourse,
                                  const unsigned int idCed,
                                  const unsigned int idAssistance)
{
   if(model->getMapAssistance().contains(idAssistance) == false || model->getMapCourse().contains(idCourse) == false || model->getMapStudent().contains(idCed) == false)
   {
      return false;
   }
   else
   {
      Assistance* assistance = model->getMapAssistance().find(idAssistance).value();
      assistance->setIdCed(idCed);
      assistance->setIdCourse(idCourse);
      model->getMapCourse().find(idCourse).value()->addAssistance(assistance);
      return true;
   }

}

bool Model::addCalificationToEvaluation(const unsigned int idCalification, const unsigned int idEvaluation)
{
   if(model->getMapCalification().contains(idCalification) == false || model->getMapEvaluation().contains(idEvaluation) == false)
   {
      return false;
   }
   else
   {
      Calification* calification= model->getMapCalification().find(idCalification).value();
      calification->setIdEvaluation(idEvaluation);
      model->getMapEvaluation().find(idEvaluation).value()->addCalification(calification);
      return true;
   }

}

bool Model::updateCourse(const unsigned int idCourse, const QString nameCourse)
{
   if(model->getMapCourse().contains(idCourse))
   {
      Course* course = model->getMapCourse().find(idCourse).value();
      course->setNameCourse(nameCourse);
      typeCourseRegister pepe;
      ofstream fsalida( "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/course.dat",ios::out | ios::binary);
      foreach (Course * course, model->getMapCourse())
      {
         pepe.idCourse = course->getIdCourse();
         strcpy(pepe.nameCourse,course->getNameCourse().toStdString().c_str());

         fsalida.write(reinterpret_cast<char *>(&pepe),sizeof(typeCourseRegister));

      }
      fsalida.close();
      return true;
   }
   else
      return false;
}

bool Model::updateStudent(const QString nombre,
                          const QString apellido,
                          const int cedula,
                          const QString correoElectronico)
{
   if(model->getMapStudent().contains(cedula))
   {
      Student* student= model->getMapStudent().find(cedula).value();
      typePersonRegister pepe;


      student->setNombre(nombre);
      student->setApellido(apellido);
      student->setCorreoElectronico(correoElectronico);

      ofstream fsalida("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/prueba.dat",
                       ios::out | ios::binary);
      foreach (Student * student, model->getMapStudent())
      {
         strcpy(pepe.nombre , student->getNombre().toStdString().c_str());
         strcpy(pepe.apellido , student->getApellido().toStdString().c_str());
         pepe.cedula = student->getCedula();
         strcpy(pepe.correoElectronico, student->getCorreoElectronico().toStdString().c_str());

         fsalida.write(reinterpret_cast<char *>(&pepe),sizeof(typePersonRegister));

      }
      fsalida.close();
      return true;
   }
   else
      return false;
}

bool Model::updateEvaluation(const unsigned int idEvaluation, const unsigned int idCourse, const QString description, const float porcent)
{
   if(model->getMapEvaluation().contains(idEvaluation))
   {
      Evaluation* evaluation= model->getMapEvaluation().find(idEvaluation).value();
      typeEvaluationRegister pepe;

      evaluation->setIdEvaluation(idEvaluation);
      evaluation->setIdCourse(idCourse);
      evaluation->setDescription(description);
      evaluation->setPorcent(porcent);

      ofstream fsalida("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/evaluation.dat",
                       ios::out | ios::binary);
      foreach (Evaluation* evaluation, model->getMapEvaluation())
      {

         pepe.idEvaluation = evaluation->getIdEvaluation();
         pepe.idCourse = evaluation->getIdCourse();
         strcpy(pepe.description, evaluation->getDescription().toStdString().c_str());
         pepe.porcent = evaluation->getPorcent();

         fsalida.write(reinterpret_cast<char *>(&pepe),sizeof(typeEvaluationRegister));

      }
      fsalida.close();
      return true;
   }
   else
      return false;
}

bool Model::updateCalification(const unsigned int idEvaluation,
                               const unsigned int idCourse,
                               const float calification1,
                               const QString observation,
                               const unsigned int idCed,
                               const unsigned int idCalification)
{
   if(model->getMapCalification().contains(idCalification))
   {
      Calification* calification= model->getMapCalification().find(idCalification).value();
      typeCalificationRegister pepe;

      calification->setIdEvaluation(idEvaluation);
      calification->setIdCed(idCed);
      calification->setIdCourse(idCourse);
      calification->setCalification(calification1);
      calification->setIdCalification(idCalification);
      calification->setObservation(observation);

      ofstream fsalida("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/calification.dat",
                       ios::out | ios::binary);
      foreach (Calification* calification, model->getMapCalification())
      {

         pepe.idEvaluation = calification->getIdEvaluation();
         pepe.idCourse = calification->getIdCourse();
         pepe.calification = calification->getCalification();
         strcpy(pepe.observation,calification->getObservation().toStdString().c_str());
         pepe.idCed = calification->getIdCed();
         pepe.idCalification = calification->getIdCalification();

         fsalida.write(reinterpret_cast<char *>(&pepe),sizeof(typeCalificationRegister));

      }
      fsalida.close();
      return true;
   }
   else
      return false;
}

bool Model::updateAssistance(const unsigned int idCourse,
                             const unsigned int idCed,
                             const QDateTime fechaAssistance,
                             const unsigned int totalAssistance,
                             const unsigned int porcentAssistance,
                             const unsigned int idAssistance)
{
   if(model->getMapAssistance().contains(idAssistance))
   {
      Assistance* assistance= model->getMapAssistance().find(idAssistance).value();
      typeAssistanceRegister pepe;

      assistance->setIdCourse(idCourse);
      assistance->setIdCed(idCed);
      assistance->setFechaAssistance(fechaAssistance);
      assistance->setTotalAssistance(totalAssistance);
      assistance->setPorcentAssistance(porcentAssistance);

      ofstream fsalida("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/tests/dbhandler/assistance.dat",
                       ios::out | ios::binary);
      foreach (Assistance* assistance, model->getMapAssistance())
      {

         pepe.idCourse = assistance->getIdCourse();
         pepe.idCed = assistance->getIdCed();
         strcpy(pepe.fechaAssistance, assistance->getFechaAssistance().toString("yyyy:MM:dd").toStdString().c_str());
         pepe.totalAssistance = assistance->getTotalAssistance();
         pepe.porcentAssistance = assistance->getPorcentAssistance();
         pepe.idAssistance = assistance->getIdAssistance();

         fsalida.write(reinterpret_cast<char *>(&pepe),sizeof(typeAssistanceRegister));

      }
      fsalida.close();
      return true;
   }
   else
      return false;
}

bool Model::deleteCourse(const unsigned int idCourse)
{
   if(model->getMapCourse().contains(idCourse))
   {
      Course* course = model->getMapCourse().find(idCourse).value();
      QList<Student* > students = course->getStudents();

      /*******************Para eliminar la relacion de la list de courses en estudiantes*************************************/
      foreach (Student* student, students)
      {
         QList<Course* > &courses = student->getCourses();
         QList<Course*>::iterator it = courses.begin();

         while(it!=courses.end())
         {
            if((*it)->getIdCourse() == idCourse)
               it = courses.erase(it);
            else
               ++it;
         }

      }

      QMap<int, Assistance* >& mapAssist = model->getMapAssistance();
      QMap<int, Assistance* >::iterator it = mapAssist.begin();

      while(it != mapAssist.end())
      {
         Assistance* as = it.value();
         if(as->getIdCourse() == idCourse)
         {
            it = mapAssist.erase(it);
            delete as;
         }
         else
            ++it;
      }


      QMap<int, Calification* >& calification= model->getMapCalification();
      QMap<int, Calification* >::iterator itc = calification.begin();

      while(itc != calification.end())
      {
         Calification* cal = itc.value();
         if(cal->getIdCourse() == idCourse)
         {
            itc = model->getMapCalification().erase(itc);
            delete cal;
         }
         else
            ++itc;
      }


      QMap<int, Evaluation* >& mapEvaluation = model->getMapEvaluation();
      QMap<int, Evaluation* >::iterator itEvaluation = mapEvaluation.begin();
      while(itEvaluation != mapEvaluation.end())
      {
         Evaluation* eval = itEvaluation.value();
         if(eval->getIdCourse() == idCourse)
         {
            eval->getCalifications().clear();
            itEvaluation = mapEvaluation.erase(itEvaluation);
            delete eval;
         }
         else
            ++itEvaluation;
      }


      course->getStudents().clear();
      course->getAssistances().clear();
      course->getEvaluations().clear();

      QMap<int,Course*>& qmcourse = model->getMapCourse();
      QMap<int, Course* >::iterator itt = qmcourse.find(idCourse);

      qmcourse.erase(itt);
      delete course;

      /**************************updateRalation between Student and Course in data base********************************/

      model->generateDbQmapStudentRelationCourseToBinary();
      /****************************updateCourse in DB***********/
      model->generateDbQmapCourseToBinary();
      /***updateRalation between Student and Course in data base****/
      model->generateDbQmapStudentToBinary();
      /****updateCalification in data base**************************/
      model->generateDbQmapCalificationToBinary();
      /*******updateAssistance in DB********************************/
      model->generateDbQmapAssistanceToBinary();
      /*********updateEvaluation in DB******************************/
      model->generateDbQmapEvaluationToBinary();
      /*****************************************************************************************************************/

      return true;
   }
   else
      return false;
}
/**
 * @brief Model::deleteStudent
 * @param idCedula
 * @return
 */
bool Model::deleteStudent(const unsigned int idCedula)
{
   if(model->getMapStudent().contains(idCedula))
   {
      QMap<int,Course*> &qmcourse = model->getMapCourse();

      /*******************Para eliminar la relacion de la list de courses en estudiantes*************************************/
      foreach (Course* course, qmcourse)
      {
         QList<Student*> &students = course->getStudents();
         QList<Student*>::iterator it = students.begin();

         while(it != students.end())
         {
            if((*it)->getCedula() == idCedula)
            {
               it = students.erase(it);

            }
            else
               ++it;
         }

         //list Assistance in course
         QList<Assistance* > & assistances = course->getAssistances();
         QList<Assistance* >::iterator ita =assistances.begin();

         while(ita != assistances.end())
         {
            if((*ita)->getIdCed() == idCedula)
            {
               Assistance* as= (*ita);

               QMap<int, Assistance*> & qmAssistance = model->getMapAssistance();
               QMap<int, Assistance*>::iterator itqmA = qmAssistance.find(as->getIdAssistance());

               itqmA = qmAssistance.erase(itqmA);
               ita = assistances.erase(ita);

               delete as;
            }
            else
               ++ita;
         }
         //list Evaluation in course and list calification
         QList<Evaluation* > evaluations = course->getEvaluations();
         QList<Evaluation* >::iterator itEvaluation =evaluations.begin();

         while(itEvaluation != evaluations.end())
         {
            QList<Calification*> califications = (*itEvaluation)->getCalifications();
            QList<Calification* >::iterator itCalification = califications.begin();
            while(itCalification != califications.end())
            {
               if((*itCalification)->getIdCed() == idCedula)
               {
                  Calification* cal= (*itCalification);
                  QMap<int, Calification* > & qmCal = model->getMapCalification();
                  QMap<int, Calification* >::iterator itqmCal = qmCal.find(cal->getIdCalification());
                  itqmCal = qmCal.erase(itqmCal);
                  itCalification = califications.erase(itCalification);
                  delete cal;
               }
               else
                  ++itCalification;
            }
            itEvaluation++;
         }

      }

      QMap<int, Student*> &qmstu = model->getMapStudent();
      QMap<int, Student*>::iterator itStu = qmstu.find(idCedula);
      Student* stu = (*itStu);
      qmstu.erase(itStu);
      delete stu;


      /**************************updateRalation between Course and Student in data base********************************/
      model->generateDbQmapCourseRelationStudentToBinary();
      /********************************updateAssistance**********************************************************/
      model->generateDbQmapAssistanceToBinary();
      /******************updateCalification***********************************************************************/
      model->generateDbQmapCalificationToBinary();
      //      /******************updateEvaluation*******************************************************************************/
      //      model->generateDbQmapEvaluationToBinary();
      /***********************************updateStudent******************************************************************************/
      model->generateDbQmapStudentToBinary();

      return true;
   }
   else
      return false;
}

bool Model::deleteEvaluation(const unsigned int idEvaluation)
{
   if(model->getMapEvaluation().contains(idEvaluation))
   {
      QMap<int,Course*> &qmcourse = model->getMapCourse();

      /*******************Para eliminar la relacion de la list de courses en estudiantes*************************************/
      foreach (Course* course, qmcourse)
      {

         //list Evaluation in course and list calification
         QList<Evaluation* > &evaluations = course->getEvaluations();
         QList<Evaluation* >::iterator itEvaluation =evaluations.begin();

         while(itEvaluation != evaluations.end())
         {
            QList<Calification*> &califications = (*itEvaluation)->getCalifications();
            QList<Calification* >::iterator itCalification = califications.begin();
            while(itCalification != califications.end())
            {
               if((*itCalification)->getIdEvaluation() == idEvaluation)
               {
                  Calification* cal= (*itCalification);
                  QMap<int, Calification* >& qmCal = model->getMapCalification();
                  QMap<int, Calification* >::iterator itqmCal = qmCal.find(cal->getIdCalification());

                  itqmCal = qmCal.erase(itqmCal);
                  itCalification = califications.erase(itCalification);
                  delete cal;

               }
               else
                  ++itCalification;
            }
            // lo saco de la lista evaluation en course
            if((*itEvaluation)->getIdEvaluation() == idEvaluation)
               itEvaluation = evaluations.erase(itEvaluation);
            else
               itEvaluation++;
         }

      }
      /******************Liberar memoria para evaluation***********************************************************************/
      QMap<int, Evaluation*> &qmEvaluation = model->getMapEvaluation();
      QMap<int, Evaluation*>::iterator itEvall = qmEvaluation.find(idEvaluation);
      qmEvaluation.erase(itEvall);
      delete itEvall.value();

      //****************updateCalification in data Base*************************************//
      model->generateDbQmapCalificationToBinary();

      /******************UpdateEvaluation in the data base****************************************************************/
      model->generateDbQmapEvaluationToBinary();
      return true;
   }
   else
      return false;
}

bool Model::deleteCalification(const unsigned int idCalification)
{
   if(model->getMapCalification().contains(idCalification))
   {

      QMap<int, Calification* >& qmCal = model->getMapCalification();
      QMap<int, Calification* >::iterator itqmCal = qmCal.find(idCalification);
      if(model->getMapEvaluation().contains((*itqmCal)->getIdEvaluation()))
      {
         Evaluation* qmEvaluation= model->getMapEvaluation().find((*itqmCal)->getIdEvaluation()).value();

         QList<Calification*> &califications = qmEvaluation->getCalifications();
         QList<Calification* >::iterator itCalification = califications.begin();

         while(itCalification != califications.end())
         {
            if((*itCalification)->getIdCalification() == idCalification)
            {
               Calification* cal= (*itCalification);
               itqmCal = qmCal.erase(itqmCal);
               itCalification = califications.erase(itCalification);
               delete cal;
               //****************updateCalification in data Base*************************************//
               model->generateDbQmapCalificationToBinary();
               return true;
            }
            else
               ++itCalification;
         }

      }else{
         Calification* cal= itqmCal.value();
         itqmCal = qmCal.erase(itqmCal);
         delete cal;
         //****************updateCalification in data Base*************************************//
         model->generateDbQmapCalificationToBinary();
         return true;

      }
   }
   else
      return false;

}

bool Model::deleteAssistance(const unsigned int idAssistance)
{
   if(model->getMapAssistance().contains(idAssistance))
   {

      QMap<int, Assistance* >& qmAssistance = model->getMapAssistance();
      QMap<int, Assistance* >::iterator itqmAss = qmAssistance.find(idAssistance);
      //aqui va el if contains
      if(model->getMapCourse().contains((*itqmAss)->getIdCourse()))
      {
         Course* course= model->getMapCourse().find((*itqmAss)->getIdCourse()).value();

         QList<Assistance*>& assistances = course->getAssistances();
         QList<Assistance* >::iterator itAssistance = assistances.begin();

         while(itAssistance != assistances.end())
         {
            if((*itAssistance)->getIdAssistance()== idAssistance)
            {
               Assistance* assist = (*itAssistance);
               itqmAss = qmAssistance.erase(itqmAss);
               itAssistance= assistances.erase(itAssistance);
               delete assist;
               //****************updateAssistance in data Base*************************************//
               model->generateDbQmapAssistanceToBinary();
               return true;
            }
            else
               ++itAssistance;
         }

      }//cierra aca el if contains
      else
      {

         Assistance* assist = itqmAss.value();
         qmAssistance.erase(itqmAss);
         qDebug()<<assist->getIdCed()<<"Cedula";
         delete assist;
         //****************updateAssistance in data Base*************************************//
         model->generateDbQmapAssistanceToBinary();
         return true;
      }
   }
   else
      return false;

}


const QMap<int, Course*>& Model::getMapCourseAll() const
{
   return model->getMapCourse();
}

Dbhandler* Model::getModel() const
{
   return model;
}

void Model::setModel(Dbhandler* value)
{
   model = value;
}
