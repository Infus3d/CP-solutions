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
  int n, d;
  scanf("%d%d", &n, &d);
  vector<int> a(n+1), b(n+1);
  vector<pair<int, int>> v;
  multiset<int> setik;
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
    b[i] = a[i] - a[i-1] - 1;
    v.push_back({b[i], i});
    setik.insert(b[i]);
  }
  sort(all(v));
  if(sz(v) > 2 && v[0].ff == v[2].ff){
    printf("%d\n", v[0].ff);
    return;
  }
  if(v[0].ff == v[1].ff){
    if(v[0].ss+1 != v[1].ss){
      printf("%d\n", v[0].ff);
      return;
    }
    setik.erase(setik.find(v[0].ff));
    setik.erase(setik.find(v[1].ff));
    setik.insert(v[0].ff+v[1].ff+1);
    int temp = *(--setik.end());
    setik.erase(setik.find(temp));
    setik.insert((temp+1)/2-1);
    setik.insert(temp/2);
    int maxi = *setik.begin();
    setik.erase(setik.find(temp/2));
    setik.erase(setik.find((temp+1)/2-1));
    setik.insert(temp);
    setik.insert(max(0, d-a[n]-1));
    maxi = max(maxi, *setik.begin());
    printf("%d\n", maxi);
  }
  else{
    multiset<int> tempsetik = setik;
    int maxi = *setik.begin();
    if(v[0].ss != 1){
      setik = tempsetik;
      setik.erase(setik.find(b[v[0].ss-1]));
      setik.erase(setik.find(v[0].ff));
      setik.insert(v[0].ff + b[v[0].ss-1] + 1);
      int temp = *(--setik.end());
      setik.erase(setik.find(temp));
      setik.insert((temp+1)/2-1);
      setik.insert(temp/2);
      maxi = max(maxi, *setik.begin());
      setik.erase(setik.find(temp/2));
      setik.erase(setik.find((temp+1)/2-1));
      setik.insert(temp);
      setik.insert(max(0, d-a[n]-1));
      maxi = max(maxi, *setik.begin());
    }
    if(v[0].ss != n){
      setik = tempsetik;
      setik.erase(setik.find(v[0].ff));
      setik.erase(setik.find(b[v[0].ss+1]));
      setik.insert(b[v[0].ss+1] + v[0].ff + 1);
      int temp = *(--setik.end());
      setik.erase(setik.find(temp));
      setik.insert((temp+1)/2-1);
      setik.insert(temp/2);
      maxi = max(maxi, *setik.begin());
      setik.erase(setik.find(temp/2));
      setik.erase(setik.find((temp+1)/2-1));
      setik.insert(temp);
      setik.insert(max(0, d-a[n]-1));
      maxi = max(maxi, *setik.begin());
    }
    if(v[0].ss == n){
      setik = tempsetik;
      setik.erase(setik.find(v[0].ff));
      int temp = *(--setik.end());
      setik.erase(setik.find(temp));
      setik.insert((temp+1)/2-1);
      setik.insert(temp/2);
      maxi = max(maxi, *setik.begin());
      setik.erase(setik.find(temp/2));
      setik.erase(setik.find((temp+1)/2-1));
      setik.insert(temp);
      setik.insert(max(0, d-a[n-1]-1));
      maxi = max(maxi, *setik.begin());
    }
    printf("%d\n", maxi);
  }
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
