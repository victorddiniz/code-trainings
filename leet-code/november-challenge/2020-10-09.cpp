/**
 * Because it is the absolute difference, we need to compare our root value
 * with the maximum and minimum values in the subtrees. With that information at hand,
 * and also remembering which was the best difference we have seen until current node,
 * it is easy to get the answer based on the best difference and the absolute difference
 * of current node and min and max value of subtrees.
 */

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
    pair<int, pair<int, int> > processTree(TreeNode* root) {
        int maxDiffInTree = 0;
        int maxValueInTree = root->val;
        int minValueInTree = root->val;
        
        if (root->left != NULL) {
            pair<int, pair<int, int>> leftResult = processTree(root->left);
            int subTreeMinValue = leftResult.second.first;
            int subTreeMaxValue = leftResult.second.second;
            int subTreeMaxDiff = leftResult.first;
            maxDiffInTree = max(subTreeMaxDiff, max(maxDiffInTree, max(abs(root->val - subTreeMinValue), abs(root->val - subTreeMaxValue))));
            maxValueInTree = max(maxValueInTree, subTreeMaxValue);
            minValueInTree = min(minValueInTree, subTreeMinValue);
        }
        
        if (root->right != NULL) {
            pair<int, pair<int, int>> rightResult = processTree(root->right);
            int subTreeMinValue = rightResult.second.first;
            int subTreeMaxValue = rightResult.second.second;
            int subTreeMaxDiff = rightResult.first;
            maxDiffInTree = max(subTreeMaxDiff, max(maxDiffInTree, max(abs(root->val - subTreeMinValue), abs(root->val - subTreeMaxValue))));
            maxValueInTree = max(maxValueInTree, subTreeMaxValue);
            minValueInTree = min(minValueInTree, subTreeMinValue);
        }
        
        return make_pair(maxDiffInTree, make_pair(minValueInTree, maxValueInTree));
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        pair<int, pair<int, int> > result = processTree(root);
        return result.first;
    }
};