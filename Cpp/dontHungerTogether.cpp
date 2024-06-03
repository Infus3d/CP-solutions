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
    int n, k;
    scanf("%d%d", &n, &k);
    vector<pair<double, int>> v(n);
    vector<long long> timeLine(n+2, 0);
    for(int i=0; i<n; i++){
        scanf("%lf%d", &v[i].ff, &v[i].ss);
        timeLine[i+1] += (long long)v[i].ff;
        timeLine[v[i].ss+1] -= (long long)v[i].ff;
    }
    for(int i=1; i<=n; i++){
        timeLine[i] += timeLine[i-1];
        if(timeLine[i] == 0){
            puts("-1");
            return;
        }
    }
    auto ok = [&](double x) -> bool{
        vector<double> amountAvailable(n+2, 0);
        set<int> setik;
        for(int i=0; i<n; i++){
            setik.insert(v[i].ss);
            amountAvailable[v[i].ss] += v[i].ff;
            double todayAmount = x * k;
            while(!setik.empty() && todayAmount > 0.000000001){
                auto idx = *setik.begin();
                if(todayAmount < amountAvailable[idx]){
                    amountAvailable[idx] -= todayAmount;
                    todayAmount = 0.0;
                    break;
                } else {
                    todayAmount -= amountAvailable[idx];
                    amountAvailable[idx] = 0.0;
                    setik.erase(setik.begin());
                }
            }
            if(todayAmount > 0.0000000001){
                return false;
            }
            while(!setik.empty() && *setik.begin() <= i+1){
                setik.erase(setik.begin());
            }
        }
        return true;
    };
    double lo = 0.000000000, hi = (double)20000000000.0;
    double eps = 0.000000001;
    int cnt = 0;
    while((hi - lo) > eps && cnt < 67){
        cnt++;
        double mid = (hi + lo) / 2;
        if(ok(mid)){
            lo = mid;
        } else {
            hi = mid;
        }
    }
    printf("%.9lf\n", (hi + lo) / 2);
}

int main(){
    int testcase = 1;
    while(testcase--){
        solve();
    }
    return 0;
}
