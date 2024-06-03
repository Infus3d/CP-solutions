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

int n;
int cnt[3], s[3];
vector<int> boats;

bool ok(int x){
    vector<pair<int, pair<int, int>>> v;
    for(int i=0; i<3; i++){
        for(int j=i; j<3; j++){
            v.push_back({s[i] + s[j], {i, j}});
        }
    }
    sort(all(v));
    vector<int> left(3);
    for(int i=0; i<3; ++i){
        left[i] = cnt[i];
    }
    for(int i=0; i<n; i++){
        int needed = ceil(1.0 * x / boats[i]);
        
        bool found = false;
        for(auto j : v){
            if(needed <= j.ff && left[j.ss.ff] > 0 && left[j.ss.ss] > 0){
                if(j.ss.ff == j.ss.ss && left[j.ss.ff] < 2){
                    continue;
                }
                left[j.ss.ff]--;
                left[j.ss.ss]--;
                found = true;
                // printf("boat: %d, kayaker1: %d, kayaker2: %d\n", boats[i], s[j.ss.ff], s[j.ss.ss]);
                break;
            }
        }
        if(!found) return false;
    }
    return true;
}

void solve(){
    n = 0;
    for(int i=0; i<3; i++){
        scanf("%d", &cnt[i]);
        n += cnt[i];
    }
    n = n/2;
    for(int i=0; i<3; i++) scanf("%d", &s[i]);
    boats = vector<int>(n);
    for(int i=0; i<n; i++){
        scanf("%d", &boats[i]);
    }
    sort(all(boats)); // this order is 100% needed (kattis needs below testcases because wrong solutions pass)
    // printf("NNNNNNNNNNN : %d\n", n);
    int lo = 1, hi = 2e8+1;
    while(lo + 1 < hi){
        // puts("******************************");
        bool okk = ok(mid(lo, hi));
        // printf("lo: %d, hi: %d, mid: %d, ok: %d\n", lo, hi, mid(lo, hi), okk);
        if(okk){
            lo = mid(lo, hi);
        } else {
            hi = mid(lo, hi) - 1;
        }
    }
    if(ok(hi)) lo = hi;
    printf("%d\n", lo);
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
/*
1 3 8
5 10 501
1 1 1 1 1 1

2 2 2
5 10 20
15 20 10
*/
