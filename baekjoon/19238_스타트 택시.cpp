#include <iostream>
#include <memory.h>
#include <map>
#include <queue>
using namespace std;

#define MAX_N 21
#define WALL 1
struct Passenger {
	int src_x;
	int src_y;
	int dst_x;
	int dst_y;
	Passenger(int _src_x, int _src_y, int _dst_x, int _dst_y)
	{
		src_x = _src_x;
		src_y = _src_y;
		dst_x = _dst_x;
		dst_y = _dst_y;
	}
	Passenger() 
	{
		src_x = 0;
		src_y = 0;
		dst_x = 0;
		dst_y = 0;
	}
	bool operator<(const Passenger& _p) const
	{
		if (src_x == _p.src_x)
		{
			return src_y > _p.src_y;
		}
		return src_x > _p.src_x;
	}
};

struct Taxi
{
	int x;
	int y;
	int fuel;
	Taxi(int _x, int _y, int _fuel)
	{
		x = _x;
		y = _y;
		fuel = _fuel;
	}
	Taxi()
	{
		x = 0;
		y = 0;
		fuel = 0;
	}
	bool operator<(const Taxi& _t) const
	{
		if (fuel == _t.fuel)
		{
			if (x == _t.x)
			{
				return y > _t.y;
			}
			return x > _t.x;
		}
		return fuel > _t.fuel;
	}
};

int N, M, L;
int Area[MAX_N][MAX_N] = { 0, };
int dir[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
map<pair<int, int>, Passenger> passenger_list;
Taxi taxi;

void StartTaxi();
Passenger FindPassenger();
int MoveTaxi(int, int);

int main()
{
	cin >> N >> M >> L;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> Area[i][j];
		}
	}
	cin >> taxi.x >> taxi.y;
	taxi.fuel = L;
	for (int i = 0; i < M; ++i)
	{
		Passenger p;
		cin >> p.src_x >> p.src_y >> p.dst_x >> p.dst_y;
		passenger_list.emplace(pair<int, int>(p.src_x, p.src_y), p);
	}

	for (int i = 0, size = passenger_list.size(); i < size; ++i)
	{
		StartTaxi();
		if (taxi.fuel < 0)
		{
			break;
		}
	}
	
	cout << taxi.fuel << endl;
	return 0;
}

void StartTaxi()
{
	Passenger p = FindPassenger();	// 가장 가까운 승객 찾기
	if (p.src_x == 0)	// 승객 못 찾음
	{
		taxi.fuel = -1;
		return;
	}
	if (taxi.fuel < 0)	// 승객 까지 이동 불가
	{
		taxi.fuel = -1;
		return;
	}
	int fuel = MoveTaxi(p.dst_x, p.dst_y);	// 승객 목적지로 배송
	if (taxi.fuel < 0)
	{
		taxi.fuel = -1;
		return;
	}
	taxi.fuel += fuel * 2; // 승객 이동에 사용 된 만큼 연료 보충

	passenger_list.erase({ p.src_x, p.src_y });
}

Passenger FindPassenger()
{
	auto p = passenger_list.find({ taxi.x, taxi.y });	// 택시 위치가 승객 위치랑 같음.
	if (p != passenger_list.end())
	{
		return p->second;
	}

	int area[MAX_N][MAX_N] = { 0, };
	memcpy(area, Area, sizeof(area));
	area[taxi.x][taxi.y] = 1;

	queue<Taxi> q;
	priority_queue<Passenger> pq;
	Taxi temp(taxi.x, taxi.y, 1);
	q.push(temp);

	while (q.empty() == false)
	{
		for (int i = 0, size = q.size(); i < size; ++i)
		{
			Taxi t = q.front();
			q.pop();
			for (int d = 0; d < 4; ++d)
			{
				int x = t.x + dir[d][0];
				int y = t.y + dir[d][1];
				if (x > 0 && y > 0 && x <= N && y <= N && area[x][y] != WALL)
				{
					auto p = passenger_list.find({ x, y });
					if (p != passenger_list.end()) // 택시 승객으로 이동
					{
						pq.push(p->second);
					}
					area[x][y] = WALL;
					Taxi temp(x, y, t.fuel + 1);
					q.push(temp);
				}
			}
		}
		if (pq.empty() == false)
		{
			Passenger p = pq.top();
			taxi.x = p.src_x;
			taxi.y = p.src_y;
			taxi.fuel -= (q.front().fuel - 1);
			return p;
		}
	}

	return Passenger();
}

int MoveTaxi(int _dst_x, int _dst_y)
{
	if (Area[_dst_x][_dst_y] == WALL)
	{
		taxi.fuel = -1;
		return -1;
	}
	int moving_cnt = 0;
	int area[MAX_N][MAX_N] = { 0, };
	memcpy(area, Area, sizeof(area));
	area[taxi.x][taxi.y] = 1;

	queue<Taxi> q;
	q.push(taxi);
	while (q.empty() == false)
	{
		++moving_cnt;
		for (int i = 0, size = q.size(); i < size; ++i)
		{
			Taxi t = q.front();
			q.pop();
			for (int d = 0; d < 4; ++d)
			{
				int x = t.x + dir[d][0];
				int y = t.y + dir[d][1];
				if (x > 0 && y > 0 && x <= N && y <= N && area[x][y] != WALL)
				{
					if (x == _dst_x && y == _dst_y)
					{
						taxi.x = _dst_x;
						taxi.y = _dst_y;
						taxi.fuel -= moving_cnt;
						return moving_cnt;
					}
					area[x][y] = WALL;
					Taxi temp(x, y, moving_cnt+1);
					q.push(temp);
				}
			}
		}
	}

	taxi.fuel = -1;

	return moving_cnt;
}
