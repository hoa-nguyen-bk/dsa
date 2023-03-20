LLNode* addLinkedList(LLNode* l0, LLNode* l1) {
    // STUDENT ANSWER
    int carry = 0;
    LLNode* result = nullptr;
    LLNode* tail = nullptr;

    while (l0 != nullptr || l1 != nullptr || carry != 0) {
        int sum = carry;
        if (l0 != nullptr) {
            sum += l0->val;
            l0 = l0->next;
        }
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }

        carry = sum / 10;
        sum %= 10;
        LLNode* node = new LLNode(sum, nullptr);

        if (result == nullptr) {
            result = node;
        } else {
            tail->next = node;
        }
        tail = node;
    }

    return result;
}