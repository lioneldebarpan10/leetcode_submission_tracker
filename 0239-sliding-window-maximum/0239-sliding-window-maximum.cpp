class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>result;
        deque<int>dq;

        for(int right = 0 ; right < nums.size() ; right++){
            // 1. remove items which are out of window
            while(!dq.empty() && dq.front() <= right - k){
                dq.pop_front();
            }
            // 2.remove smaller elements from back
            while(!dq.empty() && nums[dq.back()] <= nums[right]){
                dq.pop_back();
            }
            // 3.add current index
            dq.push_back(right);
            // 4. add maximum to the answer array
            if(right >= k - 1){
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
        
    }
};