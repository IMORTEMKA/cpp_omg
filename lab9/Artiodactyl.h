#pragma once

#include "Mammal.h"

// Класс "Парнокопытные" наследует от Mammal
class Artiodactyl : public Mammal {
private:
    // Специфичные поля для парнокопытных
    int artiodactylHoofCount;     // Количество копыт (обычно 2, но для простоты оставим число)
    bool artiodactylHasHorns;     // Наличие рогов

public:
    // Конструкторы
    Artiodactyl();
    Artiodactyl(string name, int age, float weight, string habitat,
                string furType, int gestationPeriod, string dietType,
                int hoofCount, bool hasHorns);

    // Деструктор
    ~Artiodactyl();

    // Сеттеры и геттеры
    void setHoofCount(int hoofCount);
    int getHoofCount();
    void setHasHorns(bool hasHorns);
    bool getHasHorns();

    // Переопределяем виртуальные методы
    virtual void inputData() override;
    virtual void displayData() override;
    virtual string getTypeName() override;
};