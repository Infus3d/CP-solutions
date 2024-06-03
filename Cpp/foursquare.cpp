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

int rec(int h, int w, int pos, vector<pair<int, int>> &v){
    if(pos == 3){
        return v[pos].first == h && v[pos].second == w;
    }
    int ret = 0;
    if(v[pos].first == h){
        ret |= rec(h, w-v[pos].second, pos+1, v);
    }
    if(v[pos].second == w){
        ret |= rec(h-v[pos].first, w, pos+1, v);
    }
    return ret;
}

void solve(){
    vector<pair<int, int>> vv(4), v(4);
    vector<int> perm(4);
    int totalArea = 0;
    for(int i=0; i<4; i++){
        scanf("%d%d", &v[i].first, &v[i].second);
        totalArea += v[i].first * v[i].second;
        vv[i] = v[i];
        perm[i] = i;
    }
    int h = sqrt(totalArea);
    if(h*h != totalArea) {
        puts("0");
        return;
    }
    for(int mask=0; mask<(1<<4); mask++){
        vector<pair<int, int>> tempv(4);
        for(int i=0; i<4; i++){
            tempv[i] = vv[i];
            if((1<<i)&mask){
                swap(tempv[i].first, tempv[i].second);
            }
        }
        do{ //v[i].first = heigh, v[i].second = width
            for(int i=0; i<4; i++){
                v[i] = tempv[perm[i]];
            }
            if(rec(h, h, 0, v)){
                puts("1");
                return;
            }
            // this is a special case where there is no rectangle with height == h
            if(v[0].second == v[1].second && v[2].second == v[3].second && (v[0].first + v[1].first) == h && (v[2].first + v[3].first) == h && (v[0].second + v[2].second) == h){
                puts("1");
                return;
            }
        } while (next_permutation(perm.begin(), perm.end()));
    }
    puts("0");
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
