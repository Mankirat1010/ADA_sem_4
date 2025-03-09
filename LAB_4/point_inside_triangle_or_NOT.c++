#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate area of a triangle using coordinates
float area(float x1, float y1, float x2, float y2, float x3, float y3) {
    return abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);
}

// Function to check if point lies inside the Triangle or NOT
bool isInside(float x1, float y1, float x2, float y2, float x3, float y3, float x, float y) {
    // Calculate area of the triangle ABC
    float A = area(x1, y1, x2, y2, x3, y3);

    // Area of sub-triangles PBC, PAC and PAB
    float A1 = area(x, y, x2, y2, x3, y3);
    float A2 = area(x1, y1, x, y, x3, y3);
    float A3 = area(x1, y1, x2, y2, x, y);

    // case where P is inside the triangle ABC
    if(A == A1 + A2 + A3) {
        return true;
    }
    else return false;
};

int main() {
    float x1, y1, x2, y2, x3, y3;
    float x, y;

    cout << "Enter coordinates of triangle vertices (x1 y1 x2 y2 x3 y3): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    cout << "Enter coordinates of the point (x y): ";
    cin >> x >> y;

    if (isInside(x1, y1, x2, y2, x3, y3, x, y))
        cout << "Point (" << x << ", " << y << ") is inside the triangle.\n";
    else
        cout << "Point (" << x << ", " << y << ") is NOT inside the triangle.\n";

    return 0;
}
