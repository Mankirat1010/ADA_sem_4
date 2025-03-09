#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

// Function to check if three points are collinear
bool areCollinear(Point a, Point b, Point c) {
    return (b.x - a.x)*(c.y - a.y) == (b.y - a.y)*(c.x - a.x);
}

// Function to generate all triangles
void generateTriangles(Point points[], int n) {
    int count = 0;
    
    cout << "All possible non-degenerate triangles:\n";
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (!areCollinear(points[i], points[j], points[k])) {
                    count++;
                    cout << "Triangle " << count << ": ";
                    cout << "(" << points[i].x << "," << points[i].y << ") ";
                    cout << "(" << points[j].x << "," << points[j].y << ") ";
                    cout << "(" << points[k].x << "," << points[k].y << ")\n";
                }
            }
        }
    }

    if (count == 0) {
        cout << "No non-degenerate triangles can be formed.\n";
    } else {
        cout << "\nTotal triangles: " << count << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of points: ";
    cin >> n;

    // Declare an array to store points
    Point points[n];

    cout << "Enter coordinates of " << n << " points (x y):\n";
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    generateTriangles(points, n);

    return 0;
}
