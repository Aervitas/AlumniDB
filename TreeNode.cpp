#include "TreeNode.h"

template<typename Type>
TreeNode<Type>::TreeNode(const Type& data, TreeNode* p, TreeNode* fc, TreeNode* ns) :
	value(data), parent(p), firstChild(fc), nextSibling(ns){
	
}

template<typename Type>
Type TreeNode<Type>::getData() const {
	return value;
}

template<typename Type>
TreeNode<Type>* TreeNode<Type>::getParent() const {
	return parent;
}

template<typename Type>
TreeNode<Type>* TreeNode<Type>::getNextSibling() const {
	return nextSibling;
}

template<typename Type>
TreeNode<Type>* TreeNode<Type>::getfirstChild() const {
	return firstChild;
}

//call helper function on first child
template<typename Type>
std::vector<TreeNode<Type>*> TreeNode<Type>::getAllChildren() const {
	std::vector<TreeNode<Type>*> hold; //initialize empty return vector
	TreeNode<Type>* node = firstChild; //copy firstChild ptr into node
	while (node != nullptr) { //iterate through all siblings and 
		hold.push_back(node);
		node = node->getNextSibling();
	}
	return hold;
}

template<typename Type>
void TreeNode<Type>::setValue(const Type& data) {
	value = data;
}

template<typename Type>
void TreeNode<Type>::addChild(TreeNode<Type>* child) {
	if (firstChild == nullptr) //if no children, this becomes firstChild
		firstChild = child;
	//iterate through siblings until you find one with no nextSibling
	TreeNode<Type>* node = firstChild;
	while (node->nextSibling != nullptr)
		node = node->nextSibling;
	node->NextSibling = child; 
}
