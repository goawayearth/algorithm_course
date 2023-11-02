#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

typedef pair<int, int> P;

vector<vector<P>> graph;
vector<int> dist;

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(make_pair(0, s));
    dist[s] = 0;

    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dist[v] < p.first) continue;
        for (auto e : graph[v]) {
            int to = e.first;
            int cost = e.second;
            if (dist[to] > dist[v] + cost) {
                dist[to] = dist[v] + cost;
                pq.push(make_pair(dist[to], to));
            }
        }
    }
}

int main() {
    int V, E, r;
    cin >> V >> E >> r;

    graph.resize(V);
    dist.resize(V, INF);

    for (int i = 0; i < E; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        graph[s].push_back(make_pair(t, d));
    }

    dijkstra(r);

    for (int i = 0; i < V; ++i) {
        if (dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }

    return 0;
}
