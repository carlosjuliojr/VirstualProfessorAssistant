#include"../../src/libs/dataBaseGenerator/databasegenerator.h"


using namespace std;


int main()
{

GeneratorDB gDB;
//gDB.generatorPerson("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/utilityAplication/generatorDB/persona.txt","prueba.dat");
//gDB.generatorCourse("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/utilityAplication/generatorDB/course.txt","course.dat");
//gDB.generatorAssistance("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/utilityAplication/generatorDB/assistance.txt","assistance.dat");
//gDB.generatorCalification("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/utilityAplication/generatorDB/calification.txt","calification.dat");
//gDB.generatorRelationSC("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/utilityAplication/generatorDB/relationSC.txt","relationSC.dat");

gDB.generatorAll("/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/utilityAplication/generatorDB/persona.txt","prueba.dat",
                 "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/utilityAplication/generatorDB/course.txt","course.dat",
                 "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/utilityAplication/generatorDB/calification.txt","calification.dat",
                 "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/utilityAplication/generatorDB/assistance.txt","assistance.dat",
                 "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/utilityAplication/generatorDB/relationSC.txt","relationSC.dat",
                 "/home/julio/Documentos/Qt/Proyectos/VirtualProfessorAssistant/utilityAplication/generatorDB/evaluation.txt","evaluation.dat"
);

return 0;

}

