#include <bits/stdc++.h>
#define G _g
#define B _b
using namespace std;
const int maxn = 1e6 + 5, inf = 1e18 + 1, maxx = 101;
vector<int> v1, v2;
int g, b, k;
int G[maxn], B[maxn], f[maxx][maxx][maxx];
set<int> st;
void sub1()
{
    int ans = inf;
    for (int mask = 0; mask < (1 << b); mask++)
    {
        for (int mask2 = 0; mask2 < (1 << g); mask2++)
        {
            int dem1 = __builtin_popcount(mask), dem2 = __builtin_popcount(mask2);
            v1.clear(), v2.clear();
            if (dem1 == k && dem2 == k)
            {
                for (int i = 0; i < b; i++)
                {
                    if (mask & (1 << i))
                        v1.push_back(B[i + 1]);
                }
                for (int i = 0; i < g; i++)
                {
                    if (mask2 & (1 << i))
                        v2.push_back(G[i + 1]);
                }
                int res = 0;
                for (int i = 0; i < v1.size(); i++)
                    res = max(res, abs(v1[i] - v2[i]));
                ans = min(ans, res);
            }
        }
    }
    cout << ans << endl;
}

void sub2()
{
    for (int i = 0; i <= b; i++)
        for (int j = 0; j <= g; j++)
            for (int _k = 1; _k <= k; _k++)
                f[i][j][_k] = inf;
    for (int i = 1; i <= b; i++)
        for (int j = 1; j <= g; j++)
            for (int _k = 1; _k <= k; _k++)
            {
                f[i][j][_k] = min(min(f[i - 1][j][_k], f[i][j - 1][_k]), f[i - 1][j - 1][_k]);
                f[i][j][_k] = min(f[i][j][_k], max(f[i - 1][j - 1][_k - 1], abs(B[i] - G[j])));
                //cerr<<i<<j<<k<<f[i][j][k]<<endl;
            }
    cout << f[b][g][k] << endl;
}

void sub4()
{
    int ans = inf;
    for (int i = 1; i <= g; i++)
        st.insert(G[i]);
    for (int i = 1; i <= b; i++)
    {
        auto it = st.upper_bound(B[i]);
        ans = min(ans, abs(B[i] - (*it)));
        it--;
        ans = min(ans, abs(B[i] - (*it)));
    }
    cout << ans << endl;
}
bool ok(int x)
{
    int len = 0, pos = 0;
    for (int i = 1; i <= g; i++)
    {
        int l = lower_bound(B + 1, B + 1 + b, G[i] - x) - B;
        int r = upper_bound(B + 1, B + 1 + b, G[i] + x) - B - 1;
        if (l > r)
            continue;
        if (r > pos)
            pos = max(l, pos + 1), len++;
    }
    if (len >= k)
        return true;
    return false;
}
void sub36()
{
    int ans;
    int l = 0, r = 1e9;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (ok(mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> b >> g >> k;
    for (int i = 1; i <= b; i++)
        cin >> B[i];
    for (int i = 1; i <= g; i++)
        cin >> G[i];
    sort(B + 1, B + 1 + b);
    sort(G + 1, G + 1 + g);
    if (max(b, g) <= 10)
        sub1();
    else if (max(b, g) <= 100)
        sub2();
    else if (k == 1)
        sub4();
    else
        sub36();
}