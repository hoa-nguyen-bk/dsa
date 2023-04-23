int countInRange(Node* root, int lowerbound, int upperbound)
{
    if(root==nullptr) return 0;
    if(root->getData() >= upperbound) return 0 + countInRange(root->getLeft(), lowerbound, upperbound);
    if(root->getData() <= lowerbound) return 0 + countInRange(root->getRight(), lowerbound, upperbound);
    return 1 + countInRange(root->getLeft(), lowerbound, upperbound) + countInRange(root->getRight(), lowerbound, upperbound);
}