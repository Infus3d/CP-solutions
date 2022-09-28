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

char s[N];

void solve(){
  int a, b, ab, ba;
  scanf("%d%d%d%d", &a, &b, &ab, &ba);
  scanf("%s", s);
  int n = strlen(s);
  vector<int> cnt(2), v(n);
  for(int i=0; i<n; i++){
    cnt[s[i]-'A']++;
    v[i] = s[i]-'A';
  }
  if(a+ab+ba != cnt[0] || b+ab+ba != cnt[1]){
    puts("NO");
    return;
  }
  for(int i=0; i<n-1; i++){
    if((!i || s[i-1] == s[i]) && (i == n-2 || s[i+1] == s[i+2]) && s[i] != s[i+1]){
      if(s[i] == 'A' && ab > 0){
        ab--;
        v[i] = v[i+1] = -1;
      }
      if(s[i] == 'B' && ba > 0){
        ba--;
        v[i] = v[i+1] = -1;
      }
    }
  }
  int remaining = 0;
  v.push_back(-1);
  bool before = false;
  vector<int> AB;
  for(int i=1; i<=n; i++){
    if(v[i] != v[i-1] && v[i] != -1 && v[i-1] != -1){
      if(v[i] == 1){
        if(before){
          AB[sz(AB)-1]++;
        }
        else if(i == 1 || v[i-2] == -1 || v[i-2] == v[i-1]){
          AB.push_back(2);
          before = true;
        }
      }
      else if(before){
        AB[sz(AB)-1]++;
      }
    }
    else{
      if(!AB.empty() && AB.back() % 2 == 1){
        remaining += AB.back() / 2;
        AB.pop_back();
      }
      before = false;
    }
  }
  
  before = false;
  vector<int> BA;
  for(int i=1; i<=n; i++){
    if(v[i] != v[i-1] && v[i] != -1 && v[i-1] != -1){
      if(v[i] == 0){
        if(before){
          BA[sz(BA)-1]++;
        }
        else if(i == 1 || v[i-2] == -1 || v[i-2] == v[i-1]){
          BA.push_back(2);
          before = true;
        }
      }
      else if(before){
        BA[sz(BA)-1]++;
      }
    }
    else{
      if(!BA.empty() && BA.back() % 2 == 1){
        remaining += BA.back() / 2;
        BA.pop_back();
      }
      before = false;
    }
  }
  
  //~ printf("AB:\n");
  //~ for(int i : AB) printf("%d ", i);
  //~ printf("\nBA:\n");
  //~ for(int i : BA) printf("%d ", i);
  //~ puts("");
  
  sort(all(AB)); reverse(all(AB));
  while(!AB.empty() && ab > 0){
    if(ab >= AB.back() / 2){
      ab -= AB.back() / 2;
      AB.pop_back();
    }
    else{
      AB[sz(AB)-1] -= ab * 2;
      ab = 0;
    }
  }
  
  sort(all(BA)); reverse(all(BA));
  while(!BA.empty() && ba > 0){
    if(ba >= BA.back() / 2){
      ba -= BA.back() / 2;
      BA.pop_back();
    }
    else{
      BA[sz(BA)-1] -= ba * 2;
      ba = 0;
    }
  }
  
  for(int i : AB) remaining += (i - 2) / 2;
  for(int i : BA) remaining += (i - 2) / 2;
  
  if(remaining >= (ab + ba)) puts("YES");
  else puts("No");
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
