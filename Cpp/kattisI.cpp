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

const int N = 1e3+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

int n, t[N], cnt, vis[N*N];
vector<int> v[N];
map<string, int> mk;
vector<string> in[N];

void solve(){
  cin >> n;
  for(int i=1; i<=n; i++){
    string type, topping;
    cin >> type;
    if(type == "if"){
      while(true){
        cin >> topping;
        if(topping != "then"){
          if(topping == "or") t[i] = 1;
          else if(topping == "and") t[i] = 2;
          else in[i].pb(topping);
        }
        else{
          cin >> topping;
          in[i].pb(topping);
          if(t[i] == 0) t[i] = 2;
          break;
        }
      }
    }
    else{
      t[i] = 0;
      in[i].pb(type);
    }
  }
  
  for(int j=1; j<=n; j++)
    for(string &i : in[j]) 
      mk[i] = 1;
  for(auto &i : mk) i.ss = ++cnt;
  for(int j=1; j<=n; j++)
    for(string &i : in[j]) 
      v[j].pb(mk[i]);
  
  int ans = 0;
  for(int step=1; step<=3*n; step++){
    bool found = false;
    for(int i=1; i<=n; i++){
      if(t[i] == 0){
        if(vis[v[i][0]] == 0){
          ans++; 
          vis[v[i][0]] = 1;
        }
        found = true;
        t[i] = -1;
      }
      else if(t[i] == 1){
        for(int j=0; j<sz(v[i])-1; j++)
          if(vis[v[i][j]] == 1){
            if(vis[v[i][sz(v[i])-1]] == 0){
              ans++;
              vis[v[i][sz(v[i])-1]] = 1;
              found = true;
            }
            t[i] = -1;
            break;
          }
      }
      else if(t[i] == 2){
        bool al = true;
        for(int j=0; j<sz(v[i])-1; j++)
          if(vis[v[i][j]] == 0)
            al = false;
        if(al == true){
          if(vis[v[i][sz(v[i])-1]] == 0){
            ans++;
            vis[v[i][sz(v[i])-1]] = 1;
            found = true;
          }
          t[i] = -1;
        }
      }
    }
    if(found == false) break;
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
