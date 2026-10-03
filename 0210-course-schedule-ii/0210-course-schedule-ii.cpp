class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses , 0);
        vector<vector<int>> adj(numCourses);

        for(auto &pre : prerequisites){
            int a = pre[0];
            int b = pre[1];
            adj[b].push_back(a);
            indeg[a]++;
        }
        queue<int> que;
        for(int i = 0 ; i < numCourses ; i++){
            if(indeg[i] == 0){
                que.push(i);
            }
        }
        vector<int> order;
        while(!que.empty()){
            int node = que.front();
            que.pop();
            order.push_back(node);

            for(int nei : adj[node]){
                indeg[nei]--;
                if(indeg[nei] == 0){
                    que.push(nei);
                }
            }
        }
        if(order.size() == numCourses){
            return order;
        }
        return {};
    }
};