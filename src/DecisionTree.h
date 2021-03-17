#pragma once
#ifndef __DECISION_TREE__
#define __DECISION_TREE__
#include "Agent.h"
#include "CloseCombatCondition.h"
#include "LOSCondition.h"
#include "RadiusCondition.h"
#include "TreeNode.h"
#include "TreeNodeType.h"

class DecisionTree
{
public:
	DecisionTree();
	~DecisionTree();
	
	Agent* getAgent();
	void setAgent(Agent* agent);

	// convenience function
	TreeNode* AddNode(TreeNode* parent, TreeNode* child_node, TreeNodeType type);
	void Display();
	void Update();

	std::string MakeDecision();

private:
	Agent* m_agent;

	LOSCondition* m_LOSNode;
	RadiusCondition* m_radiusNode;
	CloseCombatCondition* m_closeCombatNode;
	
	void m_builTree();
	
	std::vector<TreeNode*> m_treeNodeList;
};

#endif
