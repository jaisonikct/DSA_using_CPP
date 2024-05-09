#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

class BinaryTree {
private:
    TreeNode* root;

public:
    BinaryTree() {
        root = nullptr;
    }

    TreeNode* createNode(int data) {
        TreeNode* newNode = new TreeNode();
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    void insert(int data) {
        root = insertRec(root, data);
    }

    TreeNode* insertRec(TreeNode* root, int data) {
        if (root == nullptr) {
            return createNode(data);
        }

        if (data < root->data) {
            root->left = insertRec(root->left, data);
        } else if (data > root->data) {
            root->right = insertRec(root->right, data);
        }

        return root;
    }

    void inorderTraversal(TreeNode* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            cout << root->data << " ";
            inorderTraversal(root->right);
        }
    }

    void preorderTraversal(TreeNode* root) {
        if (root != nullptr) {
            cout << root->data << " ";
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
    }

    void postorderTraversal(TreeNode* root) {
        if (root != nullptr) {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            cout << root->data << " ";
        }
    }

    void displayMenu() {
        cout << "\nBinary Tree Operations:" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Inorder Traversal" << endl;
        cout << "3. Preorder Traversal" << endl;
        cout << "4. Postorder Traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
    }

    void menu() {
        int choice, data;
        do {
            displayMenu();
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter data to insert: ";
                    cin >> data;
                    insert(data);
                    break;
                case 2:
                    cout << "Inorder Traversal: ";
                    inorderTraversal(root);
                    cout << endl;
                    break;
                case 3:
                    cout << "Preorder Traversal: ";
                    preorderTraversal(root);
                    cout << endl;
                    break;
                case 4:
                    cout << "Postorder Traversal: ";
                    postorderTraversal(root);
                    cout << endl;
                    break;
                case 5:
                    cout << "Exiting program." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
            }
        } while (choice != 5);
    }
};

int main() {
    BinaryTree tree;
    tree.menu();
    return 0;
}
