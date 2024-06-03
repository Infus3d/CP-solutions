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

char s[N];

void solve(){
    int t, c;
    scanf("%d%d", &t, &c);
    vector<int> a(t);
    for(int i=0; i<t; i++){
        scanf("%d", &a[i]);
    }
    scanf("%s", s);
    int pos = 0;
    vector<vector<int>> dp(2, vector<int>(5, 0));
    for(int i=0; i<n; i++){
        int cur = (i & 1);
        for(int j=-2; j<3; j++){
            if(j == 0){
                
            }
        }
    }
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
