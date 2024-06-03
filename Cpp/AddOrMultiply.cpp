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
const int MOD = (int)1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

struct MyDataStructure{
    int n;
    int a[N], T[N<<2];
    char s[N];
    set<pair<int, int>> setik;
    int curAns;
    string theString;
    
    MyDataStructure(){
        n = curAns = 0;
    }
    
    MyDataStructure(int _n, string &t){
        n = _n;
        theString = t;
        curAns = 0;
        for(int i=0; i<(int)t.length(); i+=2){
            if(i < (int)t.length()-1){
                s[i/2+1] = t[i+1];
            }
            a[i/2+1] = t[i] - '0';
        }
        int lastIdx = 1;
        int curProduct = a[1];
        for(int i=1; i<=n; i++){
            // cout << "iteration " << i << " curProduct: " << curProduct << endl;
            if(i == n || s[i] == '+'){
                setik.insert({lastIdx, i});
                lastIdx = i+1;
                curAns = (curAns + curProduct) % MOD;
                if(i < n){
                    curProduct = a[i+1];
                }
            } else {
                curProduct = (1LL * curProduct * a[i+1]) % MOD;
            }
        }
        build_tree(1, n, 1);
    }
    
    string printIt(){
        string ss = "";
        for(int i=1; i<n; i++){
            ss += a[i];
            ss += s[i];
        }
        ss += a[n];
        return ss;
    }
    
    void build_tree(int l, int r, int v){
        if(l == r){
            T[v] = a[l];
            return;
        }
        build_tree(l, mid(l, r), v<<1);
        build_tree(mid(l, r)+1, r, v<<1|1);
        T[v] = (1LL * T[v<<1] * T[v<<1|1]) % MOD;
    }
    
    int get(int x, int y, int l, int r, int v){
        if(y < l || r < x) return 1;
        if(x <= l && r <= y) return T[v];
        return (1LL * get(x, y, l, mid(l, r), v<<1) * get(x, y, mid(l, r)+1, r, v<<1|1)) % MOD;
    }
    
    void upd(int x, int val, int l, int r, int v){
        if(l == r){
            T[v] = val;
            return;
        }
        if(x <= mid(l, r)){
            upd(x, val, l, mid(l, r), v<<1);
        } else {
            upd(x, val, mid(l, r)+1, r, v<<1|1);
        }
        T[v] = (1LL * T[v<<1] * T[v<<1|1]) % MOD;
    }
    
    void swapOp(int x, int y){
        auto [xl, xr] = *(--setik.upper_bound(make_pair(x, n)));
        auto [yl, yr] = *(--setik.upper_bound(make_pair(y, n)));
        
        curAns = (curAns - get(xl, xr, 1, n, 1) + MOD) % MOD;
        curAns = (curAns - get(yl, yr, 1, n, 1) + MOD) % MOD;
        
        upd(x, a[y], 1, n, 1);
        upd(y, a[x], 1, n, 1);
        
        swap(a[x], a[y]);
        
        curAns = (curAns + get(xl, xr, 1, n, 1)) % MOD;
        curAns = (curAns + get(yl, yr, 1, n, 1)) % MOD;
    }
    
    void flipOp(int x){
        if(s[x] == '*'){
            auto it = (--setik.upper_bound({x, n}));
            auto [xl, xr] = *it;
            
            assert(xl <= x && x <= xr && xl != xr);
            curAns = (curAns - get(xl, xr, 1, n, 1) + MOD) % MOD;
            curAns = (curAns + get(xl, x, 1, n, 1)) % MOD;
            curAns = (curAns + get(x+1, xr, 1, n, 1)) % MOD;
            
            setik.erase(*it);
            setik.insert({xl, x});
            setik.insert({x+1, xr});
            
            s[x] = '+';
        } else {
            auto xit = setik.upper_bound({x, n});
            assert(xit != setik.begin() && xit != setik.end());
            auto yit = (--setik.upper_bound({x, n}));
            
            auto [xl, xr] = *xit;
            auto [yl, yr] = *yit;
            
            assert(yr+1 == xl);
            
            curAns = (curAns - get(xl, xr, 1, n, 1) + MOD) % MOD;
            curAns = (curAns - get(yl, yr, 1, n, 1) + MOD) % MOD;
            curAns = (curAns + get(yl, xr, 1, n, 1)) % MOD;
            
            setik.erase({xl, xr});
            setik.erase({yl, yr});
            setik.insert({yl, xr});
            
            s[x] = '*';
        }
    }
};

void solve(){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    string t = s;
    vector<MyDataStructure> D;
    D.push_back(MyDataStructure(n, s));
    for(int i=1; i<2*n-1; i+=2){
        if(t[i] == '+'){
            t[i] = '*';
        } else {
            t[i] = '+';
        }
    }
    D.push_back(MyDataStructure(n, t));
    int curD = 0;
    cout << D[curD].curAns << endl;
    for(int i=0; i<q; i++){
        char qtype;
        cin >> qtype;
        if(qtype == 's'){
            int a, b;
            cin >> a >> b;
            if(a > b){
                swap(a, b);
            }
            D[1-curD].swapOp(a, b);
            D[curD].swapOp(a, b);
        } else if(qtype == 'f'){
            int a;
            cin >> a;
            D[1-curD].flipOp(a);
            D[curD].flipOp(a);
        } else {
            curD = 1-curD;
        }
        cout << D[curD].curAns << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int testcase = 1;
    // cin >> testcase;
    while(testcase--){
        solve();
    }
    return 0;
}
