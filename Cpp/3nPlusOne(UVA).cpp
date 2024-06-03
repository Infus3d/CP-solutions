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

unordered_map<int, int> seen;

int rec(int x){
    if(seen[x] != 0){
        return seen[x];
    }
    if(x % 2 == 0){
        seen[x] = rec(x / 2) + 1;
    } else {
        seen[x] = rec(3*x + 1) + 1;
    }
    return seen[x];
}

void solve(){
    int a, b;
    while(cin >> a >> b){
        int ans = 0;
        assert(a <= 10000 && b <= 10000);
        for(int i=min(a, b); i<=max(a, b); i++){
            ans = max(ans, rec(i));
        }
        printf("%d %d %d\n", a, b, ans);
    }
}

int main(){
    seen[1] = 1;
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
