#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=2e5+1,inf=1e9+1;
#define find _find
int c[maxn],rt[maxn];
struct nodes
{
    int u,v,w;
};

vector<nodes> g;

bool cmp(nodes a, nodes b)
{
    return a.w<b.w;
}
	
int find(int x) {
	if (rt[x]==x) return (x);
	rt[x]=find(rt[x]);
	return (rt[x]);
}
void join(int a,int b) 
{
	int x=find(a);
	int y=find(b);
	if (x==y) return;
	rt[y]=x;
}
int32_t main()
{
    int n,m;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>c[i],g.push_back(nodes({0ll,i,c[i]})),rt[i]=i;
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
    {
        int p;
        cin>>p;
        if (i<j) g.push_back(nodes({i,j,p}));
    }
    sort(g.begin(),g.end(),cmp);

    int ans=0;
    for (auto val:g)
    {
        int u=val.u,v=val.v,w=val.w;
        if (find(v)==find(u)) continue;
        ans+=w;
        join(u,v);
    }
    cout<<ans<<endl;
}