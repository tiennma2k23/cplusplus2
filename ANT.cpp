#include <bits/stdc++.h>

using namespace std;
int n;
int a[200010];
int q;
void read()
{
    cin >> n >> q;
    for(int i = 1;i <= n; i++)
        cin >> a[i];
}
int main()
{
    read();
    for(int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;
        if((r - l) % 2 == 0)
            cout << 1 << '\n';
        else
        {
            int mid =  (r - l + 1) / 2;
            cout << a[l + mid] - a[l + mid - 1] + 1 << '\n';
        }
    }
    return 0;
}