#include "DecisionTree.h"


#include <iostream>



#include "AttackAction.h"
#include "MoveToLOSAction.h"
#include "MoveToPlayerAction.h"
#include "PatrolAction.h"

DecisionTree::DecisionTree()
{
	m_builTree();
}

DecisionTree::~DecisionTree()
= default;

Agent* DecisionTree::getAgent()
{
	return m_agent;
}

void DecisionTree::setAgent(Agent* agent)
{
	m_agent = agent;
}

TreeNode* DecisionTree::AddNode(TreeNode* parent, TreeNode* child_node, TreeNodeType type)
{
	switch (type)
	{
	case LEFT_TREE_NODE:
		parent->left = child_node;
		break;
	case RIGHT_TREE_NODE:
		parent->right = child_node;
		break;
	}

	child_node->Parent = parent; //backward travelsal
	return child_node;
}

void DecisionTree::Display()
{
	for (auto* node : m_treeNodeList)
	{
		std::cout << node->name << std::endl;
	}
}

std::string DecisionTree::MakeDecision()
{
	auto currentNode = m_treeNodeList[0]; // start at root node
	while(!currentNode->isLeaf)
	{
		currentNode = currentNode->data ? currentNode->right : currentNode->left;
	}

	return currentNode->name;
}

void DecisionTree::m_builTree()
{
	// add the root node
	m_LOSNode = new LOSCondition();
	m_treeNodeList.push_back(m_LOSNode); //node 0

	m_radiusNode = new RadiusCondition();
	AddNode(m_LOSNode, m_radiusNode, LEFT_TREE_NODE);
	m_treeNodeList.push_back(m_radiusNode);//node 1

	m_closeCombatNode = new CloseCombatCondition();
	AddNode(m_LOSNode, m_closeCombatNode, RIGHT_TREE_NODE);
	m_treeNodeList.push_back(m_closeCombatNode); //node 2

	TreeNode* patrolNode = AddNode(m_radiusNode, new PatrolAction(), LEFT_TREE_NODE);
	m_treeNodeList.push_back(patrolNode);

	TreeNode* moveToLOSNode = AddNode(m_radiusNode, new MoveToLOSAction(), RIGHT_TREE_NODE);
	m_treeNodeList.push_back(moveToLOSNode);

	TreeNode* moveToPlayerNode = AddNode(m_closeCombatNode, new MoveToPlayerAction(), LEFT_TREE_NODE);
	m_treeNodeList.push_back(moveToPlayerNode);

	TreeNode* attackNode = AddNode(m_closeCombatNode, new AttackAction(), RIGHT_TREE_NODE);
	m_treeNodeList.push_back(attackNode);
}
