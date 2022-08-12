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

void solve(){
  int a, b;
  scanf("%d%d", &a, &b);
  for(int i=1; i<=a; i++){
    for(int j=1; j<=b*2+1; j++)
      printf("%c", (i == 1 && j < 3) ? '.' : (j % 2 == 1 ? '+' : '-'));
    puts("");
    for(int j=1; j<=b*2+1; j++)
      printf("%c", (i == 1 && j < 3) ? '.' : (j % 2 == 1 ? '|' : '.'));
    puts("");
  }
  for(int i=1; i<=b*2+1; i++)
    printf("%c", (i % 2 == 1 ? '+' : '-'));
  puts("");
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  for(int tt=1; tt<=testcase; tt++){
    printf("Case #%d:\n", tt);
    solve();
  }
  return 0;
}
