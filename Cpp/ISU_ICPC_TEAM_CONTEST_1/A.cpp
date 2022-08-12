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

const int N = 1e6;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int b[(int)1e6+2][19], c[10];
int cnt;
ll ten[20];
vector<pii> trie[N*19];

int get(int node, int dig){
  for(pii i : trie[node])
    if(i.ff == dig)
      return i.ss;
  return -1;
}

ll findmax(int idx){
  ll ret = 0LL;
  int cur = 0;
  for(int i=0; i<19; i++){
    int dig = b[idx][i];
    int nex = -1;
    for(int j=9-dig; j>=0; j--)
      if(nex == -1 && get(cur, j) != -1){
        nex = j;
        break;
      }
    for(int j=9; j>9-dig; j--)
      if(nex == -1 && get(cur, j) != -1){
        nex = j;
        break;
      }
    if(nex == -1){ 
      ret = 0LL;
      break;
    }
    else cur = get(cur, nex);
    ret += ten[19-i-1]*((nex + dig)%10);
    //~ printf("i:%d, dig:%d, nex:%d, ret:%lld\n", i, dig, nex, ret);
  }
  //~ printf("max -> idx:%d, ret:%lld\n", idx, ret);
  return ret;
}

ll findmin(int idx){
  ll ret = 0;
  int cur = 0;
  for(int i=0; i<19; i++){
    int dig = b[idx][i];
    int nex = -1;
    for(int j=10-dig; j<10; j++)
      if(nex == -1 && get(cur, j) != -1){
        nex = j;
        break;
      }
    for(int j=0; j<10-dig; j++)
      if(nex == -1 && get(cur, j) != -1){
        nex = j;
        break;
      }
    if(nex == -1){ 
      ret = (ll)1e18+7;
      break;
    }
    else cur = get(cur, nex);
    ret += ten[19-i-1]*((nex + dig)%10);
    //~ printf("i:%d ", i);
  }
  //~ printf("min -> idx:%d, ret:%lld\n", idx, ret);
  return ret;
}

void ins(int idx){
  int cur = 0;
  for(int i=0; i<19; i++){
    int dig = b[idx][i];
    if(get(cur, dig) == -1)
      trie[cur].pb({dig, ++cnt});
    cur = get(cur, dig);
  }
}

void solve(){
  int n;
  ten[0] = 1LL;
  for(int i=1; i<=19; i++) ten[i] = ten[i-1] * 10;
  ll mn = (ll)1e18+7, mx = 0LL;
  
  scanf("%d", &n);
  vector<ll> a(n+1);
  vector<int> ind;
  for(int i=1; i<=n; i++){
    scanf("%lld", &a[i]);
    ll num = a[i];
    for(int j=0; j<19; j++){
      b[i][19-j-1] = num%10;
      num /= 10LL;
    }
    //~ for(int j=0; j<19; j++) printf("%d ", b[i][j]);
    //~ puts("");
    umin(mn, findmin(i));
    umax(mx, findmax(i));
    ins(i);
  }
  printf("%lld %lld\n", mn, mx);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
