#include <iostream>
#include <string>
#include "BSNode.h"
#include <windows.h>
#include "printTreetoFile.h"
using namespace std;

int main()
{
	BSNode* bs = new BSNode("6");
	bs->insert("3");
	bs->insert("8");
	bs->insert("4");
	bs->insert("5");//everything work here
	bs->insert("9");
	bs->insert("6");

	
	cout << "Tree height: " << bs->getHeight() << endl;
	cout << "depth of node with 5 depth: " << bs->getLeft()->getRight()->getRight()->getDepth(*bs) << endl;//getDepth i doesnt understand what it does same with get Height
	cout << "depth of node with 3 depth: " << bs->getLeft()->getRight()->getDepth(*bs) << endl;

	
	string textTree = "BSTData.txt";
	printTreeToFile(bs, textTree);

	system("BinaryTree.exe");
	system("pause");
	//remove(textTree.c_str());
	delete bs;

	return 0;
}

