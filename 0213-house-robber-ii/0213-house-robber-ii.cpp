class Solution {
public:
    int solve(vector<int>&nums){
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        int prev = nums[0];
        int prev2 = 0;

        for(int i = 1 ; i < n ; i++){
            int option1 = nums[i];
            if(i > 1){
                option1 += prev2;
            }
            int option2 = 0 + prev;
            int curr = max(option1 , option2);
            prev2 = prev;
            prev = curr;
        }
        return prev;

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        vector<int> ex_first , ex_last;
        for(int i = 0 ; i < n ; i++){
            if(i != 0) ex_first.push_back(nums[i]);
            if(i !=  n - 1) ex_last.push_back(nums[i]);
        }
        int ans1 = solve(ex_first);
        int ans2 = solve(ex_last);
        int max_money = max(ans1 , ans2);
        return max_money;
    }
};