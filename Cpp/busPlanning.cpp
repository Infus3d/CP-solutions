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
    int n, k, c;
    scanf("%d%d%d", &n, &k, &c);
    map<string, int> stoi;
    vector<string> names(n);
    for(int i=0; i<n; i++){
        cin >> names[i];
        stoi[names[i]] = i;
    }
    vector<vector<int>> T(n, vector<int>(n, 0));
    for(int i=0; i<k; i++){
        string s, t;
        cin >> s >> t;
        T[stoi[s]][stoi[t]] = 1;
        T[stoi[t]][stoi[s]] = 1;
    }
    vector<bool> validBus((1<<n), true);
    for(int mask=0; mask<(1<<n); mask++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if((mask&(1<<i)) > 0 && (mask&(1<<j)) > 0 && T[i][j] == 1){
                    validBus[mask] = false;
                }
            }
        }
        if(__builtin_popcount(mask) > c){
            validBus[mask] = false;
        }
    }
    vector<int> dp((1<<n), n+1);
    vector<int> track((1<<n), -1);
    dp[0] = 0;
    for(int mask=0; mask<(1<<n); mask++){
        for(int nmask=mask; nmask<(1<<n); nmask=((nmask+1)|mask)){
            if(validBus[(nmask&(~mask))] && dp[nmask] > dp[mask] + 1){
                dp[nmask] = dp[mask] + 1;
                track[nmask] = mask;
            }
        }
    }
    int curMask = (1<<n)-1;
    cout << dp[curMask] << "\n";
    while(curMask > 0){
        int curBus = curMask & (~track[curMask]);
        for(int i=0; i<n; i++){
            if((curBus&(1<<i)) > 0){
                cout << names[i] << " ";
            }
        }
        cout << "\n";
        curMask = track[curMask];
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
