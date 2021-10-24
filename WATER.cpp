#include<bits/stdc++.h>
#define int long long
using namespace std ;
const int maxn=1e6+1;
int h[maxn], l[maxn], maxl[maxn];
stack<int> s ;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin>>n ;
    for (int i = 1;i<=n ;i++)
    {
        cin >> h[i] ;
        while (!s.empty() && h[i] >= h[s.top()]) s.pop() ;
        if (s.empty()) l[i]=0;
        else l[i]=s.top();
        s.push(i) ;
        if (h[i]>h[maxl[i-1]]) maxl[i]=i ;
        else maxl[i]=maxl[i-1];
    }

    while (!s.empty()) s.pop() ;
    int sum = 0, add = 0 ;
    int maxr = 0, r ;
    for (int i=n;i>=1;i--)
    {
        while (!s.empty() && h[i]>=h[s.top()])s.pop() ;
        if (s.empty()) r=n+1;
        else r=s.top();
        s.push(i);
        if (h[i]>h[maxr]) maxr = i ;
        sum+=min(h[maxr],h[maxl[i]])-h[i] ;
        if (h[i]>=min(h[maxl[i]],h[maxr]))
        {
            int cur=0 ;
            if (l[i]) cur+=i-l[i]-1 ;
            if (r<=n) cur+=r-i-1 ;
            add = max(add, cur) ;
        }
    }
    cout<<sum+add<<endl;
}
