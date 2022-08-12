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

void solve(){
  vector<int> a(8);
  for(int mask=0; mask<(1<<8); mask++){
    for(int j=0; j<8; j++)
      a[j] += (mask>>j)&1;
  }
  for(int i=0; i<8; i++)  printf("%d %d\n", i, a[i]);
  
  
  
  int success = 0, closeenough = 0;
  for(int run=0; run<100; run++){
    vector<int> chosen(8, 0);
    chosen[random(0, 7)] = 1; //generator initial value
    vector<int> b(8, 0);
    b[0] = 1; //0011111
    for(int i=0; i<300; i++){
      int r = random(0, 7);
      for(int j=0; j<8; j++)
        chosen[j] ^= b[(j+r)%8];
      
      int cnt = 0;
      //~ printf("%d:\n", i);
      for(int j=0; j<8; j++){
        //~ printf("%d ", chosen[j]);
        cnt += chosen[j];
      }
      //~ puts("");
      if(cnt == 0 || cnt == 8) { success++; break; }
      //~ if(cnt == 1 || cnt == 7) {
        //~ printf("It reached the top most layer");
        //~ closeenough++;
        //~ break;
      //~ }
    }
  }
  printf("Overall %d success and %d close-enough\n", success, closeenough);
  puts("");
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  for(int i=1; i<=testcase; i++){
    printf("Case #%d ", i);
    solve();
  }
  return 0;
}
