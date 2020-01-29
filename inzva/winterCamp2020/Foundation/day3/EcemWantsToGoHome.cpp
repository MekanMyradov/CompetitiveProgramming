#include<bits/stdc++.h>
using namespace std;
#define maxN (int)(1e5 +5)
typedef pair<int,int> edge;
vector<edge> adjList[maxN];
bool visited[maxN];
int dist[maxN];
#define inf (int)(1e9 +9)
void dijk(int start, int end){
priority_queue< edge, vector<edge>, greater<edge> > pq;
    pq.push({0,start});
    dist[start]=0;
    
    while(pq.empty()==false){
        int currNode=pq.top().second;
        int currWeight=pq.top().first;
        pq.pop();
        if(visited[currNode]==false){
            visited[currNode]=true;
            for(auto node: adjList[currNode]){
                if(currWeight+node.first < dist[node.second]){ dist[node.second]=currWeight+node.first; pq.push({dist[node.second], node.second}); }        
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
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        adjList[a].push_back({c,b});
        adjList[b].push_back({c,a});
    }
    int x,y;
    scanf("%d %d",&x,&y);
    dijk(x,y);
    if(dist[y]==inf)printf("-1");
    else printf("%d",dist[y]);
    return 0;
}

