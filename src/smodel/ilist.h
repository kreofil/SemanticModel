#ifndef ILIST_H
#define ILIST_H

//=============================================================================
// ilist.h - заголовочный файл с описанием списка команд и действий с ним.
//=============================================================================

#include "operand.h"
#include "instruction.h"

class InstructionList {
public:
    explicit InstructionList():head{nullptr}, tail{nullptr}, lastOpd{nullptr} {}

    // Добавление очередной команды в голову списка
    void addInstructionToHead(Instruction *instruction);
    // Добавление очередной команды в хвост списка
    void addInstructionToTail(Instruction *instruction);
    // Добавление операнда в список команд в качестве последнего
    void addInstructionLastOperand(Operand *opd) {lastOpd = opd;}

    // Получение указателя на голову списка
    Instruction* getHeadInstruction() {return head;}
    // Получение указателя на хвост списка
    Instruction* getTaiInstruction() {return tail;}
    // Получение указателя на операнд списка
    Operand* getLastOperand() {return lastOpd;}

    // Добавление списка команд к текущему списку
    void appendInstructionList(InstructionList *ilist);

    // Вывод отладочной информации
    void debugOut();

private:
    Instruction *head;      // голова списка команд
    Instruction *tail;      // хвост списка команд
    Operand     *lastOpd;   // последний операнд, являющийся результатом выполнения
};

#endif // ILIST_H
