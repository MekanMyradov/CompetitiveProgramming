#include<bits/stdc++.h>
using namespace std;
#define N 3005
typedef pair<int,int> edge;
vector<edge>adjList[N];
bool visited[N];
int res=0;
void prim(int start){
    priority_queue< edge, vector<edge>, greater<edge> >pq;
    pq.push({0,start});
  //  visited[start]=true;
    
    while(pq.empty()==false){
 //       printf("%d %d\n",pq.top().first,pq.top().second);
        int weight=pq.top().first;
        int currNode=pq.top().second;
        pq.pop();
        
        if(visited[currNode]==false){
            visited[currNode]=true;
            res+=weight;
            for(auto item: adjList[currNode]){
                if(visited[item.second]==false) pq.push({item.first, item.second});
            }
        }
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
memset(visited, false, sizeof visited);
    for(int i=0;i<m;i++){
        int x,y,r;
        scanf("%d %d %d",&x,&y,&r);
        adjList[x].push_back({r,y});
        adjList[y].push_back({r,x});
    }
    int start;
    scanf("%d",&start);
prim(start);
    
    printf("%d",res);
}
