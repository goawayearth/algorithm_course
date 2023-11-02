#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100010;
int n, m, cnt, color, cnt_scc;
int head[MAXN], dfn[MAXN], low[MAXN], belong[MAXN];
int inDegree[MAXN], outDegree[MAXN], st[MAXN];
vector<int> s, topo;

struct node {
    int to, next;
}e[MAXN];

void add(int u, int v) {
    cnt++;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void tarjan(int u) {
    dfn[u] = low[u] = ++cnt_scc;
    s.push_back(u);
    st[u] = 1;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (st[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        int v;
        color++;
        do {
            v = s.back();
            s.pop_back();
            st[v] = 0;
            belong[v] = color;
        } while (u != v);
    }
}

void find_scc() {
    cnt_scc = color = 0;
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(belong, 0, sizeof(belong));
    memset(st, 0, sizeof(st));
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
}

void dfs(int u) {
    st[u] = 1;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if (!st[v]) {
            dfs(v);
        }
    }
    topo.push_back(u);
}

void topologicalSort() {
    for (int i = 1; i <= n; i++) {
        if (!st[i]) {
            dfs(i);
        }
    }
    reverse(topo.begin(), topo.end());
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }
    find_scc();
    memset(inDegree, 0, sizeof(inDegree));
    memset(outDegree, 0, sizeof(outDegree));
    for (int i = 1; i <= n; i++) {
        for (int j = head[i]; j; j = e[j].next) {
            int v = e[j].to;
            if (belong[i] != belong[v]) {
                inDegree[belong[v]]++;
                outDegree[belong[i]]++;
            }
        }
    }
    int in = 0, out = 0;
    for (int i = 1; i <= color; i++) {
        if (!inDegree[i]) {

            in++;
        }
        if (!outDegree[i]) {
            out++;
        }
    }
    if (color == 1) {
        cout << 0 << endl;
        return 0;
    }
    if (in == 1 && out == 1) {
        cout << 1 << endl;
    }
    else {
        cout << max(in, out) << endl;
    }
    return 0;
}
