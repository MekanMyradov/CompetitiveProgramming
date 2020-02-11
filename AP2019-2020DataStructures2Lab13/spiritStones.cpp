// Spirit Stones
#include <bits/stdc++.h>
using namespace std;
#define MAXN (int)((5 * 1e5) +5 )
long long FT[MAXN];

void buildORalter(int val, int x, int n){
    while(x<=n){
        FT[x]+=(long long)val;
        x+=x & (-x);
    }
}

long long summ(int x){
    long long res=0LL;
    while(x>0){
        res+=FT[x];
        x-= x&(-x);
    }
    return res;
}

long long query(int l, int r){
    return summ(r) - summ(l-1);
}

int main() {
    int n;
    scanf("%d",&n);
    int arr[n+1];
    arr[0]=0;
    for(int i=1; i<=n; i++) scanf("%d",&arr[i]);
    for(int i=1;i<=n;i++) buildORalter(arr[i],i,n);
    
int q;
    scanf("%d",&q);
    while(q--){
        int typ;
        scanf("%d",&typ);
        if(typ==1){
            int l,r;
            scanf("%d %d",&l,&r);
            printf("%d\n",query(l,r));
        }
        if(typ==2){
            int x,y;
            scanf("%d %d",&x,&y);

            buildORalter(y-arr[x], x, n);
                        arr[x]=y;
        }
    }
    //    for(int i=1;i<=n;i++) cout<<FT[i]<<" ";
    return 0;
}
