#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;

    long long pow2r1 = r1 * r1;
    long long pow2r2 = r2 * r2;

    for (int i = 0; i < r2/sqrt(2); i++)
    {
        long long pow2i = i * i;
        answer += sqrt(static_cast<double>(pow2r2 - pow2i)) - ceil(sqrt(static_cast<double>(pow2r1 - pow2i))) + 1;
    }
    
    answer *= 2;
    
    return answer;    
}