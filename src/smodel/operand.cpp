#include "operand.h"

Operand::Operand(OperandType opdType, Context *ctx): operandType(opdType), context{ctx}
{}

// Вывод отладочной информации
void Operand::debugOut() {
    //std::cout << "OPERAND ";
    if(context != nullptr) {
        context->debugOut();
    } else {
        std::cout << "Context is NULL";
    }
}

// Вывод отладочной информации
void OperandVar::debugOut() {
    std::cout << "VAR OPERAND ";
    Operand::debugOut();
}

// Вывод отладочной информации
void OperandTmpVar::debugOut() {
    std::cout << "TMPVAR OPERAND ";
    Operand::debugOut();
}

// Вывод отладочной информации
void OperandConst::debugOut() {
    std::cout << "CONST OPERAND ";
    Operand::debugOut();
}

