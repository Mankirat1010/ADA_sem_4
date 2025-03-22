#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    int x, y;
};

const int MAX = 100;
Point points[MAX];
bool isHull[MAX]; // true if point is part of convex hull
int n;

// Function to find area of triangle
float area(Point a, Point b, Point c) {
    return fabs((a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y)) / 2.0);
}

// Function to check if point p lies inside triangle (a, b, c)
bool isInside(Point p, Point a, Point b, Point c) {
    float A = area(a, b, c);
    float A1 = area(p, b, c);
    float A2 = area(a, p, c);
    float A3 = area(a, b, p);

    return (fabs(A - (A1 + A2 + A3)) < 1e-6);
}

// Function to check which side of line the point lies
// >0 means left | <0 means right | 0 means on the line
int side(Point a, Point b, Point p) {
    return (b.x - a.x)*(p.y - a.y) - (b.y - a.y)*(p.x - a.x);
}

void quickHullLike() {
    // Step 1: Find leftmost and rightmost points
    int minX = 0, maxX = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[minX].x) minX = i;
        if (points[i].x > points[maxX].x) maxX = i;
    }

    Point A = points[minX];
    Point B = points[maxX];

    // A and B are our HULL POINTS 
    isHull[minX] = true;
    isHull[maxX] = true;

    // Divide into two groups
    for (int s = -1; s <= 1; s += 2) { // s = -1 (right), +1 (left)
        for (int i = 0; i < n; i++) {
            if (i == minX || i == maxX) continue;
            // looking for same signs ++ or -- 
            if (side(A, B, points[i]) * s <= 0) continue; // Skip wrong side or on the line

            bool inside = false;
            // Check if point lies inside any triangle formed by A, B, and another point on same side
            for (int j = 0; j < n && !inside; j++) {
                if (j == i || j == minX || j == maxX) continue;
                if (side(A, B, points[j]) * s > 0) {
                    if (isInside(points[i], A, B, points[j])) {
                        inside = true;
                        break;
                    }
                }
            }

            if (!inside) {
                isHull[i] = true;
            }
        }
    }

    // Print hull points
    cout << "\nPoints on Convex Hull:\n";
    for (int i = 0; i < n; i++) {
        if (isHull[i]) {
            cout << "(" << points[i].x << ", " << points[i].y << ")\n";
        }
    }
}

int main() {
    cout << "Enter number of points: ";
    cin >> n;

    cout << "Enter " << n << " points (x y):\n";
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
        isHull[i] = false; // Initially assume none are hull
    }

    if (n < 3) {
        cout << "Convex hull not possible with less than 3 points.\n";
    } else {
        quickHullLike();
    }

    return 0;
}
