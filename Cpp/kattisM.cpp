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

char s[20];
int d[20];
int game = 0;

int get(int x){
  return (game>>x)&1;
}

int play(int x){
  return (game>>x)&1;
}

int check(){
  int won = -1;
  if(get(9) == get(10) && get(10) == get(11) && play(9-9) && play(10-9) && play(11-9)) won = get(9);
  if(get(9) == get(12) && get(12) == get(15) && play(9-9) && play(12-9) && play(15-9)) won = get(9);
  if(get(15) == get(16) && get(16) == get(17) && play(15-9) && play(16-9) && play(17-9)) won = get(15);
  if(get(11) == get(14) && get(14) == get(17) && play(11-9) && play(14-9) && play(17-9)) won = get(11);
  if(get(9) == get(13) && get(13) == get(17) && play(9-9) && play(13-9) && play(17-9)) won = get(9);
  if(get(15) == get(13) && get(13) == get(11) && play(15-9) && play(13-9) && play(11-9)) won = get(15);
  if(get(12) == get(13) && get(13) == get(14) && play(12-9) && play(13-9) && play(14-9)) won = get(12);
  if(get(10) == get(13) && get(13) == get(16) && play(10-9) && play(13-9) && play(16-9)) won = get(10);
  return won;
}

void solve(){
  scanf("%s", s); int n = strlen(s);
  
  game = 0;
  for(int i=0; i<n; i++){
    game *= 8;
    game += (s[i]-'0');
  }
  
  for(int i=0; i<19; i++)
    d[i] = (game>>i)&1;
  
  int iswon = check();
  if(iswon != -1){
    if(iswon == 1)
      puts("X wins");
    else
      puts("O wins");
  }
  else if((game&((1<<9)-1)) == ((1<<9)-1))
    puts("Cat's");
  else
    puts("In progress");
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
