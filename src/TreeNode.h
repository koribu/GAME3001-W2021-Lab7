#pragma once
#ifndef  __TREE_NODE__
#define __TREE_NODE__
#include <string>

struct TreeNode
{
	TreeNode() = default;
	virtual ~TreeNode() = default;

	std::string name = "";
	bool data = false;

	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
	TreeNode* Parent = nullptr;
	bool isLeaf = false;
	
};

#endif

