#include <bits/stdc++.h>
using namespace std;

int partition(long int arr[], int low, int high) {
    long int pivot = arr[low];
    long int i = low;
    long int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {i++;}
        while (arr[j] > pivot && j >= low + 1) {j--;}
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(long int arr[], int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1, high);
    }
}

int main() {
    srand(time(0)); // Seed for random numbers

    int n = 1000;
    while (n <= 25000) {
        double totalTime = 0.0;

        for (int i = 1; i <= 10; i++) {
            long int arr[n];
            
            // Generate random array of size n
            for (int j = 0; j < n; j++) {
                arr[j] = rand() % n + 1;
            }

            auto start = chrono::high_resolution_clock::now();
            quickSort(arr, 0, n - 1);
            auto end = chrono::high_resolution_clock::now();

            chrono::duration<double> duration = end - start;
            totalTime += duration.count();
        }

        double avgTime = totalTime / 10;
        cout << "Size: " << n << ", Time: " << avgTime << " seconds" << endl;

        n += 1000;
    }

    return 0;
}