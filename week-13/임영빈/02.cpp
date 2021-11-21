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
        int temp1, temp2;
        cin >> temp1 >> temp2;
        vec.push_back(make_pair(temp2,temp1));
    }
	sort(vec.begin(), vec.end());
}

int main() {
	vector<pair<int, int> > meeting_v;
	init(meeting_v);
	
	int temp1, temp2;
	temp1 = meeting_v[0].first;
    int count = 1;
    for(int i = 1; i < meeting_v.size(); i++){
        int temp2 = meeting_v[i].second;
        if(temp2 >= temp1){
            temp1 = meeting_v[i].first;
            count++;
        }
    }
	cout << count << endl;
}