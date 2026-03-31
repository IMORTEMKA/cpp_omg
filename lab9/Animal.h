#pragma once  // Защита от повторного включения

#include <iostream>
#include <string>

using namespace std;

// Базовый класс "Животное"
class Animal {
protected:
    // Поля, общие для всех животных (имена максимально подробные)
    string animalName;      // Кличка или название вида
    int animalAge;          // Возраст в годах
    float animalWeightKg;   // Вес в килограммах
    string animalHabitat;   // Среда обитания

public:
    // Конструктор по умолчанию
    Animal();
    // Конструктор с параметрами
    Animal(string name, int age, float weight, string habitat);
    // Виртуальный деструктор
    virtual ~Animal();

    // Методы доступа (геттеры и сеттеры)
    void setName(string name);
    string getName();
    void setAge(int age);
    int getAge();
    void setWeight(float weight);
    float getWeight();
    void setHabitat(string habitat);
    string getHabitat();

    // Виртуальные методы для ввода и вывода данных
    virtual void inputData();      // Ввод данных с клавиатуры
    virtual void displayData();    // Вывод данных на экран
    virtual string getTypeName();  // Возвращает строку с названием типа животного
};