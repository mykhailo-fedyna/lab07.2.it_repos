// Lab_7_2_1.cpp
// Лабораторна робота № 7.2.1)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 17
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
int SearchMaxInRow(int* row, const int n);
int SearchMinInRow(int* row, const int n);
void SwapMaxMin(int** a, const int k, const int n);

int main() {
    srand((unsigned)time(NULL));
    int Low, High, n, k;

    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;
    cout << "Low = "; cin >> Low;
    cout << "High = "; cin >> High;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, k, n, Low, High);
    Print(a, k, n);
    SwapMaxMin(a, k, n);

    cout << "Modified Matrix:" << endl;
    Print(a, k, n);

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int k, const int n, const int Low, const int High) {
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int k, const int n) {
    cout << endl;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int SearchMaxInRow(int* row, const int n) {
    int maxIndex = 0;
    for (int j = 1; j < n; j++) {
        if (row[j] > row[maxIndex])
            maxIndex = j;
    }
    return maxIndex;
}
int SearchMinInRow(int* row, const int n) {
    int minIndex = 0;
    for (int j = 1; j < n; j++) {
        if (row[j] < row[minIndex])
            minIndex = j;
    }
    return minIndex;
}
void SwapMaxMin(int** a, const int k, const int n) {
    for (int i = 1; i < k; i += 2) {
        int maxIndex = SearchMaxInRow(a[i], n);
        int minIndex = SearchMinInRow(a[i - 1], n);
        int temp = a[i][maxIndex];
        a[i][maxIndex] = a[i - 1][minIndex];
        a[i - 1][minIndex] = temp;
        cout << "Swapped elements from row " << i << " and row " << i - 1 << endl << endl;
    }
}
