// Solution #1: Recursive Merge Sort!
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode* merge(ListNode* l1,ListNode* l2)
    {
        if( l1 == NULL )
            return l2;
        if( l2 == NULL )
            return l1;
        if( l1->val < l2->val )
        {
            l1->next = merge(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next = merge(l1,l2->next);
            return l2;
        }
    }
    ListNode *sortList(ListNode *head) 
    {
        if( head == NULL )
            return NULL;
        if( head->next == NULL )
            return head;
        ListNode* l1 = head;
        ListNode* l2 = head->next;
        while(l2!=NULL && l2->next!=NULL)
        {
            l1 = l1->next;
            l2 = l2->next->next;
        }
        ListNode* tmp = l1->next;
        l1->next = NULL;
        return merge(sortList(head),sortList(tmp));
    }
};
