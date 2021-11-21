#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init (vector<pair<int, int> > &vec){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	int N;	
	cin >> N;

    for(int i = 0; i < N; i++){
        int start, end;
        cin >> start >> end;
        vec.push_back(make_pair(end,start));
    }
	sort(vec.begin(), vec.end());
}

int main() {
	vector<pair<int, int> > meeting_v;
	init(meeting_v);
	
	int end, start;
	end = meeting_v[0].first;
    int count = 1;
    for(int i = 1; i < meeting_v.size(); i++){
        int start = meeting_v[i].second;
        if(start >= end){
            end = meeting_v[i].first;
            count++;
        }
    }
	cout << count << endl;
}