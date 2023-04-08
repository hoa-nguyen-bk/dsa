 T getMin()
  {
    if (root == nullptr)
    {
      throw runtime_error("Tree is empty");
    }
    Node *current = root;
    T min = root->value;
    while (current->pLeft != nullptr)
    {
      current = current->pLeft;
      if (min > current->value)
      {
        min = current->value;
      }
    } 
    return current->value;
  }

  T getMax()
  {
    if (root == nullptr)
    {
      throw runtime_error("Tree is empty");
    }
    Node *current = root;
    T max = root->value;
    while (current->pRight != nullptr)
    {
      current = current->pRight;
      if (max < current->value)
      {
        max = current->value;
      }
    }
    return max;
  }