#include <bits/stdc++.h>
#define data _data
#define int long long
#define II pair<int, int>
#define fi first
#define se second
using namespace std;
const int maxn = 2e5 + 1;
int rt[maxn], sz[maxn], cnt, ans[maxn];
II q[maxn];
struct data
{
    int u, v, w;
};
data a[maxn];
bool cmp(data a, data b)
{
    return a.w < b.w;
}

int get(int u)
{
    if (u == rt[u])
        return u;
    return (rt[u] = get(rt[u]));
}

void unite(int u, int v)
{
    u = get(u), v = get(v);
    if (u == v)
        return;
    if (sz[u] < sz[v])
        swap(u, v);
    rt[v] = u;
    cnt -= ((sz[u] - 1) * sz[u] / 2 + (sz[v] - 1) * sz[v] / 2);
    sz[u] += sz[v];
    cnt += (sz[u] * (sz[u] - 1) / 2);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    for (int i = 1; i <= n; i++)
        rt[i] = i, sz[i] = 1;
    for (int i = 1; i <= m; i++)
        cin >> q[i].fi, q[i].se = i;
    sort(q + 1, q + 1 + m);
    sort(a + 1, a + n, cmp);
    int pos = 1;
    for (int i = 1; i <= m; i++)
    {
        data tmp = {0ll, 0ll, q[i].fi};
        int p = upper_bound(a + 1, a + n, tmp, cmp) - a - 1;
        for (int j = pos; j <= p; j++)
            unite(a[j].u, a[j].v);
        ans[q[i].se] = cnt;
        pos = p + 1;
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << " ";
}