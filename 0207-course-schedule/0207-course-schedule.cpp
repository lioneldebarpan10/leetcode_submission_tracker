class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses , 0);

        for(auto& pre : prerequisites){
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
        int count = 0;
        while(!que.empty()){
            int node = que.front();
            que.pop();
            count++;
            for(int nei : adj[node]){
                indeg[nei]--;
                if(indeg[nei] == 0){
                    que.push(nei);
                }
            }
        }
        return count == numCourses;  
    }
};