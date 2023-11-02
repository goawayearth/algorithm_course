#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

const int MAXN = 1e5 + 10;
int n, m, cnt, head[MAXN], inDegree[MAXN], outDegree[MAXN], vis[MAXN], st[MAXN];
vector<int> topo; // 存储拓扑排序的结果
struct node {
    int to, next;
}e[MAXN];

void add(int u, int v) {
    cnt++;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs(int u) {
    vis[u] = 1;
    st[u] = 1;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if (!vis[v]) {
            dfs(v);
        }
    }
    st[u] = 0;
    topo.push_back(u); // 将当前节点加入拓扑序列
}

void topologicalSort() {
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    reverse(topo.begin(), topo.end()); // 将结果反转，得到拓扑排序序列
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        inDegree[v]++; // 统计入度和出度
        outDegree[u]++;
    }
    topologicalSort();
    if (topo.size() != n) { // 如果存在环，则无法进行拓扑排序
        cout << "Impossible" << endl;
    }
    else {
        for (int i = 0; i < topo.size(); i++) {
            cout << topo[i] << " "; // 输出拓扑排序结果
        }
        cout << endl;
    }
    return 0;
}
