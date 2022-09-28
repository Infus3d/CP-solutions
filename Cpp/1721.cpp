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

const int N = 1e5+2;
const int K = 1e6+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int trie[N*10][26], globalcnt;
int d[N*10];
int contains[K];
string s;

vector<int> prefix_function(string &s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void solve(){
  cin >> s;
  int n = (int)s.length();
  vector<int> pi = prefix_function(s);
  contains[0] = 1;
  int temp = pi[n-1];
  while(temp > 0){
    contains[temp] = 1;
    temp = pi[temp-1];
  }
  for(int i=0; i<n; i++){
    if(!contains[i]) continue;
    int cur = 0;
    for(int j=0; j<min(10, n-i); j++){
      int c = s[i+j]-'a';
      if(trie[cur][c] == 0)
        trie[cur][c] = ++globalcnt;
      cur = trie[cur][c];
      umax(d[cur], i);
    }
  }
  int q;
  cin >> q;
  vector<string> t(q);
  vector<vector<int>> ans(q);
  for(int i=0; i<q; i++){
    cin >> t[i];
    int m = (int)t[i].length();
    for(int j=0; j<m; j++) ans[i].push_back(0);
    int cur = pi[n-1];
    while(cur >= 0 && n-cur < m){
      for(int j=0; j<m; j++){
        char thechar = (cur+j < n ? s[cur+j] : (char)t[i][(cur+j)-n]);
        if(thechar != t[i][j])
          break;
        umax(ans[i][j], cur+j+1);
      }
      if(cur == 0) break;
      cur = pi[cur-1];
    }
    for(int j=0; j<m; j++){
      for(int k=j; k<min(j+n, m); k++){
        if(s[k-j] != t[i][k]) break;
        umax(ans[i][k], k-j+1);
      }
    }
    cur = 0;
    for(int j=0; j<m; j++){
      int c = t[i][j]-'a';
      if(trie[cur][c] == 0) break;
      cur = trie[cur][c];
      umax(ans[i][j], d[cur]+j+1);
    }
  }
  for(int i=0; i<q; i++){
    for(int j : ans[i])
      printf("%d ", j);
    puts("");
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int testcase = 1;
  while(testcase--){
    solve();
  }
  return 0;
}
