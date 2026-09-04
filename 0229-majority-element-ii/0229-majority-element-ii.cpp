class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0;
        int count2 = 0;
        int candidate1 = 0;
        int candidate2 = 0;

        for(int num : nums){
            if(num == candidate1){
                count1++;
            }
            else if(num == candidate2){
                count2++;
            }
            else if(count1 == 0){
                count1 = 1;
                candidate1 = num;
            }
            else if(count2 == 0) {
                count2 = 1;
                candidate2 = num;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1 = 0 , count2 = 0;
        vector<int>ans;
        for(int num : nums){
            if(candidate1 == num){
                count1++;
            }
            else if(candidate2 == num){
                count2++;
            }
        }
        int limit = nums.size() / 3;
        if(count1 > limit){
            ans.push_back(candidate1);
        }
        if(count2 > limit){
            ans.push_back(candidate2);
        }
        return ans;
    }
};