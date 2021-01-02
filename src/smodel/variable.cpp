#include "variable.h"

// Конструктор для создания переменной заданного типа
VarContext::VarContext(TypeContext* type): Context{ContextType::Var}, context(type) {}

// Вывод общей отладочной информации о переменной
void VarContext::debugOut() {
    std::cout << "VAR ";
    // Добавление информации о типе переменной
    context->debugOut();
}

