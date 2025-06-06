#include <iostream>
#include <fstream>
#include <vector>
#include "array_utils.h"

using namespace std;

// Завдання 1: Зсув масиву вправо на K позицій
void runTask1() {
    string inputFileName, outputFileName;
    cout << "Введіть ім'я вхідного файлу: ";
    cin >> inputFileName;
    cout << "Введіть ім'я вихідного файлу: ";
    cin >> outputFileName;

    ifstream inFile(inputFileName);
    ofstream outFile(outputFileName);

    if (!inFile.is_open()) {
        cerr << "Не вдалося відкрити вхідний файл." << endl;
        return;
    }

    int n, k;
    inFile >> n;
    vector<double> A(n);
    for (int i = 0; i < n; ++i) inFile >> A[i];
    cout << "Введіть значення K (1 <= K <= 4 та K < N): ";
    cin >> k;

    double temp[4];
    for (int i = 0; i < k; ++i) temp[i] = A[n - k + i];
    for (int i = n - 1; i >= k; --i) A[i] = A[i - k];
    for (int i = 0; i < k; ++i) A[i] = temp[i];

    for (int i = 0; i < n; ++i) outFile << A[i] << " ";
    inFile.close();
    outFile.close();
}

// Завдання 3: Сортування методом двійкових вставок
void runTask3() {
    string inputFile, outputFile;
    cout << "Введіть ім'я вхідного файлу: ";
    cin >> inputFile;
    cout << "Введіть ім'я вихідного файлу: ";
    cin >> outputFile;

    ifstream in(inputFile);
    ofstream out(outputFile);

    if (!in.is_open()) {
        cerr << "Не вдалося відкрити вхідний файл." << endl;
        return;
    }

    int size;
    in >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; ++i) in >> arr[i];

    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int left = 0, right = i - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (key < arr[mid]) right = mid - 1;
            else left = mid + 1;
        }
        for (int j = i - 1; j >= left; --j) arr[j + 1] = arr[j];
        arr[left] = key;
    }

    for (int i = 0; i < size; ++i) out << arr[i] << " ";
    in.close();
    out.close();
}
