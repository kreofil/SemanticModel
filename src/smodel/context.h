#ifndef CONTEXT_H
#define CONTEXT_H

#include <iostream>
#include <string>

// Варианты контекстов, используемых в семантической модели
enum class ContextType {
    Type=0,
    Const,
    Var,
    Import,
    Proc,
};

// Класс, определяющий назначение различных типов программных объектов
class Context {
public:
    // Установка общего начального контекста
    explicit Context(ContextType ct, std::string* pn = nullptr): contextType{ct}, pName{pn} {}

    // Вывод отладочной информации о назначении контекста
    virtual void debugOut() = 0;

    // Получение информации о контексте
    ContextType getContextType() { return contextType;}
    // Получение информации об имени
    std::string* getNamePtr() { return pName; }       // Указатель на имя, связанное с контекстом

private:
    ContextType contextType;   // Хранилище типа контекста
    std::string* pName;        // Указатель на имя, связанное с контекстом
};

#endif // CONTEXT_H
