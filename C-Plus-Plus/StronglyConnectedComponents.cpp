/*
  Strongly Connected Components
  Author: Johnny Villegas
  Github: Jvillegasd
*/

#include <bits/stdc++.h>

using namespace std;

int NUM_NODES = 100
vector<int> g[NUM_NODES], rg[NUM_NODES];
bool visited[NUM_NODES];
stack<int> s;

void DFS(int u) {
  visited[u] = true;
  for(auto v : g[u]) {
    if (!visited[v]) {
      DFS(v);
    }
  }
  s.push(u);
}

void DFS_inv(int u) {
  visited[u] = true;
  print("Node: %d\n", u);
  for(auto v : rg[u]) {
    if (!visited[v]) {
      DFS_inv(v);
    }
  }
}

void SCC() {
  int comp = 1;
  for (int u = 1; u <= NUM_NODES; u++) {
    if (!visited[u]) {
      DFS(u);
    }
  }
  memset(visited, 0, sizeof(visited));
  while(!s.empty()) {
    int u = s.top();
    s.pop();
    if (visited[u]) {
      continue;
    }
    printf("Component #%d:\n", comp++);
    DFS_inv(u);
    printf("\n");
  }
}

int main() {
  /*
    This is the SCC Kosajaru algorithm. Before to run it, you have to 
    fill DAG "g" and its reverse "rg". Reverse DAG is the same DAG "g" but
    edges are pointing to oppposite direction.
  */
  
  /*
    Input graph "g":
    
    ||========||
    ||        ||
    1 => 2 => 3 => 4 => 5 =||
              ^^           ||
              ||===========||
              
  */
  g[1].push_back(2);
  g[2].push_back(3);
  g[3].push_back(4);
  g[4].push_back(5);
  g[5].push_back(3);
  g[3].push_back(1);
  
  rg[2].push_back(1);
  rg[3].push_back(2);
  rg[4].push_back(3);
  rg[5].push_back(4);
  rg[3].push_back(5);
  rg[1].push_back(3); 
  
  SCC();
  return 0;
}
