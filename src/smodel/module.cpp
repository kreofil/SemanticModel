#include "module.h"

std::string CommonData::moduleName{""};  // имя модуля
// Список артефактов с зарезервированными именами
std::vector<Artefact*> CommonData::reservedArtefacts;
// Список именованных артефактов, порождаемых в модуле
std::vector<Artefact*> CommonData::artefacts;

// Таблица артефактов с зарезервированными именами (системная таблица)
NameTable CommonData::systemNameTable{nullptr, nullptr};

// формирование системной таблицы имен. Создаются общие для всех артефакты и их контексты.
// Данные имена привязаны к текущему языку и должны быть переопределены
// для языка с другим синтаксисом.
void CommonData::fillSystemNameTable() {
    // Целочисленный тип с именем INTEGER (для Оберона-7)
    static TypeIntegerContext integerContext;
    static Artefact integerArtefact{"INTEGER", &integerContext, true};
    systemNameTable.append(&integerArtefact);

    // Действительный тип с именем REAL (для Оберона-7)
    static TypeRealContext realContext;
    static Artefact realArtefact{"REAL", &realContext, true};
    systemNameTable.append(&realArtefact);

    // Булевский тип с именем BOOLEAN (для Оберона-7)
    static TypeBoolContext boolContext;
    static Artefact boolArtefact{"BOOLEAN", &boolContext, true};
    systemNameTable.append(&boolArtefact);

    // Символьный тип с именем CHAR (для Оберона-7)
    static TypeCharContext charContext;
    static Artefact charArtefact{"CHAR", &charContext, true};
    systemNameTable.append(&charArtefact);

    // Множественный тип с именем SET (для Оберона-7)
    static TypeSetContext setContext;
    static Artefact setArtefact{"SET", &setContext, true};
    systemNameTable.append(&setArtefact);
}

Module::Module(): CommonData(nullptr) {
    fillSystemNameTable();
}

// Добавление именованного артефакта
void Module::addArtefact(std::string name, Context* context, bool access) {
    Artefact* tmpNamed = new Artefact{name, context, access};
    artefacts.push_back(tmpNamed);

    // Добавление артефакта в локальную таблицу модуля
    if(localNameTable.isAbsentInLocalAndSystemTables(name)) {
        localNameTable.append(tmpNamed);
    }
}

// Вывод отладочной информации о модуле
void Module::debugOut() {
    std::cout << "Module " << CommonData::moduleName << "\n\n";
    std::cout << "++++++++++++++++++++++++\n\n";

    std::cout << "Reserved artefats:\n";
    std::cout << "------------------\n";
    systemNameTable.debugOut();
/*
    std::cout << "\nArtefats:\n";
    std::cout << "---------\n";
    for(Artefact* artefact: artefacts) {
        std::cout << artefact->getName() << (artefact->getAccess()? "*: ":": ");
        artefact->getContext()->debugOut();
        std::cout << std::endl;
    }
*/
    std::cout << "\nModule Name Table:\n";
    std::cout << "---------\n";
    localNameTable.debugOut();

    std::cout << "\nInitInsructionBlock:\n";
    std::cout << "----------------------\n";
    initInsructionBlock.debugOut();
    std::cout << "\nFinalInsructionBlock:\n";
    std::cout << "----------------------\n";
    finalInsructionBlock.debugOut();
}
