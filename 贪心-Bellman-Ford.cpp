#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

const int MAXN = 100;
const int INF = INT_MAX;

int dist[MAXN];     // 存储起点到各个节点的最短路径长度
int graph[MAXN][MAXN];  // 存储图的邻接矩阵表示
int n, m;           // n为节点数，m为边数

void bellman_ford(int s) {
    // 初始化距离列表
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[s] = 0;

    // 进行N-1轮松弛操作,相当于
    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    // 检查是否存在负权环路
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                cout << "存在负权环路！" << endl;
                return;
            }
        }
    }
}

int main() {
    // 读入节点数和边数
    cin >> n >> m;

    // 初始化邻接矩阵
    memset(graph, INF, sizeof(graph));
    for (int i = 0; i < n; i++) {
        graph[i][i] = 0;
    }

    // 读入边的信息，构建邻接矩阵
    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    // 运行Bellman-Ford算法
    bellman_ford(0);

    // 输出结果
    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}
