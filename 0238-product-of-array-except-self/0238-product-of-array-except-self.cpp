class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftArr(n);
        vector<int>rightArr(n);
        vector<int>ans(n);

        leftArr[0] = 1;
        rightArr[n-1] = 1;

        for(int i = 1 ; i < n ; i++){
            leftArr[i] = leftArr[i-1] * nums[i-1];
        }
        for(int i = n - 2 ; i >= 0 ; i--){
            rightArr[i] = rightArr[i+1] * nums[i+1];
        }
        for(int i = 0 ; i < n ; i++){
            ans[i] = leftArr[i] * rightArr[i];
        }
        return ans;
        
    }
};