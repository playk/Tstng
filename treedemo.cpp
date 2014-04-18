

#include "stdio.h"
#include "tree.h"
#include "string"
using namespace std;

typedef Tree<string> StringTree;
typedef StringTree::Node StringNode;



void PrintNode(StringNode node,int nLevel) {
	
	fputs("\n",stdout);
	
	string s;
	s.resize(nLevel*2,' ');
	fputs(s.c_str(),stdout);

	
	fputs(node.get_Data()->c_str(),stdout);

	
	nLevel++;
	for(int n=0;n<node.Count;n++) {
		PrintNode(node.Nodes[n],nLevel);
	}
}

int main()
{
	
	StringTree tree; 
	((string&)tree)="Root";

	
	StringNode node=tree;

	node.AddNode("1").AddNode("11");
	StringNode node2=node.AddNode("2");

	node2.AddNode("21").AddNode("211");
	node2.AddNode("22");
	node2.AddNode("23");
	
	node.AddNode("3");

	
	PrintNode(tree,0);

	
	char buf[3];
	fputs("\nPress ENTER :",stdout);
	fgets(buf,3,stdin);
	return 0;
}
