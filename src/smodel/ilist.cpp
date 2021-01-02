//=============================================================================
// ilist.cpp - файл с реализациями методов списка команд
//=============================================================================

#include "ilist.h"

// Добавление очередной команды в голову списка
void InstructionList::addInstructionToHead(Instruction *instruction) {
    if(head == nullptr) {
        head = tail = instruction;
    } else {
        instruction->setNextInstr(head);
        head = instruction;
    }
}

// Добавление очередной команды в хвост списка
void InstructionList::addInstructionToTail(Instruction *instruction) {
    if(head == nullptr) {
        head = tail = instruction;
    } else {
        tail->setNextInstr(instruction);
        tail = instruction;
    }
}

// Добавление списка команд к текущему списку
void InstructionList::appendInstructionList(InstructionList *ilist) {
    // Голова нового списка соединяется с хвостом основного
    tail->setNextInstr(ilist->getHeadInstruction());
    // Хвостом нового списка становится последний элемент добавляемого списка
    tail = ilist->getTaiInstruction();
}

// Вывод отладочной информации для списка команд
void InstructionList::debugOut() {
    std::cout << "Instruction List:\n";
    std::cout << "-----------------\n";

    if(head == nullptr) {
        std::cout << "    Empty Instruction List\n";
    } else {
        auto tmp = head;
        do {
            std::cout << "    ";
            tmp->debugOut();
            std::cout << "\n";
            tmp = tmp->getNextInstr();
        } while(tmp != nullptr);
    }
    // Вывод последнего операнда списка
    if(lastOpd == nullptr) {
        std::cout << "Empty Last Operand\n";
    } else {
        lastOpd->debugOut();
    }
}
