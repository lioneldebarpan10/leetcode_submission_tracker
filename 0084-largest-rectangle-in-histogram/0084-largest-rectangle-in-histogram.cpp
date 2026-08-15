class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int n = heights.size();
        int maxarea = 0;
        // Traverse all bars including one extra pass for cleanup
        for(int i=0 ; i<=n ; i++){
            // Process bars in stack while current bar is shorter
            while(!stk.empty() && (i==n || heights[stk.top()] >= heights[i])){
                int height = heights[stk.top()];
                stk.pop();
                // Calculate width for current height
                int width;
                if(stk.empty()){
                    width = i;
                }
                else{
                    width = i - stk.top() - 1;
                }
                // calculate maxarea
                maxarea = max(maxarea , width * height);
            }
            // push curr index into the stack
            
            stk.push(i);
        }
        return maxarea;
        
    }
};