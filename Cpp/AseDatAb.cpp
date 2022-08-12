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

template<typename T>
T random(T range_from, T range_to) {
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<T>    distr(range_from, range_to);
    return distr(generator);
}

int n, m;
string s;

void solve(){
  s = "00000000";
  cout << s << endl;
  while(true){
    cin >> m;
    if(m == 0) return;
    if(m == 8) {
      for(int i=0; i<8; i++) s[i] = '1';
      cout << s << endl;
      continue;
    }
    if(m == -1) break;
    for(int i=0; i<8; i++) s[i] = '0';
    for(int i=7; i>8-m-1; i--) s[i] = '1';
    cout << s << endl;
  }
}

int main(){
  int testcase = 1;
  cin >> testcase;
  for(int i=1; i<=testcase; i++){
    solve();
  }
  return 0;
}
