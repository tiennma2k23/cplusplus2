#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=2e5+1;
int a[maxn][5];

void solve()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    for (int j=1;j<=5;j++) cin>>a[i][j];
    for (int j1=1;j1<=5;j1++)
        for (int j2=1;j2<=5;j2++)
        {
            
            if (j1==j2) continue;
            int cnt1=0,cnt2=0,cnt3=0;
            bool ok=true;
            for (int i=1;i<=n;i++)
            {
                if (a[i][j1]==0&&a[i][j2]==0) {ok=false; break;}
                else if (a[i][j1]==1&&a[i][j2]==1) cnt1++;
                else if (a[i][j1]==1&&a[i][j2]==0) cnt2++;
                else cnt3++;
            }
            if (ok&&cnt1+cnt2>=n/2&&cnt1+cnt3>=n/2)
            {
                cout<<"YES"<<endl;
                return;
            }
        }
    cout<<"NO"<<endl;
}

int32_t main()
{
    int q;
    cin>>q;
    while (q--)
    {
        solve();
    }
}