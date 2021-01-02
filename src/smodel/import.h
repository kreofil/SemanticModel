#ifndef IMPORT_H
#define IMPORT_H

#include "context.h"

// Класс, определяющий контекст импорта
class ImportContext: public Context {
public:
    ///ImportContext();
    // Создание контекста импорта с установкой имен
    explicit ImportContext(std::string importedName, std::string alias);

    // Получение ссылки на имя импортируемого модуля
    std::string& getImportedName() {return importedName;}
    // Получение ссылки на алиас импортируемого модуля
    std::string& getAlias() {return alias;}

    // Вывод отладочной информации о контексте импорта
    virtual void debugOut();
private:
    std::string importedName;   // имя импортируемого модуля
    std::string alias;          // имя псевдонима модуля
};

#endif // IMPORT_H
