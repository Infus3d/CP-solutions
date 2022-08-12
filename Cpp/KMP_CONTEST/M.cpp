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

void solve(int tt){
  string s, t;
  cin >> s; t = s;
  int n = (int)s.length();
  reverse(all(t));
  t += "#" + s;
  
  vector<int> res = z_function(t);
  
  int mx = 0;
  for(int i=sz(s)+1; i<sz(res); i++){
    if(i + res[i] == sz(res)){
      mx = res[i];
      break;
    }
  }
  umax(mx, 1);
  
  cout << "Case " << tt << ": " << 2*n - mx << endl;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int testcase = 1;
  cin >> testcase;
  for(int tt=1; tt<=testcase; tt++){
    solve(tt);
  }
  return 0;
}
