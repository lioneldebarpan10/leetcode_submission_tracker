class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double max_avg = -DBL_MAX;
        double avrg = 0.0 , sum = 0.0;

        int left = 0;
        for(int right = 0 ; right < n ; right++){
            sum += nums[right];
            if((right - left + 1) == k){    

                avrg = sum / k;
                max_avg = max(max_avg , avrg);

                sum -= nums[left];
                left++;
            }   
        }
        return max_avg;
    }
};