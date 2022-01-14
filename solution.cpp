#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int> graph[1005];

	int n, m, q;
	cin >> n >> m >> q;


	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			graph[j].push_back(a - 1);
		}

	}

	int connected[1005][1005];
	for (int j = 0; j < n; j++) {
		vector<int> todo = { j };


		while (todo.size() > 0) {

			int current = todo[0];
			todo.erase(todo.begin());

			if (connected[j][current])continue;

			for (auto el : graph[current]) {
				connected[j][current] = 1;
				connected[current][j] = 1;
				todo.push_back(el);
			}
		}
	}
	for (int i = 0; i < q; i++) {

		int a, b;
		cin >> a >> b;

		if (connected[a - 1][b - 1])cout << "DA\n";
		else cout << "NE\n";
	}
}
