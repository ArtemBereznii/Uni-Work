#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>

using namespace std;

// Функція для генерації випадкових символів
char getRandomChar() {
    const char chars[] = { '*', '$', '%', '@', '&', '*', '*', '*', '*', '*', '*' };
    int index = rand() % 11; // Випадковий індекс від 0 до 10
    return chars[index];
}

// Функція для виведення символів з кольорами
string getColorCode(char c) {
    switch (c) {
    case '*': return "\033[32m"; // Зелений для зірочок
    case '$': return "\033[33m"; // Жовтий для $
    case '%': return "\033[31m"; // Червоний для %
    case '@': return "\033[34m"; // Синій для @
    case '&': return "\033[35m"; // Фіолетовий для &
    default: return "\033[37m"; // Білий для всього іншого
    }
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Ініціалізуємо генератор випадкових чисел

    int level;
    cout << "Enter the amount of levels for the tree: ";
    cin >> level;

    // Визначаємо ширину ялинки
    int width = (2 * level) + 5;

    // Визначаємо загальну висоту ялинки
    int height = 0;
    for (int lvl = 0; lvl < level; ++lvl) {
        height += (3 + lvl); // Кожен рівень складається з (3 + lvl) рядків
    }
    height += 2; // Додаємо 2 рядки для стовбура

    // Створюємо двовимірний масив для ялинки
    vector<vector<char>> tree(height, vector<char>(width, ' ')); // Заповнюємо ' '

    int middle = width / 2; // Знаходимо середину
    int currentHeight = 0;  // Відстежуємо поточну висоту під час побудови

    // Алгоритм для побудови ялинки
    for (int lvl = 0; lvl < level; ++lvl) {
        int rowsInLevel = 3 + lvl; // Кількість рядків у рівні
        for (int i = 0; i < rowsInLevel; ++i) {
            int numSymbols = 2 * i + 1; // Непарна кількість символів у кожному рядку
            int startPos = middle - numSymbols / 2; // Початкова позиція для символів

            // Заповнюємо випадковими символами
            for (int j = 0; j < numSymbols; ++j) {
                tree[currentHeight][startPos + j] = getRandomChar();
            }
            ++currentHeight; // Переходимо на наступний рядок
        }
    }

    // Створюємо стовбур ялинки
    int trunkHeight = 2;   // Висота стовбура
    int trunkWidth = 1;    // Ширина стовбура
    int trunkStart = middle - trunkWidth / 2; // Початкова позиція стовбура

    for (int i = 0; i < trunkHeight; ++i) {
        for (int j = 0; j < trunkWidth; ++j) {
            tree[height - trunkHeight + i][trunkStart + j] = '*'; // Малюємо стовбур
        }
    }

    // Виведення ялинки з кольорами
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            char symbol = tree[i][j];
            if (symbol != ' ') {
                cout << getColorCode(symbol) << symbol << "\033[0m"; // Виводимо символ з кольором
            }
            else {
                cout << symbol; // Виводимо порожнє місце без кольору
            }
        }
        cout << endl;
    }

    ofstream file("christmas_tree.txt");
    if (file.is_open()) {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                file << tree[i][j]; // Записуємо кожен символ у файл
            }
            file << endl; // Переходимо на новий рядок після кожного рядка
        }
        file.close();
        cout << "Christmas tree has been saved to christmas_tree.txt" << endl;
    }
    else {
        cout << "Unable to open file for writing." << endl;
    }

    return 0;
}
