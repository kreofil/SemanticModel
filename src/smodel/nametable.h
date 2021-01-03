#ifndef NAMETABLE_H
#define NAMETABLE_H

#include <iostream>
#include <string>
#include <vector>

#include "artefact.h"

// Класс, определяющий однуровневую таблицу имен (артефактов),
// которая может являться составной частью пространства таблиц имен.

class NameTable {
public:
    // Основной конструктор, обеспечивающий начальную инициализацию таблицы имен
    explicit NameTable(NameTable* system = nullptr, NameTable* parent = nullptr):
        parentNameTablePtr{system}, systemNameTablePtr{parent} {}

    // Получение доступа к родительской таблице имен
    NameTable* getParent() {return parentNameTablePtr;}
    // Установка указателя на родительскую таблицу имен
    void setParent(NameTable* parent) {parentNameTablePtr = parent;}

    // Получение доступа к системной таблице имен
    NameTable* getSystem() {return systemNameTablePtr;}
    // Установка указателя на родительскую таблицу имен
    void setSystem(NameTable* system) {systemNameTablePtr = system;}

    // Поиск артефакта в текущей таблице имен по имени
    Artefact* find(std::string &name);
    // Поиск артефакта в общем пространстве имен
    Artefact* globalFind(std::string&& name);
    // Поиск артефакта в системной таблице.
    Artefact* systemFind(std::string& name) {
        if(systemNameTablePtr != nullptr) {return systemNameTablePtr->find(name);}
        return nullptr;
    }
    // Проверка на отсутствие артефакта в локальной и системной таблицах
    bool isAbsentInLocalAndSystemTables(std::string& name) {
        if(systemFind(name)) {return false;}
        if(find(name)) {return false;}
        return true;    // отсутствует
    }

    // Добавление артефакта в таблицу
    void append(Artefact* a) {artefacts.push_back(a);}

    // Отладочный вывод таблицы имен
    void debugOut();
private:
    // Вектор артефактов, определяющий содержание таблицы имен
    std::vector<Artefact*> artefacts;
    // Указатель на родительскую таблицу имен
    NameTable* parentNameTablePtr;
    // Указатель на системную таблицу имен, являющуюся приоритетной
    NameTable* systemNameTablePtr;
};

#endif // NAMETABLE_H
