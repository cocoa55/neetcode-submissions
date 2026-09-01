class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) //if the incoming node is empty, or the next node is empty start unwinding
      return head;

    ListNode* nextItem = head->next; //hold the address of the next node, so we can swap it with old one,
    ListNode* newHead {reverseList(nextItem)}; //store the new head in a function

    head->next = nextItem->next; //modify the head to point at the one after the next item 
    nextItem->next = head; //modify the next node to point at the head

      return newHead; //return the new Head, 
  }
  
};

