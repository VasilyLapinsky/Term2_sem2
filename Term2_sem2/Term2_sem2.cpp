// Term2_sem2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

int pop(Node *&head)
{
	if (head == nullptr) return NULL;
	int data = head->data;
	Node *deleted = head;
	head = head->next;
	deleted->next = nullptr;
	delete deleted;
	return data;

}

struct DNode
{
	int data;
	DNode *prev;
	DNode *next;
};

int max(Node *head)
{
	if (head == nullptr) return NULL;
	int max = head->data;
	head = head->next;
	while (head != nullptr)
	{
		if (head->data > max) max = head->data;
		head = head->next;
	}
	return max;
}

int max(DNode *head)
{
	if (head == nullptr) return NULL;
	int max = head->data;
	head = head->next;
	while (head != nullptr)
	{
		if (head->data > max) max = head->data;
		head = head->next;
	}
	return max;
}

Node* create_stack() 
{
	Node *head = nullptr;
	int n;
	cin >> n;
	while (n >= 0)
	{
		head = new Node{ n, head };
	}
	return head;
}

void push(Node *&head, int value)
{
	head = new Node{ value, head };
}

bool search(Node *head, int value)
{
	while (head != nullptr)
	{
		if (head->data == value) return true;
		head = head->next;
	}
	return false;
}

Node* Task1()
{
	Node *head = nullptr;
	int n, max;
	cin >> n;
	max = n;
	while (n >= 0)
	{
		if (n > max) max = n;
		head = new Node{ n, head };
	}
	if (max >= 0)
	{
		Node *current = head;
		while (current != nullptr)
		{
			current->data += max;
		}
	}
	return head;
}

int Task2(Node *head)
{
	if (head == nullptr) return 0;
	int max = head->data, count =1;
	head = head->next;
	while (head != nullptr)
	{
		if (head->data > max)
		{
			max = head->data;
			count = 1;
		}
		else if (head->data == max) count++;
		head = head->next;
	}
	return count;
}

Node *Task3()
{
	int n;
	cin >> n;
	Node *head = new Node{ n,nullptr };
	cout << "For exit enter: -505" << endl;
	cin >> n;
	while (n != -505)
	{
		if(!search(head,n))
		{
			push(head, n);
		}
		cin >> n;
	}
	return head;
}

bool Task4(Node *head)
{
	if (head == nullptr) return true;
	while (head->next != nullptr)
	{
		if (head->data > head->next->data) return false;
		head = head->next;
	}
	return true;
}

int Task5(Node *head)
{
	int count=0, prev;
	if (head == nullptr) return count;
	prev = head->data;
	count++;
	head = head->next;
	while (head != nullptr)
	{
		if (head->data != prev)
		{
			prev = head->data;
			count++;
		}
		head = head->next;
	}
	return count;
}

void Task6(Node *head)
{
	bool flag = true;
	while (head != nullptr && flag)
	{
		flag = false;
		if (search(head->next, head->data))
		{
			flag = true;
			Node *deleted = head;
			head = head->next;
			deleted->next = nullptr;
			delete deleted;
		}
	}

	if (head == nullptr) return;

	while (head->next == nullptr)
	{
		if (search(head->next->next, head->next->data))
		{
			Node *deleted = head->next;
			head->next = head->next->next;
			deleted->next = nullptr;
			delete deleted;
		}
	}
}

