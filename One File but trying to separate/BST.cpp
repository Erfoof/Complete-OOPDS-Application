    #include "BST.h"
    //----------------------------BST:
    //Constructor
    BST::BST() { root = nullptr; Dstype = "bst"; }


    string BST::gettype() {
        return Dstype;
    };

    //returns the node.
    BSTNode* BST::BSTgetRoot() { return root; }

    //used internally by the BSTaddItem method
    BSTNode* BST::insert(BSTNode* node, int value) {
        if (node == nullptr) {
            return new BSTNode(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        }
        else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    //add value to the BST
    void BST::BSTaddItem(int value) {
        root = insert(root, value);
    }


    //only used internally by the delete item method
    BSTNode* BST::deleteNode(BSTNode* node, int value) {
        if (node == nullptr) {
            return node;
        }
        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        }
        else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        }
        else {
            if (node->left == nullptr) {
                BSTNode* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                BSTNode* temp = node->left;
                delete node;
                return temp;
            }
            BSTNode* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    //delete an item
    void BST::BSTdeleteItem(int value) {
        root = deleteNode(root, value);
    }

    //only used internally
    BSTNode* BST::minValueNode(BSTNode* node) {
        BSTNode* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    void BST::BSTinorder(BSTNode* node) {
        if (node != nullptr) {
            BSTinorder(node->left);
            cout << node->data << " ";
            BSTinorder(node->right);
        }
    }

    void BST::BSTpostorder(BSTNode* node) {
        if (node != nullptr) {
            BSTpostorder(node->left);
            BSTpostorder(node->right);
            cout << node->data << " ";
        }
    }

    void BST::BSTpreorder(BSTNode* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            BSTpreorder(node->left);
            BSTpreorder(node->right);
        }
    }

    void BST::print() {
        BSTinorder(root);
    }


    void BST::sort_ascend() {
        BSTinorder(root);
        cout << endl;
    }
    void BST::sort_descend() {
        BSTpostorder(root);
        cout << endl;
    }


    BST::BST(const BST& other) {
        root = nullptr;
        Dstype = other.Dstype;
        root = copyTree(other.root);
    }

    //helper method. Used by the copy constructor
    BSTNode* BST::copyTree(BSTNode* node) {
        if (node == nullptr) {
            return nullptr;
        }
        BSTNode* newNode = new BSTNode(node->data);
        newNode->left = copyTree(node->left);
        newNode->right = copyTree(node->right);
        return newNode;
    }






    //returns true if found, otherwise returns false.
     //It iterates through the tree using a while loop and moves to the left or right --
     //child based on the comparison of the search key with the current node's value.
    bool BST::search(int value) {
        BSTNode* current = root;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            if (current->data < value) {
                current = current->right;
            }
            else {
                current = current->left;
            }
        }
        return false;
    }

    BST ::  ~BST() {
        root = deleteTree(root);
    }

    //used internally only to delete tree.
    BSTNode* BST::deleteTree(BSTNode* node) {
        if (node == nullptr) {
            return nullptr;
        }
        node->left = deleteTree(node->left);
        node->right = deleteTree(node->right);
        delete node;
        return nullptr;
    }

