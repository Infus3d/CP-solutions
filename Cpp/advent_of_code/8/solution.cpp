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

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

string s;
vector<string> v[222], dig[222];
vector<char> perm(7);
int n, ans;
map<string, int> mk;

int getDigit(string &S){
  vector<char> t(S.length());
    for(int j=0; j<(int)S.length(); j++)
      t[j] = perm[S[j]-'a'];
  
  string z = "";
  sort(all(t));
  for(char i : t) z += i;
  
  if(mk.find(z) == mk.end())  return -1;
  else return mk[z];
}

bool check(int ind){
  vector<int> ten;
  for(auto i : v[ind])
    ten.push_back(getDigit(i));
  
  sort(ten.begin(), ten.end());
  ten.erase(unique(ten.begin(), ten.end()), ten.end());
  
  return (ten[0] > -1 && sz(ten) == 10);
}

void getAns(int ind){
  int cur = 0;
  assert(sz(dig[ind]) == 4);
  for(auto i : dig[ind]){
    //~ if(getDigit(i) == -1)
      //~ printf("ind:%d\n", ind);
    assert(getDigit(i) > -1);
    cur = cur*10 + getDigit(i);
  }
  ans += cur;
}

void solve(){
  mk["abcefg"] = 0; mk["cf"] = 1; 
  mk["acdeg"] = 2; mk["acdfg"] = 3;
  mk["bcdf"] = 4; mk["abdfg"] = 5;
  mk["abdefg"] = 6; mk["acf"] = 7;
  mk["abcdefg"] = 8; mk["abcdfg"] = 9;
  
  freopen("input.txt", "r", stdin);
  while(!feof(stdin)){
    int p = 0;
    while(p < 10 && cin >> s)
      v[n].pb(s), p++;
    cin >> s;
    while(p < 14 && cin >> s)
      dig[n].pb(s), p++;
    n++;
  }
  n--;
  
  //~ for(int i=0; i<n; i++){
    //~ printf("iiii:%d\n", i);
    //~ printf("v: ");
    //~ for(auto &j : v[i])
      //~ cout << j << " ";
    //~ printf("\ndig: ");
    //~ for(auto &j : dig[i])
      //~ cout << j << " ";
  //~ }
  
  for(int i=0; i<n; i++){
    //~ int cn = 0;
    for(int j=0; j<7; j++) perm[j] = 'a'+j;
    do{
        if(check(i)){
          //~ printf("i:%d\n", i);
          getAns(i);
          break;
        }
        //~ for(int i=0; i<7; i++)
          //~ printf("%c ", perm[i]);
        //~ puts("");
      }
    while(next_permutation(all(perm)));
    //~ printf("%d\n", cn);
  }
  
  printf("%d\n", ans);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
