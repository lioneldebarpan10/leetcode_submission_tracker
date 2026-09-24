class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> currCombo;
        vector<vector<int>> allCombo;
        sort(candidates.begin() , candidates.end());
        backtrack(candidates , 0 , target , currCombo , allCombo);
        return allCombo;
    }
private:
    void backtrack(vector<int>& candidates , int start , int target , vector<int>& currCombo , vector<vector<int>>& allCombo){
        if(target == 0){
            allCombo.push_back(currCombo);
            return;
        }
        if(target < 0){
            return;
        }
        for(int i = start ; i < candidates.size() ; ++i){
            currCombo.push_back(candidates[i]);
            backtrack(candidates , i , target - candidates[i] , currCombo , allCombo);
            currCombo.pop_back();
        }
    }
};