#ifndef OPERAND_H
#define OPERAND_H

#include "context.h"

// Типы операндов
enum class OperandType {Var = 0, TmpVar, Const,};

// Класс, определяющий основу для различных операндов, обрабатываемых инструкциями
class Operand
{
public:
    explicit Operand(Context* ctx = nullptr);

    // Вывод отладочной информации
    virtual void debugOut();
private:
    OperandType operandType;    // Тип операнда (определяет возможный контекст)
    Context* context;   // назначение операнда
};

#endif // OPERAND_H
