class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>external{{}};
        for(int num : nums){
            int n = external.size();
            for(int i = 0 ; i < n ; i++){
                vector<int>internal = external[i];
                internal.push_back(num);
                external.push_back(internal);
            }
        }
        return external;  
    }
};