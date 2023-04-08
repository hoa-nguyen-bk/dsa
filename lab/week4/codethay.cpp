void longestPathSum(BTNode* root, int & sum, int len) {
    if (root == NULL) {
        sum = len = 0;
    }
    else {
        int sumL, lenL, sumR, lenR;
        longestPathSum(root->left, sumL, lenL);
        longestPathSum(root->right, sumR, lenR);

        if (lenL > lenR) {
            sum = sumL + root->val;
            len = lenL + 1;
        }
        else if (lenL < lenR) {
            sum = sumR + root->val;
            len = lenR + 1;
        }
        else {
            sum = max(sumL, sumR) + root->val;
            len = lenL + 1;
        }
    }
} 

int longestPathSum(BTNode* root) {
    int sum, len;
    longestPathSum(root, sum, len);
    return sum;
}

//Helping functions
void rotL(Node * & root) {

}
void rotR(Node * & root) {

}
bool balanceLeft(Node * & root) {

}
bool balanceRight(Node * & root) {
    if (root->balance == EH) {
        root->balance = RH;
        return true;
    }
    else if (root->balance == LH) {
        root->balance = EH;
        return false;
    }
    else {// RH - imbalanced
        if (root->pRight->balance == RH) {
            // R of R
            rotL(root);
            
            root->balance = EH; root->pLeft->balance = EH;
            
            return false;
        }
        else if (root->pRight->balance == LH) {
            rotR(root->pRight); rotL(root);

            if (root->balance == EH) {
                root->pLeft->balance = root->pRight->balance = EH;
            }
            else if (root->balance == LH) {
                root->pLeft->balance = EH; root->pRight->balance = RH;
            }
            else {
                root->pLeft->balance = LH; root->pRight->balance = EH;
            }
            root->balance = EH;

            return false;
        }
    }
}
bool insert(Node * & root, const T & data) {
    // pLeft, pRight, data
    // **return: tree get higher?
    if (root == NULL) {
        root = new Node(data);
        return true;
    }
    else if (data >= root->data) {
        if (insert(root->pRight, data)) {
            return balanceRight(root);
        }
        else {
            return false;
        }
    }
    else {
        return insert(root->pLeft, data);
    }
}

void insert(const T &value){
    //TODO
    
}



class ShellSort{
private:
    int * increments;
    int lenOfIncr;

public:
    ShellSort(int *increments, int lengthOfIncrements) {
        this->lenOfIncr = lengthOfIncrements;
        this->increments = new int[lengthOfIncrements];
        for (int i = 0; i < lenOfIncr; ++i) {
            this->increments[i] = increments[i];
        }
    }
    ~ShellSort() {
        delete [] increments;
    }

    static void sortSegment(Complex *list, int length, int increment, int segment = 0) {
        if (length <= 1) {
            return;
        }
        for (int curIdx = segment + increment; curIdx < length; curIdx += increment) {
            Complex temp = list[curIdx];
            int step = curIdx - increment;
            while (step >= 0 && list[step] > temp) {
                list[step + increment] = list[step];
                step -= increment;
            }
            list[step + increment] = temp;
        }
    }

    void sort(Complex *list, int length) {
        for (int i = 0; i < lenOfIncr; ++i) {
            int k = this->increments[i];
            for (int segment = 0; segment < k; ++segment) {
                ShellSort::sortSegment(list, length, k, segment);
            }
        }
    }
};


//Helping functions

void add(Node * & root, const T & value) {
    // pLeft, pRight, value
    if (root == NULL) {
        root = new Node(value);
    }
    else if (value <= root->value) {
        add(root->pLeft, value);
    }
    else {
        add(root->pRight, value);
    }
}

void add(T value){
    //TODO
    add(this->root, value);
}

bool remove(Node * & root, const T & value) {
    if (root == NULL) {
        return false;
    }
    if (value < root->value) {
        return remove(root->pLeft, value);
    }
    else if (value > root->value) {
        return remove(root->pRight, value);
    }
    else {
        if (root->pLeft == NULL && root->pRight == NULL) {
            delete root;
            root = NULL;
            return true;
        }
        else if (root->pLeft == NULL) {
            Node * temp = root;
            root = root->pRight;
            delete temp;
            return true;
        }
        else if (root->pRight == NULL) {
            Node * temp = root;
            root = root->pLeft;
            delete temp;
            return true;
        }
        else {
            Node * minRight = root->pRight;
            while (minRight->pLeft != NULL) {
                minRight = minRight->pLeft;
            }
            root->value = minRight->value;

            return remove(root->pRight, minRight->value);
        }
    }
}

void deleteNode(T value){
    //TODO
    remove(this->root, value);
}