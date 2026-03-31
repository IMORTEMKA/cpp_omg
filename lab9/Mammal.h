#pragma once

#include "Animal.h"

// Класс "Млекопитающее" наследует от Animal
class Mammal : public Animal {
protected:
    // Дополнительные поля для млекопитающих
    string mammalFurType;           // Тип шерсти (короткая, длинная, пушистая и т.д.)
    int mammalGestationPeriodDays;  // Период беременности в днях
    string mammalDietType;          // Тип питания (хищник, травоядный, всеядный)

public:
    // Конструкторы
    Mammal();
    Mammal(string name, int age, float weight, string habitat,
           string furType, int gestationPeriod, string dietType);

    // Деструктор
    ~Mammal();

    // Сеттеры и геттеры для новых полей
    void setFurType(string furType);
    string getFurType();
    void setGestationPeriodDays(int gestationPeriod);
    int getGestationPeriodDays();
    void setDietType(string dietType);
    string getDietType();

    // Переопределяем виртуальные методы базового класса
    virtual void inputData() override;    // Ввод с учётом новых полей
    virtual void displayData() override;  // Вывод с учётом новых полей
    virtual string getTypeName() override;
};