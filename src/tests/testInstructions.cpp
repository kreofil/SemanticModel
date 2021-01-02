#include <iostream>
//#include <fstream>
//#include <sstream>

//using namespace std;

#include "ilist.h"
#include "creator.h"

void testInstructions() {
    std::cout << "Semantic model Instruction List test\n";
    std::cout << "===================\n\n";



    // Создание списка команд, заполняемого командами и операндами
    InstructionList* piList = Creator::CreateInstructionList();
    InstructionLabel* pLabel00 = Creator::CreateInstructionLabel();
    piList->addInstructionToHead(pLabel00);
    InstructionLabel* pLabel01 = Creator::CreateInstructionLabel();
    piList->addInstructionToHead(pLabel01);
    InstructionLabel* pLabel02 = Creator::CreateInstructionLabel();
    piList->addInstructionToHead(pLabel02);
    InstructionLabel iLabel02;
    InstructionLabel* pLabel03 = Creator::CreateInstructionLabel();
    piList->addInstructionToTail(pLabel03);
    InstructionLabel* pLabel04 = Creator::CreateInstructionLabel();
    piList->addInstructionToTail(pLabel04);
    InstructionGoto* pGoto01 = Creator::CreateInstructionGoto(pLabel01);
    piList->addInstructionToTail(pGoto01);

    piList->debugOut();
/*
    ConstContext* cContext = Creator::CreateConstInt(10);
    cContext->debugOut();
    //delete cContext;
    cContext = Creator::CreateConstReal(3.14);
    cContext->debugOut();
    cContext = Creator::CreateConstBool(true);
    cContext->debugOut();
    cContext = Creator::CreateConstString("Hello, World!");
    cContext->debugOut();
    ///cContext->debugInfoAboutName();

    TypeContext* tContext = Creator::CreateTypeInt();
    tContext = Creator::CreateTypeBool();
    tContext = Creator::CreateTypeChar();
    tContext = Creator::CreateTypeSet();

    TypeRecordContext* recordType = Creator::CreateTypeRecord();
    tContext = Creator::CreateTypeSet();
    recordType->AddNamedModuleField("f1", tContext, true);
    tContext = Creator::CreateTypeReal();
    recordType->AddNamedModuleField("f5", tContext, true);
    tContext = Creator::CreateTypeBool();
    recordType->AddNamedModuleField("f3", tContext, false);

    TypeRecordContext* recordType2 = Creator::CreateTypeRecord(recordType);
    tContext = Creator::CreateTypeSet();
    recordType2->AddNamedModuleField("c1", tContext, true);
    tContext = Creator::CreateTypeBool();
    recordType2->AddNamedModuleField("c2", tContext, false);

    TypePointerContext* pContext = Creator::CreateTypePointer(recordType);

    VarContext* vContext = Creator::CreateVariable(Creator::CreateTypeReal());
    tContext = Creator::CreateTypeReal();
    vContext = Creator::CreateVariable(tContext);
*/
}
