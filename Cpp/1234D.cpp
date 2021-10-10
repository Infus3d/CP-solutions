/**
 * Solved on 2020-01-11
 * */
 
#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) x.size())
#define pb push_back 

string s;
int q;
 
/** Utilities for segment tree */
 
#define MAX_N 100005
 
namespace segtree {
    vector<int> distinct[4*MAX_N];
    
    void build(int l, int r, int v) {
        for(int i=0; i<26; i++)
            distinct[v].pb(0);
            
        if(l == r) {
            distinct[v][s[l]-'a']++;
            return;
        }
        int m = (l+r)/2;
        build(l, m, 2*v);
        build(m+1, r, 2*v+1);
 
        for(int i=0; i<26; i++)
            distinct[v][i] = distinct[v<<1][i] + distinct[v<<1|1][i];
    }
 
    void print() {
        int v = 1;
        int change = 1;
        int d = 2;
        while(sz(distinct[v]) > 0) {
            cout << sz(distinct[v]) << " ";
            if(v == change) {
                cout << endl;
                change += d;
                d *= 2;
            };
            v++;
        }
        cout << endl;
    }
 
    vector<int> get(int x, int y, int l, int r, int v) {
        if(r < x || y < l)  // totally outside
            return vector<int>(26);
        if(x <= l && r <= y) // totally inside
            return distinct[v];
 
        // partically inside
        int m = (l+r)/2;
        vector<int> p = get(x, y, l, m, 2*v);
        vector<int> q = get(x, y, m+1, r, 2*v+1);
        vector<int> res(26);
        for(int i=0; i<26; i++)
            res[i] = p[i] + q[i];
        return res;
    }
 
    void update(int x, char val, int l, int r, int v) {
        if(l == r) {
            distinct[v][s[x]-'a']--;
            distinct[v][val-'a']++;
            s[x] = val;
            return;
        }
        int m = (l+r)/2;
        if(x <= m)
            update(x, val, l, m, 2*v);
        else
            update(x, val, m+1, r, 2*v+1);
        
        for(int i=0; i<26; i++)
            distinct[v][i] = distinct[v<<1][i] + distinct[v<<1|1][i];
    }
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    cin >> s >> q;
 
    segtree::build(0, sz(s)-1, 1);
    // segtree::print();
 
    for(int i=0; i<q; i++) {
        int q_type;
        cin >> q_type;
        if(q_type == 1) {
            int pos;
            char c;
            cin >> pos >> c;
            segtree::update(pos-1, c, 0, sz(s)-1, 1);
            // segtree::print();
        } else {
            int l, r;
            cin >> l >> r;
            vector<int> vec = (segtree::get(l-1, r-1, 0, sz(s)-1, 1));
            int cn = 0;
            for(int i=0; i<26; i++)
                if(vec[i])
                    cn++;
            cout << cn << endl;
//            cout << sz(segtree::get(l-1, r-1, 0, sz(s)-1, 1)) << endl;
        }
    }
 
    return 0;
}
