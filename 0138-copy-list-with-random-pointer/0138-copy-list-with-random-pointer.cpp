/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        // Map to store mapping from Old Node -> New Node
        unordered_map<Node*, Node*> m;

        // Create the new head and store its mapping
        Node* newHead = new Node(head->val);
        m[head] = newHead;

        Node* oldTemp = head->next;
        Node* newTemp = newHead;

        // First Pass: Plain way to copy our linked list structure using next pointers
        while (oldTemp != NULL) {
            Node* copyNode = new Node(oldTemp->val);
            m[oldTemp] = copyNode; // Store mapping

            newTemp->next = copyNode;
            
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        // Reset pointers to the start for the second pass
        oldTemp = head; 
        newTemp = newHead;

        // Second Pass: Connect the random pointers using our map
        while (oldTemp != NULL) {
            // m[oldTemp->random] gives the corresponding cloned node
            newTemp->random = m[oldTemp->random];

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};
