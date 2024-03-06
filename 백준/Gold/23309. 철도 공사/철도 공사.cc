#include <iostream>
#include <string>
using namespace std;

struct Node {
    int next;
    int prev;
};

Node nodes[100'0001];
int head = 0;
int tail = 0;

void PushBack(int data) {
    if (head == 0) {
        head = tail = data;
        nodes[data].next = nodes[data].prev = data;
    }
    else {
        nodes[tail].next = data;
        nodes[data].prev = tail;
        nodes[data].next = head;
        nodes[head].prev = data;
        tail = data;
    }
}

void Insert(int idx, bool isNext, int data) {
    if (isNext) { // idx와 다음 노드 사이에 삽입
        cout << nodes[idx].next << '\n'; // 다음 역의 고유 번호 출력
        nodes[data].prev = idx;
		nodes[data].next = nodes[idx].next;
		nodes[nodes[idx].next].prev = data;
		nodes[idx].next = data;
        if (tail == idx) tail = data; // idx가 마지막 노드일 경우 tail 갱신
	}
	else { // idx와 이전 노드 사이에 삽입
        cout << nodes[idx].prev << '\n'; // 이전 역의 고유 번호 출력
		nodes[data].next = idx;
		nodes[data].prev = nodes[idx].prev;
		nodes[nodes[idx].prev].next = data;
		nodes[idx].prev = data;
        if (head == idx) head = data; // idx가 첫 노드일 경우 head 갱신
    }
}

void Delete(int idx, bool isNext) {
    if (isNext) {
        int target = nodes[idx].next;
        cout << target << '\n'; // 다음 역의 고유 번호 출력

        nodes[nodes[target].prev].next = nodes[target].next;
        nodes[nodes[target].next].prev = nodes[target].prev;
        if (tail == target) tail = nodes[target].prev; // target이 마지막 노드일 경우 tail 갱신
	}
    else {
        int target = nodes[idx].prev;
		cout << target << '\n'; // 이전 역의 고유 번호 출력

		nodes[nodes[target].prev].next = nodes[target].next;
		nodes[nodes[target].next].prev = nodes[target].prev;
		if (head == target) head = nodes[target].next; // target이 첫 노드일 경우 head 갱신
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int tmp;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        PushBack(tmp);
	}

    while (m--) {
        char type1, type2;
        int i, j;
        cin >> type1 >> type2 >> i;

        if (type1 == 'B') {
            cin >> j;
            Insert(i, type2 == 'N', j);
        }
        else {
			Delete(i, type2 == 'N');
		}
    }

    return 0;
}