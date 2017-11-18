#include<bits/stdc++.h>
#define clr(x) memset(x,0,sizeof(x))
#define clr_1(x) memset(x,-1,sizeof(x))
#define mod 1000000007
#define LL long long
#define eps (1e-6)
#define INF (0x3f3f3f3f)
using namespace std;
const int N=5e2+10;
struct edg
{
    int u,v,cost;
    bool use;
}edge[N*N];
int n,m,p,k,ecnt,u,v,cst,usd,maxn,cost;
int fa[N],maxans[N];
bool inf[N];
void addedge(int u,int v,int cost,int use)
{
    edge[++ecnt]=(edg){u,v,cost,(bool)use};
    return ;
}
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
        inf[i]=0;
    }
    return ;
}
bool cmp(edg a,edg b)
{
    return a.cost<b.cost;
}
int Find(int x)
{
    if(x!=fa[x])
        fa[x]=Find(fa[x]);
    return fa[x];
}
void Union(int u,int v)
{
    fa[Find(u)]=Find(v);
    return ;
}
int main()
{
    scanf("%d%d",&n,&m);
    ecnt=0;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d%d",&u,&v,&cst,&usd);
        addedge(u,v,cst,usd);
    }
    sort(edge+1,edge+ecnt+1,cmp);
    maxn=0;
    for(int i=1;i<=n;i++)
    {
        init(n);
        cost=0;
        for(int j=1;j<=ecnt;j++)
        {
            u=edge[j].u; v=edge[j].v;
            if(u!=i && v!=i && edge[j].use)
                if(Find(u)!=Find(v))
                    Union(u,v);
        }
        for(int j=1;j<=ecnt;j++)
        {
            u=edge[j].u; v=edge[j].v;
            if(u!=i && v!=i && !edge[j].use)
                if(Find(u)!=Find(v))
                {
                    Union(u,v);
                    cost+=edge[j].cost;
                }
        }
        cst=0;
        for(int j=1;j<=n;j++)
        {
            if(!inf[Find(j)])
                cst++;
            inf[Find(j)]=1;
        }
        if(cst>2)
        {
            maxn=INF;
            maxans[i]=INF;
        }
        else
        {
            maxans[i]=cost;
            maxn=max(maxn,cost);
        }
    }
    if(maxn==0)
        printf("0\n");
    else
    {
        int i;
        for(i=1;i<=n;i++)
            if(maxans[i]==maxn)
            {
                printf("%d",i);
                break;
            }
        for(i++;i<=n;i++)
            if(maxans[i]==maxn)
                printf(" %d",i);
        printf("\n");
    }
    return 0;
}
