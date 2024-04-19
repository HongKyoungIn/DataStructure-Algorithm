#include <iostream>
#include <windows.h>

#define MAX_SIZE 1000
#define MAX 10

using namespace std;

struct Position {
	int x;
	int y;
};

template <typename T>
class Stack {
private:
	int _top;
	bool empty = 1; // 비어있다면 1, 데이터가 있다면 0
	Position Array[1000];

public:
	Stack() {
		_top = -1;
	}
	~Stack() {

	}

	void Push(T inputdata) {
		_top++;
		Array[_top] = inputdata;
	}

	void Pop() {
		Array[_top] = {NULL, NULL};
		_top--;
	}

	T Top() {
		return Array[_top];
	}

	bool Empty() {
		return Size() == 0 ? true : false;
	}

	int Size() {
		return _top + 1;
	}
};

enum EMAZETYPE {
	PATH,
	WALL,
	VISIT,
	BACK
}; // 0,1,2,3


void Render(int *a) {
	switch(*a) {
		case 1:
			*a = 35;
			break;
		case 2:
			*a = 86;
			break;
		case 3:
			*a = 66;
			break;
		default:
			*a = 32;
			break;
	}
}

int main() {
	int Maze[MAX][MAX] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1, 0, 1, 1, 0, 1},
		{1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 1, 1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1, 1, 1, 1, 1},
		{1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	int dirX[4] = {0, 1, 0, -1};
	int dirY[4] = {-1, 0, 1, 0};

	Stack<Position> stack;

	Position position = {1, 1};
	stack.Push(position);
	Maze[position.y][position.x] = VISIT;


	while(true) {
		Position currentPos = stack.Top();

		if(currentPos.x == 8 && currentPos.y == 8)
			break;
		// 백트래킹 확인하기 위한 변수
		bool back = true;
		// 서 남 동 북 넣음
		for(int i = 0; i < 4; i++) {
			Position nextPos;
			nextPos.x = currentPos.x + dirX[i];
			nextPos.y = currentPos.y + dirY[i];

			// 만약에 다음 위치가 길이라면
			if(Maze[nextPos.y][nextPos.x] == PATH) {
				Maze[nextPos.y][nextPos.x] = VISIT;
				stack.Push(nextPos);
				back = false;
				break;
			}
		}

		if(back) {
			// Maze[currentPos.y][currentPos.x] = BACK;
			Maze[stack.Top().y][stack.Top().x] = BACK;
			stack.Pop();
			Maze[stack.Top().y][stack.Top().x] = BACK;
		}
	}

	for(int i = 0; i < MAX; i++) {
		for(int j = 0; j < MAX; j++) {
			Render(&Maze[i][j]);
			cout << (char)Maze[i][j];
		}
		cout << endl;
	}

	cin.ignore();
	cin.get();

	return 0;
}