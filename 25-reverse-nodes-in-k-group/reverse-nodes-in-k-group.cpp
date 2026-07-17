/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLinkedList(ListNode* temp){
        
        ListNode* back = nullptr ;

        while(temp){
            ListNode* front = temp->next ;
            temp->next = back;

            //move each pointers
            back = temp ;
            temp  = front ;
        }
        return back;
    }

    ListNode* getKthNode(ListNode* temp , int k ){
        k--;
        while(temp && k>0){
            k--;
            temp = temp->next;
        }
        return temp ;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head; 
        ListNode* prev = nullptr;

        while(temp){
            //find the kth element 
            ListNode* kthNode = getKthNode(temp , k);
            if(kthNode == nullptr){
                if(prev)  prev->next = temp;
                break;
            }

            //once you get the kth node -> save its next node and break the connectopn 
            ListNode* next_node = kthNode->next ;
            kthNode->next = nullptr;

            //now send the available list into reverse function 
            reverseLinkedList(temp);
            // in return we will get kth node as a head of this reversed ll 
            if(temp == head){
                head = kthNode;
            }
            else{
                prev->next = kthNode;
            }

            prev = temp ;
            temp = next_node;
        }
        return head;
    }
};