#include <iostream>
#include <string>
using namespace std;

const string PUSH = "push";
const string POP = "pop";
const string SIZE = "size";
const string EMPTY = "empty";
const string FRONT = "front";
const string BACK = "back";

struct Node
{
	int data;
	Node* next;
};

struct Queue
{
	Node* front;
	Node* rear;
	int size;
};

void init(Queue* q)
{
	q->front = q->rear = NULL;
	q->size = 0;
}

bool isEmpty(const Queue* q)
{
	return q->size == 0;
}

void enqueue(Queue* q, int data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;

	if (isEmpty(q))
		q->front = q->rear = newNode;
	else
	{
		q->rear->next = newNode;
		q->rear = newNode;
	}
	q->size++;
}

int dequeue(Queue* q)
{
	if (isEmpty(q)) return -1;

	Node* delNode = q->front;
	q->front = q->front->next;
	int ret = delNode->data;
	delete delNode;
	q->size--;
	return ret;
}

int front(const Queue* q)
{
	if (isEmpty(q))
		return -1;
	return q->front->data;
}

int back(const Queue* q)
{
	if (isEmpty(q))
		return -1;
	return q->rear->data;
}

int size(const Queue* q)
{
	return q->size;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	Queue q;
	init(&q);
	
	while (n--)
	{
		string cmd;
		cin >> cmd;

		if (cmd == PUSH)
		{
			int num;
			cin >> num;
			enqueue(&q, num);
		}
		else if (cmd == POP)
		{
			cout << dequeue(&q) << '\n';
		}
		else if (cmd == SIZE)
		{
			cout << size(&q) << '\n';
		}
		else if (cmd == EMPTY)
		{
			cout << isEmpty(&q) << '\n';
		}
		else if (cmd == FRONT)
		{
			cout << front(&q) << '\n';
		}
		else if (cmd == BACK)
		{
			cout << back(&q) << '\n';
		}
		else
		{
			cout << "error" << '\n';
		}
	}


	return 0;
}