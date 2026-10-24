class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0 , mid = n - 1 , high = n - 1;

        while(low <= mid){
            if(nums[mid] == 0){
                swap(nums[low] , nums[mid]);
                low++;
            }
            else if(nums[mid] == 1){
                mid--;
            }
            else{
                swap(nums[mid] , nums[high]);
                high-- , mid--;
            }
        }
    }
};