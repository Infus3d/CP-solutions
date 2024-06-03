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
    int q, w;
    scanf("%d%d", &q, &w);
    vector<int> x(q), y(q);
    map<int, int> sorter;
    for(int i=0; i<n; i++){
        scanf("%d%d", &x[i], &y[i]);
        sorter[x[i]-y[i]] = sorter[x[i]-y[i]-1] = 1;
        sorter[x[i]+y[i]] = sorter[x[i]+y[i]+1] = 1;
    }
    int cnt = 0;
    vector<int> ctor;
    for(auto &i : mk){
        ctor.push_back(i.ff);
        i.ss = cnt++;
    }
    map<pair<int, int>, int> visible;
    auto area = [&](int l, int r){
        double h = (r - l - 2) / 2.0;
        return h * h;
    };
    for(int i=0; i<q; i++){
        int l = x[i] - y[i];
        int r = x[i] + y[i];
        
        int ll = mk[l];
        int rr = mk[r];
        
        if(visible[{l, r}]){
            int leftZero = ctor[walkLeft(l, 0, cnt, 1)];
            int rightZero = ctor[walkRight(r, 0, cnt, 1)];
            double minusArea = area(leftZero, rightZero);
            
            upd(l, r, -1, 0, cnt, 1);
            
            int lleftZero = ctor[walkLeft(l, 0, cnt, 1)];
            int lrightZero = ctor[walkRight(
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
