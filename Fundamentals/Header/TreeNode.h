#pragma once
#ifndef TreeNode_H
struct TreeNode {
	TreeNode *right;
	TreeNode *left;
	int val;
	TreeNode(int x) : val(x), right(nullptr), left(nullptr) {}
};
#endif