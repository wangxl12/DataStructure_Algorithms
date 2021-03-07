#include<iostream>
#include<iomanip>
#include<stack>
#include<queue>
using namespace std;
typedef int ElemType;
//二叉树节点
class BTNode   //Binary Tree Node
{
public:
	ElemType data;
	BTNode* lchild;   //左孩子
	BTNode* rchild;   //右孩子
	BTNode(ElemType d, BTNode* left=NULL, BTNode* right=NULL) 
		:data(d), lchild(left), rchild(right){}
};
//二叉树
class BinaryTree
{
private:
	//根节点指针
	BTNode* Root;
	//节点个数
	int size;
public:
	//构造函数
	BinaryTree();
	BTNode* buildTree();
	//析构函数
	~BinaryTree();
	//求树的高度
	int height();
	//获取节点个数
	int getSize()
	{return size;}
	void getHeight(BTNode*, int, int&);
	//指定遍历方式
	void traverse();
	//前序遍历
	void preOrderWithoutRecursion();
	void preOrder();
	void preorder(BTNode*);
	//中序遍历
	void inOrderWithoutRecursion();
	void inOrder();
	void inorder(BTNode*);
	//后序遍历
	void postOrderWithoutRecursion();
	void postOrder();
	void postorder(BTNode*);
	//层次遍历
	void levelOrder();
	//判断树是否为空
	bool empty()
	{return Root == NULL;}
	//获取根节点
	BTNode* root()
	{return Root;}
	//查找指定节点
	bool find(ElemType);
	//获取父节点
	BTNode* parent(ElemType);
	//获取左孩子
	BTNode* lchild(ElemType);
	//获取右孩子
	BTNode* rchild(ElemType);
};
//构造函数
BinaryTree::BinaryTree()
{
	size = 0;
	cout << "输入根节点 ";
	Root = buildTree();
}
BTNode* BinaryTree::buildTree()
{
	ElemType data;
	BTNode* p = NULL;
	cin >> data;
	//输入0结束
	if (data == 0)
		return p;
	else
	{
		p = new BTNode(data);
		size++;
		if (!p)
		{
			cerr << "内存分配失败!" << endl;
			exit(0);
		}
		else
		{
			cout << "请输入 " << data << " 节点的左孩子 ";
			p->lchild = buildTree();
			cout << "请输入 " << data << " 节点的右孩子 ";
			p->rchild = buildTree();
		}
	}
	return p;
}
//析构函数
BinaryTree::~BinaryTree()
{
	queue<BTNode*> q;
	q.push(Root);
	BTNode* p = NULL;
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		//左孩子不为空，则左孩子入队
		if (p->lchild)
			q.push(p->lchild);
		//右孩子不为空，则右孩子入队
		if (p->rchild)
			q.push(p->rchild);
		//释放内存
		delete p;
	}
}
//求树的高度
int BinaryTree::height()
{
	if (empty())
		return 0;
	int h = 0;
	getHeight(Root, 0, h);
	return h;
}

