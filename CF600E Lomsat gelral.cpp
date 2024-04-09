#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const int MaxN = 1e5 + 10, start = 0, endd = MaxN - 1;

int cnt[MaxN], fa[MaxN], sz[MaxN], son[MaxN], c[MaxN], nxt[MaxN], pre[MaxN], n, m, heavy;
long long ans[MaxN], maxx, sum;
vector<int> g[MaxN];
bool vis[MaxN];

void FB(int x, int fa) {
  sz[x] = 1;
  for (int i : g[x]) {
    if (i == fa) continue;
    FB(i, x);
    sz[x] += sz[i];
    if (sz[son[x]] < sz[i]) son[x] = i;
  }
}

void update(int x, int v, int fa) {
  for (int i : g[x]) {
    if (i == heavy || i == fa) continue;
    update(i, v, x);
  }    
  cnt[c[x]] += v;
  if (v == 1) {
    if (maxx == cnt[c[x]]) {
      sum += c[x];
    }
    if (maxx < cnt[c[x]]) {
      maxx = cnt[c[x]];
      sum = c[x];
    }
  }
  if (!vis[c[x]] && cnt[c[x]] > 0) {
    pre[c[x]] = pre[endd], nxt[pre[endd]] = c[x], nxt[c[x]] = endd, pre[endd] = c[x], vis[c[x]] = 1;
  }
  if (cnt[c[x]] == 0 && vis[c[x]]) {
    vis[c[x]] = 0;
    nxt[pre[c[x]]] = nxt[c[x]], pre[nxt[c[x]]] = pre[c[x]];
  }
}

void G(int x) {
  ans[x] += sum;
}

void DFS(int x, int flag, int fa) {
  for (int i : g[x]) {
    if (i == son[x] || i == fa) continue;
    DFS(i, 0, x);
  }
  if (son[x]) DFS(son[x], 1, x), heavy = son[x];
  update(x, 1, fa);
  G(x);
  heavy = 0;
  if (!flag) update(x, -1, fa), maxx = sum = 0;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  nxt[start] = endd, pre[endd] = start;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  FB(1, 0);
  DFS(1, 0, 0);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  return 0;
}
