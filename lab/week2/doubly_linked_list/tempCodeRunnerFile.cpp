    if (this->head != nullptr)
    {
      cout << "please do not here" << endl;

      head->previous = newNode;
    }
    head = newNode;
    this->count++;
    return;