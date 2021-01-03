// nametable.cpp
#include "nametable.h"

// Поиск артефакта в текущей таблице имен по имени
Artefact* NameTable::find(std::string& name) {
    for(auto artefact: artefacts) {
        if(name == artefact->getName()) {
            return artefact;
        }
    }
    return nullptr;
}

// Поиск артефакта в общем пространстве имен
Artefact* NameTable::globalFind(std::string &&name) {
    Artefact* artefact = nullptr;
    // Поиск в системной таблице, как приоритетной.
    if(systemNameTablePtr != nullptr) {
        artefact = systemNameTablePtr->find(name);
        if(artefact != nullptr) {return artefact;}
    }
    // Поиск в текущей таблице
    artefact = find(name);
    if(artefact != nullptr) {return artefact;}
    // Поиск в родительских таблицах
    auto parent = parentNameTablePtr;
    while(parent != nullptr) {
        artefact = parent->find(name);
        if(artefact != nullptr) {return artefact;}
        parent = parent->parentNameTablePtr;
    }
    return nullptr;
}



// Вывод отладочной информации о модуле
void NameTable::debugOut() {
    std::cout << "NameTable " << "\n";
    std::cout << "++++++++++++++++++++++++\n";

    std::cout << "\nArtefats:\n";
    std::cout << "---------\n";
    for(Artefact* artefact: artefacts) {
        artefact->debugOut();
        //std::cout << artefact->getName() << (artefact->getAccess()? "*: ":": ");
        //artefact->getContext()->debugOut();
        std::cout << std::endl;
    }
    std::cout << "----------------------\n";
    if(parentNameTablePtr != nullptr) {
        std::cout << "Have Parent\n";
    } else {
        std::cout << "Don't have Parent\n";
    }
    if(systemNameTablePtr != nullptr) {
        std::cout << "Have System\n";
    } else {
        std::cout << "Don't have System\n";
    }
}
