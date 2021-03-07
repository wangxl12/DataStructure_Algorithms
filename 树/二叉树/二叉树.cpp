#include<iostream>
#include<iomanip>
#include<stack>
#include<queue>
using namespace std;
typedef int ElemType;
//�������ڵ�
class BTNode   //Binary Tree Node
{
public:
	ElemType data;
	BTNode* lchild;   //����
	BTNode* rchild;   //�Һ���
	BTNode(ElemType d, BTNode* left=NULL, BTNode* right=NULL) 
		:data(d), lchild(left), rchild(right){}
};
//������
class BinaryTree
{
private:
	//���ڵ�ָ��
	BTNode* Root;
	//�ڵ����
	int size;
public:
	//���캯��
	BinaryTree();
	BTNode* buildTree();
	//��������
	~BinaryTree();
	//�����ĸ߶�
	int height();
	//��ȡ�ڵ����
	int getSize()
	{return size;}
	void getHeight(BTNode*, int, int&);
	//ָ��������ʽ
	void traverse();
	//ǰ�����
	void preOrderWithoutRecursion();
	void preOrder();
	void preorder(BTNode*);
	//�������
	void inOrderWithoutRecursion();
	void inOrder();
	void inorder(BTNode*);
	//�������
	void postOrderWithoutRecursion();
	void postOrder();
	void postorder(BTNode*);
	//��α���
	void levelOrder();
	//�ж����Ƿ�Ϊ��
	bool empty()
	{return Root == NULL;}
	//��ȡ���ڵ�
	BTNode* root()
	{return Root;}
	//����ָ���ڵ�
	bool find(ElemType);
	//��ȡ���ڵ�
	BTNode* parent(ElemType);
	//��ȡ����
	BTNode* lchild(ElemType);
	//��ȡ�Һ���
	BTNode* rchild(ElemType);
};
//���캯��
BinaryTree::BinaryTree()
{
	size = 0;
	cout << "������ڵ� ";
	Root = buildTree();
}
BTNode* BinaryTree::buildTree()
{
	ElemType data;
	BTNode* p = NULL;
	cin >> data;
	//����0����
	if (data == 0)
		return p;
	else
	{
		p = new BTNode(data);
		size++;
		if (!p)
		{
			cerr << "�ڴ����ʧ��!" << endl;
			exit(0);
		}
		else
		{
			cout << "������ " << data << " �ڵ������ ";
			p->lchild = buildTree();
			cout << "������ " << data << " �ڵ���Һ��� ";
			p->rchild = buildTree();
		}
	}
	return p;
}
//��������
BinaryTree::~BinaryTree()
{
	queue<BTNode*> q;
	q.push(Root);
	BTNode* p = NULL;
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		//���Ӳ�Ϊ�գ����������
		if (p->lchild)
			q.push(p->lchild);
		//�Һ��Ӳ�Ϊ�գ����Һ������
		if (p->rchild)
			q.push(p->rchild);
		//�ͷ��ڴ�
		delete p;
	}
}
//�����ĸ߶�
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
//ָ��������ʽ
void BinaryTree::traverse()
{
	int choice;
	cout << "���������ʽ��0(ǰ��)��1(����)��2(����)��3(���)��";
	cin >> choice;
	while (choice < 0 || choice > 3)
	{
		cout << "��Ĳ��ԣ����������룺 ";
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
//ǰ���������->��->��
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
//�����������->��->��
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
//�����������->��->��
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
//��α���
void BinaryTree::levelOrder()
{
	//ʹ��STL�еĶ���
	queue<BTNode*> q;
	//���ڵ����
	q.push(Root);
	BTNode* p = NULL;
	while (!q.empty())
	{
		p = q.front();
		//��ӡ
		cout << setw(4) << p->data;
		q.pop();
		//���Ӳ�Ϊ�գ����������
		if (p->lchild)
			q.push(p->lchild);
		//�Һ��Ӳ�Ϊ�գ����Һ������
		if (p->rchild)
			q.push(p->rchild);
	}
	cout << endl;
}
//����ָ���ڵ�
bool BinaryTree::find(ElemType data)
{
	if (!empty())
	{
		//����α�������
		queue<BTNode*> q;
		q.push(Root);
		BTNode* p = NULL;
		while (!q.empty())
		{
			p = q.front();
			//�Ƚ�
			if(p->data==data)
				return true;
			q.pop();
			if (p->lchild)
				q.push(p->lchild);
			if (p->rchild)
				q.push(p->rchild);
		}
	}
	//�����պͲ����ڸýڵ������£�������false
	return false;
}
//��ȡ���ڵ�
BTNode* BinaryTree::parent(ElemType data)
{
	if (!empty())
	{
		//���ڵ�ĸ��ڵ�Ϊ��
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
			{//������������󣬷���������
				p = s.top();
				s.pop();
				p = p->rchild;
			}
		}
	}
	return NULL;
}
//��ȡ����
BTNode* BinaryTree::lchild(ElemType data)
{
	if (!empty())
	{
		//����α�������
		queue<BTNode*> q;
		q.push(Root);
		BTNode* p = NULL;
		while (!q.empty())
		{
			p = q.front();
			//�Ƚ�
			if (p->data == data)
				return p->lchild;
			q.pop();
			if (p->lchild)
				q.push(p->lchild);
			if (p->rchild)
				q.push(p->rchild);
		}
	}
	//�����պͲ����ڸýڵ������£�������NULL
	return NULL;
}
//��ȡ�Һ���
BTNode* BinaryTree::rchild(ElemType data)
{
	if (!empty())
	{
		//����α�������
		queue<BTNode*> q;
		q.push(Root);
		BTNode* p = NULL;
		while (!q.empty())
		{
			p = q.front();
			//�Ƚ�
			if (p->data == data)
				return p->rchild;
			q.pop();
			if (p->lchild)
				q.push(p->lchild);
			if (p->rchild)
				q.push(p->rchild);
		}
	}
	//�����պͲ����ڸýڵ������£�������NULL
	return NULL;
}
int main()
{
	cout << "******������******" << endl;
	BinaryTree tree;
	cout << "���ĸ߶��� " << tree.height() << endl;
	cout << "���й��нڵ���� " << tree.getSize() << endl;
	tree.traverse();
	ElemType data = 2;
	cout << "�Խڵ� " << data << " ���в�ѯ" << endl;
	cout << "������������";
	tree.find(data) ? cout << "Yes!" <<endl: cout << "No!" << endl;
	BTNode* p = NULL;
	p = tree.parent(data);
	p ? cout << "���ڵ��� " << p->data << endl : cout << data << "�Ǹ��ڵ㣬�ʲ��޸��ڵ�" << endl;
	p = tree.lchild(data);
	p ? cout << "������ " << p->data << endl : cout << "�����ӣ�" << endl;
	p = tree.rchild(data);
	p ? cout << "�Һ����� " << p->data << endl : cout << "���Һ��ӣ�" << endl;
	system("pause");
	return 0;
}
