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

void solve(){
    int n; scanf("%d", &n);
    vector<int> a(n);
    vector<int> ans;
    int sum = 0;
    for(int i=0; i<n; i++){
        char c; scanf(" %c", &c);
        a[i] = c - '0';
        sum += a[i];
    }
    for(int i=n-1; i>=0; i--){
        int cur = (sz(ans) > 0 ? ans.back() / 10 : 0) + sum;
        if(!cur) break;
        ans.push_back(cur);
        if(i >= 0){
            sum -= a[i];
        }
    }
    while(sz(ans) > 0 && ans.back() / 10 > 0){
        ans.push_back(ans.back() / 10);
    }
    reverse(all(ans));
    for(int i : ans){
        printf("%d", i%10);
    }
    puts("");
}

int main(){
    int testcase = 1;
    scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
