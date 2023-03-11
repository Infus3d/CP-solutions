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
  char a, b;
  // char t[26];
  // int s[26]; 
  // t['X'-'A'] = 'A';
  // t['Y'-'A'] = 'B';
  // t['Z'-'A'] = 'C';
  // s['X'-'A'] = 1;
  // s['Y'-'A'] = 2;
  // s['Z'-'A'] = 3;
  
  long long sum = 0;
  while(infile >> a >> b){
    int c = a-'A';
    if(b == 'X'){
      c = (c-1 + 3) % 3;
      sum += (c+1);
    } else if(b == 'Y'){
      sum += (3 + c + 1);
    } else {
      c = (c+1) % 3;
      sum += (6 + c + 1);
    }
  }
  cout << sum << endl;
}

int main(){
  int testcase = 1;
  
  // scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
