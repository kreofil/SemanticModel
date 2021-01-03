#ifndef MODULE_H
#define MODULE_H

#include <iostream>
#include <string>
#include <vector>

#include "artefact.h"
#include "nametable.h"
#include "ilist.h"
#include "type.h"

// Класс определяющий данные, непосредственно доступные для модуля и процедур
class CommonData {
protected:
    // Конструктор, инициализирующий указатели локальной таблицы
    explicit CommonData(NameTable* parent = nullptr):
        localNameTable(&systemNameTable, parent) {}

    // формирование системной таблицы имен. Создаются общие для всех артефакты и их контексты.
    // Данные имена привязаны к текущему языку и должны быть переопределены
    // для языка с другим синтаксисом.
    static void fillSystemNameTable();

    static std::string moduleName;  // имя модуля
    // Список артефактов с зарезервированными именами
    static std::vector<Artefact*> reservedArtefacts;
    // Список именованных артефактов, порождаемых в модуле
    static std::vector<Artefact*> artefacts;


    // Таблица артефактов с заризервированными именами (системная таблица)
    static NameTable systemNameTable;
    // Локальная таблица текущего программного объекта (модуля, процедуры)
    NameTable localNameTable;
public:
    // Получение указателя на локальную таблицу имен, с которой можно начинать поиск
    NameTable* getLocalNameTable() {return &localNameTable;}
};

// Класс, определяющий модуль семантической модели.
// Содержит все данные, описывающие артефакты языка программирования
class Module: public CommonData {
    friend class Creator;
public:
    Module();

    // Установка имени модуля
    void setModuleName(std::string mn) { moduleName = mn; }

    // Добавление именованного артефакта
    void addArtefact(std::string name, Context* context, bool access = false);

    // Получение ссылки на блок инициализации
    InstructionList* getInitInstructionBlock() {return &initInsructionBlock;}
    // Получение ссылки на блок инициализации
    InstructionList* getFinalInstructionBlock() {return &finalInsructionBlock;}

    // Вывод отладочной информации о модуле
    void debugOut();

private:
    // Список команд, осуществляющих инициализацию модуля
    InstructionList initInsructionBlock;
    // Список команд, осуществляющих финализацию модуля
    InstructionList finalInsructionBlock;
};

#endif // MODULE_H
