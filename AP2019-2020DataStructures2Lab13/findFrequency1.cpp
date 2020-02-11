// Find Frequency 1
#include <bits/stdc++.h>
using namespace std;
#define MAXN (int)(1e5 +5)
int arr[MAXN], answers[MAXN];
pair< pair<int,int>, pair<int,int> > query[MAXN];
int BLOCK_SIZE;
map<int,int> numsOfNums;

bool moCompare(const pair< pair<int,int>, pair<int,int> >&x, const pair< pair<int,int>, pair<int,int> >&y){
    int block_x=x.first.first/BLOCK_SIZE;
    int block_y=y.first.first/BLOCK_SIZE;
    
    if(block_x!=block_y) return block_x < block_y;
    return x.first.second < y.first.second;
}

void add(int x){
    numsOfNums[x]++;
    return ;
}
void remove(int x){
    numsOfNums[x]--;
    return ;
} 

int main() {
    int n,q;
    scanf("%d",&n);
    BLOCK_SIZE=sqrt(n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        int l,r;
        scanf("%d %d %d",&l,&r,&query[i].second.first); 
        query[i].first.first=l-1; query[i].first.second=r-1;
        query[i].second.second=i;
    }
    
    sort(query, query+q, moCompare);
    int mo_left=0, mo_right=-1;
//    for(int i=0;i<q;i++) printf("%d %d\n",query[i].first.first, query[i].first.second);
  for(int i=0;i<q;i++){
      int left=query[i].first.first;
      int right=query[i].first.second;
      while(mo_right < right){
          mo_right++;
          add(arr[mo_right]);
      }
      while(mo_right > right){
          remove(arr[mo_right]);
          mo_right--;
      }
      while(mo_left < left){
          remove(arr[mo_left]);
          mo_left++;
      }
      while(mo_left > left){
          mo_left--;
          add(arr[mo_left]);
      }

      answers[query[i].second.second]=numsOfNums[query[i].second.first];
  }  
    
    for(int i=0;i<q;i++) printf("%d\n",answers[i]);
    return 0;
}
