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

int n, m, dp[19683+2][65][2];
int f[10];
char s[9][9];

int get(int idx, int state){
    for(int i=0; i<idx; i++) state /= 3;
    return state % 3;
}

int getState(int state, char newC){
    int theC = newC == 'C' ? 0 : (newC == 'I' ? 1 : 2);
    state = (state / 3) + (theC * f[m]); // f[m] = 3 ^ m
    return state;
}

void printState(int state){
    printf("state: ");
    for(int i=0; i<m+1; i++){
        printf("%c ", (state % 3) == 0 ? 'C' : ((state % 3) == 1 ? 'I' : 'P'));
        state /= 3;
    }
}

int rec(int state, int pos, int advertised){
    // printf("%d %d %d\n", state, pos, advertised);
    // printState(state);
    // printf(", pos: %d, ad: %d\n", pos, advertised);
    if(pos == n*m){
        return advertised;
    }
    int &ret = dp[state][pos][advertised];
    if(~ret) return ret;
    ret = 0;
    int i = pos / m, j = pos % m;
    int potentialICPC = pos > m && j > 0 && get(0, state) == 1 && get(1, state) == 0 && get(m, state) == 2;
    if(s[i][j] == '?'){
        ret = (ret + rec(getState(state, 'C'), pos+1, advertised | potentialICPC)) % MOD;
        ret = (ret + rec(getState(state, 'I'), pos+1, advertised)) % MOD;
        ret = (ret + rec(getState(state, 'P'), pos+1, advertised)) % MOD;
    } else {
        if(s[i][j] == 'C'){
            ret = (ret + rec(getState(state, s[i][j]), pos+1, advertised | potentialICPC)) % MOD;
        } else {
            ret = (ret + rec(getState(state, s[i][j]), pos+1, advertised)) % MOD;
        }
    }
    return ret;
}

void solve(){
    f[0] = 1;
    for(int i=1; i<10; i++){
        f[i] = f[i-1] * 3;
    }
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++){
        scanf("%s", s[i]);
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", rec(0, 0, 0));
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
