#ifndef CREATOR_H
#define CREATOR_H

#include <string>

#include "context.h"
#include "import.h"
#include "const.h"
#include "type.h"
#include "variable.h"
#include "module.h"
#include "instruction.h"
#include "ilist.h"


// Класс, обеспечивающий создание различных артефактов
class Creator
{
public:
    //Creator();

    // Создание контекста импорта
    static ImportContext* CreateImportContext(std::string importedName, std::string alias);

    // Создание целочисленной константы
    static ConstContext* CreateConstInt(int v);
    // Создание действительной константы
    static ConstContext* CreateConstReal(double v);
    // Создание булевской константы
    static ConstContext* CreateConstBool(bool v);
    // Создание строковой константы
    static ConstContext* CreateConstString(std::string v);

    // Создание целочисленного типа
    static TypeIntegerContext* CreateTypeInt();
    // Создание действительного типа
    static TypeRealContext* CreateTypeReal();
    // Создание булевского типа
    static TypeBoolContext* CreateTypeBool();
    // Создание символьного типа
    static TypeCharContext* CreateTypeChar();
    // Создание множественного типа
    static TypeSetContext* CreateTypeSet();

    // Создание типа Запись (пустой оболочки)
    static TypeRecordContext* CreateTypeRecord(TypeRecordContext* parent = nullptr);

    // Создание типа-указателя на запись
    static TypePointerContext* CreateTypePointer(TypeRecordContext* r);

    // Создание переменной с установкой соответствующего типа
    static VarContext* CreateVariable(TypeContext* type);

    //----------------------------------------------------------------------
    // Создание объектов, определяющих формирование списка команд
    //----------------------------------------------------------------------

    // Создание списка команд
    static InstructionList* CreateInstructionList();

    // Создание команды-метки
    static InstructionLabel* CreateInstructionLabel(Instruction* next=nullptr);
    // Создание команды безусловного перехода
    static InstructionGoto* CreateInstructionGoto(InstructionLabel* gotoLabel, Instruction* next=nullptr);

};

#endif // CREATOR_H
