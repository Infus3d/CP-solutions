/*
ID : omarmuh1
PROG : test
LANG : C++11
*/

#include "bits/stdc++.h"
//#include "ext/pb_ds/assoc_container.hpp"

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
#define sz(x) int(x.size())
#define tr(it , c) for(__typeof(c.begin()) it = (c.begin()); it != (c.end()); it++)
#define y1 you_made_my_day

using namespace std;
//using namespace __gnu_pbds;

const int N = 1e5+7;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

const int M = 10 * 11 / 2;

int a, b, n, m, T[N*4][4*M+2];
char s[N], c[12];

int getInd(int i, int j, int k){
    return k*M + i*(i-1)/2 + j;
}

int getId(char ch){
    if(ch == 'A')   return 0;
    if(ch == 'G')   return 1;
    if(ch == 'T')   return 2;
    if(ch == 'C')   return 3;
}

void doit(int l, int r, int v){
    int md = mid(l, r)-l+1;
    for(int i=0; i<10; i++)
        for(int j=0; j<=i; j++)
            for(int k=0; k<4; k++)
                T[v][getInd(i+1, j, k)] = T[v<<1][getInd(i+1, j, k)] + T[v<<1|1][getInd(i+1, (j-(md%(i+1))+(i+1))%(i+1), k)];
//                T[v][i][j][k] = T[v<<1][i][j][k] + T[v<<1|1][i][(j-(md%(i+1))+(i+1))%(i+1)][k];
}

void form_tree(int l, int r, int v){
    if(l == r){
        for(int i=0; i<10; i++)
            T[v][getInd(i+1, 0, getId(s[l-1]))]++;
//            T[v][i][0][getId(s[l-1])]++;
        return;
    }
    
    form_tree(l, mid(l, r), v<<1);
    form_tree(mid(l, r)+1, r, v<<1|1);
    
    doit(l, r, v);
}

void upd(int x, int lid, int nid, int l, int r, int v){
    if(l == r){
        for(int i=0; i<10; i++){
            T[v][getInd(i+1, 0, lid)]--;
            T[v][getInd(i+1, 0, nid)]++;
        }
        return;
    }
    
    if(x <= mid(l, r))
        upd(x, lid, nid, l, mid(l, r), v<<1);
    else
        upd(x, lid, nid, mid(l, r)+1, r, v<<1|1);
    
    doit(l, r, v);
}

int get(int x, int y, int id, int siz, int ind, int l, int r, int v){
    if(y < l || r < x)
        return 0;
    
    if(x <= l && r <= y)
        return T[v][getInd(siz+1, (ind-((l-x)%(siz+1))+(siz+1))%(siz+1), id)];
//        return T[v][siz][(ind-((l-x)%(siz+1))+(siz+1))%(siz+1)][id];
    
    return get(x, y, id, siz, ind, l, mid(l, r), v<<1) + get(x, y, id, siz, ind, mid(l, r)+1, r, v<<1|1);
}

int main(){
    scanf("%s", s); n = strlen(s);
    form_tree(1, n, 1);
    /*
    for(int k=0; k<4; k++){
        printf("for k = %d :\n", k);
        for(int i=0; i<=10; i++){
            for(int j=0; j<=i; j++)
                printf("%d ", T[1][i][j][k]);
            puts("");
        }
    }
    */
    scanf("%d", &m);
    while(m--){
        int type;
        scanf("%d", &type);
        if(type == 1){
            scanf("%d%s", &a, c);
            upd(a, getId(s[a-1]), getId(c[0]), 1, n, 1);
            s[a-1] = c[0];
        }
        else{
            scanf("%d%d%s", &a, &b, c);
            int ans = 0;
            for(int i=0; i<strlen(c); i++)
                ans += get(a, b, getId(c[i]), strlen(c)-1, i, 1, n, 1);
            
            printf("%d\n", ans);
        }
    }
    
	return 0;
}

