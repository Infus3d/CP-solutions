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

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string &s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res), end(res));
}

void solve(){
  int n; cin >> n;
  string s; cin >> s;
  vector<int> res = manacher(s);
  int m = sz(res);
  vector<int> even(n+1), odd(n+1);
  for(int i=0; i<m; i+=2) even[i/2] = (res[i]-1)/2;
  for(int i=1; i<m; i+=2) odd[(i-1)/2] = res[i]/2;
  auto isPali = [&](int st, int en){
    int d = en - st + 1;
    //~ cout << "this is d -> " << d << "\n";
    if(d % 2 == 0){
      return (even[st+(d/2)] >= d/2);
    }
    else{
      return (odd[st+(d/2)] >= d/2+1);
    }
  };
  
  int ans = n-1;
  for(int i=0; i<n; i++){
    //~ cout << i << " " << i+even[i] << " " << n-1 << " " << ans << endl;
    //~ cout << i << " " << i+odd[i] << " " << n-1 << " " << ans << endl;
    if(i > 0 && i - even[i] == 0){
      //~ int rem = n-(i+even[i]);
      if(i+even[i] == n || isPali(i+even[i], n-1))
        ans = min(ans, i+even[i]-1);
    }
    if(i - odd[i] + 1 == 0){
      if(i+odd[i] == n || isPali(i+odd[i], n-1))
        ans = min(ans, i+odd[i]-1);
    }
  }
  assert(ans+1 >= 0);
  cout << s.substr(0, ans+1) << endl;
  //~ cout << "***" << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int testcase = 1;
  cin >> testcase;
  for(int tt=1; tt<=testcase; tt++){
    cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}
