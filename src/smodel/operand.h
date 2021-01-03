#ifndef OPERAND_H
#define OPERAND_H

#include "context.h"

// Типы операндов
enum class OperandType {Var = 0, TmpVar, Const,};

// Класс, определяющий основу для различных операндов, обрабатываемых инструкциями
class Operand
{
public:
    explicit Operand(OperandType opdType, Context* ctx = nullptr);

    // Вывод отладочной информации
    virtual void debugOut();
protected:
    OperandType operandType;    // Тип операнда (определяет возможный контекст)
    Context* context;   // назначение операнда
};

// Операнд - именованная переменная, формируемая в описании переменных
class OperandVar: public Operand {
public:
    explicit OperandVar(Context* ctx = nullptr): Operand(OperandType::Var, ctx)
    {}

    // Вывод отладочной информации
    virtual void debugOut();
};

// Операнд - временная переменная, формируемая в выражениях
class OperandTmpVar: public Operand {
public:
    explicit OperandTmpVar(Context* ctx = nullptr): Operand(OperandType::TmpVar, ctx)
    {}

    // Вывод отладочной информации
    virtual void debugOut();
};

// Операнд - константа, формируемая в описании констант или непосредственно в коде
class OperandConst: public Operand {
public:
    explicit OperandConst(Context* ctx = nullptr): Operand(OperandType::Const, ctx)
    {}

    // Вывод отладочной информации
    virtual void debugOut();
};

#endif // OPERAND_H
