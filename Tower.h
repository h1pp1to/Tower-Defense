#pragma once

#include <chrono>
class Tower
{
	int Health;
	int Range;
	int Damage;
	std::chrono::milliseconds AtackSpeed;

	int TotalCoin;
public:
	Tower();
	~Tower();

	void UpdateHealth();
	void UpdateRange();
	void UpdateDamage();
	void UpdateAtackSpeed();

	int GetHealth();
	int GetRange();
	int GetDamage();
	std::chrono::milliseconds GetAtackSpeed();
	
	void AddCoin(int CoinAmount);
	int GetTotalCoin();
};

