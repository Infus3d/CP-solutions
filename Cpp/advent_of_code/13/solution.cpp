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

const int N = 2e3+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

vector<pii> v, e;
string s;
int n, m, d[N][N];

int getInt(int st){
  int cur = 0;
  for(int i=st; i < (int)s.length() && s[i] != ','; i++)
    cur = cur*10 + (s[i]-'0');
  return cur;
}
void solve(){
  freopen("input.txt", "r", stdin);
  //~ freopen("input2.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  while(cin >> s){
    if(s[1] == '='){
      e.pb({(s[0] == 'x' ? 0 : 1), getInt(2)});
    }
    else if(s[0] != 'f' && s[0] != 'a'){
      int a, b;
      a = getInt(0);
      for(int i=0; i<(int)s.length(); i++)
        if(s[i] == ','){
          b = getInt(i+1);
          break;
        }
      v.pb({a, b});
    }
  }
  for(pii i : v){
    umax(n, i.ss);
    umax(m, i.ff);
  }
  printf("%d %d\n", n, m);
  
  int ans = 0;
  for(pii i : e){
    printf("%d %d\n", i.ff, i.ss);
    if(i.ff == 0){
      for(pii &j : v)
        if(j.ff > i.ss)
          j.ff -= 2*(j.ff - i.ss);
      m = i.ss;
    }
    else{
      for(pii &j : v)
        if(j.ss > i.ss)
          j.ss -= 2*(j.ss - i.ss);
      n = i.ss;
    }
  }
  for(pii i : v)
    d[i.ss][i.ff]++;
  for(int i=0; i<=n; i++){
    for(int j=0; j<=m; j++){
      if(d[i][j])
        ans++, printf("#");
      else
        printf(".");
    }
    puts("");
  }
  printf("%d\n", ans);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
