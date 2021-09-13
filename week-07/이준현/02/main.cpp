#include<iostream>
#include<vector>

using namespace std;

int ct = -1;

class Node{
public:
    bool visited;
    vector<int> connect;
};

vector<Node> graph;

void connect(int a, int b){
    graph[a].connect.push_back(b);
    graph[b].connect.push_back(a);
}
void DFS(int a){
    if(!graph[a].visited){
        graph[a].visited = true;
        ct++;
    }
    else{
        return;
    }
    for(int index : graph[a].connect){
        DFS(index);
    }
}
int main(){
    int computer;
    int pair;
    int a, b;
    cin >> computer;
    cin >> pair;
    graph.push_back(Node());
    for(int i=0;i<computer;i++){
        graph.push_back(Node());
    }
    for(int i=0;i<pair;i++){
        cin >> a >> b;
        connect(a,b);
    }
    DFS(1);
    cout << ct;
}