void BinaryTree::getHeight(BTNode* p, int level, int &h)
{
	if (p)
	{
		if (level > h)
			h = level;
		getHeight(p->lchild, level + 1, h);
		getHeight(p->rchild, level + 1, h);
	}
}
//指定遍历方式
void BinaryTree::traverse()
{
	int choice;
	cout << "输入遍历方式：0(前序)、1(中序)、2(后序)、3(层次)：";
	cin >> choice;
	while (choice < 0 || choice > 3)
	{
		cout << "输的不对！请重新输入： ";
		cin >> choice;
	}
	switch(choice)
	{
	case 0:preOrder(); break;
	case 1:inOrder(); break;
	case 2:postOrder();break;
	case 3:levelOrder(); break;
	}
}
//前序遍历：根->左->右
void BinaryTree::preOrder()
{
	BTNode* pnode = Root;
	preorder(pnode);
	cout << endl;
}
void BinaryTree::preorder(BTNode* p)
{
	if (p)
	{
		cout << setw(4) << p->data;
		preorder(p->lchild);
		preorder(p->rchild);
	}
}
//中序遍历：左->根->右
void BinaryTree::inOrder()
{
	BTNode* pnode = Root;
	inorder(pnode);
	cout << endl;
}
void BinaryTree::inorder(BTNode* p)
{
	if (p)
	{
		inorder(p->lchild);
		cout << setw(4) << p->data;
		inorder(p->rchild);
	}
}
//后序遍历：左->右->根
void BinaryTree::postOrder()
{
	BTNode* pnode = Root;
	postorder(pnode);
	cout << endl;
}
void BinaryTree::postorder(BTNode* p)
{
	if (p)
	{
		postorder(p->lchild);
		postorder(p->rchild);
		cout << setw(4) << p->data;
	}
}
//层次遍历
void BinaryTree::levelOrder()
{
	//使用STL中的队列
	queue<BTNode*> q;
	//根节点入队
	q.push(Root);
	BTNode* p = NULL;
	while (!q.empty())
	{
		p = q.front();
		//打印
		cout << setw(4) << p->data;
		q.pop();
		//左孩子不为空，则左孩子入队
		if (p->lchild)
			q.push(p->lchild);
		//右孩子不为空，则右孩子入队
		if (p->rchild)
			q.push(p->rchild);
	}
	cout << endl;
}
//查找指定节点
bool BinaryTree::find(ElemType data)
{
	if (!empty())
	{
		//按层次遍历查找
		queue<BTNode*> q;
		q.push(Root);
		BTNode* p = NULL;
		while (!q.empty())
		{
			p = q.front();
			//比较
			if(p->data==data)
				return true;
			q.pop();
			if (p->lchild)
				q.push(p->lchild);
			if (p->rchild)
				q.push(p->rchild);
		}
	}
	//在树空和不存在该节点的情况下，都返回false
	return false;
}
//获取父节点
BTNode* BinaryTree::parent(ElemType data)
{
	if (!empty())
	{
		//根节点的父节点为空
		if (Root->data == data)
			return NULL;
		stack<BTNode*> s;
		BTNode* p = Root;
		while (!s.empty() || p)
		{
			if (p)
			{
				if ((p->lchild && p->lchild->data == data) || (p->rchild && p->rchild->data == data))
					return p;
				s.push(p);
				p = p->lchild;
			}
			else
			{//左子树访问完后，访问右子树
				p = s.top();
				s.pop();
				p = p->rchild;
			}
		}
	}
	return NULL;
}
//获取左孩子
BTNode* BinaryTree::lchild(ElemType data)
{
	if (!empty())
	{
		//按层次遍历查找
		queue<BTNode*> q;
		q.push(Root);
		BTNode* p = NULL;
		while (!q.empty())
		{
			p = q.front();
			//比较
			if (p->data == data)
				return p->lchild;
			q.pop();
			if (p->lchild)
				q.push(p->lchild);
			if (p->rchild)
				q.push(p->rchild);
		}
	}
	//在树空和不存在该节点的情况下，都返回NULL
	return NULL;
}
//获取右孩子
BTNode* BinaryTree::rchild(ElemType data)
{
	if (!empty())
	{
		//按层次遍历查找
		queue<BTNode*> q;
		q.push(Root);
		BTNode* p = NULL;
		while (!q.empty())
		{
			p = q.front();
			//比较
			if (p->data == data)
				return p->rchild;
			q.pop();
			if (p->lchild)
				q.push(p->lchild);
			if (p->rchild)
				q.push(p->rchild);
		}
	}
	//在树空和不存在该节点的情况下，都返回NULL
	return NULL;
}
int main()
{
	cout << "******二叉树******" << endl;
	BinaryTree tree;
	cout << "树的高度是 " << tree.height() << endl;
	cout << "树中共有节点个数 " << tree.getSize() << endl;
	tree.traverse();
	ElemType data = 2;
	cout << "对节点 " << data << " 进行查询" << endl;
	cout << "存在于树中吗？";
	tree.find(data) ? cout << "Yes!" <<endl: cout << "No!" << endl;
	BTNode* p = NULL;
	p = tree.parent(data);
	p ? cout << "父节点是 " << p->data << endl : cout << data << "是根节点，故并无父节点" << endl;
	p = tree.lchild(data);
	p ? cout << "左孩子是 " << p->data << endl : cout << "无左孩子！" << endl;
	p = tree.rchild(data);
	p ? cout << "右孩子是 " << p->data << endl : cout << "无右孩子！" << endl;
	system("pause");
	return 0;
}
