#include <iostream>
#include <string>

using namespace std;

//���Ĵ洢�ṹ
typedef struct Lnode
{
	int data;//������
	struct Lnode* next;//ָ����
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
		cout<<"�����빦�ܱ��:";
		cin>>function;
		switch(function)
		{
		case 1:
			void frontInsert(Linklist& L,int n);
			cout<<"ǰ�巨����������"<<endl;
			cout<<"�������ʼ����������������ݸ���n:";
			cin>>n;
			frontInsert(L,n);
			break;
		case 2:
			void BehindInsert(Linklist& L,int n);
			cout<<"��巨����������"<<endl;
			cout<<"�������ʼ����������������ݸ���n:";
			cin>>n;
			BehindInsert(L,n);
			break;
		case 3:
			void disPlay(Linklist L);
			cout<<"�����ӡ�������ȫ������"<<endl;
			disPlay(L);
			break;
		case 4:
			int seekValue(Linklist L,int e);
			cout<<"������Ĳ���"<<endl;
			cout<<"��������ҵ�����e:";
			cin>>e;
			temp=seekValue(L,e);
			if(temp!=0)
				printf("��ֵ%d��λ����%d\n",e,temp);
			else
				cout<<"��������û����ֵ"<<e<<endl;
			break;
		case 5:
			void InsertValue(Linklist& L,int n,int e);
			cout<<"������Ĳ��뺯��"<<endl;
			cout<<"����������λ��n:";
			cin>>n;
			cout<<"������������ֵe:";
			cin>>e;
			InsertValue(L,n,e);
			break;
		case 6:
			void DelectValue(Linklist& L,int n,int& e);
			cout<<"������ɾ�����ݵ�λ��n:";
			cin>>n;
			DelectValue(L,n,e);
			printf("ɾ����λ��%d������ֵΪ%d\n",n,e);
			break;
		default:
			cout<<"����Ĺ��ܱ�Ų�����"<<endl;
		}
		cout<<"�Ƿ�ִ����������?\t1-���� 0-�˳�:";
		InputJudge(Key);
		system("cls");
	}
	system("pause");
	return 0;
}


//������ĳ�ʼ������
void Init(Linklist& L)
{
	L=new Lnode;
	L->next=NULL;
	//����һ��ͷ��㣬ָ����ΪNULL;
}

//ǰ�巨����������
void frontInsert(Linklist& L,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		Lnode* s=new Lnode;
		printf("�������%d������:",i+1);
		cin>>s->data;
		s->next=L->next;
		L->next=s;
	}
}

//�����ӡ�������ȫ������
void disPlay(Linklist L)
{
	Linklist P=L->next;
	if(P==NULL)
	{
		cout<<"������LΪ��"<<endl;
		system("pause");
		exit(1);
	}
	cout<<"������L����:";
	while(P!=NULL)
	{
		cout<<P->data<<'\t';
		P=P->next;
	}
	cout<<endl;
}

//��巨����������
void BehindInsert(Linklist& L,int n)
{
	cout<<"��巨����������"<<endl;
	Lnode* rear;
	rear=L;

	int i;
	for(i=0;i<n;i++)
	{
		Lnode* s=new Lnode;
		printf("�������%d������:",i+1);
		cin>>s->data;
		s->next=NULL;
		rear->next=s;
		rear=s;
	}
}

//��������ֵ�Ĳ���
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

//������Ĳ��뺯��
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
		cout<<"����λ��n������"<<endl;
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

//�������ɾ������
void DelectValue(Linklist& L,int n,int& e)
{
	Lnode* p=L;
	int i=0;
	while(i<n-1 && p->next)//p->next��Ϊ�գ�����p��Ϊ��
	{
		p=p->next;
		i++;
	}
	if(!p->next || n<1)
	{
		cout<<"ɾ��λ��n������"<<endl;
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
	string function[6]={"1-ǰ�巨����������","2-��巨����������",
		"3-���������ݵĴ�ӡ���","4-������Ĳ���",
		"5-����������ݲ���","6-�����������ɾ��"};
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
			cout<<"���벻����"<<endl;
			cin.clear();
			cin.sync();
		}
		else
			break;
	}while(true);
}




