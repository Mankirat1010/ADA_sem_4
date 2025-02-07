#include<iostream>
using namespace std;

void findPeak(int arr[5][5], int rows, int columns, int low, int high) {
 
    int mid = low + (high - low) / 2;
    
    // Find the row with the maximum element in the middle column
    int maxRow = 0;
    for (int i = 1; i < rows; i++) {
        if (arr[i][mid] > arr[maxRow][mid]) {
            maxRow = i;
        }
    }
    
    // Check if the middle element is a peak
    if ((mid == 0 || arr[maxRow][mid] >= arr[maxRow][mid - 1]) &&
        (mid == columns - 1 || arr[maxRow][mid] >= arr[maxRow][mid + 1])) {
        cout << "Peak element: " << arr[maxRow][mid] << endl;
        return;
    }
    
    // If left element is greater, search in left half
    if (mid > 0 && arr[maxRow][mid - 1] > arr[maxRow][mid]) {
        findPeak(arr, rows, columns, low, mid - 1);
    }
    // If right element is greater, search in right half
    else {
        findPeak(arr, rows, columns, mid + 1, high);
    }
}

int main() {
    int arr[5][5] = { {11, 12, 13, 14, 15},
                      {16, 17, 18, 79, 80},
                      {21, 22, 50, 54, 55},
                      {26, 27, 28, 29, 90},
                      {31, 32, 33, 34, 25} }; 

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    findPeak(arr, 5, 5, 0, 4);

    return 0;
}
