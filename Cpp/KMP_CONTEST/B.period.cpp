#include "stdio.h"
#include "iostream"
#include "vector"
#include "algorithm"
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
      //~ cout << l << " " << r << " " << i << endl;
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
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for(int t=1; ; t++){
    int n; string s;
    cin >> s;
    if(s == ".") break;
    
    n = (int)s.length();
    vector<int> res = z_function(s);
    vector<int> a(n+1);
    for(int i=1; i<=n; i++){
      int cn = 0;
      for(int j=0; j<n; j+=i){
        if(j == 0 || res[j] >= i)
          umax(a[j+i-1], ++cn);
        if(j != 0 && res[j] < i) break;
      }
    }
    printf("%d\n", a[n-1]);
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
