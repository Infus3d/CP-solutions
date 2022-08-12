#include "iostream"
#include "stdio.h"
#include "algorithm"
#include "vector"
#include "string"

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

vector<int> z_function(string &s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

void solve(){
  int n;
  string s;
  vector<string> v;
  cin >> n;
  for(int i=1; i<=n; i++){
    cin >> s;
    v.pb(s);
  }
  int ans = 0, mxpref = -1;
  for(int pref=0; pref<(int)v[0].length(); pref++){
    int mn = MOD;
    s = v[0].substr(pref, (int)v[0].length()-pref);
    for(int i=0; i<n; i++){
      string t = s + "#" + v[i];
      vector<int> res = z_function(t);
      int mx = 0;
      for(int j=(int)s.length()+1; j<sz(res); j++)
        umax(mx, res[j]);
      umin(mn, mx);
    }
    //~ printf("pref:%d, mn:%d, ans:%d\n", pref, mn, ans);
    if(umax(ans, mn))
      mxpref = pref;
    else if(ans == mn && ~mxpref && v[0][mxpref] > v[0][pref])
      mxpref = pref;
  }
  if(ans < 3) cout << "no significant commonalities" << endl;
  else cout << v[0].substr(mxpref, ans) << endl;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  int testcase = 1;
  cin >> testcase;
  while(testcase--){
    solve();
  }
  
  return 0;
}
