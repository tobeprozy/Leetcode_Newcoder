#include<iostream>
using namespace std;
#include<vector>

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

public:
    //无参（默认）构造函数
    TreeNode() {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x, TreeNode* leftnode, TreeNode* rightnode) {
        val = x;
        left = leftnode;
        right = rightnode;
    }
};

class Solution {
public:
    TreeNode* traverval(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        
        //寻找最大值
        int rootValue = nums[0];
        int maxIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (rootValue < nums[i]) {
                rootValue = nums[i];
                maxIndex = i;
            }
        }
        TreeNode* root = new TreeNode(rootValue);
        if (nums.size() == 1) return root;

        //切割剩余数组
        //[nums.begin(), nums.begin() + index)
        //[nums.begin() + index + 1, nums.end())
        vector<int> leftNums(nums.begin(), nums.begin() + maxIndex);
        vector<int> rightNums(nums.begin() + maxIndex + 1, nums.end());

        root->left = traverval(leftNums);
        root->right = traverval(rightNums);

        //显示分割数组
        cout << "nums = " << endl;
        for (auto x : nums) cout << x << " ";
        cout << endl;

        cout << "leftNums = " << endl;
        for (auto x : leftNums) cout << x << " ";
        cout << endl;

        cout << "rightNums = " << endl;
        for (auto x : rightNums) cout << x << " ";
        cout << endl;
        
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        return traverval(nums);
    }
};

int main() {
    vector<int> nums = {3,2,1,6,0,5};
    Solution test;
    test.constructMaximumBinaryTree(nums);
    return 0;
}
