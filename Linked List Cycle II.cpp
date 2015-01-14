// Solution #1: this solution is the most ordinary one. 
// We have a slow and fast pointer, and they will meet at some node in the cycle if there is one.
// Then we break the cycle at the first met node into two lists that will intersect at the node which is the 
// begining of the cycle of the orginal list. So far, the problem becomes finding the first intersected node
// of two intersected list.

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


// Solution #2:
// It's a very smart solution. Still, we have a fast and slow pointer, they will meet at some cycle node. Suppose that
// when they first meet, slow pointer had k steps while the fast one had 2k steps. r is the length of the cycle. So we 
// have 2K-k=nr. so k=nr. Then, suppose there are s steps from the list's head to the first node of the cycle, and there
// are m steps from the first node of the cycle to the first meeting node. we have k = s + m. s = k - m.  s = nr - m. 
// s = (n-1)r + r-m. Let n = 1, we have s = r - m. Suppose we have a pointer p1 starting from the list's head, a pionter 
// p2 from the first meeting node, and they both move one step each time. When p1 meets p2 for the first time, the meeting
// node is the very node we want that is the start node of the cycle.

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
    ListNode *detectCycle(ListNode *head) 
    {
        if( NULL == head || NULL == head->next )
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Find the node where they first meet each other.
        while( NULL != slow && NULL != fast )
        {
            slow = slow->next;
            fast = NULL == fast->next ? fast->next : fast->next->next;
            if( slow == fast )
                break;
        }
        
        // If the fast reaches the NULL, then there's no cycle in the list.
        if( NULL == fast )
            return NULL;
        
        // slow start from the head of the list.
        // fast start from the node where they first meet.
        // where they meet this time is the starting node of the cycle.
        slow = head;
        while( slow != fast )
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
