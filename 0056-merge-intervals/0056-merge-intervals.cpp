class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        sort(intervals.begin() , intervals.end());

        for(auto i : intervals){
            if(merged.empty() || merged.back()[1] < i[0]){
                merged.push_back(i);
            }
            else{
                merged.back()[1] = max(merged.back()[1] , i[1]);
            }
        }
        return merged;
        
    }
};