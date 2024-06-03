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
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

void solve(){
    int n; scanf("%d", &n);
    vector<int> a(n+2);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    vector<int> prefmin(n+2), sufmin(n+2);
    vector<int> prefmax(n+2), sufmax(n+2);
    prefmin[0] = sufmin[n+1] = MOD;
    prefmax[0] = sufmax[n+1] = 0;
    for(int i=1; i<=n+1; i++){
        prefmin[i] = min(prefmin[i-1], a[i]);
        prefmax[i] = max(prefmax[i-1], a[i]);
    }
    for(int i=n; i>=0; i--){
        sufmin[i] = min(sufmin[i+1], a[i]);
        sufmax[i] = max(sufmax[i+1], a[i]);
    }
    auto ok = [&](int x){
        deque<int> mini, maxi;
        int l = 0, r = 0;
        while(r < n){
            r++;
            while(l <= r && ((!maxi.empty() && (a[maxi.front()] - a[r]) > x) || (!mini.empty() && (a[r] - a[mini.front()]) > x))){
                if(maxi.front() == l) maxi.pop_front();
                if(mini.front() == l) mini.pop_front();
                l++;
            }
            while(!maxi.empty() && a[maxi.back()] <= a[r]){
                maxi.pop_back();
            }
            while(!mini.empty() && a[mini.back()] >= a[r]){
                mini.pop_back();
            }
            maxi.push_back(r);
            mini.push_back(r);
            int diffInside = a[maxi.front()] - a[mini.front()];
            int diffOutside = max(sufmax[r+1], prefmax[l-1]) - min(sufmin[r+1], prefmin[l-1]);
            if(max(diffInside, diffOutside) <= x){
                // printf("diffInside: %d, diffOutside: %d, left: %d, right: %d\n", diffInside, diffOutside, l, r);
                return true;
            }
        }
        return false;
    };
    int l = -1, r = (int) 1e9;
    while(l+1 < r){
        bool okk = ok(mid(l, r));
        // printf("************ l: %d, r:%d, mid: %d, okk: %d\n", l, r, mid(l, r), okk);
        if(okk){
            r = mid(l, r);
        } else {
            l = mid(l, r);
        }
    }
    if(l != -1 && ok(l)) r = l;
    printf("%d\n", r);
}

int main(){
    int testcase = 1;
    scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
