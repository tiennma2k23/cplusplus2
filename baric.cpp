#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1001, inf = 1e9;
int f[maxn][maxn], c[maxn][maxn], m[maxn];
int32_t main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 1; i <= n; i++)
        cin >> m[i];
    for (int i = 1; i <= n; i++)
    {
        c[0][i] = 0;
        for (int j = 1; j < i; j++)
            c[0][i] += 2 * abs(m[j] - m[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        c[i][n + 1] = 0;
        for (int j = i + 1; j <= n; j++)
            c[i][n + 1] += 2 * abs(m[j] - m[i]);
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            c[i][j] = 0;
            for (int k = i + 1; k < j; k++)
                c[i][j] += abs(2 * m[k] - m[i] - m[j]);
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            f[i][j] = inf;
    for (int i = 1; i <= n; i++)
        f[i][1] = c[0][i];
    int res = 1, opt = 1000000000;
    while (true)
    {
        opt = 1000000000;
        for (int i = 1; i <= n; i++)
            opt = min(opt, f[i][res] + c[i][n + 1]);
        if (opt <= e)
            break;
        res++;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j < i; j++)
                f[i][res] = min(f[i][res], f[j][res - 1] + c[j][i]);
    }
    cout << res << " " << opt << endl;
}