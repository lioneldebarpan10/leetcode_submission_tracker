class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>stk;
        vector<int>leftSmaller(n);
        vector<int>rightSmaller(n);

        for(int i = 0 ; i < n ; i++){
            while(!stk.empty() && heights[stk.top()] >= heights[i]){
                stk.pop();
            }
            if(stk.empty()){
                leftSmaller[i] = -1;
            }
            else{
                leftSmaller[i] = stk.top();
            }
            stk.push(i);
        }
        while(!stk.empty()){
            stk.pop();
        }
        for(int i = n - 1 ; i >= 0 ; i--){
            while(!stk.empty() && heights[stk.top()] >= heights[i]){
                stk.pop();
            }
            if(stk.empty()){
                rightSmaller[i] = n;
            }
            else{
                rightSmaller[i] = stk.top();
            }
            stk.push(i);
        }
        int maxarea = 0;
        for(int i = 0 ; i < n ; i++){
            int width = rightSmaller[i] - leftSmaller[i] - 1;
            int area = heights[i] * width;

            maxarea = max(maxarea , area);
        }
        return maxarea;
    }
};