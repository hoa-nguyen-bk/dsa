 int recursiveSumOfLeafs(Node *node)
  {
    if (node == nullptr)
      return 0;
    if (node->pLeft == nullptr && node->pRight == nullptr)
      return node->value;
    return recursiveSumOfLeafs(node->pLeft) + recursiveSumOfLeafs(node->pRight);
  }
  int sumOfLeafs()
  {
    // TODO
    return recursiveSumOfLeafs(this->root);
  }