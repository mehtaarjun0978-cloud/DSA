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
    ListNode* oddEvenList(ListNode* head) {
         if(head==nullptr || head->next == nullptr)  return head ;

         ListNode *odd =  head;
         ListNode *even =  head->next;
         ListNode *evenhead =  even;         //will be used at the end 

         while( even != nullptr && even->next != nullptr ){
            // connect one odd to other 
            odd->next = even->next ;
            odd = odd->next;
            
            // we make other list of even valo ki 
            even->next = odd->next;
            even = even->next;
         }
         //join both the lists 
         odd->next = evenhead;
         return head;          
    }
};