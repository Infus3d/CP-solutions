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

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, m;
char aa[N], bb[N];

vector<int> doit(char* s, char* t, int slen, int tlen){
  int len = max(slen, tlen);
  vector<int> ret(len+1, 0);
  vector<int> a, b;
  for(int i=slen-1; i>=0; i--) a.push_back(s[i]-'0');
  for(int i=tlen-1; i>=0; i--) b.push_back(t[i]-'0');
  for(int i=slen; i<len+1; i++) a.push_back(0);
  for(int i=tlen; i<len+1; i++) b.push_back(0);
  
  for(int i=0; i<len; i++){
    if(a[i] + b[i] < 10) continue;
    int r = min((10-a[i]), b[i]);
    if(r + a[i] > 9) a[i+1]++;
    ret[i] = r;
  }
  while(sz(ret) && ret[sz(ret)-1] == 0) ret.pop_back();
  reverse(all(ret));
  return ret;
}

void solve(){
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      vector<pair<pii, pii>> v[2][2][10];
      for(int di=0; di<2; di++){
        for(int dj=0; dj<2; dj++){
          for(int k=0; k<10; k++){
            int ndi = (i + di + k) > 9 ? 1 : 0;
            int ndj = (j - dj - k) < 0 ? 1 : 0;
            int ni = (i + di + k) % 10;
            int nj = (j - dj - k + 30) % 10;
            if(ni + nj < 10)
              v[ndi][ndj][k].pb({{i, j}, {ni, nj}});
          }
        }
      }
      printf("i:%d, j:%d\n", i, j);
      for(int ii=0; ii<2; ii++){
        for(int jj=0; jj<2; jj++){
          for(int k=0; k<10; k++){
            //~ printf("ii:%d, jj:%d, k:%d, sz(v[ii][jj]):%d\n", ii, jj, k, sz(v[ii][jj][k]));
              for(auto u : v[ii][jj][k])
                printf("digi:%d, digj:%d, ni:%d, nj:%d\n", u.ff.ff, u.ff.ss, u.ss.ff, u.ss.ss);
            if(sz(v[ii][jj][k]) > 0){
              printf("ii:%d, jj:%d, smollest k:%d, size:%d\n", ii, jj, k, sz(v[ii][jj][k]));
              break;
            }
          }
        }
      }
    }
  }
  
  scanf("%s%s", aa, bb);
  n = (int)strlen(aa);
  m = (int)strlen(bb);
  
  vector<int> ans;
  vector<int> ans1 = doit(aa, bb, n, m);
  vector<int> ans2 = doit(bb, aa, m, n);
  if(sz(ans1) == sz(ans2)){
    int flag = true;
    for(int i=0; i<sz(ans1); i++)
      if(ans1[i] != ans2[i]){
        if(ans1[i] > ans2[i])
          flag = false;
        break;
      }
    if(flag) ans = ans1;
    else ans = ans2;
  }
  else if(sz(ans1) < sz(ans2)) ans = ans1;
  else ans = ans2;
  for(int i : ans)
    printf("%d", i);
  puts("");
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
