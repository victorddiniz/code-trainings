/**
 * To solve this question with constante space and recursive,
 * I looked at the next arros in a level 4 tree and I realized
 * if I use connect a literaly what is means - connect these two nodes
 * it is a matter of making the call to this function in the same fashion as the "next" arrows
 * /

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    void connect(Node* root, Node* queue) {
        if (root != NULL) {
            root->next = queue;
            connect(root->left, root->right);
            connect(root->right, queue != NULL ? queue->left : NULL);
        }
    }
public:
    Node* connect(Node* root) {
        connect(root, NULL);
        return root;
    }
};