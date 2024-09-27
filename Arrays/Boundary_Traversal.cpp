class Solution {
public:
    vector<int> left, right, leaf;

    void leftTraversal(Node* root) {
        if (!root) return;
        if (root->left) {
            left.push_back(root->data);
            leftTraversal(root->left);
        } else if (root->right) {
            left.push_back(root->data);
            leftTraversal(root->right);
        }
    }

    void rightTraversal(Node* root) {
        if (!root) return;
        if (root->right) {
            rightTraversal(root->right);
            right.push_back(root->data);  // we want right in reverse order
        } else if (root->left) {
            rightTraversal(root->left);
            right.push_back(root->data);  // we want right in reverse order
        }
    }

    void leafTraversal(Node* root) {
        if (!root) return;
        leafTraversal(root->left);
        if (!root->left && !root->right) {
            leaf.push_back(root->data);
        }
        leafTraversal(root->right);
    }

    vector<int> boundary(Node *root) {
        if (!root) return {}; // Handle the case where root is null

        leftTraversal(root->left);  // this are important steps to avoid duplication
        leafTraversal(root->left);
        leafTraversal(root->right);
        rightTraversal(root->right);
        
        // Create the result vector
        vector<int> merged;

        // Reserve space for the final vector (optional, improves performance)
        merged.reserve(left.size() + leaf.size() + right.size());

        // Merge left, leaf, and right
        merged.push_back(root->data);  // Add root first if it's not empty
        merged.insert(merged.end(), left.begin(), left.end());
        merged.insert(merged.end(), leaf.begin(), leaf.end());
        //std::reverse(right.begin(), right.end()); // Reverse the right boundary before merging
        merged.insert(merged.end(), right.begin(), right.end());

        return merged;
    }
};
