// STUDENT ANSWER BEGIN
// You can define other functions here to help you.

bool find(T i) {
    Node* current = root;
    while (current != nullptr) {
        if (i == current->value) {
            return true;
        } else if (i < current->value) {
            current = current->pLeft;
        } else {
            current = current->pRight;
        }
    }
    return false;
}


T sum(T l, T r)
  {
    return sumRec(root, l, r);
  }

  T sumRec(Node *node, T l, T r)
  {
    if (node == nullptr)
    {
      return 0;
    }

    T result = 0;

    if (node->value >= l && node->value <= r)
    {
      result += node->value;
    }

    if (node->value > l)
    {
      result += sumRec(node->pLeft, l, r);
    }

    if (node->value < r)
    {
      result += sumRec(node->pRight, l, r);
    }

    return result;
  }


// STUDENT ANSWER END