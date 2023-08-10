#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
	T data;
	Node<T>* next;
	Node<T>* prev;

	Node(T data)
	{
		this->data = data;
		this->next = nullptr;
		this->prev = nullptr;
	}
};

template <typename T>
class Deque
{
private:
	Node<T>* head;
	Node<T>* tail;
	int size;
public:
	Deque()
	{
		this->head = nullptr;
		this->tail = nullptr;
		this->size = 0;
	}
	~Deque()
	{
		Node<T>* temp = this->head;
		while (temp != nullptr)
		{
			Node<T>* next = temp->next;
			delete temp;
			temp = next;
		}
		this->head = nullptr;
		this->tail = nullptr;
		this->size = 0;
	}
	void push_front(T data)
	{
		Node<T>* newNode = new Node<T>(data);
		if (this->head == nullptr)
		{
			this->head = newNode;
			this->tail = newNode;
		}
		else
		{
			newNode->next = this->head;
			this->head->prev = newNode;
			this->head = newNode;
		}
		this->size++;
	}
	void push_back(T data)
	{
		Node<T>* newNode = new Node<T>(data);
		if (this->head == nullptr)
		{
			this->head = newNode;
			this->tail = newNode;
		}
		else
		{
			newNode->prev = this->tail;
			this->tail->next = newNode;
			this->tail = newNode;
		}
		this->size++;
	}
	T pop_front()
	{
		if (this->head == nullptr)
		{
			return -1;
		}
		else
		{
			Node<T>* temp = this->head;
			T data = temp->data;
			this->head = this->head->next;
			if (this->head != nullptr)
			{
				this->head->prev = nullptr;
			}
			else
			{
				this->tail = nullptr;
			}
			delete temp;
			this->size--;
			return data;
		}
	}
	T pop_back()
	{
		if (this->head == nullptr)
		{
			return -1;
		}
		else
		{
			Node<T>* temp = this->tail;
			T data = temp->data;
			this->tail = this->tail->prev;
			if (this->tail != nullptr)
			{
				this->tail->next = nullptr;
			}
			else
			{
				this->head = nullptr;
			}
			delete temp;
			this->size--;
			return data;
		}
	}
	int Size()
	{
		return this->size;
	}
	bool Empty()
	{
		if (this->head == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	T Front()
	{
		if (this->head == nullptr)
		{
			return -1;
		}
		else
		{
			return this->head->data;
		}
	}
	T Back()
	{
		if (this->head == nullptr)
		{
			return -1;
		}
		else
		{
			return this->tail->data;
		}
	}
};

enum Command
{
	push_front = 1,
	push_back,
	pop_front,
	pop_back,
	size,
	empty,
	front,
	back
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Deque<int> dq;
	int n;
	cin >> n;

	while (n--)
	{
		Command cmd;
		cin >>(int&)cmd;
		switch (cmd)
		{
			case Command::push_front:
			{
				int data;
				cin >> data;
				dq.push_front(data);
				break;
			}
			case Command::push_back:
			{
				int data;
				cin >> data;
				dq.push_back(data);
				break;
			}
			case Command::pop_front:
			{
				cout << dq.pop_front() << '\n';
				break;
			}
			case Command::pop_back:
			{
				cout << dq.pop_back() << '\n';
				break;
			}
			case Command::size:
			{
				cout << dq.Size() << '\n';
				break;
			}
			case Command::empty:
			{
				cout << dq.Empty() << '\n';
				break;
			}
			case Command::front:
			{
				cout << dq.Front() << '\n';
				break;
			}
			case Command::back:
			{
				cout << dq.Back() << '\n';
				break;
			}
			default:
				break;
		}
	}

	return 0;
}