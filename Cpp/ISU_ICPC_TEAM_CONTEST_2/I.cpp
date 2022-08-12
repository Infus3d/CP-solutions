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

void solve(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tcase = 0;
  while(true){
    string s;
    cin >> s;
    if(s == ".") break;
    int n = s.length();
    bool add = false;
    int a[3] = {0, 0, 0}, b = 0;
    for(int i=0; i<n; i++){
      if(s[i] == '+') add = true;
      if(s[i] == '*' || s[i] == '+' || s[i] == '=' || s[i] == '.'){
        b++; continue;
      }
      a[b] += s[i] - '0';
    }
    cout << ++tcase << ". ";
    if((add ? (0LL + a[0] + a[1]) : (1LL * a[0] * a[1])) % 9 == a[2] % 9)
      cout << "PASS" << endl;
    else
      cout << "NOT!" << endl;
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
