#ifndef TREENODE
#define TREENODE
#include <vector>
//I need a tree implementation where each node can hold any amount of children.
//I templatize this implementation so future changes only need to be made in the AlumniDB.h file
//It will also allow me to reuse this n-ary tree implementation for future projects

template <typename Type>
class TreeNode {
public:
	TreeNode(const Type& data, TreeNode* p = nullptr, TreeNode* fc = nullptr, TreeNode* ns = nullptr);
	//getter functions
	Type getData() const;
	TreeNode* getParent() const;
	TreeNode* getNextSibling() const;
	TreeNode* getfirstChild() const;
	std::vector<TreeNode*> getAllChildren() const;
	//setter functions
	void setValue(const Type& data);
	void addChild(TreeNode* child);

private:
	Type value;
	TreeNode* parent;
	TreeNode* firstChild;
	TreeNode* nextSibling;
	int height; //height of node in binary tree
};

#endif