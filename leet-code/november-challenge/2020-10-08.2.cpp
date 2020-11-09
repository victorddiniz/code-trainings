// To Solve this problem, we can use recursion as a way to keep track of the sum of the child trees.
// With their sun, can tilt the current node and pass the sum to the parent by returning the function.

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
private:
    int transformToTiltTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            int sumOfLeft = transformToTiltTree(root->left);
            int sumOfRight = transformToTiltTree(root->right);
            int value = root->val;
            root->val = abs(sumOfLeft - sumOfRight);
            return value + sumOfLeft + sumOfRight;
        }
    }
    int sumOfTiltTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            return root->val + sumOfTiltTree(root->left) + sumOfTiltTree(root->right);
        }
    }
public:
    int findTilt(TreeNode* root) {
        transformToTiltTree(root);
        return sumOfTiltTree(root);
    }
};