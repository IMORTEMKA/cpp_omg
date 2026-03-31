#include "Animal.h"
#include <iostream>

using namespace std;

// Конструктор по умолчанию: инициализируем поля пустыми значениями
Animal::Animal() {
    animalName = "";
    animalAge = 0;
    animalWeightKg = 0.0;
    animalHabitat = "";
}

// Конструктор с параметрами
Animal::Animal(string name, int age, float weight, string habitat) {
    animalName = name;
    animalAge = age;
    animalWeightKg = weight;
    animalHabitat = habitat;
}

// Деструктор (виртуальный, но в базовом классе он пустой)
Animal::~Animal() {
    // Ничего не делаем, но нужен для полиморфизма
}

// Установить имя
void Animal::setName(string name) {
    animalName = name;
}

// Получить имя
string Animal::getName() {
    return animalName;
}

// Установить возраст
void Animal::setAge(int age) {
    animalAge = age;
}

// Получить возраст
int Animal::getAge() {
    return animalAge;
}

// Установить вес
void Animal::setWeight(float weight) {
    animalWeightKg = weight;
}

// Получить вес
float Animal::getWeight() {
    return animalWeightKg;
}

// Установить среду обитания
void Animal::setHabitat(string habitat) {
    animalHabitat = habitat;
}

// Получить среду обитания
string Animal::getHabitat() {
    return animalHabitat;
}

// Ввод данных с клавиатуры (общая часть для всех животных)
void Animal::inputData() {
    cout << "Enter name: ";
    cin >> animalName;
    cout << "Enter age (years): ";
    cin >> animalAge;
    cout << "Enter weight (kg): ";
    cin >> animalWeightKg;
    cout << "Enter habitat: ";
    cin >> animalHabitat;
}

// Вывод данных на экран (общая часть)
void Animal::displayData() {
    cout << "Type: " << getTypeName() << endl;
    cout << "Name: " << animalName << endl;
    cout << "Age: " << animalAge << " years" << endl;
    cout << "Weight: " << animalWeightKg << " kg" << endl;
    cout << "Habitat: " << animalHabitat << endl;
}

// Возвращает тип животного (по умолчанию "Animal")
string Animal::getTypeName() {
    return "Animal";
}