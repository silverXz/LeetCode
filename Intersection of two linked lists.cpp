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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if( headA == 0 || headB == 0 )
            return 0;
        ListNode* pA = headA;
        ListNode* pB = headB;
        int lenA = 0,lenB = 0;
        while( pA != 0 )
        {
            lenA++;
            pA = pA->next;
        }
        
        while( pB != 0 )
        {
            lenB++;
            pB = pB->next;
        }
        
        // make pB point to the longer one
        if( lenA > lenB )
        {
            int lenTmp = lenA;
            lenA = lenB;
            lenB = lenTmp;
            pB = headA;
            pA = headB;
        }
        else
        {
            pA = headA;
            pB = headB;
        }
        
        for(int i = 0 ; i < lenB - lenA  ; i++ )
            pB = pB->next;
            
        while( pB != 0 )
        {
            if( pB == pA )
                return pB;
            else
            {
                pB = pB->next;
                pA = pA->next;
            }
        }
        return pB;
    }
};
