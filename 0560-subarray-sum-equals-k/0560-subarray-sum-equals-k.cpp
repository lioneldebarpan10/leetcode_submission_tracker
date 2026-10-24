class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int prefix = 0 , count = 0;

        unordered_map<int , int> mp;
        for(int i = 0 ; i < n ; i++){
            prefix += nums[i];

            if(prefix == k){
                count++;
            }
            int need = prefix - k;
            if(mp.find(need) != mp.end()){
                count += mp[need];
            }
            mp[prefix]++;
        }
        return count;    
    }
};