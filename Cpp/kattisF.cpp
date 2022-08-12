#include "bits/stdc++.h"

#define ff first
#define ss second
#define pb push_back
#define ll long long
#define db puts("*****")
#define sz(x) int(x.size())
#define pii pair <int , int>
#define mid(x , y) ((x+y)>>1)
#define all(x)  x.begin(),x.end()
#define y1 your_name_engraved_herein

using namespace std;

const int N = 2e5+2;
const int K = 1e3+2;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, id[150];
int vowl[N][11], vowr[N][11];
int conl[N][45][11], conr[N][45][11];
char s[N];

bool isVowel(char c){
  if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
  if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
  return false;
}

void getIDs(vector<char> &vowels, vector<char> &consonants){
  for(char i='a'; i<='z'; i++){
    if(isVowel(i)) vowels.pb(i);
    else consonants.pb(i);
  }
  for(char i='A'; i<='Z'; i++){
    if(isVowel(i)) vowels.pb(i);
    else consonants.pb(i);
  }
  for(int i=0; i<sz(vowels); i++) id[(int)vowels[i]] = i;
  for(int i=0; i<sz(consonants); i++) id[(int)consonants[i]] = i;
}

void add(int &x, int y){
  x = (0LL + x + y + MOD) % MOD;
}

int mul(int x, int y){
  return (1LL * x * y) % MOD;
}

void solve(){
  scanf("%s", s); n = strlen(s);
  vector<char> vowels, consonants;
  getIDs(vowels, consonants);
  
  for(int i=0; i<n; i++){
    if(!isVowel(s[i]) && i > 0){
      for(int j=0; j<sz(vowels); j++)
        add(conl[i][id[(int)s[i]]][j], vowl[i-1][j]);
    }
    else if(isVowel(s[i])){
      add(vowl[i][id[(int)s[i]]], 1);
    }
    if(i > 0){
      for(int v=0; v<sz(vowels); v++){
        add(vowl[i][v], vowl[i-1][v]);
        for(int c=0; c<sz(consonants); c++)
          add(conl[i][c][v], conl[i-1][c][v]);
      }
    }
  }
  
  for(int i=n-1; i>=0; i--){
    if(!isVowel(s[i]) && i < n-1){
      for(int j=0; j<sz(vowels); j++)
        add(conr[i][id[(int)s[i]]][j], vowr[i+1][j]);
    }
    else if(isVowel(s[i])){
      add(vowr[i][id[(int)s[i]]], 1);
    }
    if(i < n-1){
      for(int v=0; v<sz(vowels); v++){
        add(vowr[i][v], vowr[i+1][v]);
        for(int c=0; c<sz(consonants); c++)
          add(conr[i][c][v], conr[i+1][c][v]);
      }
    }
  }
  
  int ans = 0;
  for(int i=2; i<n-2; i++){
    if(!isVowel(s[i])) continue;
    
    int tot = 0;
    vector<int> vowex(11, 0), conex(45, 0);
    
    for(int v=0; v<sz(vowels); v++){
      for(int c=0; c<sz(consonants); c++){
        add(vowex[v], conl[i-1][c][v]);
        add(conex[c], conl[i-1][c][v]);
        add(tot, conl[i-1][c][v]);
      }
    }
    
    for(int v=0; v<sz(vowels); v++){
      if(v == id[(int)s[i]]) continue;
      for(int c=0; c<sz(consonants); c++){
        int r = conr[i+1][c][v];
        int l = tot;
        
        add(l, conl[i-1][c][v]);
        add(l, conl[i-1][c][id[(int)s[i]]]);
        
        add(l, -vowex[v]);
        add(l, -vowex[id[(int)s[i]]]);
        add(l, -conex[c]);
        
        add(ans, mul(l, r));
      }
    }
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
