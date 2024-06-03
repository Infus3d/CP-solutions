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
    int k; scanf("%d", &k);
    vector<int> a(12);
    int n = 12;
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for(int i=1; i<n-1; i++){
        for(int j=i; j<n-1; j++){
            int mini = INT_MAX;
            for(int l=i; l<=j; l++){
                mini = min(mini, a[l]);
            }
            if(mini > a[i-1] && mini > a[j+1]){
                ans++;
            }
        }
    }
    printf("%d %d\n", k, ans);
}

int main(){
    int testcase = 1;
    scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
