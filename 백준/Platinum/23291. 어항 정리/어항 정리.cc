#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cstdlib>

#define MAX_N 100

using namespace std;

int n, k;

// 밀가루 양을 관리합니다.
int arr[MAX_N];

// 동시에 일어나는 처리를 깔끔하게 하기 위해 사용되는 배열입니다.
int temp[MAX_N];

int elapsed_time;

void AddOne() {
    // 최솟값을 찾아 전부 1씩 더해줍니다.
    int min_val = INT_MAX;
    for (int i = 0; i < n; i++)
        min_val = min(min_val, arr[i]);

    for (int i = 0; i < n; i++)
        if (arr[i] == min_val)
            arr[i]++;
}

// (row_num, col_num)판을 기준으로 
// 시계방향으로 90' 회전한 이후의 위치를 구합니다.
void Rotate(vector<pair<int, int> >& flours, int row_num, int col_num) {
    for (int i = 0; i < n; i++) {
        int x, y;
        tie(x, y) = flours[i];
        flours[i] = make_pair(y, row_num - x + 1);
    }
}

// 도우를 말아줍니다.
vector<pair<int, int> > RollUp() {
    // 말아올려진 후, 각 숫자들의 위치를 구해줍니다.
    vector<pair<int, int> > flours(n);

    // 처음 2개를 놓고 시작합니다.
    flours[0] = make_pair(1, 1);
    flours[1] = make_pair(2, 1);
    int row_num = 2, col_num = 1;

    int s_index = 2;
    // 계속 말아 올려질때까지 반복합니다.
    while (s_index + row_num <= n) {
        // 기존 숫자들은 90' 회전시켜줍니다.
        Rotate(flours, row_num, col_num);

        // 새롭게 추가되는 숫자들의 위치를 잡아줍니다.
        for (int i = 1; i <= row_num; i++)
            flours[s_index++] = make_pair(col_num + 1, i);

        // 말아 올려진 이후의 row, col 개수를 갱신합니다.
        if (row_num == col_num + 1)
            col_num++;
        else
            row_num++;
    }

    // 남아있는 부분의 위치를 계산합니다.
    int delta = 1;
    while (s_index < n) {
        flours[s_index++] = make_pair(row_num, col_num + delta);
        delta++;
    }

    return flours;
}

void ReArrange(vector<pair<int, int> > flours) {
    // temp를 초기화해줍니다.
    for (int i = 0; i < n; i++)
        temp[i] = 0;

    // 열은 오름차순, 행은 내림차순이 되도록 정렬한 뒤, temp에 넣어줍니다.
    vector<tuple<int, int, int> > extended_flours;
    for (int i = 0; i < n; i++) {
        int x, y;
        tie(x, y) = flours[i];
        extended_flours.push_back(make_tuple(y, -x, i));
    }
    sort(extended_flours.begin(), extended_flours.end());

    for (int i = 0; i < n; i++) {
        int prev_index;
        tie(ignore, ignore, prev_index) = extended_flours[i];
        temp[i] = arr[prev_index];
    }

    // temp 값을 다시 arr에 옮겨줍니다.
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}

// 두 위치가 인접한 곳인지를 판단합니다.
bool Adjacency(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2) == 1;
}

void Press(vector<pair<int, int> > flours) {
    // temp를 초기화해줍니다.
    for (int i = 0; i < n; i++)
        temp[i] = arr[i];

    // 인접한 쌍끼리 밀가루 양을 서로 옮겨줍니다.
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x1, y1, x2, y2;
            tie(x1, y1) = flours[i];
            tie(x2, y2) = flours[j];
            if (Adjacency(x1, y1, x2, y2)) {
                if (arr[i] > arr[j]) {
                    temp[i] -= (arr[i] - arr[j]) / 5;
                    temp[j] += (arr[i] - arr[j]) / 5;
                }
                else {
                    temp[i] += (arr[j] - arr[i]) / 5;
                    temp[j] -= (arr[j] - arr[i]) / 5;
                }
            }
        }
    }

    // temp 값을 다시 arr에 옮겨줍니다.
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];

    // 이제 행이 높은 순서대로 다시 펴주는 작업을 합니다.
    ReArrange(flours);
}


vector<pair<int, int> > Fold() {
    vector<pair<int, int> > flours(n);
    // 한번 접은 후의 위치 구하기
    for (int i = 0; i < n / 2; i++)
        flours[i] = make_pair(1, n / 2 - i);
    for (int i = n / 2; i < n; i++)
        flours[i] = make_pair(2, i - (n / 2) + 1);

    // 두번 접은 후의 위치 구하기
    for (int i = 0; i < n; i++) {
        int x, y;
        tie(x, y) = flours[i];

        // 접었을 때 위로 올라가는 부분
        if (y <= n / 4)
            flours[i] = make_pair(3 - x, n / 4 - y + 1);
        // 접었을 때 아래에 남아있는 부분
        else
            flours[i] = make_pair(x + 2, y - n / 4);
    }

    return flours;
}

void Simulate() {
    // Step 1. 가장 작은 숫자를 찾아 전부 1을 증가시켜줍니다.
    AddOne();

    // Step 2. 도우를 말아줍니다.
    vector<pair<int, int> > flours = RollUp();

    // Step 3. 도우를 꾹 눌러줍니다.
    Press(flours);

    // Step 4. 도우를 두 번 반으로 접어줍니다.
    flours = Fold();

    // Step 5. 도우를 한번 더 꾹 눌러줍니다.
    Press(flours);

    // 횟수를 증가시켜줍니다.
    elapsed_time++;
}

bool End() {
    // 전부 차이가 k 이내인지 판단합니다.
    int min_val = INT_MAX;
    int max_val = INT_MIN;
    for (int i = 0; i < n; i++) {
        min_val = min(min_val, arr[i]);
        max_val = max(max_val, arr[i]);
    }

    return max_val - min_val <= k;
}

int main() {
    // 입력:
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // 차이가 k보다 크다면 계속 반복합니다.
    while (!End())
        Simulate();

    cout << elapsed_time;
    return 0;
}