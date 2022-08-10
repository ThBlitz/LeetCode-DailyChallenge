#include <iostream>
#include <vector>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



TreeNode* recur(int left, int right, std::vector<int>& nums) {
    if (left > right) {
        return nullptr;
    }
    int mid = (left + right) / 2;
    return new TreeNode(nums[mid], recur(left, mid - 1, nums), recur(mid + 1, right, nums));
}
        

TreeNode* sortedArrayToBST(std::vector<int>& nums) {
    return recur(0, nums.size() - 1, nums);
}

int main() {

    std::vector<int> nums = {-2, -1, 0, 1, 2};
    TreeNode* root = sortedArrayToBST(nums);
    return 0;
}


