#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n;
	cin >> n;
 
	vector<vector<int>> edges(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
 
	set<pair<int, int>> to_destroy;
	vector<int> roots;
	vector<bool> visited(n, false);
	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		stack<pair<int, int>> s;  // [parent, node]
		s.push({-1, i});
		while (!s.empty()) {
			pair<int, int> a = s.top();
			s.pop();
			if(visited[a.second]) continue;
			visited[a.second] = true;
 
			for (int edge : edges[a.second]) {
				if (!visited[edge]) {
					s.push({a.second, edge});
				} else if (edge != a.first) {
					to_destroy.insert(
						{min(a.second, edge), max(a.second, edge)});
				}
			}
		}
		roots.push_back(i);
	}
	
	assert(((int)roots.size()-1) == (int)(to_destroy.size()));
	cout << roots.size() - 1 << endl;
	auto iter = to_destroy.begin();
	for (int i = 0; i < roots.size() - 1; i++) {
		cout << (*iter).first + 1 << ' ' << (*iter).second + 1 << ' '
			 << roots[i] + 1 << ' ' << roots[i + 1] + 1 << endl;
		iter++;
	}
 
	return 0;
}
