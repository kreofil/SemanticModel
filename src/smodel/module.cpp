#include "module.h"

std::string CommonData::moduleName{""};  // имя модуля
// Список артефактов с зарезервированными именами
std::vector<Artefact*> CommonData::reservedArtefacts;
// Список именованных артефактов, порождаемых в модуле
std::vector<Artefact*> CommonData::artefacts;

// Таблица артефактов с зарезервированными именами (системная таблица)
NameTable CommonData::systemNameTable{nullptr, nullptr};


Module::Module(): CommonData(nullptr) {}

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
