// Solution 1:
// My dummy solution. I believe there's a better one!

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
    void reorderList(ListNode *head) 
    {
        // If there is no more than 2 nodes, no need to reorder. Return immediately.
        if( NULL == head || NULL == head->next || NULL == head->next->next )
            return;
        
        stack<ListNode*> s;
        ListNode* p1 = head;
        ListNode* p2 = head;
        
        // p2 moves twice faster than p1. so when p2 reaches the end, p1 points to the 
        // middle element of the list.
        while( NULL != p2 )
        {
            p1 = p1->next;
            p2 = NULL == p2->next ? p2->next : p2->next->next;
        }
        
        // starting from the node that p1 is pointing to, pushing all left nodes to the stack
        // for later insertion.
        while( NULL != p1 )
        {
            s.push(p1);
            p1 = p1->next;
        }
        
        // from the head of the list, insert nodes in the stack.
        p1 = head;
        while( !s.empty() )
        {
            p2 = s.top();
            ListNode* tmp = p1->next;
            p1->next = p2;
            p2->next = tmp;
            s.pop();
            p1 = tmp;
        }
        
        // Don't forget to set the tail of the list null.
        p1->next = NULL;
        
        return;
    }
};
