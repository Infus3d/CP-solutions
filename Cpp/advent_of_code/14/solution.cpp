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

string s;
ll d[30][30], t[30][30], cnt[30], c[30][30];

void solve(){
  freopen("input.txt", "r", stdin);
  //~ freopen("input2.txt", "r", stdin);
  cin >> s;
  memset(t, -1LL, sizeof(t));
  for(int i=0; i<(int)s.length(); i++) cnt[s[i]-'A']++;
  for(int i=0; i<(int)s.length()-1; i++)  d[s[i]-'A'][s[i+1]-'A']++;
  
  while(cin >> s){
    string tt;
    cin >> tt; cin >> tt;
    t[s[0]-'A'][s[1]-'A'] = tt[0] - 'A';
    cout << s << " " << tt << endl;
  }
  
  for(int step=1; step<=40; step++){
    memset(c, 0LL, sizeof(c));
    for(int i=0; i<26; i++)
      for(int j=0; j<26; j++){
        if(d[i][j] > 0 && t[i][j] != -1){
          cnt[t[i][j]] += d[i][j];
          c[i][t[i][j]] += d[i][j];
          c[t[i][j]][j] += d[i][j];
          d[i][j] = 0;
        }
      }
    
    for(int i=0; i<26; i++)
      for(int j=0; j<26; j++)
        d[i][j] += c[i][j];
  }
  
  vector<ll> v;
  ll tot = 0LL;
  for(int i=0; i<26; i++){
    if(cnt[i] > 0)
      v.pb(cnt[i]);
    tot += cnt[i];
  }
  sort(all(v));
  printf("%lld\n", v[sz(v)-1] - v[0]);
  printf("%lld\n", tot);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
