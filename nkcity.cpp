#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=1e6+1,inf=1e9+1;
#define find _find
int c[maxn],rt[maxn];
struct nodes
{
    int u,v,w;
};

nodes g[maxn];

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
    cin>>n>>m;
    for (int i=1;i<=n;i++) rt[i]=i;
    for (int i=1;i<=m;i++)
    {
        cin>>g[i].u>>g[i].v>>g[i].w;
    }
    sort(g+1,g+1+m,cmp);

    int ans=-inf;
    for (int i=1;i<=m;i++)
    {
        if (find(g[i].u)==find(g[i].v)) continue;
        ans=max(ans,g[i].w);
        join(g[i].u,g[i].v);
    }
    cout<<ans<<endl;
}
