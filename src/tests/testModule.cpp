#include <iostream>
//#include <fstream>
//#include <sstream>

//using namespace std;

#include "module.h"
#include "creator.h"

void testModule() {
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

    VarContext* vContext = Creator::CreateVarContext(Creator::CreateTypeReal());
    module.addArtefact("var1", vContext);
    tContext = Creator::CreateTypeReal();
    module.addArtefact("Real", tContext, true);
    vContext = Creator::CreateVarContext(tContext);
    module.addArtefact("var2", vContext, true);

    // Создание списка команд для блока инициализации
    auto pInitInstructions = module.getInitInstructionBlock();
    InstructionLabel* pLabel00 = Creator::CreateInstructionLabel();
    pInitInstructions->addInstructionToTail(pLabel00);
    InstructionLabel* pLabel01 = Creator::CreateInstructionLabel();
    pInitInstructions->addInstructionToTail(pLabel01);
    InstructionLabel* pLabel02 = Creator::CreateInstructionLabel();
    pInitInstructions->addInstructionToTail(pLabel02);
    InstructionLabel iLabel02;
    InstructionLabel* pLabel03 = Creator::CreateInstructionLabel();
    pInitInstructions->addInstructionToTail(pLabel03);
    InstructionLabel* pLabel04 = Creator::CreateInstructionLabel();
    pInitInstructions->addInstructionToTail(pLabel04);
    InstructionGoto* pGoto01 = Creator::CreateInstructionGoto(pLabel01);
    pInitInstructions->addInstructionToTail(pGoto01);

    // Создание списка команд для блока финализации
    auto pFinalInstructions = module.getFinalInstructionBlock();
    pLabel00 = Creator::CreateInstructionLabel();
    pFinalInstructions->addInstructionToHead(pLabel00);
    pLabel01 = Creator::CreateInstructionLabel();
    pFinalInstructions->addInstructionToHead(pLabel01);
    pLabel02 = Creator::CreateInstructionLabel();
    pFinalInstructions->addInstructionToHead(pLabel02);
    pLabel03 = Creator::CreateInstructionLabel();
    pFinalInstructions->addInstructionToHead(pLabel03);
    pLabel04 = Creator::CreateInstructionLabel();
    pFinalInstructions->addInstructionToHead(pLabel04);
    pGoto01 = Creator::CreateInstructionGoto(pLabel01);
    pFinalInstructions->addInstructionToHead(pGoto01);

    module.debugOut();
}
