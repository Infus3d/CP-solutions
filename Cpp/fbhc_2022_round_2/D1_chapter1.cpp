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

const int N = 1e6+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, m;
int fen[4][N];

void add(int x, int a, int val){
  while(x <= n){
    fen[a][x] += val;
    x += (x & -x);
  }
}

int sum(int x, int a){
  int ret = 0;
  while(x > 0){
    ret += fen[a][x];
    x -= (x & -x);
  }
  return ret;
}

int range(int x, int y, int a){
  return sum(y, a) - sum(x-1, a);
}

void solve(){
  scanf("%d%d", &n, &m);
  vector<int> a(n+1);
  vector<int> have(4, 0);
  for(int i=1; i<=3; i++){
    for(int j=0; j<=n; j++){
      fen[i][j] = 0;
    }
  }
  int cursum = 0;
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
    add(i, a[i], 1);
    cursum += a[i];
    have[a[i]]++;
  }
  long long ans = 0;
  while(m--){
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    add(x, a[x], -1);
    cursum -= a[x];
    have[a[x]]--;
    a[x] = y;
    cursum += a[x];
    have[a[x]]++;
    add(x, a[x], +1);
    if(cursum % 2 == 1){
      printf("wtf??? cursum -> %d\n", cursum);
      puts("-1");
      ans += -1;
      continue;
    }
    int h = cursum / 2;
    vector<int> need(4, 0);
    int cnt = 0;
    need[3] = min(h/3, have[3]);
    if(h % 3 == 1 && have[1] == 0 && need[3] > 0)
      need[3]--;
    h -= 3*need[3];
    cnt += need[3];
    if(h % 2 == 1 && have[1] == 0){
      printf("h --> %d, have[1]->%d, have[2]->%d, have[3]->%d\n", h, have[1], have[2], have[3]);
      puts("-1");
      ans += -1;
      continue;
    }
    need[2] = min(h/2, have[2]);
    h -= 2*need[2];
    cnt += need[2];
    need[1] = min(h, have[1]);
    h -= need[1];
    cnt += need[1];
    if(h != 0){
      printf("h ---> %d\n", h);
      puts("-1");
      ans += -1;
      continue;
    }
    if(cnt != z && cnt != (n-z)){
      printf("cnt ---> %d, h --> %d, cursum -> %d\n", cnt, h, cursum);
      printf("%d %d %d\n", have[1], have[2], have[3]);
      puts("-1");
      ans += -1;
      continue;
    }
    int l = -1, r = -1;
    int mini = n;
    if(cnt == z){
      l = 1, r = z;
      vector<int> already(4, 0);
      for(int i=1; i<=3; i++){
        already[i] = range(l, r, i);
      }
      int thistime = 0;
      for(int i=1; i<=3; i++){
        if(need[i] - already[i] > 0)
          thistime += need[i] - already[i];
      }
      mini = min(mini, thistime);
    }
    if(cnt == (n-z)){
      l = z+1, r = n;
      vector<int> already(4, 0);
      for(int i=1; i<=3; i++){
        already[i] = range(l, r, i);
      }
      int thistime = 0;
      for(int i=1; i<=3; i++){
        if(need[i] - already[i] > 0)
          thistime += need[i] - already[i];
      }
      mini = min(mini, thistime);
    }
    //~ printf("before -> %lld\n", ans);
    ans += mini;
    //~ printf("after -> %lld\n", ans);
    printf("mini -> %d\n", mini);
  }
  printf("%lld\n", ans);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  for(int i=1; i<=testcase; i++){
    printf("Case #%d: ", i);
    solve();
  }
  return 0;
}
/*
100 
Case #1: 8 100
1 1 1 1 1 1 1 1
1 1 4
mini -> 0
1 3 3
mini -> 0
1 3 5
mini -> 1
1 2 4
-1
2 2 3
mini -> 0
2 3 5
-1
2 2 5
mini -> 2
8 3 4
-1
*/