void Task7(Node *l1, Node *l2)
{
	if (l1 == nullptr) return;

	int min, prev,count=1;
	Node *tmp1=l1, *tmp2 = l2;
	min = tmp1->data;

	while (tmp1 != nullptr)
	{
		if (tmp1->data < min)
		{
			min = tmp1->data;
			count = 1;
		}
		else if (tmp1->data == min) count++;
		tmp1 = tmp1->next;
	}

	if (l2 == nullptr)
	{
		tmp2 = new Node{ min, nullptr };
		count--;
	}
	else
	{
		while (tmp2->next != nullptr) tmp2 = tmp2->next;
	}

	while (count)
	{
		tmp2->next = new Node{ min,nullptr };
		tmp2 = tmp2->next;
		count--;
	}

	bool flag = true;
	
	while (flag)
	{
		flag = false;
		prev = min;
		tmp1 = l1;
		while (tmp1 != nullptr && tmp1->data <= min) { tmp1 = tmp1->next; }
		if (tmp1 != nullptr)
		{
			min = tmp1->data;
			count = 1;
			flag = true;
		}

		while (tmp1 != nullptr)
		{
			if (tmp1->data < min && tmp1->data > prev)
			{
				min = tmp1->data;
				count = 1;
			}
			else if (tmp1->data == min) count++;
			tmp1 = tmp1->next;
		}

		while (count)
		{
			tmp2->next = new Node{ min,nullptr };
			tmp2 = tmp2->next;
			count--;
		}
	}
}

Node *Task8(Node *head)
{
	if (head == nullptr) return nullptr;
	Node *headresult, *tmp;
	headresult = new Node{ head->data, nullptr };
	tmp = headresult;
	head = head->next;
	while (head != nullptr)
	{
		tmp->next = new Node{ (tmp->data + head->data), nullptr };
	}
	return headresult;
}

bool search(vector<int> v, int number)
{
	for (int i = 0;i < v.size();++i)
	{
		if (v[i] == number) return true;
	}
	return false;
}

void Task9(Node *head)
{
	if (head == nullptr) return;
	vector<int> v;
	v.push_back(head->data);
	while (head->next != nullptr && head != nullptr)
	{
		if (search(v, head->next->data))
		{
			Node *deleted = head->next;
			head = head->next->next;
			deleted->next = nullptr;
			delete deleted;
		}
		else
		{
			v.push_back(head->next->data);
			head = head->next;
		}
	}
}

