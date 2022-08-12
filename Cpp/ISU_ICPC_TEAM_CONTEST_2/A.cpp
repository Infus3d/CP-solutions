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

int r, n;
string p1, p2;

void solve(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for(int t=1; ; t++){
    cin >> r;
    if(r == 0) break;
    cin >> n;
    
    cin >> p1;
    if(p1[0] == char(34)){
      p1 = p1.substr(1, (int)p1.length()-1);
      string s;
      while(true){
        cin >> s;
        if(s[(int)s.length()-1] == char(34)){
          p1 += " " + s.substr(0, (int)s.length()-1);
          break;
        }
        p1 += " " + s;
      }
    }
    
    cin >> p2;
    if(p2[0] == char(34)){
      p2 = p2.substr(1, (int)p2.length()-1);
      string s;
      while(true){
        cin >> s;
        if(s[(int)s.length()-1] == char(34)){
          p2 += " " + s.substr(0, (int)s.length()-1);
          break;
        }
        p2 += " " + s;
      }
    }
    
    for(int i=0; i<(int)p1.length(); i++)
      p1[i] = tolower(p1[i]);
    for(int i=0; i<(int)p2.length(); i++)
      p2[i] = tolower(p2[i]);
    
    int c = (r-1) / n;
    cout << t << ". ";
    if(c % 2 == 0) cout << p1 << endl;
    else cout << p2 << endl;
  }
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
