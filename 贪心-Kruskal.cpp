#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100010;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

vector<Edge> edges;
int parent[MAXN], depth[MAXN];

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    int px = find(x), py = find(y);
    if (depth[px] < depth[py]) {
        parent[px] = py;
    }
    else {
        parent[py] = px;
        if (depth[px] == depth[py]) {
            depth[px]++;
        }
    }
}

int kruskal(int n) {
    sort(edges.begin(), edges.end());
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        depth[i] = 0;
    }
    int total_weight = 0, cnt = 0;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (find(u) != find(v)) {
            unite(u, v);
            total_weight += w;
            cnt++;
            if (cnt == n - 1) {
                break;
            }
        }
    }
    return total_weight;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({ u, v, w });
    }
    int ans = kruskal(n);
    cout << ans << endl;
    return 0;
}
