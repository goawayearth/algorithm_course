#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 100010;

struct Edge {
    int to, weight;
    Edge(int to, int weight) : to(to), weight(weight) {}
};

vector<Edge> graph[MAXN];
int dist[MAXN];
bool vis[MAXN];

void dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    memset(dist, INF, sizeof(dist));
    memset(vis, false, sizeof(vis));
    dist[s] = 0;
    pq.push(make_pair(0, s));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].to;
            int w = graph[u][i].weight;
            if (!vis[v] && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(Edge(v, w));
    }

    dijkstra(s);

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            cout << "INF" << endl;
        }
        else {
            cout << dist[i] << endl;
        }
    }

    return 0;
}
