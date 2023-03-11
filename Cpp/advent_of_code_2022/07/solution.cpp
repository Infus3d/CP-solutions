#include "bits/stdc++.h"

#include <fstream>
#include <sstream>
#include <string>

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

vector<int> E[1001];

struct Node{
  int u, t;
  long long n;
  int par;
  Node(){}
  Node(int _u, int _t, long long _n, int _par){
    u = _u;
    t = _t;
    n = _n;
    par = _par;
  }
};

std::ifstream infile("input.txt");

vector<Node> v;

void dfs(int u, int par){
  for(int w : E[u]){
    if(w != par){
      dfs(w, u);
      v[u].n += v[w].n;
    }
  }
}

void solve(){
  string line, s, command, t;
  v.push_back({0, 0, 0, -1});
  int idx = 0;
  int cnt = 0;
  
  map<string, int> mk;
  map<int, int> done;
  mk["/"] = 0;
  while(getline(infile, line)){
    std::istringstream iss(line);
    iss >> s;
    if(s == "$"){
      iss >> command;
      if(command == "cd"){
        iss >> t;
        if(t == ".."){
          if(v[idx].par != -1){
            idx = v[idx].par;
          }
        } else if(t == "/"){
          idx = 0;
        } else {
          assert(mk.count(t) > 0);
          idx = mk[t];
        }
      } else {
        done[idx]++;
      }
    } else {
      if(s == "dir"){
        iss >> t;
        if(done[idx] == 1)
          v.push_back({++cnt, 0, 0, idx});
        mk[t] = cnt;
      } else {
        long long a = 0;
        for(int i=0; i<(int)s.length(); i++){
          a = a*10 + (s[i] - '0');
        }
        if(done[idx] == 1)
          v.push_back({++cnt, 1, a, idx});
        iss >> t;
        mk[t] = cnt;
      }
    }
  }
  
  long long ans = 0;
  for(int i=v.size()-1; i>=0; i--){
    int par = v[i].par;
    E[par].push_back(i);
    E[i].push_back(par);
  }
  dfs(0, -1);
  for(int i=0; i<sz(v); i++){
    if(v[i].t != 1 && v[i].n <= 100000){
      ans += v[i].n;
    }
  }
  printf("%lld\n", ans);
}

int main(){
  int testcase = 1;
  
  // scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
