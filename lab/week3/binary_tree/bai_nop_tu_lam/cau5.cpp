void BFS()
{
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* current = q.front();
        cout << current->value << " ";
        q.pop();

        if (current->pLeft != nullptr)
            q.push(current->pLeft);
        if (current->pRight != nullptr)
            q.push(current->pRight);
    }
}