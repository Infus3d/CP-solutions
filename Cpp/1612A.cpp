#include "bits/stdc++.h"
// #include "ext/pb_ds/assoc_container.hpp"

#define mp make_pair
#define pb push_back
#define ppb pop_back
#define db puts("*****")
#define mid(x , y) ((x+y)>>1)
#define ff first
#define ss second
#define all(x)	x.begin(),x.end()
#define ll long long
#define sqr(x)	((x)*(x))
#define pii pair <int , int>
#define pll pair <ll, ll>
#define sz(x) int(x.size())
#define tr(it , c) for(__typeof(c.begin()) it = (c.begin()); it != (c.end()); it++)
#define y1 your_name_engraved_herein

using namespace std;
// using namespace __gnu_pbds;

const int N = 2e5+2;
const int MOD = 998244353;
const int K = 20+2;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int testcase;
int n, m[N], k[N];
double C[K][K];
double M[N];
set<int> setik;
vector<int> message;

// I have no proof and no idea why this works

void solve(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++)
    scanf("%d%d", &m[i], &k[i]), setik.insert(m[i]);
  
  for(auto i : setik)
    message.pb(i);
  
  C[0][0] = 1.0;
  for(int i=1; i<=20; i++){
    C[i][0] = C[i][i] = 1.0;
    for(int j=1; j<i; j++)
      C[i][j] = C[i-1][j-1] + C[i-1][j];
  }
  
  double mx = 0.0;
  vector<int> ans;
  for(int i=1; i<=min(20, sz(message)); i++){
    for(int j=1; j<=n; j++){
      double amount = 0.0;
      if(k[j] >= i)
        amount = 1.0;
      else
        amount = C[i-1][k[j]-1] / C[i][k[j]];
      
      M[m[j]] += amount;
    }
    sort(all(message), [&](int &x, int &y){
      return M[x] > M[y];
    });
    
    double cur = 0.0;
    vector<int> temp;
    for(int j=0; j<i; j++){
      cur += M[message[j]];
      temp.pb(message[j]);
    }
    
    if(cur > mx){
      mx = cur;
      ans = temp;
    }
    
    for(int j=1; j<=n; j++) M[m[j]] = 0.0;
  }
  
  printf("%d\n", sz(ans));
  for(int i : ans)
    printf("%d ", i);
  puts("");
}

int main(){
  testcase = 1;
  while(testcase--){
    solve();
  }
  return 0;
}
/*
 * 10 5 2
 * 
 * */
