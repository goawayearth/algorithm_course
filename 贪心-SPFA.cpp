#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 100;
const int INF = 0x3f3f3f3f;

vector<pair<int, int>> graph[MAXN];   // 存储图的邻接表表示
int dist[MAXN];     // 存储起点到各个节点的最短路径长度
bool visited[MAXN]; // 存储每个节点是否已经在队列中

void spfa(int s) {
    // 初始化距离列表和visited数组
    memset(dist, INF, sizeof(dist));
    memset(visited, false, sizeof(visited));
    dist[s] = 0;

    // 初始化队列
    queue<int> q;
    q.push(s);
    visited[s] = true;

    // 进行SPFA算法
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        visited[u] = false;

        // 遍历u的所有出边
        for (auto it : graph[u]) {
            int v = it.first;
            int w = it.second;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // 初始化邻接表
    for (int i = 0; i < n; i++) {
        graph[i].clear();
    }

    // 读入边的信息，构建邻接表
    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }

    // 运行SPFA算法
    spfa(0);

    // 输出结果
    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}
