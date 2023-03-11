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
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> a(n);
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
  }
  sort(all(a));
  int l = -1, r = (int)1e5;
  vector<int> cnt((int)1e5+1, 0);
  while(l + 1 < r){
    bool ok = false;
    int middle = mid(l, r);
    
    int p = 0, score = 0;
    for(int i=0; i<=m; i++) cnt[i] = 0;
    for(int i=0; i<n; i++){
      for(int div=1; (div*div)<=a[i]; div++){
        if(a[i] % div == 0){
          cnt[div]++;
          if(cnt[div] == 1 && div <= m){
            score++;
          }
          if(a[i] / div != div){
            cnt[a[i] / div]++;
            if(cnt[a[i] / div] == 1 && a[i] / div <= m){
              score++;
            }
          }
        }
      }
      while(p < i && (a[i] - a[p]) > middle){
        for(int div=1; (div*div)<=a[p]; div++){
          if(a[p] % div == 0){
            cnt[div]--;
            if(cnt[div] == 0 && div <= m){
              score--;
            }
            if(a[p] / div != div){
              cnt[a[p] / div]--;
              if(cnt[a[p] / div] == 0 && a[p] / div <= m){
                score--;
              }
            }
          }
        }
        p++;
      }
      if(score == m){
        ok = true;
      }
    }
    
    if(ok)
      r = mid(l, r);
    else
      l = mid(l, r);
  }
  if(r == (int)1e5) printf("%d\n", -1);
  else printf("%d\n", r);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
