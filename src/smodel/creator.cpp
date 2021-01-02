#include "creator.h"
#include "import.h"
#include "const.h"
#include "type.h"

/*
Creator::Creator()
{

}
*/

// Создание контекста импорта
ImportContext* Creator::CreateImportContext(std::string importedName, std::string alias) {
    return new ImportContext(importedName, alias);
}

// Создание целочисленной константы
ConstContext* Creator::CreateConstInt(int v) {
    return new ConstValueContext<int>(ConstType::Int, v);
}

// Создание действительной константы
ConstContext* Creator::CreateConstReal(double v) {
    return new ConstValueContext<double>(ConstType::Real, v);
}

// Создание булевской константы
ConstContext* Creator::CreateConstBool(bool v) {
    return new ConstValueContext<bool>(ConstType::Bool, v);
}

// Создание строковой константы
ConstContext* Creator::CreateConstString(std::string v) {
    return new ConstValueContext<std::string>(ConstType::String, v);
}

// Создание целочисленного типа
TypeIntegerContext* Creator::CreateTypeInt() {
    return new TypeIntegerContext();
}

// Создание действительного типа
TypeRealContext* Creator::CreateTypeReal() {
    return new TypeRealContext();
}

// Создание булевского типа
TypeBoolContext* Creator::CreateTypeBool()  {
    return new TypeBoolContext();
}

// Создание символьного типа
TypeCharContext* Creator::CreateTypeChar() {
    return new TypeCharContext();
}

// Создание множественного типа
TypeSetContext* Creator::CreateTypeSet() {
    return new TypeSetContext();
}

// Создание типа Запись (пустой оболочки)
TypeRecordContext* Creator::CreateTypeRecord(TypeRecordContext* parent) {
    return new TypeRecordContext(parent);
}

// Создание типа-указателя на запись
TypePointerContext* Creator::CreateTypePointer(TypeRecordContext* r) {
    return new TypePointerContext(r);
}

// Создание переменной с установкой соответствующего типа
VarContext* Creator::CreateVariable(TypeContext* type) {
    return new VarContext(type);
}

//----------------------------------------------------------------------
// Создание объектов, определяющих формирование списка команд
//----------------------------------------------------------------------

// Создание списка команд
InstructionList* Creator::CreateInstructionList() {
    return new InstructionList();
}

// Создание команды-метки
InstructionLabel* Creator::CreateInstructionLabel(Instruction* next) {
    return new InstructionLabel(next);
}

// Создание команды безусловного перехода
InstructionGoto* Creator::CreateInstructionGoto(InstructionLabel* gotoLabel, Instruction* next) {
    return new InstructionGoto(gotoLabel, next);
}
