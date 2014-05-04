/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void _connect(TreeLinkNode *node)
    {
        if(node == NULL)
        {
            return;
        }

        if(node->left == NULL)
        {
            if(node->right != NULL){
            if(node->next != NULL)
            {
                node->left->next = node->next->left ? node->next->left : node->next->right;
            }
            else
            {
                node->left->next = NULL;
            }
            _connect(node->right);
            }
        }
        else if(node->right == NULL)
        {
            if(node->next != NULL)
            {
                node->left->next = node->next->left ? node->next->left : node->next->right;
            }
            else
            {
                node->left->next = NULL;
            }
            _connect(node->left);
        }
        else
        {
            node->left->next = node->right;
            if(node->next != NULL){
                node->right->next = node->next->left ? node->next->left : node->next->right;                
            }
            else{
                node->right->next = NULL;
            }
            _connect(node->left);
            _connect(node->right);
        }
    }

    void connect(TreeLinkNode *root) {
        _connect(root);
    }
};