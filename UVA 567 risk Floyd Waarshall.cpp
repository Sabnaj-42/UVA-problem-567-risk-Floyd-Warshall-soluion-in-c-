#include<bits/stdc++.h>
using namespace std;
int dist[22][22];
int inf=1000000;
void floydwarshall()
{
    for(int k=1; k<=20; k++)
    {
        for(int i=1; i<=20; i++)
        {
            for(int j=1; j<=20; j++)
            {
                if(dist[i][k]!=inf&&dist[k][j]!=inf)
                {
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
}
int main()
{
    int t,cnt=1;;
    while(scanf("%d",&t)!=EOF)
    {
        for(int i=1; i<=20; i++)
        {
            for(int j=1; j<=20; j++)
            {
                if(i==j)dist[i][j]=0;
                else dist[i][j]=inf;
            }
        }
        for(int i=1;i<=t;i++)
        {
            int a;
            cin>>a;
            dist[1][a]=1;
            dist[a][1]=1;
        }
        for(int i=2;i<=19;i++)
        {
            int d;
            cin>>d;
            for(int j=1;j<=d;j++)
            {
                int e;cin>>e;
                dist[i][e]=1;
                dist[e][i]=1;
            }
        }
        floydwarshall();
        int n;cin>>n;
        printf("Test Set #%d\n",cnt);
        for(int i=1;i<=n;i++)
        {
            int u,v;cin>>u>>v;
            cout<<u<<" to "<<v<<": "<<dist[u][v]<<endl;
        }
        cnt++;

    }

}
