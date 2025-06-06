#include <iostream>
#include "array_utils.h"
#include "matrix_utils.h"

using namespace std;

int main() {
    int choice;
    cout << "Виберіть завдання для запуску (1 - масив, 2 - матриця, 3 - сортування): ";
    cin >> choice;

    switch (choice) {
        case 1:
            runTask1();
            break;
        case 2:
            runTask2();
            break;
        case 3:
            runTask3();
            break;
        default:
            cout << "Невірний вибір." << endl;
    }

    return 0;
}
