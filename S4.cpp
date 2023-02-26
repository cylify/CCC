#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2005;

int n, m, id[N][N], par[N];
ll ans;
vector<pair<int, pair<int, int>>> edges;
vector<int> tree[N];

int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    par[x] = y;
    return true;
}

void kruskal() {
    sort(edges.begin(), edges.end());
    for (int i = 1; i <= n; i++) par[i] = i;
    for (auto e : edges) {
        int u = e.second.first, v = e.second.second;
        ll c = e.first;
        if (merge(u, v)) {
            tree[u].push_back(v);
            tree[v].push_back(u);
            ans += c;
        }
    }
}

void dfs(int u, int p, int mx, vector<int>& path) {
    path.push_back(u);
    if (u == mx) return;
    for (int v : tree[u]) {
        if (v == p) continue;
        dfs(v, u, mx, path);
        if (path.back() == mx) return;
    }
    path.pop_back();
}

bool check(int u, int v, int c) {
    vector<int> path;
    dfs(u, -1, v, path);
    for (int i = 0; i < (int)path.size() - 1; i++) {
        int x = path[i], y = path[i + 1];
        if(id[x][y] == -1) continue;
        if(c < edges[id[x][y]].first) return false;
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) par[i] = i;
    memset(id, -1, sizeof(id));
    for (int i = 0; i < m; i++) {
        int u, v, l, c;
        cin >> u >> v >> l >> c;
        edges.push_back({c, {u, v}});
        if(l == 0) merge(u, v);
        else id[u][v] = id[v][u] = i;
    }
    kruskal();
    for (auto e : edges) {
        int u = e.second.first, v = e.second.second;
        int l = e.first;
        if(l == 0 || find(u) == find(v)) continue;
        if(check(u, v, l)) ans += l;
    }
    cout << ans << endl;
    return 0;
}
