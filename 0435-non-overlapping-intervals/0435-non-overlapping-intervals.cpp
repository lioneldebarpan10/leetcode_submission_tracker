class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin() , intervals.end() ,[](auto &a , auto &b){
            return a[1] < b[1];
        });

        int count = 0;
        int lastEndTime = intervals[0][1];
        
        for(int i = 1 ; i < intervals.size() ; i++){
            if(lastEndTime > intervals[i][0]){
                count++;
            }
            else{
                lastEndTime = intervals[i][1];
            }
        }
        return count;
        
    }
};