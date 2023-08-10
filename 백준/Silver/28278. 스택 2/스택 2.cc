#include <iostream>

using namespace std;

enum class Command
{
	PUSH = 1,
	POP,
	SIZE,
	EMPTY,
	TOP
};

struct Node
{
	int data;
	Node* next;
};

struct Stack
{
	Stack() = default;
	~Stack()
	{
		Node* cur = head;
		while (cur != nullptr)
		{
			Node* next = cur->next;
			delete cur;
			cur = next;
		}
	}

	void push(int data)
	{
		Node* newNode = new Node{ data, head };
		head = newNode;
		++size;
	}

	int pop()
	{
		if (size == 0)
			return -1;

		Node* cur = head;
		head = head->next;
		int data = cur->data;
		delete cur;
		--size;
		return data;
	}

	int getSize()
	{
		return size;
	}

	bool isEmpty()
	{
		return size == 0;
	}

	int top()
	{
		if (size == 0)
			return -1;

		return head->data;
	}

	Node* head = nullptr;
	int size = 0;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;		// 1 <= n <= 1'000'000
	cin >> n;
	
	Stack stack;
	while (n--)
	{
		Command cmd;
		cin >> (int&)cmd;
		switch (cmd)
		{
			case Command::PUSH:
			{
				int data;
				cin >> data;
				stack.push(data);
				break;
			}
			case Command::POP:
			{
				cout << stack.pop() << '\n';
				break;
			}
			case Command::SIZE:
			{
				cout << stack.getSize() << '\n';
				break;
			}
			case Command::EMPTY:
			{
				cout << stack.isEmpty() << '\n';
				break;
			}
			case Command::TOP:
			{
				cout << stack.top() << '\n';
				break;
			}
			default:
				break;
		}
	}

	return 0;
}