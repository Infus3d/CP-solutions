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
    char t; scanf(" %c", &t);
    map<char, vector<int>> mk;
    for(int i=0; i<2*n; i++){
        char s[3]; scanf("%s", s);
        mk[s[1]].push_back(s[0] - '0');
    }
    for(auto &i : mk){
        sort(all(i.ss));
    }
    if(sz(mk[t]) >= n){
        auto it = mk[t].begin();
        for(auto &i : mk){
            if(i.ff != t){
                for(auto j : i.ss){
                    printf("%d%c %d%c\n", j, i.ff, *(it++), t);
                }
            }
        }
        // printf("#### %d\n", *it);
        while(it != mk[t].end()){
            int it1 = *(it++);
            int it2 = *(it++);
            printf("%d%c %d%c\n", it1, t, it2, t);
        }
    } else {
        int others = 0;
        for(auto &i : mk){
            if(i.ff != t){
                others += sz(i.ss) % 2;
            }
        }
        if(others > sz(mk[t])){
            puts("IMPOSSIBLE");
            return;
        }
        auto tit = mk[t].begin();
        for(auto &i : mk){
            if(i.ff != t){
                auto it = i.ss.begin();
                if(sz(i.ss) % 2){
                    printf("%d%c %d%c\n", *(it++), i.ff, *(tit++), t);
                }
                while(it != i.ss.end()){
                    int it1 = *(it++);
                    int it2 = *(it++);
                    printf("%d%c %d%c\n", it1, i.ff, it2, i.ff);
                }
            }
        }
        while(tit != mk[t].end()){
            int tit1 = *(tit++);
            int tit2 = *(tit++);
            printf("%d%c %d%c\n", tit1, t, tit2, t);
        }
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
