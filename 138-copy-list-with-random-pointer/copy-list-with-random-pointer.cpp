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
        // edge case
        if (head == nullptr)
            return nullptr;

        Node* temp = head;
        while (temp) {
            // untill temp == nullptr we need to create clone nodes
            Node* clonenode = new Node(temp->val);

            // insert this clone node in between both the nodes
            clonenode->next = temp->next;
            temp->next = clonenode;
            temp = clonenode->next;
        }
        // successfully created a linked list attached with the copy nodes

        // STEP 2: Connect the random pointers of the cloned nodes
        temp = head;
        while (temp != nullptr) {
            // the random of copy of each node == the random next (copy of new
            // similar node)
            if(temp->random != nullptr)
            {temp->next->random = temp->random->next;}

            temp = temp->next->next;
        }
        // succesfully crated a list with copy // having random pointers

        // STEP 3: Untangle the lists
        temp = head;
        Node* clonehead = head->next;
        Node* clonetemp = clonehead;

        while (temp) {
            temp->next = clonetemp->next;
            if (clonetemp->next != nullptr) {
                clonetemp->next = clonetemp->next->next; // = temp->next->next
            }

            clonetemp = clonetemp->next;
            temp = temp->next;
        }
        return clonehead;
    }
};