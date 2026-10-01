class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> external {{}};
        sort(nums.begin() , nums.end());

        for(int num : nums){
            int n = external.size();
            for(int i = 0 ; i < n ; i++){
                vector<int> internal = external[i];
                internal.push_back(num);
                if(find(external.begin() , external.end() , internal) == external.end()){
                    external.push_back(internal);
                }
            }
        }
        return external;
    }
};