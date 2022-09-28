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

int solution(vector<int> &D, vector<string> &T){
  vector<int> a(26), b(26);
  int n = (int)D.size();
  for(int i=0; i<n; i++){
    for(char j : T[i]){
      a[j-'A']++;
      b[j-'A'] = i;
    }
    if(i > 0) D[i] += D[i-1];
  }
  vector<char> trash{'G', 'P', 'M'};
  int ans = 0;
  for(char i : trash){
    ans = max(ans, D[b[i-'A']]*2 + a[i-'A']);
  }
  if(ans == 0) ans--;
  return ans;
}

void solve(){
  int n; scanf("%d", &n);
  vector<int> a(n);
  vector<string> b(n);
  for(int i=0; i<n; i++){
    cin >> a[i] >> b[i];
  }
  printf("%d\n", solution(a, b));
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
