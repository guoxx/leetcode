/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *_merge(ListNode *l1, ListNode *l2){
    if(l1 != NULL && l2 != NULL){
        ListNode *n = NULL;
        if(l1->val <= l2->val){
            n = l1;
            ListNode *tmp = n->next;
            n->next = _merge(tmp, l2);
        }
        else{
            n = l2;
            ListNode *tmp = n->next;
            n->next = _merge(l1, tmp);
        }
    }
    else if(l1 == NULL){
        return l2;
    }
    else if(l2 == NULL){
        return l1;
    }
    else{
        return NULL;
    }
}

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        return _merge(l1, l2)
        
    }
};