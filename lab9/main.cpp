#include <iostream>
#include <vector>
#include "Animal.h"
#include "Mammal.h"
#include "Artiodactyl.h"
#include "Bird.h"

using namespace std;

// Функция для отображения меню
void showMenu() {
    cout << "\n===== MENU =====" << endl;
    cout << "1. Add new animal" << endl;
    cout << "2. Show all animals" << endl;
    cout << "3. Edit animal" << endl;
    cout << "4. Delete animal" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose option: ";
}

// Функция для выбора типа добавляемого животного
int chooseAnimalType() {
    cout << "\nSelect type of animal:" << endl;
    cout << "1. Animal (base class)" << endl;
    cout << "2. Mammal" << endl;
    cout << "3. Bird" << endl;
    cout << "4. Artiodactyl (hoofed mammal)" << endl;
    cout << "Your choice: ";
    int type;
    cin >> type;
    return type;
}

// Функция для добавления нового животного в вектор
void addAnimal(vector<Animal*>& animalList) {
    int type = chooseAnimalType();
    Animal* newAnimal = nullptr;

    switch (type) {
        case 1:
            newAnimal = new Animal();
            break;
        case 2:
            newAnimal = new Mammal();
            break;
        case 3:
            newAnimal = new Bird();
            break;
        case 4:
            newAnimal = new Artiodactyl();
            break;
        default:
            cout << "Invalid choice. Animal not added." << endl;
            return;
    }

    // Вызываем виртуальный метод inputData() (нужный подкласс определится автоматически)
    newAnimal->inputData();
    animalList.push_back(newAnimal);
    cout << "Animal added successfully!" << endl;
}

// Функция для вывода всех животных
void showAllAnimals(const vector<Animal*>& animalList) {
    if (animalList.empty()) {
        cout << "No animals in the list." << endl;
        return;
    }

    cout << "\n=== LIST OF ANIMALS ===" << endl;
    for (size_t i = 0; i < animalList.size(); ++i) {
        cout << "\n--- Animal #" << i+1 << " ---" << endl;
        animalList[i]->displayData();   // Полиморфный вызов
    }
}

// Функция для редактирования животного по индексу
void editAnimal(vector<Animal*>& animalList) {
    if (animalList.empty()) {
        cout << "No animals to edit." << endl;
        return;
    }

    showAllAnimals(animalList);   // Показываем всех с индексами
    cout << "Enter the number of the animal to edit: ";
    int index;
    cin >> index;
    if (index < 1 || index > (int)animalList.size()) {
        cout << "Invalid index." << endl;
        return;
    }

    // Вызываем виртуальный inputData() для выбранного объекта
    animalList[index-1]->inputData();
    cout << "Animal updated successfully!" << endl;
}

// Функция для удаления животного
void deleteAnimal(vector<Animal*>& animalList) {
    if (animalList.empty()) {
        cout << "No animals to delete." << endl;
        return;
    }

    showAllAnimals(animalList);
    cout << "Enter the number of the animal to delete: ";
    int index;
    cin >> index;
    if (index < 1 || index > (int)animalList.size()) {
        cout << "Invalid index." << endl;
        return;
    }

    // Удаляем объект из памяти
    delete animalList[index-1];
    // Удаляем указатель из вектора
    animalList.erase(animalList.begin() + (index-1));
    cout << "Animal deleted successfully!" << endl;
}

int main() {
    vector<Animal*> animalList;   // Вектор указателей на базовый класс
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addAnimal(animalList);
                break;
            case 2:
                showAllAnimals(animalList);
                break;
            case 3:
                editAnimal(animalList);
                break;
            case 4:
                deleteAnimal(animalList);
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid option, try again." << endl;
        }
    } while (choice != 5);

    // Освобождаем память перед выходом
    for (size_t i = 0; i < animalList.size(); ++i) {
        delete animalList[i];
    }
    animalList.clear();

    return 0;
}