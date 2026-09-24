class Solution {
public:
    vector<vector<int>> result;
    // function to generate permutations
    void permutation(vector<int>& nums , int  i ,int n){
        if(i == n){ // fixed position -> add current permutations
            result.push_back(nums);
            return;
        }
        for(int j = i ; j <= n ; j++){
            swap(nums[i] , nums[j]); // Choose: swap element at i with j
            permutation(nums , i + 1 , n); // Explore: recurse for next position
            swap(nums[i] , nums[j]); // backtrack: return to original position
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // Start backtracking from index 0 to last index
        permutation(nums , 0 , nums.size() - 1);
        return result; // all collected permutations
    }
};