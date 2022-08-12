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

const int N = 1e6+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

int n, cn[30], a[N], avail[N];
char s[N];
vector<int> v[30];

int T[N<<2];

bool isPalindrome(){
  int odd = 0;
  for(int i=0; i<26; i++) odd += (cn[i]%2);
  if(n % 2 == 1 && odd != 1) return false;
  if(n % 2 == 0 && odd != 0) return false;
  return true;
}

void upd(int x, int y, int l, int r, int v){
  if(r < x || y < l)  
    return;
  if(x <= l && r <= y){
    T[v]++;
    return;
  }
  upd(x, y, l, mid(l, r), v<<1);
  upd(x, y, mid(l, r)+1, r, v<<1|1);
}

int get(int x, int l, int r, int v){
  if(l == r)
    return T[v];
  if(x <= mid(l, r))
    return T[v] + get(x, l, mid(l, r), v<<1);
  else
    return T[v] + get(x, mid(l, r)+1, r, v<<1|1);
}

void solve(){
  scanf("%s", s+1); n = strlen(s+1);
  for(int i=1; i<=n; i++){
    cn[s[i]-'A']++;
    v[s[i]-'A'].pb(i);
  }
  
  if(!isPalindrome()){
    puts("-1");
    return;
  }
  
  int j = n;
  ll ans = 0LL;
  for(int i=1; i<=n; i++){
    if(avail[i]) continue;  //0 if available, 1 if not
    
    if(cn[s[i]-'A'] == 1){
      int actualInd = i - get(i, 1, n, 1);
      ans += n/2+1 - actualInd;
    }
    else{
      int k = v[s[i]-'A'][sz(v[s[i]-'A'])-1]; // the last index of character s[i]
      int actualK = k - get(k, 1, n, 1);
      ans += j-actualK;
      upd(k+1, n, 1, n, 1);
      
      v[s[i]-'A'].pop_back();
      avail[k] = 1;
      cn[s[i]-'A'] -= 2;
      j--;
    }
  }
  printf("%lld\n", ans);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
