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

vector<long long> solution(vector<int> &red, vector<int> &blue, int blueCost){
  int n = (int)red.size()+1;
  vector<vector<long long>> dp(n, vector<long long>(2, (long long)1e16));
  dp[0][0] = 0;
  dp[0][1] = blueCost;
  for(int i=1; i<n; i++){
    umin(dp[i][0], dp[i-1][0] + red[i-1]);
    umin(dp[i][0], dp[i-1][1] + red[i-1]);
    umin(dp[i][1], dp[i-1][0] + blue[i-1] + blueCost);
    umin(dp[i][1], dp[i-1][1] + blue[i-1]);
  }
  vector<long long> ans;
  for(int i=0; i<n; i++){
    ans.push_back(min(dp[i][0], dp[i][1]));
  }
  return ans;
}

void solve(){
  int n; scanf("%d", &n);
  vector<int> a(n-1), b(n-1);
  for(int i=0; i<n-1; i++){
    scanf("%d", &a[i]);
  }
  for(int i=0; i<n-1; i++){
    scanf("%d", &b[i]);
  }
  int c;
  cin >> c;
  vector<long long> ans = solution(a, b, c);
  for(int i=0; i<sz(ans); i++)
    printf("%lld ", ans[i]);
  puts("");
}

int main(){
  
  
  return 0;
}
