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

int n, a, b;

void solve(){
  scanf("%d%d%d", &n, &a, &b);
  int m = n * (n+1) / 2;
  if(m % (a+b) != 0){
    printf("IMPOSSIBLE\n");
    return;
  }
  
  vector<int> v;
  int k = m / (a+b) * a;
  int largest = n;
  while(k > 0){
    while(k < largest) largest--;
    k -= largest;
    v.push_back(largest);
    largest--;
  }
  sort(all(v));
  printf("POSSIBLE\n");
  printf("%d\n", sz(v));
  for(int i : v)
    printf("%d ", i);
  puts("");
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  for(int tt=1; tt<=testcase; tt++){
    printf("Case #%d: ", tt);
    solve();
  }
  return 0;
}
