// Solution #1 : Recursive algorithm using unordered_map to help. Very Straght forward! Not very fast.
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode* node, unordered_map<UndirectedGraphNode*,UndirectedGraphNode*>& m)
    {
        if( m.find(node) != m.end() ) // Already Cloned this Node.
            return m[node];
        UndirectedGraphNode* p = new UndirectedGraphNode(node->label);
        for( int i = 0 ; i < node->neighbors.size() ; i++ )
        {
            if( node->label == node->neighbors[i]->label )  //self cycle.
                p->neighbors.push_back(p);
            else
                p->neighbors.push_back(cloneGraph(node->neighbors[i],m));
        }
        m[node] = p;
        return p;
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) 
    {
        if( node == NULL )
            return NULL;
        unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> m;
        return cloneGraph(node,m);
    }
};
