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
  long long sum = 0, ans = 0;
  vector<long long> v;
  while(getline(infile, s)){
    if(s == ""){
      v.push_back(sum);
      sum = 0;
    } else {
      int a;
      std::istringstream iss(s);
      if(!(iss >> a)){
        printf("error\n");
      }
      sum += a;
    }
  }
  sort(all(v));
  for(int i=sz(v)-1; i>=sz(v)-3; i--)
    ans += v[i];
  printf("Answer: %lld\n", ans);
}

int main(){
  int testcase = 1;
  
  // scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
