class Solution {
public:
    vector<int> res;

    void leftTraversal(Node* root) {
        if (!root) return;
        if (root->left) {
            res.push_back(root->data);
            leftTraversal(root->left);
        } else if (root->right) {
            res.push_back(root->data);
            leftTraversal(root->right);
        }
    }

    void rightTraversal(Node* root) {
        if (!root) return;
        if (root->right) {
            rightTraversal(root->right);
            res.push_back(root->data);  // we want right in reverse order
        } else if (root->left) {
            rightTraversal(root->left);
            res.push_back(root->data);  // we want right in reverse order
        }
    }

    void leafTraversal(Node* root) {
        if (!root) return;
        if (!root->left && !root->right) {
            res.push_back(root->data);
        }
        leafTraversal(root->left);
        leafTraversal(root->right);
    }

    vector<int> boundary(Node *root) {
        if (!root) return {}; // Handle the case where root is null
        res.push_back(root->data);
        leftTraversal(root->left);  // this are important steps to avoid duplication
        leafTraversal(root->left);
        leafTraversal(root->right);
        rightTraversal(root->right);

        return res;
    }
};
