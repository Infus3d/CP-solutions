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

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

map<string, int> front, retro;

string rev(string t){
  reverse(t.begin(), t.end());
  return t;
}

void solve(){
  int n;
  cin >> n;
  bool flag = false;
  
  front.clear(), retro.clear();
  vector<string> s(n+1);
  for(int i=1; i<=n; i++){
    cin >> s[i];
    int m = s[i].length();
    if(m == 1 || (m == 2 && s[i][0] == s[i][1]) || (m == 3 && s[i][0] == s[i][2]))
      flag = true;
    retro[s[i]]++;
  }
  
  for(int i=1; i<=n; i++){
    retro[s[i]]--;
    int m = s[i].length();
    if(m == 1)  continue;
    if(m == 3){
      string t1 = rev(s[i].substr(0, 2));
      string t2 = rev(s[i].substr(1, 2));
      if(retro[t1] > 0)
        flag = true;
      if(front[t2] > 0)
        flag = true;
    }
    
    string t = rev(s[i]);
    if(retro[t] > 0 || front[t] > 0)
      flag = true;
  
    front[s[i]]++;
  }
  
  if(flag == true)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main(){
  ios::sync_with_stdio(false);
	cin.tie(0);
  int testcase = 1;
  cin >> testcase;
  while(testcase--){
    solve();
  }
  return 0;
}
