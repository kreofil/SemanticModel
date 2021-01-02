#ifndef TYPE_H
#define TYPE_H

#include <string>
#include <vector>

#include "artefact.h"

// Варианты типов
enum TypeTypes {tpBool=0, tpInt, tpReal, tpChar, tpSet, tpRecord, tpPtr};

//=============================================================================
// Класс, задающий обобщение для всех типов языка
class TypeContext: public Context {
public:
    // Конструктор контекста типа
    explicit TypeContext(TypeTypes tpType): Context{ContextType::Type}, typeType{tpType}
    {}

    // Получение размера типа
    int getTypeSize() { return typeSize; }

    // Вывод отладочной информации о базовом типе
    virtual void debugOut();
protected:
    // Размер типа
    int typeSize;
private:
    TypeTypes typeType;
};

//=============================================================================
// Класс, определяющий булевский тип
class TypeBoolContext: public TypeContext {
public:
    // Создание типа и определение его размера
    explicit TypeBoolContext():TypeContext{tpBool} {
        typeSize = sizeof(bool);
    }

    // Вывод отладочной информации о типе
    virtual void debugOut();
};

//=============================================================================
// Класс, определяющий целочисленный тип
class TypeIntegerContext: public TypeContext {
public:
    // Создание типа и определение его размера
    explicit TypeIntegerContext():TypeContext{tpInt} {
        typeSize = sizeof(int);
    }

    // Вывод отладочной информации о типе
    virtual void debugOut();
};

//=============================================================================
// Класс, определяющий действительный тип
class TypeRealContext: public TypeContext {
public:
    // Создание типа и определение его размера
    explicit TypeRealContext():TypeContext{tpReal} {
        typeSize = sizeof(double);
    }

    // Вывод отладочной информации о типе
    virtual void debugOut();
};

//=============================================================================
// Класс, определяющий символьный тип
class TypeCharContext: public TypeContext {
public:
    // Создание типа и определение его размера
    explicit TypeCharContext():TypeContext{tpChar} {
        typeSize = sizeof(char);
    }

    // Вывод отладочной информации о типе
    virtual void debugOut();
};

//=============================================================================
// Класс, определяющий множественный тип
class TypeSetContext: public TypeContext {
public:
    // Создание типа и определение его размера
    explicit TypeSetContext():TypeContext{tpSet} {
        typeSize = sizeof(unsigned);
    }

    // Вывод отладочной информации о типе
    virtual void debugOut();
};

//=============================================================================
// Класс, определяющий тип "запись"
class TypeRecordContext: public TypeContext {
public:
    // Создание оболочки типа и задание его контекста
    explicit TypeRecordContext(TypeRecordContext* p = nullptr):TypeContext{tpRecord}, parentContext(p) {
        typeSize = 0;
    }

    // Добавление к записи именованного поля
    void AddNamedModuleField(std::string name, TypeContext* typeContext, bool access = true);

    // Вывод отладочной информации о записи
    virtual void debugOut();
private:
    // Родительский контекст (если присутствует, иначе nullptr)
    TypeRecordContext* parentContext;
    // Список именованных типов записи, объявленной в модуле
    std::vector<Artefact> namedFields;
};

//=============================================================================
// Класс, определяющий тип - указатель
class TypePointerContext: public TypeContext {
public:
    // Создание типа и определение его размера
    TypePointerContext(TypeRecordContext* r = nullptr):TypeContext{tpPtr}, recordType(r) {
        typeSize = sizeof(int*);
    }

    // Вывод отладочной информации о типе
    virtual void debugOut();
private:
    TypeRecordContext* recordType;    // указатель ссылается только на запись
};

#endif // TYPE_H
