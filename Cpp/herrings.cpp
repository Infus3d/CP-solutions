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

// const int N = 2e5+2;
const int K = 1e4+2;
const int MOD = 12345647;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

string N, L;
int dp[K][2][2][2][2];

void solve(){
    cin >> N >> L;
    int n = (int)N.length();
    int m = (int)L.length();
    dp[n][0][0][0][0] = 1;
    for(int pos=n-1; pos>=0; pos--){
        for(int car=0; car<2; car++){
            for(int a=0; a<2; a++){
                for(int b=0; b<2; b++){
                    for(int c=0; c<2; c++){
                        
                    }
                }
            }
        }
    }
}

int main(){
    int testcase = 1;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // scanf("%d", &testcase);
    cin >> testcase;
    while(testcase--){
        solve();
    }
    return 0;
}
