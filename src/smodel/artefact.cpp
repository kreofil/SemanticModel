#include <iostream>

#include "artefact.h"
#include "context.h"

// Формирование именованного артефакта
Artefact::Artefact(std::string name, Context* context, bool access, uint r, uint c):
    name{name}, context{context}, access{access},
    row{r}, column{c}
{}

// Формирование неименованного артефакта
Artefact::Artefact(Context* context, uint r, uint c):
    name{""}, context{context}, access{false},
    row{r}, column{c}
{}

// Вывод отладочной информации об именованном артефакте
void Artefact::debugOut() {
    std::cout << "[" << row << "," << column << "] ";
    if(name == "") {
        std::cout << "nonamed: ";
    } else {
        std::cout << name << (access? "*: ":": ");
    }
    context->debugOut();
}
