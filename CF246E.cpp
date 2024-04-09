#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
 
using namespace std;
 
const int MaxN = 1e5 + 10;
 
int fa[MaxN], sz[MaxN], d[MaxN], son[MaxN], ans[MaxN], n, m, heavy, tot;
vector<int> g[MaxN];
vector<pair<int, int>> q[MaxN];
set<string> cnt[MaxN];
string s[MaxN];
 
void FB(int x) {
  sz[x] = 1;
  for (int i : g[x]) {
    d[i] = d[x] + 1;
    FB(i);
    sz[x] += sz[i];
    if (sz[son[x]] < sz[i]) son[x] = i;
  }
}
 
void update(int x, int v) {
  if (v == 1) {
    cnt[d[x]].insert(s[x]);
  } else {
    cnt[d[x]].clear();
  }
  for (int i : g[x]) {
    if (i == heavy) continue;
    update(i, v);
  }
}
 
void G(int x) {
  for (auto i : q[x]) {
    int id = i.second;
    int k = i.first;
    int pos = d[x] + k;
    if (pos <= n) ans[id] = cnt[pos].size();
  }
}
 
void DFS(int x, int flag) {
  for (int i : g[x]) {
    if (i == son[x]) continue;
    DFS(i, 0);
  }
  if (son[x]) DFS(son[x], 1), heavy = son[x];
  update(x, 1);
  G(x);
  heavy = 0;
  if (!flag) update(x, -1);
}
 
int main() {
  cin >> n;
  for (int i = 1, x; i <= n; i++) {
    cin >> s[i] >> x;
    g[x].push_back(i);
  }
  cin >> m;
  for (int i = 1, u, k; i <= m; i++) {
    cin >> u >> k;
    q[u].push_back({k, i});
  }
  FB(0);
  DFS(0, 1);
  for (int i = 1; i <= m; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}
