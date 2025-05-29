#include <iostream>
using namespace std;

const int MAX = 5;
const int INF = 9999;

class LinkStateRouter {
public:
    int n;
    int dist[MAX][MAX];
    bool visited[MAX];

    LinkStateRouter(int routers) {
        n = routers;
        for (int i = 0; i < n; i++) {
            visited[i] = false;
            for (int j = 0; j < n; j++) {
                if (i == j)
                    dist[i][j] = 0;
                else
                    dist[i][j] = INF;
            }
        }
    }

    void addLink(int u, int v, int cost) {
        dist[u][v] = cost;
        dist[v][u] = cost;
    }

    void dijkstra(int source) {
        int distance[MAX];
        for (int i = 0; i < n; i++) {
            distance[i] = INF;
            visited[i] = false;
        }
        distance[source] = 0;

        for (int i = 0; i < n; i++) {
            int u = -1;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && (u == -1 || distance[j] < distance[u])) {
                    u = j;
                }
            }

            visited[u] = true;

            for (int v = 0; v < n; v++) {
                if (!visited[v] && dist[u][v] != INF && distance[u] + dist[u][v] < distance[v]) {
                    distance[v] = distance[u] + dist[u][v];
                }
            }
        }

        cout << "Shortest paths from Router " << source << ":\n";
        for (int i = 0; i < n; i++) {
            if (distance[i] == INF) {
                cout << "Router " << i << " is unreachable.\n";
            } else {
                cout << "Distance to Router " << i << ": " << distance[i] << endl;
            }
        }
    }
};

int main() {
    LinkStateRouter network(5);
    network.addLink(0, 1, 10);
    network.addLink(0, 2, 20);
    network.addLink(1, 2, 30);
    network.addLink(1, 3, 50);
    network.addLink(2, 3, 10);
    network.addLink(3, 4, 20);

    network.dijkstra(0);
    network.dijkstra(1);
    return 0;
}
