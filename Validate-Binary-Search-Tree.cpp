/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 int _isValidBST( TreeNode *root,
                int min,
                int max,
                int lessConstrained,
                int greatConstrained) {
    
    if(root == NULL)
        return 1;
    
    int nval = root->val;
    int isValid = 1;
    if(isValid && lessConstrained){
        isValid = nval < max;
    }
    if(isValid && greatConstrained){
        isValid = nval > min;
    }

    if(isValid && root->left != NULL){
        int lval = root->left->val;
        isValid = nval > lval;
        
        if(isValid){
            isValid = _isValidBST(root->left, min, nval, 1, greatConstrained);
        }
    }
    
    if(isValid && root->right != NULL){
        int rval = root->right->val;
        isValid = rval > nval;
        
        if(isValid){
            isValid = _isValidBST(root->right, nval, max, lessConstrained, 1);
        }
    }
    
    return isValid;
}
 
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if(root == NULL)
            return true;
        return _isValidBST(root, 0, 0, 0, 0);
    }
};
