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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* tail = head ;
        ListNode* new_tail = head ;

        //base case 
        if(head == nullptr || head->next == nullptr || k==0 ) return head;

        int length = 1; 
        while(tail->next){
            tail = tail->next ;
            length++;
        }

        // fincd modulus of the k 
        k = k % length;

        if(k==0) return head ;

        //otherwise make linked list as circular linked list 
        tail->next = head ;

        // find new tail
        for(int i = 1 ; i < length -k ; i++){
            new_tail = new_tail->next;
        }

        //remove the connections 
        head = new_tail->next ;
        new_tail->next = nullptr; 

        //return new head 
        return head;
    }
};