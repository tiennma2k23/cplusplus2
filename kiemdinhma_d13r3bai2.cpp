#include<bits/stdc++.h>
#define int long long 
using namespace std;
string s[100001];
vector<int> v;
int32_t main()
{
    int n,lent=0;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>s[i],lent+=s[i].length();
    for (int i=1;i<=n;i++) v.push_back(i);
    string s1,ans="";
    s1="";
    for (auto val:v)
        {
            if (s1.length()==0)
            {
                s1+=s[val];
            }
            if (s1[s1.length()-1]==s[val][0]) 
            {
                string s2=s[val];
                s2.erase(0,1);
                s1+=s2;
            }
        }
    int len=10000000000;
    if (s1.length()<n) 
    {
        if (len>s1.length()) ans=s1,len=s1.length();
    }
    while (next_permutation(v.begin(),v.end()))
    {
        s1="";
    for (auto val:v)
        {
            if (s1.length()==0)
            {
                s1+=s[val];
            } 
            else {
                string s2=s[val];
                if (s1[s1.length()-1]==s[val][0]) s2.erase(0,1);
                s1+=s2;
            }
        }
    cout<<s1<<endl;
    if (s1.length()<lent) 
    {
        if (len>s1.length()) ans=s1,len=s1.length();
    }
    }
    if (ans=="") cout<<-1<<endl;
    else cout<<ans<<endl;
}