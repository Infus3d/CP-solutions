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
const ll INF = 1e18;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

string s;
vector<string> v;
ll d[1002][1002], c[1002][1002];
int n, m;

int dx[] = {0, -1, 0, +1};
int dy[] = {-1, 0, +1, 0};

bool ok(int x, int y){
  return (x >= 0 && y >= 0 && x < n && y < m);
}

ll nex(ll x){
  if(x == 9) return 1;
  return x+1;
}

void solve(){
  ios::sync_with_stdio(false);
	cin.tie(0);
  freopen("input.txt", "r", stdin);
  //~ freopen("input2.txt", "r", stdin);
  while(cin >> s){
    v.pb(s);
  }
  n = sz(v); m = v[0].length();
  
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++)
      c[i][j] = v[i][j] - '0';
    for(int j=m; j<5*m; j++)
      c[i][j] = nex(c[i][j-m]);
  }
  for(int i=n; i<5*n; i++)
    for(int j=0; j<5*m; j++)
      c[i][j] = nex(c[i-n][j]);
    
  n *= 5; m *= 5;
  for(int i=0; i<=n; i++)
    for(int j=0; j<=m; j++)
      d[i][j] = INF;
  
  d[0][0] = 0;
  set<pair<ll, pii>> q;
  q.insert({0LL, {0, 0}});
  //~ queue<pair<int, pii>> q;
  //~ q.push({0LL, {0, 0}});
  int mx = 0, tot = 0;
  
  while(q.size() > 0){
    tot++;
    umax(mx, (int)q.size());
    auto tr = *q.begin(); q.erase(tr);
    //~ auto tr = q.front(); q.pop();
    for(int i=0; i<4; i++){
      int x = tr.ss.ff + dx[i];
      int y = tr.ss.ss + dy[i];
      if(ok(x, y) && d[x][y] > d[tr.ss.ff][tr.ss.ss] + c[x][y]){
        //~ if(q.find({d[x][y], {x, y}}) != q.end())
          //~ q.erase({d[x][y], {x, y}});
        d[x][y] = d[tr.ss.ff][tr.ss.ss] + c[x][y];
        q.insert({d[x][y], {x, y}});
        //~ q.push({d[x][y], {x, y}});
      }
    }
  }
  printf("%d %d, mx:%d, tot:%d\n", n, m, mx, tot);
  printf("%lld\n", d[n-1][m-1]);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
