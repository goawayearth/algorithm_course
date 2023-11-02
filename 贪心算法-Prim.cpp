#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 100010;
const int INF = 0x3f3f3f3f;

struct Edge {
    int to, weight;
    Edge(int to, int weight) : to(to), weight(weight) {}
    bool operator<(const Edge& other) const {
        return weight > other.weight;
    }
};

vector<Edge> graph[MAXN];
bool vis[MAXN];
int dist[MAXN];

int prim(int start) {
    memset(vis, false, sizeof(vis));
    memset(dist, INF, sizeof(dist));
    dist[start] = 0;
    priority_queue<Edge> pq;
    pq.push(Edge(start, 0));
    int total_weight = 0;
    while (!pq.empty()) {
        int u = pq.top().to;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        total_weight += dist[u];
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].to;
            int w = graph[u][i].weight;
            if (!vis[v] && w < dist[v]) {
                dist[v] = w;
                pq.push(Edge(v, w));
            }
        }
    }
    return total_weight;
}

int main() {
    int n, m, u, v, w;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph[u].push_back(Edge(v, w));
        graph[v].push_back(Edge(u, w));
    }
    int ans = prim(1);
    cout << ans << endl;
    return 0;
}
