#include <iostream>

#include "instruction.h"

//=============================================================================
// Конструктор для базовой команды
Instruction::Instruction(OpCode opc, Instruction* next):
    opCode(opc),
    nextInstr(next)
{}

// Получение строки для кода операции
std::string Instruction::getString()
{
    switch(opCode) {
    case OpCode::Nop:       return "NOP";
    case OpCode::Add:       return "ADD";
    case OpCode::Sub:       return "SUB";
    case OpCode::Mul:       return "MUL";
    case OpCode::Div:       return "DIV";
    case OpCode::ModP:      return "MOD";
    case OpCode::ModC:      return "MOD";
    case OpCode::Goto:      return "GOTO";
    case OpCode::IfFalse:   return "IFFALSE";
    case OpCode::IfTrue:    return "IFTRUE";
    case OpCode::Minus:     return "MINUS";
    case OpCode::Label:     return "LABEL";

    default:    return "Unknown Instruction";
    }
}

// Вывод отладочной информации
void Instruction::debugOut()
{
    std::cout << getString() << " ";
}

//=============================================================================
// Установка статического счетчика меток
int InstructionLabel::labelsNumber = 0;    // количество зарегистрированных меток

// Конструктор команды-метки
InstructionLabel::InstructionLabel(Instruction* next):
    Instruction(OpCode::Label, next)
{
    labelId = labelsNumber++;
}

// Вывод отладочной информации
void InstructionLabel::debugOut()
{
    Instruction::debugOut();
    // Далее идет отладочный вывод, идентифицирующий метку
    std::cout << labelId; // << "\n";
}

//=============================================================================
// Конструктор команды безусловного перехода
InstructionGoto::InstructionGoto(InstructionLabel* gotoLabel, Instruction* next):
    Instruction(OpCode::Goto, next),
    opLabel{gotoLabel}
{}

// Вывод отладочной информации
void InstructionGoto::debugOut()
{
    Instruction::debugOut();
    // Далее идет отладочный вывод, идентифицирующий метку
    if(opLabel != nullptr) {
        std::cout << opLabel->getId(); // << "\n";
    } else {
        std::cout << "Label is absent!"; //\n";
    }
}

//=============================================================================
// Конструктор команды условного перехода по true
InstructionIfTrue::InstructionIfTrue(Operand* opd, InstructionLabel* gotoLabel, Instruction* next):
    Instruction(OpCode::IfTrue, next),
    operand{opd},
    opLabel{gotoLabel}
{}

// Вывод отладочной информации
void InstructionIfTrue::debugOut()
{
    Instruction::debugOut();
    // Отладочный код, идентифицирующий операнд
    if(operand != nullptr) {
        operand->debugOut(); // << "\n";
    } else {
        std::cout << "Operand is absent!"; //\n";
    }
    // Далее идет отладочный вывод, идентифицирующий метку
    if(opLabel != nullptr) {
        std::cout << " GOTO " << opLabel->getId(); // << "\n";
    } else {
        std::cout << "Label is absent!"; //\n";
    }
}

//=============================================================================
// Конструктор команды условного перехода по false
InstructionIfFalse::InstructionIfFalse(Operand* opd, InstructionLabel* gotoLabel, Instruction* next):
    Instruction(OpCode::IfFalse, next),
    operand{opd},
    opLabel{gotoLabel}
{}

// Вывод отладочной информации
void InstructionIfFalse::debugOut()
{
    Instruction::debugOut();
    // Отладочный код, идентифицирующий операнд
    if(operand != nullptr) {
        operand->debugOut(); // << "\n";
    } else {
        std::cout << "Operand is absent!"; //\n";
    }
    // Далее идет отладочный вывод, идентифицирующий метку
    if(opLabel != nullptr) {
        std::cout << " GOTO " << opLabel->getId(); // << "\n";
    } else {
        std::cout << "Label is absent!"; //\n";
    }
}

//=============================================================================
// Конструктор унарной команды
InstructionUno::InstructionUno(OpCode opc, Operand* opd, Instruction* next):
    Instruction(opc, next),
    operand{opd}
{}

// Вывод отладочной информации
void InstructionUno::debugOut()
{
    Instruction::debugOut();
    // Отладочный код, идентифицирующий операнд
    if(operand != nullptr) {
        operand->debugOut(); // << "\n";
    } else {
        std::cout << "Operand is absent!"; //\n";
    }
}

