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

char s[102][102];

void solve(){
  int n;
  vector<pii> v(26, {-1, -1});
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%s", s[i]);
    for(int j=0; j<n; j++)
      if(s[i][j] != '.')
        v[s[i][j]-'A'] = {i, j};
  }
  
  int ans = 0;
  for(int i=0; i<26; i++){
    int ax = v[i].ff, ay = v[i].ss;
    for(int j=i+1; j<26; j++){
      int bx = v[j].ff, by = v[j].ss;
      for(int k=j+1; k<26; k++){
        int cx = v[k].ff, cy = v[k].ss;
        
        if(ax == -1 || bx == -1 || cx == -1) continue;
        int area = ax * (by - cy) + bx * (cy - ay) + cx * (ay - by);
        if(area == 0) ans++;
      }
    }
  }
  printf("%d\n", ans);
}

int main(){
  int testcase = 1;
  while(testcase--){
    solve();
  }
  return 0;
}
