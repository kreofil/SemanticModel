#ifndef CONST_H
#define CONST_H

#include "context.h"

// Варианты констант
//enum ConstTypes {cnstInt=0, cnstReal, cnstBool, cnstString};
enum class ConstType {Int=0, Real, Bool, String};

// Класс, определяющий контекст константы.
// Предполагается, что в языке существуют константы основных типов
class ConstContext: public Context {
public:
    // Конструктор, задающий общий контекст для констант и конкретный тип константы
    explicit ConstContext(ConstType cnstType): Context{ContextType::Const}, constType{cnstType}
    {}

    // Вывод отладочной информации о контексте импорта
    virtual void debugOut();

private:
    ConstType constType;
};

/*
// Класс, определяющий контекст целочисленной константы.
class ConstIntContext: public ConstContext {
public:
    // Создание целочисленной константы
    ConstIntContext(int v): value(v) {}

    // Вывод отладочной информации о целочисленной константе
    virtual void debugOut();
private:
    // Значение константы
    int value;
};
*/

// Класс, определяющий контекст константы.
template<typename T>
class ConstValueContext: public ConstContext {
public:
    ///ConstValueContext();
    // Создание целочисленной константы
    explicit ConstValueContext(ConstType cnstType, T v):ConstContext{cnstType}, value{v}
    {}

    // Вывод отладочной информации о целочисленной константе
    virtual void debugOut();
private:
    // Значение константы
    T value;
};

#endif // CONST_H
