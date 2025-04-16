#include<iostream>
#include<math.h>
using namespace std;
int function(int arr[], int low, int high) {
    int mid = low + (high - low)/2;
    if(arr[mid] < arr[mid-1]) {
        return function(arr, low, mid-1);
    }
    else if(arr[mid] < arr[mid+1]) {
        return function(arr, mid+1, high);
    }
    else {
        return arr[mid];
    }
}

int main() {
    int arr[7] = {1, 5, 4, 7, 120, 100};
    cout<<function(arr, 0, 7);
}
