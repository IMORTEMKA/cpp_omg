#pragma once

#include "Animal.h"

// Класс "Птица" наследует от Animal
class Bird : public Animal {
private:
    // Специфичные поля для птиц
    float birdWingspanMeters;   // Размах крыльев в метрах
    string birdBeakType;        // Тип клюва (короткий, длинный, крючковатый и т.д.)
    bool birdCanFly;            // Умеет ли летать

public:
    // Конструкторы
    Bird();
    Bird(string name, int age, float weight, string habitat,
         float wingspan, string beakType, bool canFly);

    // Деструктор
    ~Bird();

    // Сеттеры и геттеры
    void setWingspanMeters(float wingspan);
    float getWingspanMeters();
    void setBeakType(string beakType);
    string getBeakType();
    void setCanFly(bool canFly);
    bool getCanFly();

    // Переопределяем виртуальные методы
    virtual void inputData() override;
    virtual void displayData() override;
    virtual string getTypeName() override;
};