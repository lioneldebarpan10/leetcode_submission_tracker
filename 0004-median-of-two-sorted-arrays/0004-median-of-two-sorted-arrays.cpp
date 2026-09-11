class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int>nums;

        for(int i = 0 ; i < m ; i++){
            nums.push_back(nums1[i]);
        }
        for(int j = 0 ; j < n ; j++){
            nums.push_back(nums2[j]);
        }
        sort(nums.begin() , nums.end());
        int k = nums.size();

        if(k % 2 == 1){
            return nums[k/2];
        }
        else{
            return (nums[k/2 - 1] + nums[k/2]) / 2.0;
        }
        
    }
};