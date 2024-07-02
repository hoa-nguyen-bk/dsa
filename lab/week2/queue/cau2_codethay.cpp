#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void bfs(vector<vector<int>> graph, int start)
{
  cout << "graph.size() = " << graph.size() << endl;
  queue<int> q;
  vector<bool> visit(graph.size(), false);

  q.push(start);
  visit[start] = true;
  for (int i = 0; i < graph.size(); i++)
  {
    cout << visit[i] << " ";
  }
  cout << endl;

  while (!q.empty())
  {
    int curV = q.front();
 
    q.pop();

    for (int adjV : graph[curV])
    {
      if (!visit[adjV])
      {
        cout << " +"<< adjV << endl;
        q.push(adjV);
        visit[adjV] = true;
      }
    }
    for (int i = 0; i < graph.size(); i++)
    {
      cout << visit[i] << " ";
    }

    cout << "->" << curV << endl;
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
      {
        cout << j << " ";
        graph[i].push_back(j);
      }
    }
    cout << endl;
  }
  cout << endl
       << " graph ne: " << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < graph[i].size(); j++)
    {
      cout << graph[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  bfs(graph, 0); // 0 1 2 4 6 8 3 7 5 9

  return 0;
}
