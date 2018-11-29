#include <iostream>
#include <queue>
#include <hash_map>
using namespace std;

class Oil
{
public:
	Oil(){};
	Oil(int a, int b, int c) :x(a), y(b), z(c){}
	~Oil(){};
	
public:
	int x = 0;
	int y = 0;
	int z = 0;

};
class Node
{
public:
	Node(){};
	Node(Oil* s_o, int c):o(s_o), n(c){}
	~Node(){};

public:
	Oil *o;
	int n;
};


//class WidthSearch
//{
//public:
//	queue <Node *>oilQueue;
//
//
//public:
//	WidthSearch();
//	~WidthSearch();
//
//
//
//
//
//};

bool isVisited(Node *node,int cnt,Node arr[1000])
{
	for (int i = 0; i < cnt; i++)
	{
		if (node->o->x == arr[i].o->x && node->o->y == arr[i].o->y && node->o->z == arr[i].o->z)
			return true;
	}
	return false;
}
void BFS(Node* r)
{
	queue<Node *>oilQueue;
	Oil *On;
	int cnt = 0;
	int t;
	int res = 0;
	Node arr[50];

	oilQueue.push(r);


	while (!oilQueue.empty())
	{
		On = oilQueue.front()->o;
		
		if (!isVisited(oilQueue.front(), cnt, arr))
		{
			arr[cnt].o = oilQueue.front()->o;
			arr[cnt].n = oilQueue.front()->n;
			cnt++;
			t = cnt - 1;
		}
		oilQueue.pop();

		if (On->y < 7)
		{
			Oil *newOil = new Oil();
			Node *newNode = new Node();
			newOil->y = 7;
			newOil->x = 10 - 7 - On->z;
			newOil->z = On->z;
			newNode->o = newOil;
			newNode->n = t;
			if (!isVisited(newNode, cnt, arr))
				oilQueue.push(newNode);
		}
		if (On->z < 3)
		{
			Oil *newOil = new Oil();
			Node *newNode = new Node();
			newOil->z = 3;
			newOil->x = 10 - 3 - On->y;
			newOil->y = On->y;
			newNode->o = newOil;
			newNode->n = t;
			if (!isVisited(newNode, cnt, arr))
				oilQueue.push(newNode);
		}
		if (On->y>0)
		{
			Oil *newOil = new Oil();
			Node *newNode = new Node();
			newOil->y = 0;
			newOil->x = 10 - On->z;
			newOil->z = On->z;
			newNode->o = newOil;
			newNode->n = t;
			if (!isVisited(newNode, cnt, arr))
				oilQueue.push(newNode);
		}
		if (On->z >0)
		{
			Oil *newOil = new Oil();
			Node *newNode = new Node();
			newOil->z = 0;
			newOil->x = 10 - On->y;
			newOil->y = On->y;
			newNode->o = newOil;
			newNode->n = t;
			if (!isVisited(newNode, cnt, arr))
				oilQueue.push(newNode);
		}
		if (On->y>0 && On->y+On->z <=3)
		{
			Oil *newOil = new Oil();
			Node *newNode = new Node();
			newOil->y = 0;
			newOil->z = On->y + On->z;
			newOil->x = 10 - On->y - On->z;
			newNode->o = newOil;
			newNode->n = t;
			if (!isVisited(newNode, cnt, arr))
				oilQueue.push(newNode);
		}
		if (On->z>0 && On->y + On->z <= 7)
		{
			Oil *newOil = new Oil();
			Node *newNode = new Node();
			newOil->z = 0;
			newOil->y = On->y + On->z;
			newOil->x = 10 - On->y - On->z;
			newNode->o = newOil;
			newNode->n = t;
			if (!isVisited(newNode, cnt, arr))
				oilQueue.push(newNode);
		}
		if (On->y<7 && On->y + On->z >=7)
		{
			Oil *newOil = new Oil();
			Node *newNode = new Node();
			newOil->y = 7;
			newOil->z = On->y + On->z - 7;
			newOil->x = 10 - On->y - On->z;
			newNode->o = newOil;
			newNode->n = t;
			if (!isVisited(newNode, cnt, arr))
				oilQueue.push(newNode);
		}
		if (On->z<3 && On->y + On->z >= 3)
		{
			Oil *newOil = new Oil();
			Node *newNode = new Node();
			newOil->z = 3;
			newOil->y = On->y + On->z - 3;
			newOil->x = 10 - On->y - On->z;
			newNode->o = newOil;
			newNode->n = t;
			if (!isVisited(newNode, cnt, arr))
				oilQueue.push(newNode);
		}
	}
	for (int i = 0; i < cnt; i++)
	{
		if (arr[i].o->x == 5)
		{
			res = i;
			break;
		}	
	}
	Node result[20];
	int a = 0;
	while (arr[res].n != -1)
	{
		result[a] = arr[res];
		res = arr[res].n;
		a++;
	}
	if (arr[res].n == -1)
	{
		result[a] = arr[res];
		res = arr[res].n;
	}
	for (int i = a; i >= 0; i--)
	{
		cout << "<" << result[i].o->x << "," << result[i].o->y << "," << result[i].o->z << ">" << endl;
	}
}

int main()
{
	Oil *root = new Oil(10, 0, 0);
	Node *rootNode = new Node(root, -1);
	BFS(rootNode);
	return 0;
}