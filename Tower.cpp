#include "Tower.h"

//TODO(Borko) - use DRY principle to clean the code

void Tower::UpdateHealth()
{
	if (GetTotalCoin() - Health.CoinToUpdate >= 0)
	{
		Health.UpdateCost();
		Health.Value += Health.UpdateCounter * 5;
	}
}

void Tower::UpdateRange()
{
	if (GetTotalCoin() - Range.CoinToUpdate >= 0)
	{
		Range.UpdateCost();
		Range.Value += Range.Value;
	}
}

void Tower::UpdateDamage()
{
	if (GetTotalCoin() - Damage.CoinToUpdate >= 0)
	{
		Damage.UpdateCost();
		Damage.Value += Damage.Value;
	}
}

void Tower::UpdateAtackSpeed()
{
	if (GetTotalCoin() - AtackSpeed.CoinToUpdate >= 0)
	{
		AtackSpeed.UpdateCost();
		AtackSpeed.Value -= std::chrono::milliseconds(50);
	}
}

int Tower::GetHealth()
{
	return Health.Value;
}
int Tower::GetRange()
{
	return Range.Value;
}
int Tower::GetDamage()
{
	return Damage.Value;
}
std::chrono::milliseconds Tower::GetAtackSpeed()
{
	return AtackSpeed.Value;
}

void Tower::AddCoin(int CoinAmount)
{
	TotalCoin += CoinAmount;
}

void Tower::TakeCoin(int CoinAmount)
{
	TotalCoin = max(0, TotalCoin - CoinAmount);
}

int Tower::GetTotalCoin()
{
	return TotalCoin;
}