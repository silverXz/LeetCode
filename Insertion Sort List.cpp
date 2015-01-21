//Solution #1:
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
    ListNode *insertionSortList(ListNode *head) 
    {
        if( head == NULL )
            return NULL;
        if( head->next == NULL )
            return head;
        ListNode* p = head;
        stack<ListNode*> s;
        while(p!=NULL)
        {
            s.push(p);
            p = p->next;
        }
        s.pop();
        while(!s.empty())
        {
            p = s.top();
            s.pop();
            ListNode* q = p;
            while( q->next != NULL && p->val > q->next->val )
                q = q->next;
            if( q == p )
                continue;
            
            // p shoud insert after q.
            ListNode* tmp = p->next;
            
            //whether p is the head node or not.
            if( !s.empty() )
                s.top()->next = tmp;
            p->next = q->next;
            q->next = p;
            p = tmp;
            //
        }
        return p;
    }
};
