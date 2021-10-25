#include <bits/stdc++.h>
#define cc pair<char, char>
#define fi first
#define se second
#define int long long
using namespace std;
map<cc, int> cnt;
int32_t main()
{
    int n;
    string a, b;
    cin >> n >> a >> b;

    for (int i = 0; i < n; i++)
    {
        char c1 = a[i], c2 = b[i];
        if (c1 != c2)
        {
            cnt[{c1, c2}]++;
            for (int j = 0; j < n; j++)
            {
                if (a[j] == c1)
                    a[j] = c2;
                if (b[j] == c1)
                    b[j] = c2;
            }
        }
    }
    cout << cnt.size() << endl;
    for (auto p : cnt)
        cout << p.fi.fi << " " << p.fi.se << endl;
}