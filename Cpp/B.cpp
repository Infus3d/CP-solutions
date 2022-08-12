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
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

string a, b;
int n, m, k;

vector<int> z_function(vector<char> &s) {
    int nn = (int) s.size();
    vector<int> z(nn);
    for (int i = 1, l = 0, r = 0; i < nn; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < nn && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

bool ok(int x){
  vector<char> str;
  for(int i=0; i<x; i++) str.pb(b[i]);
  str.pb(char(-1));
  for(int i=0; i<n; i++) str.pb(a[i]);
  
  int cnt = 0;
  vector<int> res = z_function(str);
  for(int i=x+1; i<sz(res); i++)
    if(res[i] == x)
      cnt++;
  
  return cnt >= k;
}

void solve(){
  getline(cin, a);
  getline(cin, b);
  cin >> k;
  n = (a).length(), m = (b).length();
  //~ cout << a << " " << b << endl;
  
  
  int l = 0, r = m+1;
  while(l + 1 < r){
    if(ok(mid(l, r)))
      l = mid(l, r);
    else
      r = mid(l, r);
  }
  if(l == 0)
    puts("IMPOSSIBLE");
  else{
    for(int i=0; i<l; i++)
      printf("%c", b[i]);
    puts("");
  }
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
