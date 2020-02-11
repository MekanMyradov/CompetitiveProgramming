// Ali Cafer Game
#include <bits/stdc++.h>
using namespace std;
#define MAXN (int)((2 * 1e5) +5 )
long long FT[MAXN];

int logComp(int n){
    if(n<2) return 1;
    return logComp(n/2)+1;
}

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

long long query(int x){
    return summ(x);
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
            int x,y;
            scanf("%d %d",&x,&y);

            buildORalter(y-arr[x], x, n);
                        arr[x]=y;
        }
        if(typ==2){
            int target;
            scanf("%d",&target);
            int l=1, r=n, entry=0;
            bool found=false;
// binarySearch
            int logN=logComp(n);
            while(entry++ <= logN){
                int mid=(l+r)/2;
                long long Qtmp=query(mid);
         if(Qtmp==target){printf("YES\n");found=true;break;}
         if(Qtmp<target) l=mid+1;
        if(Qtmp>target) r=mid-1;
            }
            if(found==false) printf("NO\n");
        }
    }
    //    for(int i=1;i<=n;i++) cout<<FT[i]<<" ";
    return 0;
}
