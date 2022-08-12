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

int n, d[N];

void solve(){
  multiset<int> setik;
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%d", &d[i]);
    while(d[i] > n) d[i] /= 2;
    setik.insert(d[i]);
  }
  for(int i=n; i>=1; i--){
    if(setik.find(i) == setik.end()){
      puts("NO");
      return;
    }
    setik.erase(setik.find(i));
    while(!setik.empty() && *(--setik.end()) == i){
      int t = *(--setik.end());
      setik.erase(setik.find(t));
      setik.insert(t/2);
    }
  }
  puts("YES");
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
