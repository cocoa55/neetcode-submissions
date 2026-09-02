class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    if (!head) 
      return nullptr;

    ListNode* newHead = head; //hold the address of the next node, so we can swap it with old one,
    if(head->next){
        newHead = reverseList(head->next);
        head->next->next = head;
    } //store the new head in a function

    head->next = nullptr;

      return newHead; //return the new Head, 
  }
  
};

