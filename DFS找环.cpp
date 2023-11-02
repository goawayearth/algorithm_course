#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int MAXN = 1e5 + 10;
int n, m, cnt, head[MAXN], vis[MAXN], st[MAXN];
struct node {
    int to, next;
}e[MAXN];

void add(int u, int v) {
    cnt++;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

bool dfs(int u) {
    vis[u] = 1;
    st[u] = 1;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if (!vis[v]) {
            if (dfs(v)) return true;
        }
        else if (st[v]) return true;
    }
    st[u] = 0;
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i)) {
                flag = true;
                break;
            }
        }
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
