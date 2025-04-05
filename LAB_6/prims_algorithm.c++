#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;
const int INF = INT_MAX;

int graph[MAX][MAX];
bool visited[MAX];
int parent[MAX];
int key[MAX];

int findMinKey(int n) {
    int min = INF, minIndex = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void primMST(int n) {
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        visited[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = findMinKey(n);
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print MST
    cout << "Edge \tWeight\n";
    int totalWeight = 0;
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
        totalWeight += graph[i][parent[i]];
    }
    cout << "Total cost of MST: " << totalWeight << endl;
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix (use 0 if no edge):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    primMST(n);
    return 0;
}
