class Solution {
public:
    vector<vector<int>> result;
    void solve(vector<int>&nums , int i , int n){
        if(i == n){
            result.push_back(nums);
            return;
        }
        unordered_set<int> used;
        for(int j = i ; j <= n ; j++){

            if(used.count(nums[j])){
                continue;
            }
            used.insert(nums[j]);

            swap(nums[i] , nums[j]);
            solve(nums , i + 1 , n);
            swap(nums[i] , nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(nums , 0 , nums.size() - 1);
        return result;
    }
};