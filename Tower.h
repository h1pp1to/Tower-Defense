#pragma once
#include <chrono>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

//TODO(Borko) - Create formula to gold cost and update value of combo
class Tower
{
	template <class type>
	struct Combo
	{
		string infoID;
		type Value;
		int CoinToUpdate;
		int UpdateCounter;
		Combo(string ID, type val) :
			infoID(ID), Value(val), CoinToUpdate(10), UpdateCounter(0)
		{}

		void UpdateCost()
		{
			UpdateCounter++;
			CoinToUpdate += CoinToUpdate;
		}
	};

	Combo<int> Health = Combo<int>{ "Health", 10 };
	Combo<int> Range = Combo<int>{ "Range", 100 };
	Combo<int> Damage = Combo<int>{ "Damage", 1 };
	Combo<std::chrono::milliseconds> AtackSpeed = 
		Combo<std::chrono::milliseconds>{ "Atack Speed", std::chrono::milliseconds(1000) };

	int TotalCoin;

	Tower::Tower() : TotalCoin(INT_MAX) {}
	Tower(const Tower&) = delete;
	Tower& operator=(const Tower&) = delete;
public:
	~Tower(){}
	static Tower& Instance()
	{
		static Tower *Instance = new Tower;
		return *Instance;
	}
	
	void UpdateHealth();
	void UpdateRange();
	void UpdateDamage();
	void UpdateAtackSpeed();

	int GetHealth();
	int GetRange();
	int GetDamage();
	std::chrono::milliseconds GetAtackSpeed();
	
	void AddCoin(int CoinAmount);
	void TakeCoin(int CoinAmount);
	int GetTotalCoin();

	void DEBUG()
	{
		cout << "NAME   VALUE     CoinToUpdate    UpdateCounter " << endl;
		cout << Health.infoID << " " << Health.Value << " " << Health.CoinToUpdate << " " << Health.UpdateCounter << endl;
		cout << Range.infoID << " " << Range.Value << " " << Range.CoinToUpdate << " " << Range.UpdateCounter << endl;
		cout << Damage.infoID << " " << Damage.Value << " " << Damage.CoinToUpdate << " " << Damage.UpdateCounter << endl;
		cout << AtackSpeed.infoID << " " << AtackSpeed.CoinToUpdate << " " << AtackSpeed.UpdateCounter << endl;
		cout << endl;
	}
};

