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

int a, b;
int n, m;
char ss[10];
vector<char> s;
int v[][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

map<vector<char>, pair<int, int>> mk;

bool isWinning(char t){
  for(int i=0; i<8; i++){
    bool ok = true;
    for(int j=0; j<3; j++){
      if(s[v[i][j]] != t){
        ok = false;
      }
    }
    if(ok){
      // printf("idx: %d\n", i);
      return true;
    }
  }
  return false;
}

pair<int, int> rec(int pos, char t){
  if(isWinning('X')) { return mk[s] = {1, 0}; }
  if(isWinning('O')) { return mk[s] = {0, 1}; }
  if(pos == 9){
    return mk[s] = {0, 0};
  }
  
  if(mk.find(s) != mk.end()){
    return mk[s];
  }
  
  pair<int, int> ret = {0, 0};
  for(int i=0; i<9; i++){
    if(s[i] == '.'){
      char newt = t == 'X' ? 'O' : 'X';
      s[i] = t;
      auto cur = rec(i, newt);
      ret.ff += cur.ff;
      ret.ss += cur.ss;
      s[i] = '.';
    }
  }
  return mk[s] = ret;
}

void solve(){
  scanf("%s", ss);
  s = vector<char>(9);
  for(int i=0; i<9; i++){
    s[i] = ss[i];
  }
  if(mk.find(s) != mk.end()){
    printf("%d %d\n", mk[s].ff, mk[s].ss);
    return;
  }
  puts("-1 -1");
  // if(0 <= n-m && n-m <= 1 && !(isWinning('X') && isWinning('O'))){
    // a = 0, b = 0;
    // if(!isWinning('X') && !isWinning('O')){
      // for(int i=0; i<9; i++){
        // if(s[i] == '.'){
          // char st = (n-m) == 0 ? 'X' : 'O';
          // s[i] = st;
          // auto cur = rec(i, st);
          // a += cur.ff;
          // b += cur.ss;
          // s[i] = '.';
        // }
      // }
      // printf("%d %d\n", a, b);
      // mk[s] = {a, b};
    // } else if(isWinning('X')){
      // //printf("jflksjaf;sd");
      // mk[s] = {1, 0};
      // puts("1 0");
    // } else {
      // mk[s] = {0, 1};
      // puts("0 1");
    // }
  // } else {
    // //printf("going here somehow\n");
    // puts("-1 -1");
  // }
}

int main(){
  int testcase = 1;
  s = vector<char>(9, '.');
  for(int i=0; i<9; i++){
    rec(i, 'X');
  }
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
