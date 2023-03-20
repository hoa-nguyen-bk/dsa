LLNode* rotateLinkedList(LLNode* head, int k) {
    // STUDENT ANSWER.
     if (!head || !head->next || k <= 0) {
        return head;
    }
    
    int len = 1;
    LLNode* tail = head;
    while (tail->next) {
        len++;
        tail = tail->next;
    }
    
    k = k % len;
    if (k == 0) {
        return head;
    }
    
    int steps = len - k;
    LLNode* newtail = head;
    for (int i = 1; i < steps; i++) {
        newtail = newtail->next;
    }
    
    LLNode* newhead = newtail->next;
    newtail->next = nullptr;
    tail->next = head;
    
    return newhead;
}