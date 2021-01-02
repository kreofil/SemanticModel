#include "operand.h"

Operand::Operand(Context *ctx): context{ctx}
{

}

// Вывод отладочной информации
void Operand::debugOut() {
    std::cout << "OPERAND ";
    if(context != nullptr) {
        context->debugOut();
    } else {
        std::cout << "Context is NULL";
    }
}
