
  int recursiveHeight(Node *temp)
  {
    if (temp == nullptr)
      return 0;
    return max(recursiveHeight(temp->pLeft), recursiveHeight(temp->pRight)) + 1;
  }
  int getHeight()
  {
    // TODO: return height of the binary tree.
    return recursiveHeight(this->root);
  }
  string recursivePreOrder(Node *temp)
  {
    if (temp == nullptr)
      return "";

    stringstream ss;
    ss << temp->value << " ";
    ss << recursivePreOrder(temp->pLeft);
    ss << recursivePreOrder(temp->pRight);
    return ss.str();
  }
  string preOrder()
  {
    // TODO: return the sequence of values of nodes in pre-order.
    return recursivePreOrder(this->root);
  }
  string recursiveInOrder(Node *temp)
  {
    if (temp == nullptr)
      return "";

    stringstream ss;
    ss << recursiveInOrder(temp->pLeft);
    ss << temp->value << " ";
    ss << recursiveInOrder(temp->pRight);
    return ss.str();
  }
  string inOrder()
  {
    // TODO: return the sequence of values of nodes in in-order.
    return recursiveInOrder(this->root);
  }
  string recursivePostOrder(Node *temp)
  {
    if (temp == nullptr)
      return "";

    stringstream ss;
    ss << recursivePostOrder(temp->pLeft);
    ss << recursivePostOrder(temp->pRight);
    ss << temp->value << " ";
    return ss.str();
  }
  string postOrder()
  {
    // TODO: return the sequence of values of nodes in post-order.
    return recursivePostOrder(this->root);
  }
