#include <iostream>
using namespace std;

#define INF 999
#define N 10

int main() {
    int costMatrix[N][N], distVector[N][N], via[N][N];
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter cost matrix (999 for no direct path):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> costMatrix[i][j];
            distVector[i][j] = costMatrix[i][j];
            if (i == j || costMatrix[i][j] == INF)
                via[i][j] = -1;  // No path or same router
            else
                via[i][j] = j;   // Initially via direct neighbor
        }
    }

    // Distance Vector Update using Bellman-Ford logic
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (distVector[i][k] + distVector[k][j] < distVector[i][j]) {
                    distVector[i][j] = distVector[i][k] + distVector[k][j];
                    via[i][j] = via[i][k]; // Update path through k
                }
            }
        }
    }

    // Display routing tables
    for (int i = 0; i < n; i++) {
        cout << "\nRouting table for Router " << i << ":\n";
        cout << "Destination\tCost\tNext Hop\n";
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            cout << j << "\t\t";
            if (distVector[i][j] == INF)
                cout << "INF\t-";
            else
                cout << distVector[i][j] << "\t" << via[i][j];
            cout << "\n";
        }
    }

    return 0;
}