bool is_simple(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

void Task10(Node *head)
{
	while (head != nullptr)
	{
		if (is_simple(head->data))
		{
			head->next = new Node{ head->data, head->next };
			head = head->next;
		}
		head = head->next;
	}
}

int max(int a, int b) { return a > b ? a : b; }

void Task11(Node *&ha, Node *&hb)
{
	ha = create_stack();
	if (ha == nullptr) return;
	hb = new Node{ ha->data, nullptr };
	Node *tmpA = ha->next, *tmpB = hb;
	while (tmpA != nullptr)
	{
		if (tmpA->data > tmpB->data)
		{
			tmpB->next = new Node{ tmpA->data, nullptr };
		}
		else
		{
			tmpB->next = new Node{ tmpB->data, nullptr };
		}
		// tmpB->next = new Node{ max(tmpA->data, tmpB->data), nullptr};
		tmpA = tmpA->next;
		tmpB = tmpB->next;
	}
}


//////////// TASK 13  ////////////
void add_to_cycle(Node *head, int data)
{
	head->next = new Node{ data,head->next };
}

void show_cycle(Node *head)
{
	Node *tmp = head;
	do
	{
		cout << tmp->data << endl;
		tmp = tmp->next;
	} while (tmp != head);
}

Node* Task14(int mas[], int size)
{
	Node *head = new Node{ mas[--size], nullptr };
	Node *tmp = head;
	while (size > -1) {
		tmp->next = new Node{ mas[--size], nullptr };
		tmp = tmp->next;
		--size;
	}
	return head;
}

/////////// TASK 15 //////////

struct SNode
{
	char str[20];
	SNode *prev;
	SNode *next;
};

void delete_snode_list(SNode *head)
{
	SNode *deleted;
	while (head != nullptr)
	{
		deleted = head;
		head = head->next;
		deleted->next = nullptr;
		deleted->prev = nullptr;
		delete deleted;
	}
}

void Task15(ifstream &in, ofstream &out)
{
	SNode *head = new SNode;
	head->prev = nullptr;
	head->next = nullptr;
	in >> head->str;
	SNode *now = head;

	while (!in.eof())
	{
		now->next = new SNode;
		now->next->prev = now;
		now->next->next = nullptr;
		in >> now->next->str;
		now = now->next;
	}

	while (now != nullptr)
	{
		out << now->str << ' ';
		now = now->prev;
	}

	delete_snode_list(head);
}

///////// TASK 16 ////////

struct Queue
{
	Node *head;
	Node *end;
};

void add_queue(int data,Queue *q)
{
	if (q->head == nullptr)
	{
		q->head = new Node{ data,nullptr };
		q->end = q->head;
	}
	else
	{
		q->end->next = new Node{ data, nullptr };
		q->end = q->end->next;
	}
}

Queue* createQueue(int mas[], int size)
{
	Queue *q = new Queue{ nullptr, nullptr };
	for (int i = 0;i < size;++i)
		add_queue(mas[i], q);
	return q;
}

void Task16(Queue *q)
{
	while (q->head != nullptr && q->head->data % 2 != 0)
	{
		cout << pop(q->head) << ' ';
	}
}

//////// TASK 17 /////////
void Task17(Queue *head, int c)
{
	if (head->head == nullptr) return;
	Node *current = head->head;
	while (current != head->end)
	{
		if (current->data < c)
		{
			cout << current->data << ' ';
		}
		current = current->next;
	}
	cout << current->data << ' ';
	current = head->head;
	while (current != head->end)
	{
		if (current->data >= c)
		{
			cout << current->data << ' ';
		}
		current = current->next;
	}
	cout << current->data << ' ';
}


//////// TASK 18 ////////

void Task18(DNode *head)
{
	while (head != nullptr)
	{
		if (head->data >= 0)
		{
			head->next = new DNode{ head->data,head,head->next };
			head = head->next;
		}
		head = head->next;
	}
}

void Task19(DNode *head, int x)
{
	if (head == nullptr) return;
	
	while(head->data == x && head != nullptr && head->prev == nullptr)
	{
		DNode *deleted;
		deleted = head;
		head = head->next;
		head->prev = nullptr;
		deleted->next = nullptr;
		delete deleted;
	}

	if (head == nullptr) return;

	while (head->next != nullptr)
	{
		if (head->next->data == x)
		{
			DNode *deleted = head->next;
			head->next = head->next->next;
			if (head->next != nullptr)
			{
				head->next->prev = head;
			}
			deleted->prev = nullptr;
			deleted->next = nullptr;
			delete deleted;
		}
		else
		{
			head = head->next;
		}
	}
}

void Task20(DNode *&head, int c)
{
	DNode *tmp = head;
	while (tmp->next->data < c && head->next != nullptr)
	{
		tmp = tmp->next;
	}
	while (head->next != nullptr)
	{
		if (tmp->next->data < c)
		{
			DNode *remove = tmp->next;
			if (tmp->next->next != nullptr)
			{
				tmp->next->next->prev = tmp;
			}
			tmp->next = tmp->next->next;
			head->prev = remove;
			remove->next = head;
			head = remove;
		}
		else
		{
			tmp = tmp->next;
		}
	}
}

bool Task21(DNode *head)
{
	if (head == nullptr) return false;
	DNode *end = head;
	while (end->next != nullptr) end = end->next;
	while (head != end && head->prev != end)
	{
		if (head->data != end->data)  return false;
		head = head->next;
		end = end->prev;
	}
	return true;
}

void Task22(DNode *head, int k)
{
	if (head == nullptr) return;
	DNode *remove = head;
	while (remove->next != nullptr)
	{
		remove = remove->next;
	}
	DNode *last = remove;
	while (k && remove != nullptr)
	{
		remove = remove->prev;
		--k;
	}
	if (remove == nullptr) return;

	last->next = head;
	head->prev = last;
	remove->next->prev = nullptr;
	head = remove->next;
	remove->next = nullptr;
}

int main()
{
    return 0;
}

