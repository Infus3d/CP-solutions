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

const int N = 4e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, m;
int c[N], d[N], vis[N];
char s[N];

vector<pair<int, char>> E[N];
vector<int> L[N];

map<char, vector<int>> mapping;

int dfs(int u, int suggestedPress, int& curTotal, vector<int>& visitedNodes){
    // assert(suggestedPress < 3);
    if(vis[u]){
        return d[u] == suggestedPress;
    }
    if(d[u] != -1 && d[u] != suggestedPress){
        return 0;
    }
    // printf("u: %d, suggestedPress: %d, curTotal: %d\n", u, suggestedPress, curTotal);
    curTotal += suggestedPress;
    vis[u] = 1;
    d[u] = suggestedPress;
    visitedNodes.push_back(u);
    
    int ret = 1;
    for(pair<int, char> v : E[u]){
        ret &= dfs(v.first, mapping[v.second][suggestedPress], curTotal, visitedNodes);
    }
    return ret;
}

void solve(){
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    
    for(int i=0; i<m; i++){
        d[i] = c[i] = -1;
    }
    for(int i=0; i<m; i++){
        int k; scanf("%d", &k);
        for(int j=0; j<k; j++){
            int a; scanf("%d", &a); --a;
            L[a].push_back(i);
        }
        vis[i] = 0;
    }
    for(int i=0; i<n; i++){
        if(sz(L[i]) == 0){
            if(s[i] != 'R'){
                puts("impossible");
                return;
            }
        } else if(sz(L[i]) == 1){
            int presses = (s[i] == 'R' ? 0 : (s[i] == 'B' ? 1 : 2));
            if(c[L[i][0]] != -1 && c[L[i][0]] != presses){
                puts("impossible");
                return;
            }
            c[L[i][0]] = d[L[i][0]] = presses;
        } else if(sz(L[i]) == 2){
            E[L[i][0]].push_back({L[i][1], s[i]});
            E[L[i][1]].push_back({L[i][0], s[i]});
            assert(L[i][0] != L[i][1]);
        }
        // assert(sz(L[i]) < 3);
    }
    mapping['R'] = vector<int>{0, 2, 1};
    mapping['B'] = vector<int>{1, 0, 2};
    mapping['G'] = vector<int>{2, 1, 0};
    
    
    int ans = 0;
    for(int i=0; i<m; i++){
        if(vis[i]) continue;
        int compAns = MOD;
        int bestChoice = -1;
        for(int k=0; k<3; k++){
            int curAns = 0;
            vector<int> visitedNodes;
            int possible = dfs(i, k, curAns, visitedNodes);
            
            // printf("k: %d, possible: %d\n", k, possible);
            if(possible){
                if(umin(compAns, curAns)){
                    bestChoice = k;
                }
            }
            
            for(int v : visitedNodes){
                d[v] = c[v];
                vis[v] = 0;
            }
        }
        if(bestChoice != -1){
            int someCntIdk = 0;
            vector<int> visitedNodes;
            dfs(i, bestChoice, someCntIdk, visitedNodes);
        } else {
            // printf("i: %d\n", i);
            // if(2*n > 200000) assert(false);
            puts("impossible");
            return;
        }
        ans += compAns;
    }
    // assert(ans >= 0);
    printf("%d\n", ans);
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
8 7    
GBGGGBRR
3 1 2 3
3 4 1 3
2 4 5
2 5 8
1 8
1 7
3 7 6 2

8

*
* 
* 

6 4
BBGGGGBB
3 1 2 5
3 2 1 6
3 3 4 7
3 4 3 8

*/
