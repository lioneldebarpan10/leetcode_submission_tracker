class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair <int,int> , int>> que; // Queue Format -> {{row , col} , time}
        int freshcount = 0; // count fresh oranges
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    que.push({{i,j} , 0}); // initial rotten oranges push into the queue at time 0
                }
                else if(grid[i][j] == 1){
                    freshcount++; // count no of Fresh Oranges
                }
            }
        }
        int time = 0 , rotted = 0;
        int delrow[] = {+1 , -1 , 0 , 0}; // rotten remaining fresh oranges
        int delcol[] = {0 , 0 , +1 , -1}; // 4 direction -> up down right left
        while(!que.empty()){
            int r = que.front().first.first;
            int c = que.front().first.second;
            int t = que.front().second;
            time = max(time , t); // track maximum time
            que.pop();
            for(int i = 0 ; i < 4  ; i++){
                int newrow = r + delrow[i];
                int newcol = c + delcol[i];
                if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && grid[newrow][newcol] == 1){
                    grid[newrow][newcol] = 2; // fresh ---> rotted
                    que.push({{newrow,newcol} , t + 1}); // spread rot with time + 1
                    rotted++; // count rotted oranges
                }
            }
        }
        // if rotted < freshcount , means some oranges are left fresh so return -1 else return time
        if(rotted != freshcount) return -1;
        return time;

        
    }
};