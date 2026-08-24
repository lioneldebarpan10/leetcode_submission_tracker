/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findmaxPathSum(TreeNode* root , int &maxi){
        // if root is null then sum is 0
        if(root == NULL) return 0;
        // calculate maximum path sum of right and left sub tress
        int leftpathsum = max(0, findmaxPathSum(root->left , maxi));
        int rightpathsum = max(0, findmaxPathSum(root->right , maxi));
        // maxi = max value of left + max value of right + current node value
        maxi = max(maxi , leftpathsum + rightpathsum + root->val);
        // Return the maximum sum considering
        // only one branch (either left or right)
        // along with the current node
        return max(leftpathsum , rightpathsum) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN; //initialize maxi as minimum possible integer value
        findmaxPathSum(root , maxi); // call the recursive function to find maximum path sum
        return maxi; // maximum path sum
    }
};