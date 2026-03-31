#include "Artiodactyl.h"
#include <iostream>

using namespace std;

// Конструктор по умолчанию
Artiodactyl::Artiodactyl() : Mammal() {
    artiodactylHoofCount = 0;
    artiodactylHasHorns = false;
}

// Конструктор с параметрами: передаём данные в Mammal, затем свои
Artiodactyl::Artiodactyl(string name, int age, float weight, string habitat,
                         string furType, int gestationPeriod, string dietType,
                         int hoofCount, bool hasHorns)
    : Mammal(name, age, weight, habitat, furType, gestationPeriod, dietType) {
    artiodactylHoofCount = hoofCount;
    artiodactylHasHorns = hasHorns;
}

// Деструктор
Artiodactyl::~Artiodactyl() {
    // пусто
}

void Artiodactyl::setHoofCount(int hoofCount) {
    artiodactylHoofCount = hoofCount;
}

int Artiodactyl::getHoofCount() {
    return artiodactylHoofCount;
}

void Artiodactyl::setHasHorns(bool hasHorns) {
    artiodactylHasHorns = hasHorns;
}

bool Artiodactyl::getHasHorns() {
    return artiodactylHasHorns;
}

// Ввод: сначала общие для млекопитающего, затем специфичные
void Artiodactyl::inputData() {
    Mammal::inputData();   // Вызов ввода из Mammal (который сам вызывает Animal::inputData)
    cout << "Enter hoof count (typically 2 or 4): ";
    cin >> artiodactylHoofCount;
    cout << "Does it have horns? (1 - yes, 0 - no): ";
    cin >> artiodactylHasHorns;
}

// Вывод: сначала данные из Mammal, затем свои
void Artiodactyl::displayData() {
    Mammal::displayData();
    cout << "Hoof count: " << artiodactylHoofCount << endl;
    cout << "Has horns: " << (artiodactylHasHorns ? "yes" : "no") << endl;
}

// Тип
string Artiodactyl::getTypeName() {
    return "Artiodactyl";
}