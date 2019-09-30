#include <iostream>
#include <string>

using namespace std;

//结点的存储结构
typedef struct Lnode
{
	int data;//数据域
	struct Lnode* next;//指针域
}Lnode,*Linklist;

int main()
{
	Linklist L;
	void Init(Linklist& L);
	Init(L);
	bool Key=true;
	int n;
	int function;
	int e;
	int temp;
	void InputJudge(bool& Key);
	void Menu();
	while(Key)
	{
		Menu();
		cout<<"请输入功能编号:";
		cin>>function;
		switch(function)
		{
		case 1:
			void frontInsert(Linklist& L,int n);
			cout<<"前插法创建单链表"<<endl;
			cout<<"请输入初始化创建单链表的数据个数n:";
			cin>>n;
			frontInsert(L,n);
			break;
		case 2:
			void BehindInsert(Linklist& L,int n);
			cout<<"后插法创建单链表"<<endl;
			cout<<"请输入初始化创建单链表的数据个数n:";
			cin>>n;
			BehindInsert(L,n);
			break;
		case 3:
			void disPlay(Linklist L);
			cout<<"输出打印单链表的全部数据"<<endl;
			disPlay(L);
			break;
		case 4:
			int seekValue(Linklist L,int e);
			cout<<"单链表的查找"<<endl;
			cout<<"请输入查找的数据e:";
			cin>>e;
			temp=seekValue(L,e);
			if(temp!=0)
				printf("数值%d的位置是%d\n",e,temp);
			else
				cout<<"单链表中没有数值"<<e<<endl;
			break;
		case 5:
			void InsertValue(Linklist& L,int n,int e);
			cout<<"单链表的插入函数"<<endl;
			cout<<"请输入插入的位置n:";
			cin>>n;
			cout<<"请输入插入的数值e:";
			cin>>e;
			InsertValue(L,n,e);
			break;
		case 6:
			void DelectValue(Linklist& L,int n,int& e);
			cout<<"请输入删除数据的位置n:";
			cin>>n;
			DelectValue(L,n,e);
			printf("删除的位置%d的数据值为%d\n",n,e);
			break;
		default:
			cout<<"输入的功能编号不合理"<<endl;
		}
		cout<<"是否执行其他功能?\t1-继续 0-退出:";
		InputJudge(Key);
		system("cls");
	}
	system("pause");
	return 0;
}


//单链表的初始化函数
void Init(Linklist& L)
{
	L=new Lnode;
	L->next=NULL;
	//定义一个头结点，指针域为NULL;
}

//前插法创建单链表
void frontInsert(Linklist& L,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		Lnode* s=new Lnode;
		printf("请输入第%d个数据:",i+1);
		cin>>s->data;
		s->next=L->next;
		L->next=s;
	}
}

//输出打印单链表的全部数据
void disPlay(Linklist L)
{
	Linklist P=L->next;
	if(P==NULL)
	{
		cout<<"单链表L为空"<<endl;
		system("pause");
		exit(1);
	}
	cout<<"单链表L数据:";
	while(P!=NULL)
	{
		cout<<P->data<<'\t';
		P=P->next;
	}
	cout<<endl;
}

//后插法创建单链表
void BehindInsert(Linklist& L,int n)
{
	cout<<"后插法创建单链表"<<endl;
	Lnode* rear;
	rear=L;

	int i;
	for(i=0;i<n;i++)
	{
		Lnode* s=new Lnode;
		printf("请输入第%d个数据:",i+1);
		cin>>s->data;
		s->next=NULL;
		rear->next=s;
		rear=s;
	}
}

//单链表数值的查找
int seekValue(Linklist L,int e)
{
	Lnode* p=L->next;
	int i=0;
	while(p!=NULL)
	{
		if(p->data==e)
			return i+1;
		else
		{
			p=p->next;
			i++;
		}
	}
	return 0;
}

//单链表的插入函数
void InsertValue(Linklist& L,int n,int e)
{
	Lnode* p=L;
	int i=0;
	while(i<n-1 && p)
	{
		i++;
		p=p->next;
	}

	if(!p||n<1)
	{
		cout<<"插入位置n不合理"<<endl;
		system("pause");
		exit(1);
	}
	else
	{
		Lnode* s=new Lnode;
		s->data=e;
		s->next=p->next;
		p->next=s;
	}
}

//单链表的删除函数
void DelectValue(Linklist& L,int n,int& e)
{
	Lnode* p=L;
	int i=0;
	while(i<n-1 && p->next)//p->next不为空，并非p不为空
	{
		p=p->next;
		i++;
	}
	if(!p->next || n<1)
	{
		cout<<"删除位置n不合理"<<endl;
		system("pause");
		exit(1);
	}
	else
	{
		Lnode *q=p->next;
		p->next=q->next;
		e=q->data;
		delete q;
	}
}

void Menu()
{
	string function[6]={"1-前插法创建单链表","2-后插法创建单链表",
		"3-单链表数据的打印输出","4-单链表的查找",
		"5-单链表的数据插入","6-单链表的数据删除"};
	int i;
	for(i=0;i<sizeof(function)/sizeof(function[0]);i++)
		cout<<function[i]<<endl;
}

void InputJudge(bool& Key)
{
	do
	{
		cin>>Key;
		if(cin.fail())
		{
			cout<<"输入不合理"<<endl;
			cin.clear();
			cin.sync();
		}
		else
			break;
	}while(true);
}




