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

// Sorting by weight (ascending)
void sorting_weightwise(int arr[2][10], int row, int col) {
    for(int i = 0; i < col; i++) {
        for(int j = i + 1; j < col; j++) {
            if(arr[1][j] < arr[1][i]) {
                swap(arr[0][j], arr[0][i]); // Swap profit to maintain pair
                swap(arr[1][j], arr[1][i]); // Swap weight
            }
        }
    }
}

// Filling greedily by lowest weight
void weightwise_fill(int arr[2][10], float x[10]) {
    float c = 40; // capacity
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

    sorting_weightwise(arr, 2, cols);
    cout << "\nAfter Sorting Weightwise:\n";
    printArray(arr, 2, cols);

    float weightwise[10];
    weightwise_fill(arr, weightwise);

    cout << "\nWeightwise Fill:\n";
    for (int i = 0; i < 10; i++) cout << weightwise[i] << " ";
    cout << endl;

    return 0;
}
