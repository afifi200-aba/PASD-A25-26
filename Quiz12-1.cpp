#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cctype>
using namespace std;

class Graph {
private:
    map<char, vector<char>> adjList;

public:
    void addEdge(char u, char v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<char> BFS(char start) {
        vector<char> result;
        set<char> visited;
        queue<char> q;

        q.push(start);
        visited.insert(start);

        while (!q.empty()) {
            char node = q.front();
            q.pop();
            result.push_back(node);

            for (char neighbor : adjList[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        return result;
    }

    void DFSUtil(char node, set<char>& visited, vector<char>& result) {
        visited.insert(node);
        result.push_back(node);

        for (char neighbor : adjList[node]) {
            if (visited.find(neighbor) == visited.end()) {
                DFSUtil(neighbor, visited, result);
            }
        }
    }

    vector<char> DFS(char start) {
        vector<char> result;
        set<char> visited;
        DFSUtil(start, visited, result);
        return result;
    }
};

int main() {
    Graph g;
    g.addEdge('A', 'B');
    g.addEdge('A', 'C');
    g.addEdge('B', 'D');
    g.addEdge('B', 'E');
    g.addEdge('C', 'F');

    char start;
    cout << "Masukkan simpul awal : ";	cin >> start;
    start = toupper(start);

    vector<char> bfsResult = g.BFS(start);
    cout << "\nHasil BFS :\n";
    for (size_t i = 0; i < bfsResult.size(); i++) {
        cout << bfsResult[i];
        if (i != bfsResult.size() - 1) cout << " ";
    }
    cout << "\n";

    vector<char> dfsResult = g.DFS(start);
    cout << "\nHasil DFS :\n";
    for (size_t i = 0; i < dfsResult.size(); i++) {
        cout << dfsResult[i];
        if (i != dfsResult.size() - 1) cout << " ";
    }
    cout << "\n";

    cout << "\nJumlah simpul yang dikunjungi : " << bfsResult.size() << "\n";

    return 0;
}