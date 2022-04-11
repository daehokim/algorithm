#include <iostream>
using namespace std;

int N, M, x, y, K;
int map[20][20] = { 0, };
int dir[5][2] = { {0,0}, {0,1}, {0,-1}, {-1,0}, {1,0} };

struct Dice
{
	int top;
	int bottom;
	int left;
	int right;
	int front;
	int back;

	Dice()
	{
		top = 0;
		bottom = 0;
		left = 0;
		right = 0;
		front = 0;
		back = 0;
	}

	void Update(int _dir)
	{
		int temp = bottom;;
		switch (_dir)
		{
		case 1:
			bottom = right;
			right = top;
			top = left;
			left = temp;
			break;
		case 2:
			bottom = left;
			left = top;
			top = right;
			right = temp;
			break;
		case 3:
			bottom = back;
			back = top;
			top = front;
			front = temp;
			break;
		case 4:
			bottom = front;
			front = top;
			top = back;
			back = temp;
			break;
		}
	}

	void Print()
	{
		cout << top << "\n";
	}
};

int main()
{
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> map[i][j];
		}
	}

	int input_dir = 0;
	int temp_x = 0, temp_y = 0;
	Dice dice;
	for (int i = 0; i < K; ++i)
	{
		cin >> input_dir;
		temp_x = x + dir[input_dir][0];
		temp_y = y + dir[input_dir][1];
		if (temp_x >= 0 && temp_y >= 0 && temp_x < N && temp_y < M)
		{
			dice.Update(input_dir);
			x = temp_x;
			y = temp_y;
			if (map[x][y] == 0)
			{
				map[x][y] = dice.bottom;
			}
			else
			{
				dice.bottom = map[x][y];
				map[x][y] = 0;
			}
			dice.Print();
		}
	}

	return 0;
}
