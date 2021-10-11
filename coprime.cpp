#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+1;
multiset<int> st[maxn],s;
int cnt[maxn];
int32_t main()
{
     int n,ans=0;
     cin>>n;
     while (n--)
     {
         int x,y;
         cin>>x>>y;
         if (x==1)
         {
             cnt[y]++;
             if (cnt[y]==1)
             {
                 auto it=s.begin();
                 while (it!=s.end())
                 {
                     int val=*it;
                     if (__gcd(val,y)==1) st[y].insert(val),st[val].insert(y),ans++;
                     it++;
                 }
             }
             else ans+=st[y].size();
             s.insert(y);
         }
         else
         {
             cnt[y]--;
                 auto it=st[y].begin();
                 while (it!=st[y].end())
                 {
                     auto it1=it;
                     if (it1==st[y].begin())
                     {
                         st[*it1].erase(y);
                         ans-=cnt[*it1];
                     }
                     else {
                        it1--;
                     int val1=*it,val2=*(it1);
                     if (val1!=val2)
                     {
                         st[*it].erase(y);
                         ans-=cnt[*it];
                     }
                     }

                     it++;
                 }
                 if (cnt[y]==0) st[y].clear();s.erase(y);
             }
            cout<<ans<<endl;
         }
     }
