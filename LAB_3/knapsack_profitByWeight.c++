#include <iostream>
#include <cstdlib> 
#include <ctime>  
using namespace std;

int printArray(int array[2][10], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Sort based on profit/weight ratio (descending)
void sorting_profitByWeight(int arr[2][10], int row, int col) {
    for (int i = 0; i < col; i++) {
        for (int j = i + 1; j < col; j++) {
            float r1 = (float)arr[0][i] / arr[1][i];
            float r2 = (float)arr[0][j] / arr[1][j];
            if (r2 > r1) {
                swap(arr[0][j], arr[0][i]); // profit
                swap(arr[1][j], arr[1][i]); // weight
            }
        }
    }
}

// Fill greedily using profit/weight ratio
void profitByWeight_fill(int arr[2][10], float x[10]) {
    float c = 40; // knapsack capacity
    for (int i = 0; i < 10; i++) {
        if (arr[1][i] <= c) {
            x[i] = 1;
            c -= arr[1][i];
        } else {
            x[i] = float(c / arr[1][i]);
            c = 0;
        }
    }
}

int main() {
    srand(time(0)); // Random seed

    int rows = 2, cols = 10;
    int arr[2][10];

    // Generate random profit and weight values (1 to 9)
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = (rand() % 9) + 1;
        }
    }

    cout << "Original Array (Profit | Weight):\n";
    printArray(arr, 2, cols);

    sorting_profitByWeight(arr, 2, cols);
    cout << "\nAfter Sorting by Profit/Weight Ratio:\n";
    printArray(arr, 2, cols);

    // Show profit/weight ratio for each item
    cout << "\nProfit/Weight Ratio for each item:\n";
    for (int i = 0; i < cols; i++) {
        float ratio = (float)arr[0][i] / arr[1][i];
        cout << "Item " << i + 1 << ": " << ratio << endl;
    }

    // Fill the knapsack based on profit/weight
    float profitByWeight[10];
    profitByWeight_fill(arr, profitByWeight);

    // Print x[i] values
    cout << "\nProfit/Weight Ratio Fill:\n";
    for (int i = 0; i < 10; i++) {
        cout << profitByWeight[i] << " ";
    }
    cout << endl;

    // Calculate total profit
    float totalProfit = 0;
    for (int i = 0; i < 10; i++) {
        totalProfit += profitByWeight[i] * arr[0][i];
    }

    cout << "\nTotal Profit Earned: " << totalProfit << endl;

    return 0;
}
