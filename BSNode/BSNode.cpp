#include "BSNode.h"	
BSNode* just_search(BSNode* bs, std::string val);
BSNode::BSNode(std::string data)
{
	_data = data;
	_left = nullptr;
	_right = nullptr;
}
BSNode::BSNode(const BSNode& other)
{
	_data = other._data;
	_left = other._left;
	_right = other._right;
}
BSNode& BSNode::operator=(const BSNode& other)
{
	_data = other.getData();
	_left = other.getLeft();
	_right = other.getRight();
	return *this;
}
BSNode::BSNode()
{
	_data = '#';
	_left = nullptr;
	_right = nullptr;
}
BSNode::~BSNode()
{

}
void BSNode::insert(std::string value)
{
	std::memcpy(this,insert(this,value), sizeof(insert(this, value)));
}
BSNode* BSNode::insert(BSNode* node ,std::string value)
{
	if (node == nullptr) 
	{
		node = new BSNode(value);
		return node;
	}

	if (value < node->_data)
	{
		if (node->_left == nullptr) {
			node->_left = new BSNode(value);
			return node;
		}
		else {
			insert(node->_left, value);
		}
	}

	if (value > node->_data)
	{
		if (node->_right == nullptr) {
			node->_right = new BSNode(value);
			return node;
		}
		else {
			insert(node->_right, value);
		}
	}
	else if(value == node->_data)
	{
		_count += 1;
		return node;
	}
	return node;
}
bool BSNode::isLeaf() const
{
	return true;
}
std::string BSNode::getData() const
{
	return _data;
}
BSNode* BSNode::getLeft() const
{
	return _left;
}
BSNode* BSNode::getRight() const
{
	return _right;
}

bool BSNode::search(std::string val)
{
	if (just_search(this, val)->getData() == val)
	{
		return true;
	}
	return false;
}
BSNode* just_search(BSNode* bs, std::string val)
{
	if (bs == nullptr || bs->getData() == val)
		return bs;

	if (bs->getData() < val)
		return just_search(bs->getRight(), val);

	return just_search(bs->getLeft(), val);
}
int BSNode::getHeight() const
{
	return 0;
}
int BSNode::getDepth(const BSNode& root) const
{
	return 0;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           