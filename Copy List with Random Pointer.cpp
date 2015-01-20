// solution #1: The first solution that hits my mind. Very slow.
//              It's easy to come up with the solution using a map to map the old and new pointer.
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) 
    {
        if( head == NULL )
            return NULL;
        unordered_map<RandomListNode*,RandomListNode*> m;
        RandomListNode* p = new RandomListNode(head->label);
        p->random = head->random;
        RandomListNode* result = p;
        m[head] = p;
        while( head->next != NULL )
        {
            p->next = new RandomListNode(head->next->label);
            p->next->random = head->next->random;
            m[head->next] = p->next;
            head = head->next;
            p = p->next;
        }
        p = result;
        while( p != NULL )
        {
            p->random = m[p->random];
            p = p->next;
        }
        return result;
    }
};


// solution #2: Without using any extra data structure. 

RandomListNode *copyRandomList(RandomListNode *head) {
    RandomListNode *newHead, *l1, *l2;
    if (head == NULL) 
        return NULL;
    for (l1 = head; l1 != NULL; l1 = l1->next->next) 
    {
        l2 = new RandomListNode(l1->label);
        l2->next = l1->next;
        l1->next = l2;
    }

    newHead = head->next;
    for (l1 = head; l1 != NULL; l1 = l1->next->next) 
    {
        if (l1->random != NULL) 
            l1->next->random = l1->random->next;
    }

    for (l1 = head; l1 != NULL; l1 = l1->next) 
    {
        l2 = l1->next;
        l1->next = l2->next;
        if (l2->next != NULL) 
            l2->next = l2->next->next;
    }

    return newHead;
}
