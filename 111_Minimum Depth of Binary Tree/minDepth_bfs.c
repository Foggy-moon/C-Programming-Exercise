#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX 2000
typedef struct TreeNode Tree;

int minDepth(struct TreeNode* root) {
	if (root == NULL)
		return 0;
	Tree* queue = (Tree*)malloc(sizeof(Tree) * MAX);
	int head = 0, tail = 0, depth = 1, i;
	queue[tail] = *root;
	tail++;
	while (head < tail) {
		int start = head, end = tail;
		for (i = start; i < end; i++) {
			head++;
			if (queue[i].left == NULL && queue[i].right == NULL)
				return depth;
			if (queue[i].left != NULL) {
				queue[tail] = *(queue[i].left);
				tail++;
			}
			if (queue[i].right != NULL) {
				queue[tail] = *(queue[i].right);
				tail++;
			}
		}
		depth++;
	}
	return depth;
}

void main() {
	Tree tree_node[5];
	tree_node[0].val = 3;
	tree_node[0].left = &tree_node[1];
	tree_node[0].right = &tree_node[2];
	tree_node[1].val = 9;
	tree_node[1].left = NULL;
	tree_node[1].right = NULL;
	tree_node[2].val = 20;
	tree_node[2].left = &tree_node[3];
	tree_node[2].right = &tree_node[4];
	tree_node[3].val = 15;
	tree_node[3].left = NULL;
	tree_node[3].right = NULL;
	tree_node[4].val = 7;
	tree_node[4].left = NULL;
	tree_node[4].right = NULL;
	int res = minDepth(tree_node);
}
