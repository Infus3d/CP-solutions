#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <cassert>
using namespace std;

const int MOD = 1000000007;

struct Function
{
	pair<int, int> a, b;
	
	Function(char c = 0)
	{
		if (c == 'A')
		{
			a = {1, 1};
			b = {0, 1};
		}
		else if (c == 'B')
		{
			a = {1, 0};
			b = {1, 1};
		}
		else
		{
			a = {1, 0};
			b = {0, 1};
		}
	}
	
	void reverse()
	{
		swap(a.first, b.second);
		swap(a.second, b.first);
	}
	
	pair<int, int> call(int x, int y)
	{
		return {((1LL * a.first * x) + (1LL * a.second * y)) % MOD, ((1LL * b.first * x) + (1LL * b.second * y)) % MOD};
	}
	
	static Function compose(Function F, Function G)
	{
		pair<int, int> A = {((1LL * F.a.first * G.a.first) + (1LL * F.a.second * G.b.first)) % MOD,
							((1LL * F.a.first * G.a.second) + (1LL * F.a.second * G.b.second)) % MOD};
		pair<int, int> B = {((1LL * F.b.first * G.a.first) + (1LL * F.b.second * G.b.first)) % MOD,
							((1LL * F.b.first * G.a.second) + (1LL * F.b.second * G.b.second)) % MOD};
		
		F.a = A;
		F.b = B;
		
		return F;
	}
};

struct Node
{
	int l, r;
	Function f;
	int lazy;
	Node *lnode, *rnode;
	
	Node(int l, int r, string & s) : l(l), r(r), lazy(0)
	{
		if (r - l == 1)
			f = Function(s[l]);
		else
		{
			lnode = new Node(l, l + r >> 1, s);
			rnode = new Node(l + r >> 1, r, s);
			
			f = Function::compose(rnode->f, lnode->f);
		}
	}
	
	void push()
	{
		if (lazy)
		{
			f.reverse();
			if (r - l != 1)
			{
				lnode->lazy ^= 1;
				rnode->lazy ^= 1;
			}
			lazy = 0;
		}
	}
	
	void update(int L, int R)
	{
		push();
		
		if (R <= l || r <= L)
			return;
		else if (L <= l && r <= R)
		{
			lazy ^= 1;
			push();
		}
		else
		{
			lnode->update(L, R);
			rnode->update(L, R);
			f = Function::compose(rnode->f, lnode->f);
		}
	}
	
	Function query(int L, int R)
	{
		push();
		
		if (R <= l || r <= L)
			return Function('C');
		else if (L <= l && r <= R)
			return f;
		else
			return Function::compose(rnode->query(L, R), lnode->query(L, R));
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	string s;
	cin >> s;
	
	Node* st = new Node(0, n, s);
	
	while (q--)
	{
		int t;
		cin >> t;
		
		if (t == 1)
		{
			int l, r;
			cin >> l >> r;
			
			st->update(l - 1, r);
		}
		else
		{
			int l, r, x, y;
			cin >> l >> r >> x >> y;
			pair<int, int> ans = st->query(l - 1, r).call(x, y);
			
			cout << ans.first << ' ' << ans.second << '\n';
		}
	}
	
	return 0;
}
