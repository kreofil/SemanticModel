#include <iostream>
//#include <fstream>
//#include <sstream>

//using namespace std;

#include "module.h"
#include "creator.h"

void test01() {
    std::cout << "Semantic model test\n";
    std::cout << "===================\n\n";

    Module module;      // Формирование тестовой единицы компиляции
    //Creator creator;
    module.setModuleName("Hello");

    ImportContext* iContext = Creator::CreateImportContext("M", "AM");
    module.addArtefact("AM", iContext);
    ///iContext->debugInfoAboutName();

    ConstContext* cContext = Creator::CreateConstInt(10);
    module.addArtefact("Ten", cContext, true);
    cContext = Creator::CreateConstReal(3.14);
    module.addArtefact("pi", cContext);
    cContext = Creator::CreateConstBool(true);
    module.addArtefact("t", cContext);
    cContext = Creator::CreateConstString("Hello, World!");
    module.addArtefact("hello", cContext, true);
    ///cContext->debugInfoAboutName();

    TypeContext* tContext = Creator::CreateTypeInt();
    module.addArtefact("Int", tContext, true);
    tContext = Creator::CreateTypeBool();
    module.addArtefact("Bool", tContext, true);
    tContext = Creator::CreateTypeChar();
    module.addArtefact("Char", tContext);
    tContext = Creator::CreateTypeSet();
    module.addArtefact("Set", tContext, false);

    TypeRecordContext* recordType = Creator::CreateTypeRecord();
    tContext = Creator::CreateTypeSet();
    recordType->AddNamedModuleField("f1", tContext, true);
    tContext = Creator::CreateTypeReal();
    recordType->AddNamedModuleField("f5", tContext, true);
    tContext = Creator::CreateTypeBool();
    recordType->AddNamedModuleField("f3", tContext, false);
    module.addArtefact("Record", recordType);

    TypeRecordContext* recordType2 = Creator::CreateTypeRecord(recordType);
    tContext = Creator::CreateTypeSet();
    recordType2->AddNamedModuleField("c1", tContext, true);
    tContext = Creator::CreateTypeBool();
    recordType2->AddNamedModuleField("c2", tContext, false);
    module.addArtefact("ChildRecord", recordType2);

    TypePointerContext* pContext = Creator::CreateTypePointer(recordType);
    module.addArtefact("PointerToRecord", pContext, true);

    VarContext* vContext = Creator::CreateVariable(Creator::CreateTypeReal());
    module.addArtefact("var1", vContext);
    tContext = Creator::CreateTypeReal();
    module.addArtefact("Real", tContext, true);
    vContext = Creator::CreateVariable(tContext);
    module.addArtefact("var2", vContext, true);

    module.debugOut();
}
