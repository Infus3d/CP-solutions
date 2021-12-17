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

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

vector<string> v;
string s;
map<char, char> mk;
map<char, int> cs;
vector<ll> scores;

void solve(){
  freopen("input.txt", "r", stdin);
  //~ freopen("input2.txt", "r", stdin);
  while(cin>>s){
    v.pb(s);
  }
  mk[']'] = '[';
  mk[')'] = '(';
  mk['>'] = '<';
  mk['}'] = '{';
  
  cs['['] = 2;
  cs['('] = 1;
  cs['<'] = 4;
  cs['{'] = 3;
  
  ll ans = 0LL;
  for(int i=0; i<sz(v); i++){
    stack<char> S;
    string &t = v[i];
    int m = t.length();
    for(int j=0; j<m; j++){
      if(t[j] == '[' || t[j] == '<' || t[j] == '(' || t[j] == '{')
        S.push(t[j]);
      else{
        if(S.empty() || S.top() != mk[t[j]]){
          ans += cs[t[j]];
          while(!S.empty()) S.pop();
          break;
        }
        else
          S.pop();
      }
    }
    if(!S.empty()){
      ll cur = 0;
      while(!S.empty()){
        cur = cur*5 + cs[S.top()];
        S.pop();
      }
      printf("%lld ", cur);
      scores.pb(cur);
    }
  } puts("");
  printf("%d\n", sz(scores));
  sort(all(scores));
  printf("%lld\n", scores[sz(scores)/2]);
  //~ printf("%lld\n", ans);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
