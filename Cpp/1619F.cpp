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
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  int big = n%m;
  int smol = m-big;
  int shamt = min(big * (n/m+1), smol * (n/m)); //shift amount ;)
  vector<int> ans(n);
  for(int i=0; i<n; i++) ans[i] = i+1;
  for(int rep=0; rep<k; rep++){
    int p = 0;
    for(int i=0; i<m; i++){
      int blok = n/m + (i < big);
      printf("%d ", blok);
      for(int j=0; j<blok; j++)
        printf("%d ", ans[p++]);
      puts("");
    }
    puts("");
    vector<int> temp(n);
    for(int i=0; i<n; i++){
      temp[(i+shamt)%n] = ans[i];
    }
    ans = temp;
  }
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
