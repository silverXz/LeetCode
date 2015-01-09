// A very simple and clear solution by other

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    ListNode *p1 = headA;
    ListNode *p2 = headB;

    if (p1 == NULL || p2 == NULL) return NULL;

    while (p1 != NULL && p2 != NULL && p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;

        //
        // Any time they collide or reach end together without colliding 
        // then return any one of the pointers.
        //
        if (p1 == p2) return p1;

        //
        // If one of them reaches the end earlier then reuse it 
        // by moving it to the beginning of other list.
        // Once both of them go through reassigning, 
        // they will be equidistant from the collision point.
        //
        if (p1 == NULL) p1 = headB;
        if (p2 == NULL) p2 = headA;
    }

    return p1;
}






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
