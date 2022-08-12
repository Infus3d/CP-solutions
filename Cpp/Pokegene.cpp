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

int n, q, sortInd[N];
int P[N][19], lvl[N];
pair<string, int> s[N];

int trie[N][26], cnt, leaf[N];

struct myq{
  int n, k;
  vector<int> v;
} t[N];

void add(string &word, int ind){
  int cur = 0, len = (int)word.length();
  for(int i=0; i<len; i++){
    if(trie[cur][word[i]-'a'] == 0){
      trie[cur][word[i]-'a'] = ++cnt;
      lvl[cnt] = i+1;
      P[cnt][0] = cur;
    }
    cur = trie[cur][word[i]-'a'];
  }
  leaf[ind] = cur;
}

void build_lca(){
  for(int j=1; j<19; j++)
    for(int i=1; i<=cnt; i++)
      if(P[i][j-1] > -1)
        P[i][j] = P[P[i][j-1]][j-1];
}

int lca(int x, int y){
  //~ printf("x:%d, y:%d, leaf[x]:%d, leaf[y]:%d\n", x, y, leaf[x], leaf[y]);
  x = leaf[x], y = leaf[y];
  if(lvl[x] < lvl[y]) 
    swap(x, y);
  //~ printf("x:%d, y:%d, lvl[x]:%d, lvl[y]:%d\n", x, y, lvl[x], lvl[y]);
  
  for(int i=18; i>=0; i--)
    if(lvl[x] - (1<<i) >= lvl[y])
      x = P[x][i];
  
  if(x == y) return x;
  
  for(int i=18; i>=0; i--)
    if(P[x][i] > -1 && P[x][i] != P[y][i])
      x = P[x][i], y = P[y][i];
    
  assert(P[x][0] > -1);
  return P[x][0];
}

void solve(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  cin >> n >> q;
  for(int i=1; i<=n; i++) 
    cin >> s[i].ff, s[i].ss = i;
  
  sort(s+1, s+n+1);
  memset(P, -1, sizeof(P));
  
  for(int i=1; i<=n; i++){
    sortInd[s[i].ss] = i;
    add(s[i].ff, s[i].ss);
  }
  build_lca();
  
  for(int i=1; i<=q; i++){
    cin >> t[i].n >> t[i].k;
    for(int j=0; j<t[i].n; j++){
      int a; cin >> a;
      t[i].v.push_back(a);
    }
  }
  
  for(int i=1; i<=q; i++){
    myq query = t[i];
    sort(all(query.v), [&](int &x, int &y){
      return sortInd[x] < sortInd[y];
    });
    
    //~ printf("query #:%d\n", i);
    //~ for(int j : query.v) printf("%d ", j);
    //~ puts("");
    //~ printf("n:%d, k:%d\n", query.n, query.k);
    int ans = 0;
    for(int j=0; j<=query.n - query.k; j++){
      int pre = (j > 0 ? lvl[lca(query.v[j], query.v[j-1])] : 0);
      int nex = (j + query.k < query.n ? lvl[lca(query.v[j], query.v[j+query.k])] : 0);
      int mx = lvl[lca(query.v[j], query.v[j+query.k-1])];
      if(mx - max(pre, nex) > 0)
        ans += mx - max(pre, nex);
      //~ printf("j:%d, pre:%d, nex:%d, mx:%d\n", j, pre, nex, mx);
    }
    
    cout << ans << '\n';
  }
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
