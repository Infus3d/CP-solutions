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
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int ten[N], smalleq, bigeq, eq, tot, n;
char a[N], b[N];

int mul(int x, int y){
  return (1LL * x * y) % MOD;
}

void solve(){
  smalleq = bigeq = eq = 1;
  scanf("%d", &n);
  scanf("%s%s", a, b);
  for(int i=0; i<n; i++){
    if(a[i] == '?' && b[i] == '?'){
      tot += 2;
      eq = mul(eq, 10);
      smalleq = mul(smalleq, (10 * 11)/2);
      bigeq = mul(bigeq, (10 * 11)/2);
    }
    else if(a[i] != '?' && b[i] != '?'){
      if(a[i] > b[i]) smalleq = 0;
      else if(a[i] < b[i]) bigeq = 0;
      if(a[i] != b[i]) eq = 0;
    }
    else if(a[i] == '?'){
      tot++;
      smalleq = mul(smalleq, (b[i]-'0')+1);
      bigeq = mul(bigeq, 10-(b[i]-'0'));
    }
    else if(b[i] == '?'){
      tot++;
      smalleq = mul(smalleq, 10-(a[i]-'0'));
      bigeq = mul(bigeq, (a[i]-'0')+1);
    }
  }
  
  ten[0] = 1;
  for(int i=1; i<=2*n; i++) 
    ten[i] = mul(ten[i-1], 10);
  
  printf("%d\n", (ten[tot] - (((smalleq + bigeq)%MOD - eq + MOD)%MOD) + MOD)%MOD);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
