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
private: void inorder(TreeNode* node , vector<int>& arr){
    if(node == NULL) return;
    inorder(node->left , arr);
    arr.push_back(node->val);
    inorder(node->right , arr);
    return;
}
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>arr;
        inorder(root , arr);
        int kSmallest = arr[k-1];
        return kSmallest;
    }
};