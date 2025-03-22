#include <iostream>
#include <cstdlib>  // For rand()
#include <ctime>    // For seeding rand()

using namespace std;

const int MAX = 32; 

// A, B, and result matrices are passed with size `n`
void multiplyRecursive(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int size,
                       int aRow, int aCol, int bRow, int bCol, int cRow, int cCol) {
    if (size == 2) {
        // Base case (direct multiplication)
        C[cRow][cCol]     += A[aRow][aCol]     * B[bRow][bCol]     + A[aRow][aCol+1]     * B[bRow+1][bCol];
        C[cRow][cCol+1]   += A[aRow][aCol]     * B[bRow][bCol+1]   + A[aRow][aCol+1]     * B[bRow+1][bCol+1];
        C[cRow+1][cCol]   += A[aRow+1][aCol]   * B[bRow][bCol]     + A[aRow+1][aCol+1]   * B[bRow+1][bCol];
        C[cRow+1][cCol+1] += A[aRow+1][aCol]   * B[bRow][bCol+1]   + A[aRow+1][aCol+1]   * B[bRow+1][bCol+1];
        return;
    }

    int newSize = size / 2;

    // C11 = A11*B11 + A12*B21
    multiplyRecursive(A, B, C, newSize, aRow, aCol,     bRow,     bCol,     cRow,     cCol);
    multiplyRecursive(A, B, C, newSize, aRow, aCol+newSize, bRow+newSize, bCol,     cRow,     cCol);

    // C12 = A11*B12 + A12*B22
    multiplyRecursive(A, B, C, newSize, aRow, aCol,     bRow,     bCol+newSize, cRow,     cCol+newSize);
    multiplyRecursive(A, B, C, newSize, aRow, aCol+newSize, bRow+newSize, bCol+newSize, cRow, cCol+newSize);

    // C21 = A21*B11 + A22*B21
    multiplyRecursive(A, B, C, newSize, aRow+newSize, aCol,     bRow,     bCol,     cRow+newSize, cCol);
    multiplyRecursive(A, B, C, newSize, aRow+newSize, aCol+newSize, bRow+newSize, bCol,     cRow+newSize, cCol);

    // C22 = A21*B12 + A22*B22
    multiplyRecursive(A, B, C, newSize, aRow+newSize, aCol,     bRow,     bCol+newSize, cRow+newSize, cCol+newSize);
    multiplyRecursive(A, B, C, newSize, aRow+newSize, aCol+newSize, bRow+newSize, bCol+newSize, cRow+newSize, cCol+newSize);
}

// Function to Print a Matrix
void printMatrix(int M[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << M[i][j] << "\t";
        cout << endl;
    }
}

int main() {
    srand(time(0)); // Seed for random numbers

    int n;
    cout<<"Enter the value for n (2,4,8,16...): ";
    cin>>n;

    // Initiating the Matrices
    int A[MAX][MAX] = {0};
    int B[MAX][MAX] = {0};
    int C[MAX][MAX] = {0};

    // Fill A and B with random numbers
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    cout << "Matrix A:\n";
    printMatrix(A, n);
    cout << "\nMatrix B:\n";
    printMatrix(B, n);

    multiplyRecursive(A, B, C, n, 0, 0, 0, 0, 0, 0);

    cout << "\nResult (A * B):\n";
    printMatrix(C, n);

    return 0;
}
