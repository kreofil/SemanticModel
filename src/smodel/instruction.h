#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <string>

#include "operand.h"

//=============================================================================
// Команды семантической модели
enum class OpCode {
    Nop=0,          // Пустая операция (на всякий случай)
    Add,            // Сложение двух операндов
    Sub,            // Вычитание
    Mul,            // Умножение
    Div,            // Деление
    ModP,           // Выделение остатка в стиле Паскаля (Оберона)
    ModC,           // Выделение остатка в стиле C
    Goto,           // Безусловный переход
    IfFalse,        // Условный переход по False
    IfTrue,         // Условный переход по True
    Minus,          // Унарный минус
    Label,          // Метка как инструкция
};

//=============================================================================
// Базовый класс для всех типов команд, задающий, помимо общего интерфейса,
// порождение безоперандных команд
class Instruction {
public:
    explicit Instruction(OpCode opc=OpCode::Nop, Instruction* next=nullptr);

    // Получение указателя на следующую команду
    // (задается отношение расположения, совпадающее
    // в большинстве случаев с отношением управления)
    Instruction* getNextInstr() { return nextInstr; }
    // Подключение следующей команды к текущей
    void setNextInstr(Instruction *i) { nextInstr = i; }

    // Получение кода операции
    OpCode getOperationCode() {return opCode;}
    // Установка кода операции
    void setOperationCode(OpCode opc) {opCode = opc;}

    // Получение строки для кода операции
    std::string getString();

    // Вывод отладочной информации
    virtual void debugOut();

private:
    OpCode opCode;   // Код операции
    Instruction* nextInstr;       // Следующая команда
};

//=============================================================================
// Класс, задающий команду-метку,
// Используемую для фиксации точки перехода
// при безусловных и условных переходах
class InstructionLabel: public Instruction {
public:
    explicit InstructionLabel(Instruction* next=nullptr);

    // Получение идентификатора команды-метки
    int getId() { return labelId; }

    // Вывод отладочной информации
    virtual void debugOut();

private:
    static int labelsNumber;    // количество зарегистрированных меток
    int labelId;                // уникальный идентификатор метки
};

//=============================================================================
// Класс задающий команду безусловного перехода
// Переход осуществляется на команду-метку
class InstructionGoto: public Instruction {
public:
    explicit InstructionGoto(InstructionLabel* gotoLabel, Instruction* next=nullptr);

    // Получение указателя на метку
    InstructionLabel* getLabel() {return opLabel;}
    // Установка метки
    void setLabel(InstructionLabel* label) {opLabel = label;}

    // Вывод отладочной информации
    virtual void debugOut();

private:
    InstructionLabel* opLabel;    // команда-метка
};

//=============================================================================
// Класс задающий команду условного перехода по true
// Переход осуществляется на команду-метку или будет выполняться следующая команда
class InstructionIfTrue: public Instruction {
public:
    explicit InstructionIfTrue(Operand* opd, InstructionLabel* gotoLabel, Instruction* next=nullptr);

    // Получение указателя на метку
    InstructionLabel* getLabel() {return opLabel;}
    // Установка метки
    void setLabel(InstructionLabel* label) {opLabel = label;}

    // Вывод отладочной информации
    virtual void debugOut();

private:
    Operand* operand;             // булевский операнд, значение которого определяет ветвление
    InstructionLabel* opLabel;    // команда-метка
};

//=============================================================================
// Класс задающий команду условного перехода по false
// Переход осуществляется на команду-метку или будет выполняться следующая команда
class InstructionIfFalse: public Instruction {
public:
    explicit InstructionIfFalse(Operand* opd, InstructionLabel* gotoLabel, Instruction* next=nullptr);

    // Получение указателя на метку
    InstructionLabel* getLabel() {return opLabel;}
    // Установка метки
    void setLabel(InstructionLabel* label) {opLabel = label;}

    // Вывод отладочной информации
    virtual void debugOut();

private:
    Operand* operand;             // булевский операнд, значение которого определяет ветвление
    InstructionLabel* opLabel;    // команда-метка
};

//=============================================================================
// Класс задающий унарную команду
class InstructionUno: public Instruction {
public:
    explicit InstructionUno(OpCode opc=OpCode::Nop, Operand* opd = nullptr, Instruction* next=nullptr);

    // Получение указателя на операнд
    Operand* getOperand() {return operand;}
    // Установка указателя на операнд
    void setOperand(Operand* opd) {operand = opd;}

    // Вывод отладочной информации
    virtual void debugOut();

private:
    Operand* operand;             // булевский операнд, значение которого определяет ветвление
};

#endif // INSTRUCTION_H
