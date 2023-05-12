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

vector<vector<vector<int> > > contacts;

void solve(){
  
  int n, k, d, a, b, c;
  
  cin >> n >> k >> c; 
  
  contacts.assign(k + 2, vector<vector<int> > (n + 2 , vector<int> ()));
  
  //set<int> ans;
  vector<int> q, last(n + 2, 0);
  
  for(int i = 0; i < c; i++){
    cin >> a >> b >> d;
    
    contacts[d][a].push_back(b);
    contacts[d][b].push_back(a);
    
    last[a] = max(last[a], d);
    last[b] = max(last[b], d);
    
   
  }
  // for(int i = 1; i < n+1; i++){
    // printf("last %d: %d\n", i, last[i]);
  // }
  
  
  
  vector<unordered_set<int>> pi = vector<unordered_set<int>>(k+2, unordered_set<int>());
  
  for(auto &list : contacts[1]){
      for(int person :  list){
        if(last[person] == 1){
          pi[1].insert(person);
          // printf("PPZ: %d\n", person);
        }
      }
    }
  for(int i = 2; i <= k+1; i++){
    for(int potential: pi[i-1]){
     // printf("potentialay %d %d\n", i-1, potential); 
      for(int maybe : contacts[i-1][potential]){
        if(last[maybe] == i || (last[maybe] == k && i == k+1)){
          pi[i].insert(maybe);
        }
      }
    }
  }
  
  printf("%d\n", (int)pi[k+1].size());
  vector<int> ans;
  for(int x : pi[k+1]){
    ans.push_back(x);
  }
  sort(ans.begin(),ans.end());
  for(int x : ans){
      printf("%d\n", x);

  }
  
  
 
  
}


/*
12 4 18
1 2 1

 
 
 */

int main(){
  int testcase = 1;
  //scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
