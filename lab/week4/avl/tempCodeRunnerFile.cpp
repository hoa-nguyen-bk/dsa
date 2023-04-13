 bool AVLInsert(Node *&root, const T &data, bool &taller)
  {
    // pLeft, pRight, data
    // **return: tree get higher?
    if (root == NULL)
    {
      root = new Node(data);
      taller = true;
      return true;
    }
    else if (data < root->data)
    {
      root->pLeft = AVLInsert(root->pLeft, data, taller);
      // left subtree is taller
      if (taller)
      {
        if(root->balance==LH){

        }
      }
    }
    else
    {
      return insert(root->pLeft, data);
    }
  }
  void insert(const T &value)
  {
    // TODO
    bool taller = false;
    AVLInsert(this->root, value, taller);
  }
