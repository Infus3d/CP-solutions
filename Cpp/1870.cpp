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
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n), b(m);
    int thexor = 0;
    for(int i=0; i<n; i++) scanf("%d", &a[i]), thexor ^= a[i];
    for(int i=0; i<m; i++) scanf("%d", &b[i]);
    vector<int> cntmin(30, 0), cntmax(30, 0);
    for(int i=29; i>=0; i--){
        for(int j=0; j<n; j++){
            if((a[j] & (1<<i)) == 0){
                cntmin[i]++;
                cntmax[i]++;
            }
        }
    }
    // for(int i=0; i<30; i++){
        // printf("bit:%d, cnt:%d\n", i, cntmin[i]);
    // }
    int minn = thexor;
    for(int i=29; i>=0; i--){
        int idx = -1;
        for(int j=0; j<m; j++){
            int newminn = minn;
            for(int k=29; k>=0; k--){
                if((b[j] & (1<<k)) > 0 && cntmin[k] % 2 == 1){
                    newminn ^= (1<<k);
                }
            }
            if(newminn < minn){
                minn = newminn;
                idx = j;
            }
        }
        // printf("i:%d, idx:%d\n", i, idx);
        if(idx == -1) break;
        for(int k=29; k>=0; k--){
            if((b[idx] & (1<<k)) > 0 && cntmin[k] % 2 == 1){
                cntmin[k] = 0;
            }
        }
    }
    int maxx = thexor;
    for(int i=29; i>=0; i--){
        int idx = -1;
        for(int j=0; j<m; j++){
            int newmaxx = maxx;
            for(int k=29; k>=0; k--){
                if((b[j] & (1<<k)) > 0 && cntmax[k] % 2 == 1){
                    newmaxx ^= (1<<k);
                }
            }
            if(newmaxx > maxx){
                maxx = newmaxx;
                idx = j;
            }
        }
        if(idx == -1) break;
        for(int k=29; k>=0; k--){
            if((b[idx] & (1<<k)) > 0 && cntmax[k] % 2 == 1){
                cntmax[k] = 0;
            }
        }
    }
    printf("%d %d\n", minn, maxx);
}

class DeezNuts{
public:
    DeezNuts(int capacity){
        cap = capacity;
        head = tail = new Node(1, 2);
    }
    
    void upper(){
        printf("Upper calls lower.\n");
        lower();
        printf("Upper is done executing lower.\n");
    }
    
    void lower(){
        printf("Lower is executed.\n");
    }

private:
    int cap;
    unordered_map<int, int> hashmap;
    struct Node{
        int key, val;
        Node *next, *prev;

        Node(int _key, int _val) : key(_key), val(_val) {}
    } *head, *tail;
};

int main(){
    // int testcase = 1;
    // scanf("%d", &testcase);
    // while(testcase--){
        // solve();
    // }
    
    const long long aa = 200560490130LL * 37 * 41 * 43 + 1;
    printf("%lld\n", aa);
    
    
    
    // DeezNuts *dn = new DeezNuts(123123);
    
    // unordered_map<int, int> mk;
    // printf("%d\n", mk.size());
    // mk[1] = 0;
    // printf("%d\n", mk.size());
    // mk.erase(1);
    // printf("%d\n", mk.size());
    
    // dn->upper();
    
    return 0;
}
