#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    for (int i=0;i<n;i++)
    {
        if (s1[i]==s2[i]&&s1[i]=='1')
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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