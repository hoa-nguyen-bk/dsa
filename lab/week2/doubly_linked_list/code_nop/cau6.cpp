ListNode* reverse(ListNode* head, int a, int b) {
    if (!head) return nullptr;
    if (a == b) return head;

     ListNode* prev_a = nullptr;
    ListNode* node_a = head;
    for (int i = 1; i < a; i++) {
        prev_a = node_a;
        node_a = node_a->right;
    }
    ListNode* prev = prev_a;
    ListNode* curr = node_a;
    ListNode* next = nullptr;
    for (int i = a; i <= b; i++) {
        next = curr->right;
        curr->right = prev;
        curr->left = next;
        prev = curr;
        curr = next;
    }
    if (prev_a != nullptr) {
        prev_a->right = prev;
    } else {
        head = prev;
    }
    node_a->right = curr;
    if (curr != nullptr) {
        curr->left = node_a;
    }
    return head;
}
