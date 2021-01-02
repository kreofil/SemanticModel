#ifndef ARTEFACT_H
#define ARTEFACT_H

/**
  Класс **Artefact**, определяющей именованную сущность,
  от которой формируются все остальные понятия,
  задающие контексты программных объектов.
*/

#include <iostream>

#include "context.h"

// Класс, задающий именованный контекст
class Artefact {
public:
    // Формирование именованного артефакта
    explicit Artefact(std::string name, Context* context, bool access = false);
    // Формирование неименованного артефакта
    explicit Artefact(Context* context);

    // Получение ссылки на имя артефакта
    std::string& getName() {return name;}
    // Получение указателя на контекст
    Context* getContext() {return context;}
    // Получение значения уровная доступа к артефакту
    bool getAccess() {return access;}

    // Вывод отладочной информации об именованном артефакте
    virtual void debugOut();

private:
    std::string name;   // Имя артефакта
    Context* context;   // Указатель на контекст именованного артефакта
    bool access;        // Уровень доступа к именованному артефакту

    // Местоположение артефакта в тексте программы.
    // Предполагается, что будет использоваться с разными синтаксисами языков для вывода
    // сообщений о возникающих семантических ошибках при семантическом анализе,
    // который планируется проводить после парсинга программы и построения семантической модели
    uint row;
    uint column;
};

#endif // ARTEFACT_H
