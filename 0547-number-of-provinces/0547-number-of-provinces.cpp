class Solution {
private:
    void dfs(int node , vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 1; // mark 1 as visited
        for(auto it : adj[node]){
            // if not visited then call dfs for new province 
            if(!vis[it]){
                dfs(it , adj , vis); // it indicates new start
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n); // creation of Adjacency List
        // conversion of Adjacency Matrix to Adjacency List
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int provinces = 0; // track number of provinces
        vector<int> vis(n, 0); // visited array to keep track of visited and unvisited nodes
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                provinces++; // increment count of provinces
                dfs(i , adj , vis);
            }
        }
        return provinces;
    }
};