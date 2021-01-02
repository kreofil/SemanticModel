#ifndef VARIABLE_H
#define VARIABLE_H

#include "type.h"

// Класс, задающий контекст для всех переменых
class VarContext: public Context {
public:
    // Конструктор для создания переменной заданного типа
    VarContext(TypeContext* type = nullptr);

    // Получение информации о типе переменой
    TypeContext* getType() { return context; }
    // Установка типа переменной
    void setType(TypeContext* type) { context = type; }

    // Вывод отладочной информации о базовом типе
    virtual void debugOut();
private:
    TypeContext* context;   // Тип переменной
};

#endif // VARIABLE_H
