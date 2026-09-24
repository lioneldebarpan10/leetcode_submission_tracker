class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans{{}};
        sort(nums.begin() , nums.end());
        for(int num : nums){
            int n = ans.size();
            for(int i = 0 ; i < n ; i++){
                vector<int> subset = ans[i];
                subset.push_back(num);
                if(find(ans.begin() , ans.end() , subset) == ans.end()){
                    ans.push_back(subset);
                }
            }
        }
        return ans;
    }
};