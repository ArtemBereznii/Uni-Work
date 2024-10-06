#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>

using namespace std;

char getRandomChar() {
    const char chars[] = { '*', '$', '%', '@', '&', '*', '*', '*', '*', '*', '*' };
    int index = rand() % 11;
    return chars[index];
}

string getColorCode(char c) {
    switch (c) {
    case '*': return "\033[32m"; // Green *
    case '$': return "\033[33m"; // Yellow $
    case '%': return "\033[31m"; // Red %
    case '@': return "\033[34m"; // Blue @
    case '&': return "\033[35m"; // Purple &
    default: return "\033[37m"; // White for anything else
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    int level;
    cout << "Enter the amount of levels for the tree: ";
    cin >> level;

    int width = (2 * level) + 5;

    int height = 0;
    for (int lvl = 0; lvl < level; ++lvl) {
        height += (3 + lvl);
    }
    height += 2;

    vector<vector<char>> tree(height, vector<char>(width, ' '));

    int middle = width / 2;
    int currentHeight = 0; 

    for (int lvl = 0; lvl < level; ++lvl) {
        int rowsInLevel = 3 + lvl;
        for (int i = 0; i < rowsInLevel; ++i) {
            int numSymbols = 2 * i + 1;
            int startPos = middle - numSymbols / 2;

            for (int j = 0; j < numSymbols; ++j) {
                tree[currentHeight][startPos + j] = getRandomChar();
            }
            ++currentHeight;
        }
    }

    int trunkHeight = 2; 
    int trunkWidth = 1;
    int trunkStart = middle - trunkWidth / 2;

    for (int i = 0; i < trunkHeight; ++i) {
        for (int j = 0; j < trunkWidth; ++j) {
            tree[height - trunkHeight + i][trunkStart + j] = '*';
        }
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            char symbol = tree[i][j];
            if (symbol != ' ') {
                cout << getColorCode(symbol) << symbol << "\033[0m";
            }
            else {
                cout << symbol;
            }
        }
        cout << endl;
    }

    ofstream file("christmas_tree.txt");
    if (file.is_open()) {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                file << tree[i][j];
            }
            file << endl; 
        }
        file.close();
        cout << "Christmas tree has been saved to christmas_tree.txt" << endl;
    }
    else {
        cout << "Unable to open file for writing." << endl;
    }

    return 0;
}
