#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void bfs(vector<vector<int>> graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main()
{
  int init_graph[10][10] = {{0, 1, 1, 0, 1, 0, 1, 0, 1, 0},
                            {0, 0, 1, 1, 0, 0, 0, 1, 0, 0},
                            {0, 1, 0, 0, 0, 1, 1, 0, 1, 1},
                            {1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                            {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
                            {1, 0, 1, 0, 1, 0, 0, 0, 1, 0},
                            {0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
                            {1, 0, 0, 0, 0, 1, 1, 0, 1, 0},
                            {0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
                            {1, 0, 1, 0, 1, 0, 0, 0, 1, 0}};
  int n = 10;
  vector<vector<int>> graph(n, vector<int>());
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      if (init_graph[i][j])
        graph[i].push_back(j);
    }
  }

  bfs(graph, 0);//0 1 2 4 6 8 3 7 5 9

  return 0;
}
