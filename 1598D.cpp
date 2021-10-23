#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=2e5+1;
int a[maxn],b[maxn];
map<int,int> cnta, cntb;
void solve()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i]>>b[i],cnta[a[i]]++,cntb[b[i]]++;
    int ans=(((n*(n-1))/2)*(n-2))/3;
    for (int i=1;i<=n;i++) ans-=(cnta[a[i]]-1)*(cntb[b[i]]-1);
    for (int i=1;i<=n;i++) cnta[a[i]]=cntb[b[i]]=0;
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