#include <stdlib.h>
#include <stdio.h> 
 


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode* recur(int left, int right, int* nums) {
    if (left > right) {
        return NULL;
    }
    int mid = (left + right) / 2;
    struct TreeNode* node;
    node = (struct TreeNode*)malloc(sizeof(struct TreeNode)); 
    node -> val = nums[mid];
    node -> left = recur(left, mid - 1, nums);
    node -> right = recur(mid + 1, right, nums);
    return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return recur(0, numsSize - 1, nums);
}

int main() {

    int nums[5] = {-2, -1, 0, 1, 2};
    int numsSize = 5;
    struct TreeNode* root = sortedArrayToBST(nums, numsSize); 
    return 0;
}