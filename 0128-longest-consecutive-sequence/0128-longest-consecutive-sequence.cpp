class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int longest = 0 , count = 0 , lastSmaller = INT_MIN;
        sort(nums.begin() , nums.end());
        for(int num : nums){
            if(num - 1 == lastSmaller){
                lastSmaller = num;
                count++;
            }
            else if(num != lastSmaller){
                lastSmaller = num;
                count = 1;
            }

            longest = max(longest , count);
        }
        return longest; 
        
    }
};