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

int offset_r_1[4] = {1, 0, 1, 1};
int offset_c_1[4] = {0, 1, 0, 0};
  
int offset_r_2[4] = {0, 1, 1, 1};
int offset_c_2[4] = {1, 1, 1, -1};


void solve(){
  int n;
  
  cin >> n;
  
  int new_n = 1 << n;
  
  int m[new_n][new_n];
  
  for(int i = 0; i < 1 << n; i++){
    for(int j = 0; j < 1 << n; j++){
      cin >> m[i][j];
    }
  }
  
  int m_t = ((new_n)*(new_n) - 1)/3;
  
  bool zero = false, color[m_t+1];
  for(int i = 0; i < m_t+1; i++){
    color[i] = false;
  }
  
  int r1,c1,r2,c2;
  
  
  int taken[new_n][new_n];
  
  for(int i = 0; i < new_n; i++)
    for(int j = 0; j < new_n; j++)
      taken[i][j] = 0;
  
  for(int i = 0; i < new_n; i++){
    for(int j = 0; j < new_n; j++){
      if(m[i][j] == 0 && !zero) zero = true;
      else if (m[i][j] == 0 && zero){
        cout << 0 << endl;
        return;
      }else{

        if(!taken[i][j] && color[m[i][j]]){
          cout << 0 << endl;
          return;
        }
        else if(!taken[i][j]){
          for(int k = 0; k < 4; k++){
            r1 = i + offset_r_1[k];
            c1 = j + offset_c_1[k];
            
            r2 = i + offset_r_2[k];
            c2 = j + offset_c_2[k];
            

            
            if(r1 < 0 || r1 >= new_n || c1 < 0 || c1 >= new_n) continue; 

            if(r2 < 0 || r2 >= new_n || c2 < 0 || c2 >= new_n) continue;
        
            if(m[r1][c1] == m[r2][c2] && m[i][j] == m[r1][c1]){
              color[m[i][j]] = true;
              taken[i][j] = taken[r1][c1] = taken[r2][c2] = 1;
              break;
            }
          }
          if(!color[m[i][j]]){
            cout << 0 << endl;
            return ;
          }
        }
      }
    }
  }
  cout << 1 << endl;
  
  
}

int main(){
  int testcase = 1;
  // scanf("%d", &testcase);
  
  while(testcase--){
    solve();
  }
  return 0;
}
