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

char s[100], t[100];

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s%s", s, t);
    bool sgood = true, tgood = true;
    for(int i=0; i<n-1; i++){
        if(s[i] == s[i+1]){
            sgood = false;
        }
    }
    for(int i=0; i<m-1; i++){
        if(t[i] == t[i+1]){
            tgood = false;
        }
    }
    if(sgood){
        puts("Yes");
        return;
    } else if(tgood){
        for(int i=0; i<n-1; i++){
            if(s[i] == s[i+1] && (t[0] == s[i] || t[m-1] == s[i+1])){
                puts("No");
                return;
            }
        }
        puts("Yes");
    } else {
        puts("No");
    }
}

int main(){
    int testcase = 1;
    scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
