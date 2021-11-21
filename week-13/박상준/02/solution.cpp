#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<vector<long long>> times, selected;
	long long N, start, end;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		times.push_back({ start,end });
	}
	sort(times.begin(), times.end());

	vector<long long> current = times[times.size() - 1];
	int ans = 1;
	for (int i = N - 2; i >= 0; i--) {
		if ((current[0] > times[i][0] && current[0] < times[i][1]) || (current[1] > times[i][0] && current[1] < times[i][1]) || (times[i][0] > current[0] && times[i][0] < current[1]) || (times[i][1] > current[0] && times[i][1] < current[1])) {
			continue;
		}

		if (current[0] == times[i][0] && current[1] == times[i][1] && current[0] != current[1]) continue;

		ans++;
		current = times[i];
	}
	cout << ans;
}