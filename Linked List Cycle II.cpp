/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 // It's sorry that this solution uses extra space.
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        if( NULL == head || NULL == head->next )
            return NULL;
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        while( p1 != p2 && p1 != NULL && p2 != NULL )
        {
            p1 = p1->next;
            p2 = p2->next == NULL ? p2->next : p2->next->next;
        }
        if( p1 == NULL || p2 == NULL )
            return NULL;
        
        ListNode* head2 = p1->next;
        
        // break the cycle!
        p1->next = NULL;
        
        // p1->old head
        // p2->new head
        p1 = head;
        p2 = head2;
        
        // a a a a
        //         b b b b b
        //     c c 
        while( p1 != p2 )
        {
            if( p1 == NULL )
                p1 = head2;
            else
                p1 = p1->next;
                
            if( p2 == NULL )
                p2 = head;
            else
                p2 = p2->next;
        }
        return p1;
    }
};
