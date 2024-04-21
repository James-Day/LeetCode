// returns a bool so that we don't over search as much.
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n); //size n
         for(int i=0; i<edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n, false);
        return dfs(graph, visited, source, destination);
    }
    bool dfs(vector<vector<int>>& graph, vector<bool>& visited, int current, int end) {
        if(current == end) return true;
        if(visited[current]) return false;
        visited[current] = true;
        for (int path : graph[current]){
            if(!visited[path]){
                if(dfs(graph, visited, path, end)) return true;
            }
        }
        return false;
    }
};

/* inital DFS solution
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> vis(n, false);
        vector<vector<int>> graph(n); //size n
        for(auto edge : edges){
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(source, vis, graph);
        return vis[destination];
    }
    void dfs(int node, vector<bool>& vis, vector<vector<int>>& graph){
        if(vis[node]) return;
        vis[node] = true;
        for (int path : graph[node]){
            dfs(path, vis, graph); //add a check for if !visited[path] (speeds up by 2x)
        }
    }
};
*/

/* Best DFS solution I could find using a stack and doing it iteratively.
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        unordered_map<int,vector<int>> graph;
        for(auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n,0);
        stack<int> st;
        st.push(start);
        visited[start] = 1;

        while(!st.empty()){
            auto top = st.top();
            if(top == end)
                return 1;
            st.pop();
            for(auto node : graph[top]){
                if(!visited[node]){
                    visited[node] = 1;
                    st.push(node);
                }
            }
        }
        return false;
    }
};
*/