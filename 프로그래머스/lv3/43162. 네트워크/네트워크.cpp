#include <string>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int start) {
    visited[start] = true;
    for (int i = 0; i < graph.size(); i++) {
        if (graph[start][i] && !visited[i]) {
			dfs(graph, visited, i);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(computers.size());
    
    for (int i = 0; i < computers.size(); i++) {
        if (!visited[i]) {
            answer++;
            dfs(computers, visited, i);
        }
    }    
     
    return answer;
}