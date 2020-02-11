// Interrupt Sum
#include <bits/stdc++.h>
using namespace std;
#define MAXN (int)(1e5 +5)
int numOfBlocks=0;
int arr[MAXN], BlockBegin[(int)sqrt(MAXN)], BlockEnd[(int)sqrt(MAXN)];
long long blocks[(int)sqrt(MAXN)], blockLazy[(int)sqrt(MAXN)];
int IiB[MAXN];              // Indices in Blocks
int siz;
void build(int n){
    siz=sqrt(n);
    for(int i=1;i<=n;i++){
        if(i%siz==1){numOfBlocks++; BlockBegin[numOfBlocks]=i;}
        blocks[numOfBlocks]+=(long long)arr[i];
        IiB[i]=numOfBlocks;
        BlockEnd[numOfBlocks]=i;
    }
    return ;
}

long long query(int left, int right){
long long res=0LL;
    // l and r in same block
    if(IiB[left]==IiB[right]){
        for(int i=left;i<=right;i++) {res+=arr[i];
        res+=(blockLazy[IiB[left]]/siz);}
    }
    else{
        // full blocks
        for(int i=IiB[left]+1; i<=IiB[right]-1; i++)
        {res+=blocks[i];res+=blockLazy[i];}
        for(int i=left;i<=BlockEnd[IiB[left]];i++)
        {res+=(long long)arr[i];res+=blockLazy[IiB[left]]/siz;}
        for(int i=BlockBegin[IiB[right]];i<=right;i++)
        {res+=(long long)arr[i];res+=blockLazy[IiB[right]]/siz;}
    }
    return res;
}

void update(int left, int right, int x){
    if(IiB[left]==IiB[right])
        for(int i=left;i<=right;i++) {arr[i]+=x;blocks[IiB[right]]+=x;}
    else{
    for(int i=IiB[left]+1; i<=IiB[right]-1; i++)
        blockLazy[i]+=(long long)x*siz;
    for(int i=left;i<=BlockEnd[IiB[left]];i++)
        {arr[i]+=x;blocks[IiB[left]]+=x;}
    for(int i=BlockBegin[IiB[right]];i<=right;i++)
        {arr[i]+=x;blocks[IiB[right]]+=x;}
    }
    return;
}

int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
build(n);
//    for(int i=1;i<=numOfBlocks;i++) printf("%d ",blocks[i]);
    
    int q;
    scanf("%d",&q);
    while(q--){
        int typ;
        scanf("%d",&typ);
        if(typ==1){
            int l,r;
            scanf("%d %d",&l,&r);
            if(r>n) r=n;
            printf("%lld\n",query(l,r));
  //          for(int i=1;i<=n;i++) printf("%d ",arr[i]);
    //        printf("\n");
        }
        if(typ==2){
            int l,r,x;
            scanf("%d %d %d",&l,&r,&x);
            update(l,r,x);
        }
    }  
    
    
    return 0;
}
