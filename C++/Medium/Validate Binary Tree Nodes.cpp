#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_set<int> hasParent; //used to find the root node

        for (int i = 0; i < leftChild.size(); i++) {
            if (leftChild[i] != -1) {
                hasParent.insert(leftChild[i]);
            }
            if (rightChild[i] != -1) {
                hasParent.insert(rightChild[i]);
            }
        }

        if (hasParent.size() != n - 1) {
            return false; //this means that there is no root
        }

        int root = -1;
        for (int i = 0; i < n; i++) {
            if (!hasParent.contains(i)) {
                root = i;
            }
        }
        unordered_set<int> visited;
        return dfs(root, visited, leftChild, rightChild) && visited.size() == n;
    }

    bool dfs(int i, unordered_set<int>& visited, vector<int>& leftChild, vector<int>& rightChild) {
        if (i == -1) {
            return true;
        }
        if (visited.contains(i)) {
            return false; // cycle
        }
        visited.insert(i);
        bool left = dfs(leftChild[i], visited, leftChild, rightChild);
        bool right = dfs(rightChild[i], visited, leftChild, rightChild);
        return left && right;
    }
};