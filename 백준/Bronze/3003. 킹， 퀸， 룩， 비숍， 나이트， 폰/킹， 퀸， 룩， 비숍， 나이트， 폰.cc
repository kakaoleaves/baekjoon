#include <iostream>

using namespace std;

const int KING = 1;
const int QUEEN = 1;
const int ROOK = 2;
const int BISHOP = 2;
const int KNIGHT = 2;
const int PAWN = 8;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int king, queen, rook, bishop, knight, pawn;

	cin >> king >> queen >> rook >> bishop >> knight >> pawn;
	cout << KING - king << " " << QUEEN - queen << " " << ROOK - rook << " " << BISHOP - bishop << " " << KNIGHT - knight << " " << PAWN - pawn << "\n";
		
	return 0;
}