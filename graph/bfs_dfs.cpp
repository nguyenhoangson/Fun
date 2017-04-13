/*** 
    Breadth First Search
    and
    Depth First Search
***/

#include<iostream>
#include<vector>
#include<list>
#include<cstdlib>
#include<queue>

const int UNDISCOVERED = 0;
const int DISCOVERED = 1;
const int PROCESSED = 2;

std::vector<int> bfs(std::vector<std::list<int> >&,int); 
std::vector<int> dfs(std::vector<std::list<int> >&);
void dfs_travel(std::vector<std::list<int> >&, int,
		std::vector<int>&,
		std::vector<int>&);

int main(){

  std::freopen("graph.txt", "r", stdin);
  std::ios::sync_with_stdio(0);

  int num_ver, num_edg;
   
  std::cin >> num_ver >> num_edg;
  
  // build graph
  std::vector<std::list<int> > g;

  for(int i = 0; i < num_ver; ++i){
    std::list<int> lst;
    g.push_back(lst);
  }
    
  for(int i = 0; i < num_edg; ++i){
    int u, v;
    std::cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  std::vector<int> p = bfs(g, 0);
  for(auto& t: p){
    std::cout << t << std::endl;
  }
  return 0;
}

std::vector<int> bfs(std::vector<std::list<int> >& g,int s){

  /* Initialize */
  std::vector<int> state(g.size(), UNDISCOVERED);
  std::vector<int> parent(g.size(), -1);
  state[s] = DISCOVERED;
  std::queue<int> q;
  q.push(s);
  
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(auto& v: g[u]){
      if(state[v] == UNDISCOVERED){
	q.push(v);
	parent[v] = u;
	state[v] = DISCOVERED;
      }
    }
    state[u] = PROCESSED; 
  }
  
  return parent;   
}

std::vector<int> dfs(std::vector<std::list<int> >& g){
  std::vector<int> state(g.size(), UNDISCOVERED);
  std::vector<int> parent(g.size(), -1);

  for(int s = 0; s < g.size(); ++s){
    if(state[s] == UNDISCOVERED)
      dfs_travel(g, s, state, parent);
  }
  
  return parent;
}

void dfs_travel(std::vector<std::list<int> >& g, int s,
		std::vector<int>& state,
		std::vector<int>& parent){

  state[s] = DISCOVERED;
  for(auto& v: g[s]){
    if(state[v] == UNDISCOVERED){
      parent[v] = s; 
      dfs_travel(g, v, state, parent);
    }
  }
  state[s] = PROCESSED;
  return; 
}
