#include "bits/stdc++.h"

#define ff first
#define ss second
#define pb push_back
#define ll long long
#define db puts("*****")
#define sz(x) int(x.size())
#define pii pair <int , int>
#define mid(x , y) ((x+y)>>1)
#define all(x)	x.begin(),x.end()
#define y1 your_name_engraved_herein

using namespace std;

const int N = 2e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int a, b, c, d, mark[N];
int zer, one;

int get(int x){
  if(x == 0) return 0;
  for(int i=1; i*i<=2*x; i++)
    if(i*(i+1) == 2*x)
      return i+1;
  return -1;
}

void solve(){
  scanf("%d%d%d%d", &a, &b, &c, &d);
  if(!a && !b && !c && !d){
    printf("1");
    return;
  }
  if(0LL + a + b + c + d == 1LL){
    if(a == 1) puts("00");
    else if(b == 1) puts("01");
    else if(c == 1) puts("10");
    else puts("11");
    return;
  }
  zer = get(a); one = get(d);
  //~ printf("%d %d\n", zer, one);
  if(zer == -1 || one == -1){
    puts("impossible");
    return;
  }
  if(!a && zer*one != b+c) zer++;
  if(!d && zer*one != b+c) one++;
  if(b+c != zer*one){
    puts("impossible");
    return;
  }
  
  if(zer > 0){
    mark[zer] = b / zer;
    one -= mark[zer];
    if(one > 0){
      mark[b % zer]++;
      one--;
    }
  }
  mark[0] += one;
  
  for(int i=0; i<=zer; i++){
    if(i > 0) printf("0");
    for(int j=0; j<mark[i]; j++)
      printf("1");
  }
  puts("");
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
