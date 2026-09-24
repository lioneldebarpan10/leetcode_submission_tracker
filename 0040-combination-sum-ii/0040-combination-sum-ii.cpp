class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end()); 
        vector<int> ds;
        vector<vector<int>> ans;
        findCombination(0 , target , candidates , ans , ds);
        return ans;
    }
    void findCombination(int idx , int target , vector<int>& candidates, vector<vector<int>>& ans , vector<int>& ds){
        
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i = idx ; i < candidates.size() ; i++){
            if(idx < i && candidates[i] == candidates[i-1]) continue; 
            if(candidates[i] > target) break;
            ds.push_back(candidates[i]);
            findCombination(i + 1 , target - candidates[i] , candidates , ans , ds);
            ds.pop_back(); 
        }
    }
};