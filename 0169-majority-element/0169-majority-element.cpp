class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int elem = 0, count = 0;

        for(int i = 0 ; i < n ; i++){
            if(count == 0){
                count = 1;
                elem = nums[i];
            }
            else if(nums[i] == elem){
                count++;
                elem = nums[i];
            }
            else count--;
        }
        return elem;
        
    }
};