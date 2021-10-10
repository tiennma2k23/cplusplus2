#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=2e5+1;
int a[maxn];
map<int,int> cnt;
void solve()
{
    int n,sum=0;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
    if ((sum*2)%n)
    {
        cout<<0<<endl;
        return;
    }
    sum=(sum*2)/n;
    int ans=0;
    for (int i=1;i<=n;i++) 
    {
        ans+=cnt[sum-a[i]];
        cnt[a[i]]++;
    }
    for (int i=1;i<=n;i++) cnt[a[i]]=0;
    cout<<ans<<endl;
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