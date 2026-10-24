class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0, count = 0 , lastSmaller = INT_MIN;
        sort(nums.begin() , nums.end());

        for(int num : nums){
            if(num  - 1 == lastSmaller){
                count++;
                lastSmaller = num;
            }
            else if(num != lastSmaller){
                count = 1;
                lastSmaller = num;
            }
            longest = max(longest , count);
        }
        return longest;
        
    }
};