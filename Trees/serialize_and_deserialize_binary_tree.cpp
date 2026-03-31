// Problem: Serialize and Deserialize Binary Tree
// Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// Approach: DFS (Preorder Traversal)
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Explanation:

We need to convert a binary tree into a string (serialize)
and reconstruct it back (deserialize).

------------------------------------------------

Approach:

Serialization:
1. Use preorder traversal (root → left → right)
2. For NULL nodes, store "null"
3. Separate values using commas

Example:
Tree:
    1
   / \
  2   3

Serialized:
"1,2,null,null,3,null,null,"

------------------------------------------------

Deserialization:

1. Parse the string from left to right
2. If "null" → return NULL
3. Otherwise:
   - Create node
   - Recursively build left subtree
   - Recursively build right subtree

------------------------------------------------

Key Idea:

Preorder traversal ensures we reconstruct the tree
in the exact same structure.

------------------------------------------------

Handles:
- Negative numbers
- Multi-digit values
*/

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    bool isdigit(char c){
        return (c >= '0' && c <= '9');
    }

    void serial(TreeNode* node, string &ans){

        if(node == NULL){
            ans.append("null,");
            return;
        }

        ans.append(to_string(node->val));
        ans.append(",");

        serial(node->left, ans);
        serial(node->right, ans);
    }

    TreeNode* build(string &data, int &i){

        if(i >= data.size())
            return NULL;

        // Check for null
        if(data.substr(i, 4) == "null"){
            i += 5; // skip "null,"
            return NULL;
        }

        // Handle negative numbers
        int sign = 1;
        if(data[i] == '-'){
            sign = -1;
            i++;
        }

        int num = 0;

        while(i < data.size() && isdigit(data[i])){
            num = num * 10 + (data[i] - '0');
            i++;
        }

        num *= sign;

        i++; // skip comma

        TreeNode* node = new TreeNode(num);

        node->left = build(data, i);
        node->right = build(data, i);

        return node;
    }

    // Serialize tree
    string serialize(TreeNode* root) {

        string ans = "";

        serial(root, ans);

        return ans;
    }

    // Deserialize string to tree
    TreeNode* deserialize(string data) {

        int i = 0;

        return build(data, i);
    }
};

/*
Usage:

Codec ser, deser;
TreeNode* root = deser.deserialize(ser.serialize(root));
*/