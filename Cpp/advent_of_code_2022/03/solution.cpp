#include "bits/stdc++.h"

#include <fstream>
#include <sstream>
#include <string>

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

std::ifstream infile("input.txt");
void solve(){
  string s;
  int ans = 0;
  int counter = 0;
  vector<vector<int>> cnt(3, vector<int>(52, 0));
  while(infile >> s){
    int n = s.length();
    for(int i=0; i<n; i++){
      if(s[i] <= 'Z'){
        cnt[counter][s[i]-'A'+26] = 1;
      } else {
        cnt[counter][s[i] - 'a'] = 1;
      }
    }
    counter++;
    if(counter == 3){
      for(int i=0; i<52; i++){
        bool flag = 1;
        for(int j=0; j<3; j++){
          if(cnt[j][i] != 1){
            flag = false;
          }
        }
        if(flag == true){
          ans += (i+1);
        }
        cnt[0][i] = cnt[1][i] = cnt[2][i] = 0;
      }
      
      counter = 0;
    }
  }
  printf("%d\n", ans);
}

int main(){
  int testcase = 1;
  
  // scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
