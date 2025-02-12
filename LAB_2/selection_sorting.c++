#include <bits/stdc++.h>
using namespace std;

void selectionSort(long int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
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
            selectionSort(arr, n);
            auto end = chrono::high_resolution_clock::now();

            chrono::duration<double> duration = end - start;
            totalTime += duration.count();
        }

        double avgTime = totalTime / 10;
        cout << "Size: " << n << ", Avg Time: " << avgTime << " seconds" << endl;

        n += 1000; 
    }

    return 0;
}
