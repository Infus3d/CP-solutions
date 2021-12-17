#include "bits/stdc++.h"
// #include "ext/pb_ds/assoc_container.hpp"
 
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define db puts("*****")
#define mid(x , y) ((x+y)>>1)
#define ff first
#define ss second
#define all(x)	x.begin(),x.end()
#define ll long long
#define sqr(x)	((x)*(x))
#define pii pair <int , int>
#define pll pair <ll, ll>
#define sz(x) int(x.size())
#define tr(it , c) for(__typeof(c.begin()) it = (c.begin()); it != (c.end()); it++)
#define y1 you_made_my_day
 
using namespace std;
// using namespace __gnu_pbds;
 
const int N = 1e6+7;
const int M = 600;
const int MOD = 998244353;
const int K = 1e3+7;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int testcase;
int d[N], n, m;
int mn[N][2], mx[N][2];
int rowmin[N][2][2], rowmax[N][2][2];
bool ans[N];

int get(int x, int y){
    return ((x-1)*m + y);
}

int main(){
    scanf("%d", &testcase);
    while(testcase--){
        bool flag = false;
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                scanf("%d", &d[get(i, j)]);
        
        //~ printf("new case\n");
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                int ind = get(i, j);
                int ind1 = get(i, j-1);
                if(j == 1)
                    mn[ind][0] = mx[ind][0] = d[ind];
                else{
                    mn[ind][0] = min(d[ind], mn[ind1][0]);
                    mx[ind][0] = max(d[ind], mx[ind1][0]);
                }
            }
            for(int j=m; j>=1; j--){
                int ind = get(i, j);
                int ind1 = get(i, j+1);
                if(j == m)
                    mn[ind][1] = mx[ind][1] = d[ind];
                else{
                    mn[ind][1] = min(d[ind], mn[ind1][1]);
                    mx[ind][1] = max(d[ind], mx[ind1][1]);
                }
            }
        }
        
        for(int j=1; j<m; j++){
            vector<pii> row(n+1);
            for(int i=1; i<=n; i++) row[i] = {mn[get(i, j)][0], i};
            sort(all(row));
            
            /*
            printf("col: %d\n", j);
            for(int i=1; i<=n; i++)
                printf("%d ", row[i].ss);
            puts("");
            */
            
            for(int i=1; i<=n; i++){
                int ind = get(row[i].ss, j);
                int ind1 = get(row[i].ss, j+1);
                if(i > 1){
                    rowmin[i][0][0] = min(rowmin[i-1][0][0], mn[ind][0]);
                    rowmax[i][0][0] = max(rowmax[i-1][0][0], mx[ind][0]);
                    
                    rowmin[i][1][0] = min(rowmin[i-1][1][0], mn[ind1][1]);
                    rowmax[i][1][0] = max(rowmax[i-1][1][0], mx[ind1][1]);
                }
                else{
                    rowmin[i][0][0] = mn[ind][0];
                    rowmax[i][0][0] = mx[ind][0];
                    
                    rowmin[i][1][0] = mn[ind1][1];
                    rowmax[i][1][0] = mx[ind1][1];
                }
            }
            
            for(int i=n; i>=1; i--){
                int ind = get(row[i].ss, j);
                int ind1 = get(row[i].ss, j+1);
                if(i < n){
                    rowmin[i][0][1] = min(rowmin[i+1][0][1], mn[ind][0]);
                    rowmax[i][0][1] = max(rowmax[i+1][0][1], mx[ind][0]);
                    
                    rowmin[i][1][1] = min(rowmin[i+1][1][1], mn[ind1][1]);
                    rowmax[i][1][1] = max(rowmax[i+1][1][1], mx[ind1][1]);
                }
                else{
                    rowmin[i][0][1] = mn[ind][0];
                    rowmax[i][0][1] = mx[ind][0];
                    
                    rowmin[i][1][1] = mn[ind1][1];
                    rowmax[i][1][1] = mx[ind1][1];
                }
            }
            
            for(int i=1; i<n; i++){
                if(rowmax[i][0][0] < rowmin[i+1][0][1] && rowmin[i][1][0] > rowmax[i+1][1][1]){
                    flag = true;
                    for(int t=1; t<=i; t++) ans[row[t].ss] = true;
                    printf("YES\n");
                    for(int t=1; t<=n; t++){
                        if(ans[t])
                            ans[t] = false, printf("B");
                        else
                            printf("R");
                    }
                    printf(" %d\n", j);
                    break;
                }
            }
            
            if(flag)
                break;
        }
        
        if(flag) continue;
        
        printf("NO\n");
    }
	return 0;
}
