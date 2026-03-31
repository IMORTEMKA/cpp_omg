#include "Mammal.h"
#include <iostream>

using namespace std;

// Конструктор по умолчанию
Mammal::Mammal() : Animal() {
    mammalFurType = "";
    mammalGestationPeriodDays = 0;
    mammalDietType = "";
}

// Конструктор с параметрами: вызываем конструктор базового класса
Mammal::Mammal(string name, int age, float weight, string habitat,
               string furType, int gestationPeriod, string dietType)
    : Animal(name, age, weight, habitat) {
    mammalFurType = furType;
    mammalGestationPeriodDays = gestationPeriod;
    mammalDietType = dietType;
}

// Деструктор
Mammal::~Mammal() {
    // Память не выделялась, поэтому пусто
}

void Mammal::setFurType(string furType) {
    mammalFurType = furType;
}

string Mammal::getFurType() {
    return mammalFurType;
}

void Mammal::setGestationPeriodDays(int gestationPeriod) {
    mammalGestationPeriodDays = gestationPeriod;
}

int Mammal::getGestationPeriodDays() {
    return mammalGestationPeriodDays;
}

void Mammal::setDietType(string dietType) {
    mammalDietType = dietType;
}

string Mammal::getDietType() {
    return mammalDietType;
}

// Ввод данных для млекопитающего: сначала общие, затем специфичные
void Mammal::inputData() {
    Animal::inputData();   // Вызываем ввод из базового класса
    cout << "Enter fur type (short/long/thick etc.): ";
    cin >> mammalFurType;
    cout << "Enter gestation period (days): ";
    cin >> mammalGestationPeriodDays;
    cout << "Enter diet type (carnivore/herbivore/omnivore): ";
    cin >> mammalDietType;
}

// Вывод данных: сначала общие, затем специфичные
void Mammal::displayData() {
    Animal::displayData();   // Выводим общую часть
    cout << "Fur type: " << mammalFurType << endl;
    cout << "Gestation period: " << mammalGestationPeriodDays << " days" << endl;
    cout << "Diet: " << mammalDietType << endl;
}

// Возвращаем тип "Mammal"
string Mammal::getTypeName() {
    return "Mammal";
}