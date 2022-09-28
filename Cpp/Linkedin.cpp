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

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && (s[j] != '*' && s[i] != s[j]))
            j = pi[j-1];
        if (s[j] == '*' || s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void solve(){
  string s, t;
  cin >> s;
  cin >> t;
  int n = s.length(), m = t.length();
  t = t + "#" + s;
  vector<int> res = prefix_function(t);
  for(int i=m+1; i<n+m+1; i++){
    if(res[i] == m){
      printf("%d\n", (i-2*m));
      return;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
