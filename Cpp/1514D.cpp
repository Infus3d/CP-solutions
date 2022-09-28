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

const int N = 3e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int block_size = 2000;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

int cnt[N], cntofcnt[N], a[N], biggest = 0;

void add(int x){
  cntofcnt[cnt[a[x]]]--;
  cnt[a[x]]++;
  cntofcnt[cnt[a[x]]]++;
  umax(biggest, cnt[a[x]]);
}

void remove(int x){
  cntofcnt[cnt[a[x]]]--;
  if(cnt[a[x]] == biggest && cntofcnt[cnt[a[x]]] == 0)
    biggest = cnt[a[x]]-1;
  cnt[a[x]]--;
  cntofcnt[cnt[a[x]]]++;
}

int get_answer(int l, int r){
  if(biggest <= (r-l+2)/2) return 1;
  return (biggest - ((r-l+1) - biggest));
}
  
//copied from cp-algorithms.com
vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 0;
    int cur_r = -1;
    biggest = 0;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        //~ printf("l:%d, r:%d, biggest->%d\n", q.l, q.r, biggest);
        answers[q.idx] = get_answer(q.l, q.r);
    }
    return answers;
}


void solve(){
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  vector<Query> v;
  for(int i = 0; i < m; i++){
    int l, r;
    scanf("%d%d", &l, &r);
    l--, r--;
    v.push_back(Query{l, r, i});
  }
  vector<int> ans = mo_s_algorithm(v);
  for(int i : ans)
    printf("%d\n", i);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
