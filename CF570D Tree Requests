#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int MaxN = 500010;

int cnt[MaxN][27], fa[MaxN], sz[MaxN], d[MaxN], son[MaxN], ans[MaxN], sum[MaxN], n, m, heavy;
vector<int> g[MaxN];
vector<pair<int, int>> q[MaxN];
string s;

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
    if (cnt[d[x]][s[x - 1] - 'a'] == 0 || (cnt[d[x]][s[x - 1] - 'a'] > 1 && cnt[d[x]][s[x - 1] - 'a'] % 2 == 0)) {
      sum[d[x]]++;
    }
    cnt[d[x]][s[x - 1] - 'a']++;
    if ((cnt[d[x]][s[x - 1] - 'a'] > 1 && cnt[d[x]][s[x - 1] - 'a'] % 2 == 0)) {
      sum[d[x]]--;
    }
  } else {
    if ((cnt[d[x]][s[x - 1] - 'a'] > 1 && cnt[d[x]][s[x - 1] - 'a'] % 2 == 0)) {
      sum[d[x]]++;
    }
    cnt[d[x]][s[x - 1] - 'a']--;
    if (cnt[d[x]][s[x - 1] - 'a'] == 0 || (cnt[d[x]][s[x - 1] - 'a'] > 1 && cnt[d[x]][s[x - 1] - 'a'] % 2 == 0)) {
      sum[d[x]]--;
    }
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
    ans[id] += (sum[k] <= 1);
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
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 2, fa; i <= n; i++) {
    cin >> fa;
    g[fa].push_back(i);
  }
  cin >> s;
  for (int i = 1, u, k; i <= m; i++) {
    cin >> u >> k;
    q[u].push_back({k, i});
  }
  d[1] = 1, FB(1);
  DFS(1, 1);
  for (int i = 1; i <= m; i++) {
    cout << (ans[i] ? "Yes" : "No") << '\n';
  }
  return 0;
}
