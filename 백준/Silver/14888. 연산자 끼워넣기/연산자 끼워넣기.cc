#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

#define MAX 1'000'000'000
#define MIN -1'000'000'000
#define ADD 0
#define SUB 1
#define MUL 2
#define DIV 3

int maximum = MIN;
int minimum = MAX;

void backtracking(vector<int>& seq, int add, int sub, int mul, int div, vector<int>& op)
{
	if (add == 0 && sub == 0 && mul == 0 && div == 0)
	{
		// calculate
		int result = seq[0];
		for (int i = 0; i < seq.size() - 1; i++)
		{
			switch (op[i])
			{
			case ADD:
				result += seq[i + 1];
				break;
			case SUB:
				result -= seq[i + 1];
				break;
			case MUL:
				result *= seq[i + 1];
				break;
			case DIV:
				result /= seq[i + 1];
				break;
			default:
				break;
			}
		}

		if (result > maximum)
			maximum = result;
		if (result < minimum)
			minimum = result;

	}
	else
	{
		if (add > 0)
		{
			op.push_back(ADD);
			backtracking(seq, add - 1, sub, mul, div, op);
			op.pop_back();
		}
		if (sub > 0)
		{
			op.push_back(SUB);
			backtracking(seq, add, sub - 1, mul, div, op);
			op.pop_back();
		}
		if (mul > 0)
		{
			op.push_back(MUL);
			backtracking(seq, add, sub, mul - 1, div, op);
			op.pop_back();
		}
		if (div > 0)
		{
			op.push_back(DIV);
			backtracking(seq, add, sub, mul, div - 1, op);
			op.pop_back();
		}
	}
}

int main()
{
	fastio;

	int n;
	int add;
	int sub;
	int mul;
	int div;
	vector<int> seq;
	vector<int> op;

	cin >> n;
	seq.resize(n);

	for (auto& i : seq)
		cin >> i;

	cin >> add >> sub >> mul >> div;

	backtracking(seq, add, sub, mul, div, op);

	cout << maximum << "\n";
	cout << minimum << "\n";


	return 0;
}