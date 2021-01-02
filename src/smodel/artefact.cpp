#include <iostream>

#include "artefact.h"
#include "context.h"

// Формирование именованного артефакта
Artefact::Artefact(std::string name, Context* context, bool access):
    name{name}, context{context}, access{access}
{}

// Формирование неименованного артефакта
Artefact::Artefact(Context* context):
    name{""}, context{context}, access{false}
{}

// Вывод отладочной информации об именованном артефакте
void Artefact::debugOut() {
    if(name == "") {
        std::cout << "nonamed: ";
    } else {
        std::cout << name << (access? "*: ":": ");
    }
    context->debugOut();
}
