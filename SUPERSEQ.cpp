#include<bits/stdc++.h>
#define int long long 
#define II pair<int,int>
using namespace std;
const int maxn=1e5+1;
int a[maxn],cnt[500];
vector<int> pos[500];
set<II> st;
int32_t main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,ans=0,lim;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int tmp=i*(i+1)/2;
        if (tmp<=n) lim=i;
        else break;
    }
    for (int i=1;i<=n;i++) 
    {
        cin>>a[i];
        if (a[i]<=lim) pos[a[i]].push_back(i);
    }
    for (int i=1;i<=lim;i++)
    {
        for (auto p:pos[i])
        {
            for (int j=1;j<=i;j++) cnt[j]=0;
            int dem=0;
            for (int j=p;j>=1;j--)
            {
                if (a[j]>i) break;
                cnt[a[j]]++;
                if (cnt[a[j]]>a[j]) break;
                if (cnt[a[j]]==a[j]) dem++;
                if (cnt[i]==i)
                {
                    if (dem==i) ans++;
                }
            }
            for (int j=1;j<=i;j++) cnt[j]=0;
            dem=0;
            for (int j=p;j<=n;j++)
            {
                if (a[j]>i) break;
                cnt[a[j]]++;
                if (cnt[a[j]]>a[j]) break;
                if (cnt[a[j]]==a[j]) dem++;
                if (cnt[i]==i)
                {
                    if (dem==i&&a[j]!=i) ans++;
                }
            }
        }       
    }
    cout<<ans<<endl;
}