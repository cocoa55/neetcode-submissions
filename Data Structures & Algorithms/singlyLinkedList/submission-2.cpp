class ListNode {
public: 
int val;
ListNode* next;

    ListNode(int val) : 
    val{val}, 
    next{nullptr}
    {}
    ListNode(int val, ListNode* next) : 
    val{val},
    next{next}
    {}
};


class LinkedList {

ListNode* _head;
ListNode* _tail;


public:
   LinkedList() 
   {
    _head = new ListNode(-1);
    _tail = _head;
   }

    int get(int index) // we want the index node value,
    {
        ListNode* curr {_head->next}; //create a "current" node, with the next node initialized
        int i = 0;
        while(curr != nullptr) {  //while current isnt pointing to the 
            if(i == index) { 
                return curr->val; 
            }
            i++;
            curr = curr->next;
        }
    
    return -1;
    }
    

    void insertHead(int val) { 
    
    ListNode* newHead = new ListNode(val); 
    newHead->next = _head->next; //new head is pointing to the next head, 
    _head->next = newHead;
        if(newHead->next == nullptr) //if the new head, is pointing to nothing (i.e its the tail )
            _tail = newHead;
    }
    
    void insertTail(int val) {
    ListNode* newTail = new ListNode(val); 
    _tail->next = newTail;  //old tail is pointing to new tail
    _tail = newTail;        //tail is pointing to newTail   

    }

    bool remove(int index) { //set next to the next next 
        
        ListNode* curr = _head; //set curr to the dummy node
        int i{0};
        
        while (i < index  && curr != nullptr){ //while i is less than the one we want to remove, and the current isnt a tail
            i++;
            curr = curr->next; //make curr the next node, essentially make curr the node before the one we want to delete.
        }
        //remove the node ahead of curr.
        if (curr != nullptr && curr->next != nullptr) //before we delete, ensure both of them arent tails, because if one is, we are outside of bounds
        {
            if(curr->next == _tail) //if the node ahead of curr is the tail
                _tail = curr; //set the list tail to curr, as the one ahead will be gone.
            ListNode* toDelete = curr->next; //note the address of the node to delete
            curr->next = curr->next->next; //reseat curr, which is pointed to the node after the one we want to delete, to the node after it (the check at the top ensures this is possible.) 
            delete toDelete;
            return true;

        }
      return false;
    }

    vector<int> getValues() {
        vector<int> values; //to return
        ListNode* curr = _head->next; //non-dummy head (has a value)
        
        while(curr != nullptr) {
        values.push_back(curr->val); 
        curr = curr->next; //set to next node,
        }
        return values;
    }
};


