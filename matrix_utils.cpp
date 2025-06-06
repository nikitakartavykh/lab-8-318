#include <iostream>
#include <fstream>
#include <vector>
#include "matrix_utils.h"

using namespace std;

// Завдання 2: Добуток кожного стовпця матриці
void runTask2() {
    string fileName;
    cout << "Введіть ім'я файлу з матрицею: ";
    cin >> fileName;

    fstream file(fileName, ios::in | ios::out | ios::app);
    if (!file.is_open()) {
        cerr << "Не вдалося відкрити файл." << endl;
        return;
    }

    int M, N;
    file >> M >> N;
    vector<vector<double>> matrix(M, vector<double>(N));

    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            file >> matrix[i][j];

    file << "\nДобутки по стовпцях: ";
    for (int j = 0; j < N; ++j) {
        double product = 1;
        for (int i = 0; i < M; ++i) {
            product *= matrix[i][j];
        }
        file << product << " ";
    }
    file.close();
}
