/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node* , Node*> OldtoNew; // map for old to new mapping 
        // avoid recreating visited node and infinite loop
        return dfs(node , OldtoNew);
    }
    Node* dfs(Node* node, map<Node* , Node*>& OldtoNew){
        // if node is null then return null
        if(node == NULL){
            return NULL;
        }
        // if node already exists in hashmap then return it
        // prevents infinite recursion in cyclic graphs
        if(OldtoNew.count(node)){
            return OldtoNew[node];
        }
        // create a copy node to store original value of graph
        // store the mapping in the oldtonew map
        Node* copy = new Node(node->val);
        OldtoNew[node] = copy;
        // iterates all neighbors of current node
        // copy of all neightbors of current node using dfs 
        // Append the cloned neighbors to the copy’s neighbors list
        for(Node* nei : node->neighbors){
            copy->neighbors.push_back(dfs(nei , OldtoNew));
        }
        return copy; // return copy of the created list
    }
};