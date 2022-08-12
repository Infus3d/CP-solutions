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

int n;
vector<string> v;
string ss;

bool cmp(string &a, string &b){
  ll aa = 0, bb = 0;
  for(int i=0; i<(int)a.length(); i++){
    aa *= 10;
    aa += a[i] - '0';
  }
  for(int i=0; i<(int)b.length(); i++){
    bb *= 10;
    bb += b[i] - '0';
  }
  return aa <= bb;
}

void solve(){
  v.push_back("");
  scanf("%d", &n);
  for(int i=1; i<=n; i++) cin >> ss, v.push_back(ss);
  for(int i=1; i<=n; i++){
    string t = v[i];
    int m = (int)t.length();
    for(int j=0; j<m; j++){
      for(int k=0; k<10; k++){
        if(m != 1 && j == 0 && k == 0) continue;
        t = v[i]; t[j] = '0' + k;
        if(i > 1 && !cmp(v[i-1], t)){
          for(int u=1; u<=n; u++){
            if(u == i) cout << t << " ";
            else cout << v[u] << " ";
          }
          cout << endl;
          return;
        }
        if(i < n && !cmp(t, v[i+1])){
          for(int u=1; u<=n; u++){
            if(u == i) cout << t << " ";
            else cout << v[u] << " ";
          }
          cout << endl;
          return;
        }
      }
    }
  }
  cout << "impossible" << endl;
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
