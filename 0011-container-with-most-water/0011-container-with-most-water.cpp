class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxarea = 0;

        int left = 0 , right = n - 1;
        while(left < right){
            int width = right - left;
            int ht = min(height[left] , height[right]);

            int area = ht * width;
            maxarea = max(maxarea , area);

            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxarea;
        
    }
};