#include <stdio.h>
#include <string.h>

#define MAX  10
#define LEFT 0
#define UP 1
#define DOWN 2
#define RIGHT 3
#define RED 'R'
#define BLUE 'B'
#define WAR '#'
#define ROAD '.'
#define EXIT 'O'
#define FAIL -1
#define OK 1
#define FIND 0
#define MEET_BLUE 2

int n, m, out_x, out_y, ans;
int move[4][2] = { {0, -1}, {-1, 0}, {1, 0}, {0, 1} };
char map[MAX][MAX];

void swap(char& a, char& b)
{
	char temp = a;
	a = b;
	b = temp;
}

class Marble
{
public:
	char m_color;
	int m_x;
	int m_y;
	int m_last_dir;

	Marble()
	{
		m_color = 'O';
		m_x = 0;
		m_y = 0;
		m_last_dir = -1;
	};
	Marble(const Marble& _marble)
	{
		m_color = _marble.m_color;
		m_x = _marble.m_x;
		m_y = _marble.m_y;
		m_last_dir = _marble.m_last_dir;
	}
	void SetCurrent(int _x, int _y, int _dir)
	{
		m_x = _x;
		m_y = _y;
		m_last_dir = _dir;
	}
	void SetCurrent(char _color, int _x, int _y)
	{
		m_color = _color;
		m_x = _x;
		m_y = _y;
	}
	int Move(int _dir, char _map[][MAX])
	{
		int ret = OK;
		int temp_x = m_x + move[_dir][0];
		int temp_y = m_y + move[_dir][1];
		while (_map[temp_x][temp_y] == ROAD)
		{
			temp_x += move[_dir][0];
			temp_y += move[_dir][1];
		}

		switch (_map[temp_x][temp_y])
		{
		case RED:
		case WAR:
			temp_x -= move[_dir][0];
			temp_y -= move[_dir][1];
			swap(_map[temp_x][temp_y], _map[m_x][m_y]);
			SetCurrent(temp_x, temp_y, _dir);
			break;
		case EXIT:
			if (m_color == BLUE)
			{
				ret = FAIL;
			}
			else
			{
				char road = ROAD;
				swap(road, _map[m_x][m_y]);
				ret = FIND;
			}
			break;
		case BLUE:
			temp_x -= move[_dir][0];
			temp_y -= move[_dir][1];
			swap(_map[temp_x][temp_y], _map[m_x][m_y]);
			SetCurrent(temp_x, temp_y, _dir);
			ret = MEET_BLUE;
			break;
		}

		return ret;
	}
};

void FindExit(Marble _red, Marble _blue, int _cnt, char _map[][MAX])
{
	if (_cnt <= 10)
	{
		for (int dir = 0; dir < 4; ++dir)
		{
			if (_red.m_last_dir == dir || _red.m_last_dir + dir == 3)
			{
				continue;
			}
			Marble red(_red), blue(_blue);
			char temp_map[MAX][MAX];
			memcpy(temp_map, _map, sizeof(temp_map));
			int red_move_ret = red.Move(dir, temp_map);
			if (blue.Move(dir, temp_map) == FAIL)
			{
				continue;
			}
			if (red_move_ret == MEET_BLUE)
			{
				red.Move(dir, temp_map);
			}
			else if (red_move_ret == FIND)
			{
				if (ans == FAIL || ans > _cnt)
				{
					ans = _cnt;
				}
				break;
			}
			FindExit(red, blue, _cnt + 1, temp_map);
		}
	}
}

int main()
{
	Marble red, blue;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i)
	{
		scanf("%s", &map[i]);
		for (int j = 0; j < m; ++j)
		{
			if (map[i][j] == RED)
			{
				red.SetCurrent(map[i][j], i, j);
			}
			if (map[i][j] == BLUE)
			{
				blue.SetCurrent(map[i][j], i, j);
			}
			if (map[i][j] == EXIT)
			{
				out_x = i;
				out_y = j;
			}
		}
	}
	
	ans = FAIL;
	FindExit(red, blue, 1, map);

	printf("%d\n", ans);

	return 0;
}
