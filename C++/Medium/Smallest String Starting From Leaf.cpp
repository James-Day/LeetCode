/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    string smallest = "~"; // larger than any character, could also initialize to 'z' + 1 for instance.
public:
    string smallestFromLeaf(TreeNode* root) {
        string curr = "";
        dfs(root, curr);
        return smallest;
    }
    void dfs(TreeNode* root, string curr) {
        if (root == NULL) return;
        curr += (char)(root->val + 'a');
        if (root->left == NULL && root->right == NULL) {
            reverse(curr.begin(), curr.end()); //better than adding to strings in the front each time!
            if (curr < smallest || smallest.empty()) smallest = curr;
            return;
        }

        dfs(root->left, curr);
        dfs(root->right, curr);
        curr = curr.substr(0, curr.size() - 1); //remove the last letter that's been added
    }
};

/* My initial solution, much worse because it uses nlog(n) memory where n is the number of characters. and then sorts at the end.
* 
* /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        vector<string> words;
        words = dfs(root, words);
        sort(words.begin(), words.end());
        return words[0];
    }
    vector<string> dfs(TreeNode* root, vector<string> words) {
        if (root == nullptr) return words;
        if (!root->left && !root->right) {
            string newWord = "";
            newWord += root->val + 'a';
            words.push_back(newWord);
            return words;
        }
        vector<string> res;
        vector<string> res2;

        res = dfs(root->left, words);
        res2 = dfs(root->right, words);

        res.insert(res.end(), res2.begin(), res2.end());
        for (int i = 0; i < res.size(); i++) {
            res[i] += root->val + 'a';
        }
        return res;
    }
};


*/