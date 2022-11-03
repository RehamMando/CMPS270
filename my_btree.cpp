#include <iostream>  
using namespace std;

template <typename T>
struct treeNode {
       T* data;
       struct treeNode* left;
       struct treeNode* right;

       treeNode(T value) {
            data = value;
            left = right = NULL;
       }

    // Specifications:
    //    requires: a value of generic type representing the data inside a node , the root node of the binary tree
    //    effects: inserting the node into the tree

    //    TestCases:
    //    1)any type of value should be accepted
    //    2)null tree will create a new one
    //    3) not empty tree should insert the node in the tree
       template<typename T>
       void insert(T value, treeNode<T>*& root) {
            if (root == NULL) {
                root = new treeNode<T>;
                root->data = value;
                root->left = NULL;
                root->right = NULL;
                return;
            }
            std::queue(treeNode <T> *) q;
            q.push(root);
            while (!q.empty()) {
                treeNode <T>* temp = q.fromt();
                q.pop;
                if (temp->left != NULL) {
                    q.push(temp->left);
                }
                else {
                    insert(data, temp->left);
                    break;
                }
                if (temp->right != NULL) {
                    q.push(temp->right);
                }
                else {
                    insert(data, temp->right);
                    break;
                }
            }
       }

       
    // Specifications:
    //    requires: a value of generic type representing the data inside a node
    //    effects: inserting the node in the highest possible level
    // TestCases:
    //    1)any type of value should be accepted
    //    2)null tree will create a new one 
    //    3) not empty tree should insert the node in the highest level
        template<typename T>
        void InsertminHeight(T value) {
            struct treeNode* node, * temp;

            node->data = value;
            node->left = NULL;
            node->right = NULL;
            if (root == NULL) {
                root = new treeNode<T>;
            }
            else {
                temp = minHeight(st);
                temp->left = new TreeNode(value);
            }
        }

        
    //    Specifications:
    //    requires: a node of type TreeNode
    //    effects: returns the node that have the lowest height
        template<typename T>
        treeNode* minHeight(struct treeNode node) {
            if (node->left == NULL && node->right == NULL) {
                return node;
            }
            else {
                minHeight(root->left);
                minHeight(root->right);
            }
        }

   
    //    Specifications:
    //    requires: a node of type treeNode with no children
    //    effects: delete the node only if it has no children
    //    TestCases:
    //    1)any type of value should be accepted
    //    2)leaf node  should be deleted
    //    3) not leaf node should print that it can not be printed
        template<typename T>
        void DeleteNode(struct treeNode* node) {
            if (node->left == NULL && node->right == NULL) {
                node == NULL
            }
            else {
                std::cout << "CANNOT DELETE NODE";
            }
        }

    //    Specifications:
    //    requires: the root node of the binary tree
    //    effects: returns the number of nodes in the tree
    //    TestCases:
    //    1) null tree should return size 0
    //    2) non-empty tree should return its size
       template<typename T>
       int treeSize(treeNode* root) {
            if (root == nullptr) {
                return 0;
            }// If null return 0
            // Recursively Call for left subtree and right subtree
            return 1 + treeSize(root->left) + treeSize(root->left);
        }

       
    //    Specifications:
    //    requires: a node of a binary tree which is the root of the subtree
    //    effects: the size of the subtree
    //    TestCases:
    //    1) null subtree should return size 0
    //    2) non-empty subtree should return its size
        template<typename T>
        int subtreeSize(struct treeNode* node) {
            return treeSize(node);
        }

    
        // Specifications:
        // requires: the root node of the binary tree
        // effects: prints the tree in postorder format
        // Testcases:
        // 1) null tree will return nothing
        // 2) non-empty tree should be printed

        template<typename T>
        void postOrderPrint(struct treeNode* root) {
            if (root != nullptr) {
                postOrderPrint(root->left);
                postOrderPrint(root->right);
                std::cout << " " << root->data;
            }
        }

       
    //    Specifications:
    //    requires:the root node of the binary tree
    //    effects: prints the tree in preorder format
    //    Testcases:
    //    1) null tree will return nothing
    //    2) non-empty tree should be printed
        template<typename T>
        void preOrderPrint(struct treeNode* root) {
            if (root != nullptr) {
                std::cout << " " << root->data;
                preOrderPrint(root->left);
                preOrderPrint(root->right);
            }
        }
       
    //    Specifications:
    //    requires:the root node of the binary tree
    //    effects: prints the tree in inorder format
    //    Testcases:
    //    1) null tree will return nothing
    //    2) non-empty tree should be printed
       template<typename T>
       void inOrderPrint(struct treeNode* root) {
             if (root != nullptr) {

                    inOrderPrint(root->left);
                    std::cout << " " << root->data;
                    inOrderPrint(root->right);
             }
       }


    int main() {
        treeNode* root = insert(1);
        root->left = insert(11);
        root->left->left = insert(7);
        root->right = insert(9);
        root->right->left = insert(15);
        root->right->right = insert(8);
        preOrderPrint(root);
        delete(root);
        return 0;
    }
};
