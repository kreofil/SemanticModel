#include <iostream>
//#include <fstream>
//#include <sstream>

//using namespace std;

#include "module.h"
#include "creator.h"

void testBaseScalarVar() {
    std::cout << "Using scalar variables test\n";
    std::cout << "===========================\n\n";

    Module module;      // Формирование тестовой единицы компиляции
    //Creator creator;
    module.setModuleName("Hello");
    NameTable* nt = module.getLocalNameTable();

    // Создание целочисленной переменной
    // Поиск артефакта в общем пространстве имен
    Artefact* aTmp = nt->globalFind("INTEGER");
    TypeContext* tc = dynamic_cast<TypeContext*>(aTmp->getContext());
    if(tc != nullptr) {
        VarContext* vContext = Creator::CreateVarContext(tc);
        module.addArtefact("intVar01", vContext, true);
    }

    // Создание второй (закрытой) целочисленной переменной
    // Поиск артефакта в общем пространстве имен
    aTmp = nt->globalFind("INTEGER");
    tc = dynamic_cast<TypeContext*>(aTmp->getContext());
    if(tc != nullptr) {
        VarContext* vContext = Creator::CreateVarContext(tc);
        module.addArtefact("intVar02", vContext, false);
    }

    // Создание булевской переменной
    // Поиск артефакта в общем пространстве имен
    aTmp = nt->globalFind("BOOLEAN");
    tc = dynamic_cast<TypeContext*>(aTmp->getContext());
    if(tc != nullptr) {
        VarContext* vContext = Creator::CreateVarContext(tc);
        module.addArtefact("boolVar01", vContext, true);
    }

    // Создание действительной переменной
    // Поиск артефакта в общем пространстве имен
    aTmp = nt->globalFind("REAL");
    tc = dynamic_cast<TypeContext*>(aTmp->getContext());
    if(tc != nullptr) {
        VarContext* vContext = Creator::CreateVarContext(tc);
        module.addArtefact("realVar01", vContext, true);
    }

    // Создание символьной переменной
    // Поиск артефакта в общем пространстве имен
    aTmp = nt->globalFind("CHAR");
    tc = dynamic_cast<TypeContext*>(aTmp->getContext());
    if(tc != nullptr) {
        VarContext* vContext = Creator::CreateVarContext(tc);
        module.addArtefact("charVar01", vContext, true);
    }

    // Создание множественной переменной
    // Поиск артефакта в общем пространстве имен
    aTmp = nt->globalFind("SET");
    tc = dynamic_cast<TypeContext*>(aTmp->getContext());
    if(tc != nullptr) {
        VarContext* vContext = Creator::CreateVarContext(tc);
        module.addArtefact("setVar01", vContext, true);
    }


    module.debugOut();
}
