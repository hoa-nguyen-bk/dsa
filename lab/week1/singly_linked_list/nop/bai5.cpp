LLNode* reverseLinkedList(LLNode* head) {
    // STUDENT ANSWER
    LLNode* prev = nullptr;
    LLNode* current = head;
    while (current != nullptr) {
        LLNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}