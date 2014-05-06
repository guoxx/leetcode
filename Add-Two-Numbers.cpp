// You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
void _add_x(ListNode *node, int x){
    if(node == NULL || x <= 0){
        return;
    }

    node->val = node->val + x;
    int inc = 0;
    while(node->val >= 10){
        node->val = node->val - 10;
        inc = inc + 1;
    }

    if(inc > 0){
        ListNode *next = NULL;
        if(node->next == NULL){
            ListNode *tmp = (ListNode*)malloc(sizeof(ListNode));
            tmp->val = 0;
            tmp->next = NULL;
            node->next = tmp;            
        }
        next = node->next;
        _add_x(next, inc);
    }
 }
 
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *pre1 = l1;
        ListNode *idx1 = l1;
        ListNode *idx2 = l2;
        int inc = 0;
        while(true){
            if(idx1 == NULL && idx2 == NULL){
                break;
            }
            else if(idx1 == NULL && idx2 != NULL){
                // idx2->val = idx2->val;
                pre1->next = idx2;
                break;
            }
            else if(idx1 != NULL && idx2 == NULL){
                // idx1->val = idx1->val;
                break;
            }
            else{
                _add_x(idx1, idx2->val);
                pre1 = idx1;
                idx1 = idx1->next;
                idx2 = idx2->next;
            }
        }
        return l1;
    }
};