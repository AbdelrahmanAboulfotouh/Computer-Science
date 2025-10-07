#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> Graph;
void add_node_in_dircted_graph_unwighted(Graph &graph , int from ,int to )
{
    graph[from].push_back(to);
}
void add_node_in_undircted_graph_unwighted(Graph &graph , int from ,int to )
{
    graph[from].push_back(to);
    graph[to].push_back(from);
}


//----------------------------------------------------------------------------------------------------------------------
//DFS
vector<bool>is_visited;
void dfs (Graph &graph, int node, vector<bool> & visited)
{
    visited[node] = true;
    for(auto & neighbour : graph[node])
    {
        if(!visited[neighbour]) {
            cout << "We reached " << neighbour << " ";
            dfs(graph, neighbour, visited);
        }
    }
}
void reachabilty_of_node(Graph & graph)
{
    int number_of_nodes = graph.size();
    for(int node {0}; node < number_of_nodes; ++node)
    {
        vector<bool>visited(number_of_nodes);
        cout<<"Node  "<<node<<"can reach : "<<endl;
        dfs(graph,node,visited);
    }
}

int main(){

    return 0;
}