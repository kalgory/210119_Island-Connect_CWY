#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int parent[101];
int _rank[101];


int find(int a){
    if(a == parent[a]){
        return a;
    }
    return parent[a] = find(parent[a]);
}

void _union(int _a, int _b){
    int a = find(_a);
    int b = find(_b);
    if(a == b) return;
    if(_rank[a]<=_rank[b]){
        parent[a] = b;
    }else{
        parent[b] = a;
    }
    if(_rank[a] == _rank[b]){
        _rank[b]++;
    }
}

bool compare(vector<int> a, vector<int> b){
    return a[2]<b[2];
}

int solution(int n, vector<vector<int>> costs) {
    for (int i = 0; i < 101; i++) {
    parent[i] = i;
    _rank[i] = 0;
}
    int edgeNum = 0;
    set<int> node;
    int answer = 0;
    sort(costs.begin(), costs.end(), &compare);
    int a;
    int b;
    for(int i = 0;i<costs.size();i++){
        a = costs[i][0];
        b = costs[i][1];
        if(find(a)!=find(b)){
            _union(a, b);
            node.insert(a);
            node.insert(b);
            answer += costs[i][2];
            edgeNum++;
        }
        if(edgeNum == n-1){
            return answer;
        }
        
    }
    return answer;
}
