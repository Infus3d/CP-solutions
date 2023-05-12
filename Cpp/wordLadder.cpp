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
  int n;
  cin >> n;
  string s = "aaaaaaaaaa";
  set<string> setik;
  setik.insert(s);
  
  auto insertNeighbors = [&](string t){
    int m = t.length();
    for(int i=0; i<m; i++){
      for(char a='a'; a<='z'; a++){
        char prev = t[i];
        t[i] = a;
        setik.insert(t);
        t[i] = prev;
      }
    }
  };
  
  vector<string> ans;
  ans.push_back(s);
  for(int i=1; i<n; i++){
    string t = ans[i-1];
    for(int j=0; j<(int)t.length(); j++){
      for(char a='a'; a<='z'; a++){
        char prev = t[j];
        t[j] = a;
        if(setik.find(t) == setik.end()){
          setik.insert(t);
          ans.push_back(t);
          break;
        }
        t[j] = prev;
      }
      if((int)ans.size() == i+1) break;
    }
    insertNeighbors(ans[i-1]);
  }
  for(string &i : ans){
    cout << i << "\n";
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int testcase = 1;
  // scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
