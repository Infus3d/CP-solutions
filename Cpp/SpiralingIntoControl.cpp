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

int n, k;

int getIntVal(int x, int y){
  int cycleX = min(x, n-x+1);
  int cycleY = min(y, n-y+1);
  int cycle = min(cycleX, cycleY);
  
  int beginInt = 1, nn = n;
  for(int i=1; i<cycle; i++){
    beginInt += (nn-1)*4;
    nn -= 2;
  }
  
  int cycleSize = n - (cycle-1)*2;
  if(x == cycle) return beginInt + (y - cycle);
  beginInt += cycleSize-1;
  
  if(y == n-cycle+1) return beginInt + (x - cycle);
  beginInt += cycleSize-1;
  
  if(x == n-cycle+1) return beginInt + (cycleSize-(y - cycle)-1);
  beginInt += cycleSize-1;
  
  if(y == cycle) return beginInt + (cycleSize-(x - cycle)-1);
  beginInt += cycleSize-1;
  
  assert(false);
  
  return 0;
}

/*
 * 1 2 3
 * 8 9 4
 * 7 6 5
 * */

void solve(){
  scanf("%d%d", &n, &k);
  if(k % 2 == 1 || k < (n/2 + n/2)){
    puts("IMPOSSIBLE");
    return;
  }
  
  int cycle = -1, currentInt = 1, curI = 1, curJ = 1, cnt = n/2;
  for(int i=n; i>=1; i-=2){
    if(k <= (i-1)*4-1 + (cnt-1)*2){
      cycle = i;
      break;
    }
    k -= (i-1)*4;
    currentInt += (i-1)*4;
    curJ++;
    curI++;
    cnt--;
  }
  assert(cycle > -1);
  
  int midI = n/2+1, midJ = n/2+1;
  vector<pii> ans;
  for(int i=0; i<(cycle-1)*4; i++){
    if(i + abs(curI - midI) + abs(curJ - midJ) == k){
      //answer
      ans.clear();
      int tempI = curI, tempJ = curJ, tempInt = currentInt;
      while(currentInt < n*n){
        while(curJ < midJ){
          if(getIntVal(curI, curJ+1) < currentInt) break;
          curJ++;
          int nextInt = getIntVal(curI, curJ);
          if(abs(currentInt - nextInt) > 1)
            ans.push_back({currentInt, nextInt});
          //~ printf("*** %d %d\n", currentInt, nextInt);
          currentInt = nextInt;
        }
        while(curJ > midJ){
          if(getIntVal(curI, curJ-1) < currentInt) break;
          curJ--;
          int nextInt = getIntVal(curI, curJ);
          if(abs(currentInt - nextInt) > 1)
            ans.push_back({currentInt, nextInt});
          //~ printf("*** %d %d\n", currentInt, nextInt);
          currentInt = nextInt;
        }
        while(curI < midI){
          if(getIntVal(curI+1, curJ) < currentInt) break;
          curI++;
          int nextInt = getIntVal(curI, curJ);
          if(abs(currentInt - nextInt) > 1)
            ans.push_back({currentInt, nextInt});
          //~ printf("*** %d %d\n", currentInt, nextInt);
          currentInt = nextInt;
        }
        while(curI > midI){
          if(getIntVal(curI-1, curJ) < currentInt) break;
          curI--;
          int nextInt = getIntVal(curI, curJ);
          if(abs(currentInt - nextInt) > 1)
            ans.push_back({currentInt, nextInt});
          //~ printf("*** %d %d\n", currentInt, nextInt);
          currentInt = nextInt;
        }
      }
      
      curI = tempI;
      curJ = tempJ;
      currentInt = tempInt;
      break;
    }
    
    if(i < cycle-1) curJ++;
    else if(i < (cycle-1)*2) curI++;
    else if(i < (cycle-1)*3) curJ--;
    else if(i < (cycle-1)*4) curI--;
    currentInt++;
  }
  
  sort(all(ans));
  printf("%d\n", sz(ans));
  for(pii i : ans)
    printf("%d %d\n", i.ff, i.ss);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  for(int tt=1; tt<=testcase; tt++){
    printf("Case #%d: ", tt);
    solve();
  }
  return 0;
}
/*  1  2  3  4  5  6  7
 * 24 25 26 27 28 29  8
 * 23 40 41 42 43 30  9
 * 22 39 48 49 44 31 10
 * 21 38 47 46 45 32 11
 * 20 37 36 35 34 33 12
 * 19 18 17 16 15 14 13
 * */
