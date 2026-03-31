#include "Bird.h"
#include <iostream>

using namespace std;

// Конструктор по умолчанию
Bird::Bird() : Animal() {
    birdWingspanMeters = 0.0;
    birdBeakType = "";
    birdCanFly = false;
}

// Конструктор с параметрами
Bird::Bird(string name, int age, float weight, string habitat,
           float wingspan, string beakType, bool canFly)
    : Animal(name, age, weight, habitat) {
    birdWingspanMeters = wingspan;
    birdBeakType = beakType;
    birdCanFly = canFly;
}

// Деструктор
Bird::~Bird() {
    // пусто
}

void Bird::setWingspanMeters(float wingspan) {
    birdWingspanMeters = wingspan;
}

float Bird::getWingspanMeters() {
    return birdWingspanMeters;
}

void Bird::setBeakType(string beakType) {
    birdBeakType = beakType;
}

string Bird::getBeakType() {
    return birdBeakType;
}

void Bird::setCanFly(bool canFly) {
    birdCanFly = canFly;
}

bool Bird::getCanFly() {
    return birdCanFly;
}

// Ввод: сначала общие для животного, затем свои
void Bird::inputData() {
    Animal::inputData();
    cout << "Enter wingspan (meters): ";
    cin >> birdWingspanMeters;
    cout << "Enter beak type (short/long/hooked etc.): ";
    cin >> birdBeakType;
    cout << "Can it fly? (1 - yes, 0 - no): ";
    cin >> birdCanFly;
}

// Вывод
void Bird::displayData() {
    Animal::displayData();
    cout << "Wingspan: " << birdWingspanMeters << " m" << endl;
    cout << "Beak type: " << birdBeakType << endl;
    cout << "Can fly: " << (birdCanFly ? "yes" : "no") << endl;
}

// Тип
string Bird::getTypeName() {
    return "Bird";
}