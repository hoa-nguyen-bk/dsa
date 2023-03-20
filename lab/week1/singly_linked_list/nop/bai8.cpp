void LinkedList::partition(int k) {
    if (head == NULL || head->next == NULL) return;

    Node *p = head;
    Node *group1_head = NULL, *group1_tail = NULL;
    Node *group2_head = NULL, *group2_tail = NULL;
    Node *group3_head = NULL, *group3_tail = NULL;

    while (p != NULL) {
        Node *next = p->next;
        if (p->value < k) {
            if (group1_head == NULL) group1_head = p;
            if (group1_tail != NULL) group1_tail->next = p;
            group1_tail = p;
        } else if (p->value == k) {
            if (group2_head == NULL) group2_head = p;
            if (group2_tail != NULL) group2_tail->next = p;
            group2_tail = p;
        } else {
            if (group3_head == NULL) group3_head = p;
            if (group3_tail != NULL) group3_tail->next = p;
            group3_tail = p;
        }
        p = next;
    }

    if (group1_tail != NULL) {
        head = group1_head;
        group1_tail->next = group2_head;
    } else {
        head = group2_head;
    }

    if (group2_tail != NULL) {
        group2_tail->next = group3_head;
        tail = group3_tail;
    } else if (group1_tail != NULL) {
        tail = group1_tail;
    } else {
        tail = group3_tail;
    }
}