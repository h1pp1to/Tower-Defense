#include "Tower.h"


Tower::Tower() :
Health(10),
Range(100),
Damage(1),
AtackSpeed(std::chrono::milliseconds(1000)),
TotalCoin(0)
{}


Tower::~Tower(){}

void Tower::UpdateHealth(){ Health += 10; }
void Tower::UpdateRange(){ Range += 10; }
void Tower::UpdateDamage(){ Damage += 1; }
void Tower::UpdateAtackSpeed() { AtackSpeed -= std::chrono::milliseconds(50); }

int Tower::GetHealth(){ return Health; }
int Tower::GetRange(){ return Range; }
int Tower::GetDamage(){ return Damage; }
std::chrono::milliseconds Tower::GetAtackSpeed(){ return AtackSpeed; }

void Tower::AddCoin(int CoinAmount){ TotalCoin += CoinAmount; }
int Tower::GetTotalCoin(){ return TotalCoin; }