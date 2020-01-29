#include<bits/stdc++.h>
using namespace std;
#define EMAX (int)(9*1e6)
#define VMAX 3009
pair<int, pair<int,int> > edges[EMAX];
int ancestor[VMAX];

int headParent(int k){
    if(ancestor[k]==k) return k;
    return ancestor[k]=headParent(ancestor[k]);
}

void makeUnion(int a, int b){
    int aHead=headParent(a);
    int bHead=headParent(b);
    ancestor[bHead]=aHead;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) ancestor[i]=i;
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        edges[i]={c,{a,b}};
    }
    sort(edges, edges+m);
int res=0;
    for(int i=0;i<m;i++){
        int weight=edges[i].first;
        int node1=edges[i].second.first;
        int node2=edges[i].second.second;
        
        if(headParent(node1)!=headParent(node2)){
            makeUnion(node1, node2);
            res+=weight;    
        }    
    }
    
    printf("%d",res);
    return 0;
}
