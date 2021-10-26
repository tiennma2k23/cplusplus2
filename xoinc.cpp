#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2001;
int a[maxn], dp[maxn][maxn], _max[maxn][maxn];
int32_t main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    reverse(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = a[i] - _max[i - j][min(j + j, i - j)];
            _max[i][j] = max(_max[i][j - 1], dp[i][j]);
        }
    cout << max(dp[n][1], dp[n][2]);
}