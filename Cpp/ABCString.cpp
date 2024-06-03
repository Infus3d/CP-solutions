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

const int N = 3e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n;
char s[N];

void solve(){
    scanf("%s", s);
    n = strlen(s);
    vector<int> cnt(3);
    int ans = 0;
    for(int i=0; i<n; i++){
        cnt[s[i] - 'A']++;
        int thediff = MOD;
        for(int j=0; j<3; j++){
            if(j != (s[i] - 'A')){
                umin(thediff, cnt[s[i] - 'A'] - cnt[j]);
            }
        }
        umin(ans, thediff);
    }
    printf("%d\n", -(ans-1));
}

int main(){
    int testcase = 1;
    scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
