/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
static TreeNode*
_build_tree(vector<int> inorder,
            vector<int> postorder,
            int post_start, int post_end,
            int in_start, int in_end){
    if(post_end - post_start < 0){
        return NULL;
    }

    TreeNode *node = (TreeNode*)malloc(sizeof(*node));
    node->val = postorder[post_end];

    int in_idx = in_start;
    for(int i = in_start; i <= in_end; ++i){
        if(inorder[i] == node->val){
            in_idx = i;
        }
    }

    int post_idx = post_start + (in_idx - in_start) - 1;
    node->left = _build_tree(inorder, postorder, post_start, post_idx, in_start, in_idx - 1);
    node->right = _build_tree(inorder, postorder, post_idx + 1, post_end - 1, in_idx + 1, in_end);
    return node;
}
 
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size() == 0)
            return NULL;
        else
            return _build_tree(inorder, postorder, 0, (int)postorder.size() - 1, 0, (int)inorder.size() - 1);
    }
};
