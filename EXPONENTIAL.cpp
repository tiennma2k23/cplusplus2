#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxx=1e5;
set<int> v;
int32_t main()
{
    v.insert(1);
    for (int i=2;i<=maxx;i++)
    {
        int tmp=i;
        while (tmp*i<=maxx)
        {
            tmp*=i;
            v.insert(tmp);
        }
    }
    int x;
    cin>>x;
    auto it=v.upper_bound(x);
    it--;
    int ans=*it;
    cout<<ans<<endl;
}