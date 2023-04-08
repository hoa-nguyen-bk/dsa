void add(T value)
  {
    root = addRec(root, value);
  }

  Node *addRec(Node *node, T value)
  {
    if (node == nullptr)
    {
      node = new Node(value);
    }
    else if (value <= node->value)
    {
      node->pLeft = addRec(node->pLeft, value);
    }
    else
    {
      node->pRight = addRec(node->pRight, value);
    }
    return node;
  }

  void deleteNode(T value)
  {
    root = deleteRec(root, value);
  }

  Node *deleteRec(Node *node, T value)
  {
    if (node == nullptr)
    {
      return nullptr;
    }
    if (value < node->value)
    {
      node->pLeft = deleteRec(node->pLeft, value);
    }
    else if (value > node->value)
    {
      node->pRight = deleteRec(node->pRight, value);
    }
    else
    {
      // Case 1: No child or one child
      if (node->pLeft == nullptr)
      {
        Node *temp = node->pRight;
        delete node;
        return temp;
      }
      else if (node->pRight == nullptr)
      {
        Node *temp = node->pLeft;
        delete node;
        return temp;
      }

      // Case 2: Two children
      Node *temp = minValueNode(node->pRight);
      node->value = temp->value;
      node->pRight = deleteRec(node->pRight, temp->value);
    }
    return node;
  }

  Node *minValueNode(Node *node)
  {
    Node *current = node;
    while (current->pLeft != nullptr)
    {
      current = current->pLeft;
    }
    return current;
  }
