#include<bits/stdc++.h>
using namespace std;
#define maxN 50009
typedef pair<long long,int> edge;
vector<edge> adjList[maxN];
bool visited[maxN];
long long dist[maxN];
#define inf (long long)(1e9 +9LL)
void dijk(int start, int end){
priority_queue< edge, vector<edge>, greater<edge> > pq;
    pq.push({0,start});
    dist[start]=0LL;
    
    while(pq.empty()==false){
        int currNode=pq.top().second;
        long long currWeight=pq.top().first;
        pq.pop();
        if(visited[currNode]==false){
            visited[currNode]=true;
            for(auto node: adjList[currNode]){
                if(node.first-dist[currNode] < 0LL){ dist[node.second]=dist[currNode]; pq.push({dist[node.second], node.second}); }
                else{
                    if(node.first < dist[node.second]) { dist[node.second]=node.first; pq.push({dist[node.second], node.second}); }
                }
            }
        }
    }
}

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
memset(visited, false, sizeof visited);
for(int i=0;i<maxN;i++) dist[i]=inf;
    
    for(int i=0;i<m;i++){
        int a,b;
        long long c;
        scanf("%d %d %lld",&a,&b,&c);
        adjList[a].push_back({c,b});
        adjList[b].push_back({c,a});
    }
    //n=2;
    dijk(1,n);
    //n=2;
    if(dist[n]==inf)printf("NO PATH EXISTS");
    else printf("%d",dist[n]);
    return 0;
}

