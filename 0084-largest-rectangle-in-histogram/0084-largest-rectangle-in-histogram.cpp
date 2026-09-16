class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int height = 0;
        int width = 0;
        int maxarea = 0;
        stack<int> stk;

        for(int i = 0 ; i <= n ; i++){
            while(!stk.empty() && (i == n || heights[stk.top()] >= heights[i])){
                height = heights[stk.top()];
                stk.pop();

                if(stk.empty()){
                    width = i;
                }
                else{
                    width = i - stk.top() - 1;
                }

                int area = height * width;
                maxarea = max(maxarea , area);
            }
            if(i < n){
                stk.push(i);
            }
        }
        return maxarea;
    }
};