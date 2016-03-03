#pragma once
#include "Button.h"
#include "Doodle.h"
class TowerUpdateMenu 
{
private:
	Button m_HealthButton;
	Button m_DamageButton;
	Button m_RangeButton;
	Button m_ASpeedButton;
	
	Doodle m_Doodle;
public:
	TowerUpdateMenu();
	~TowerUpdateMenu();
	
	void Init();
	void DrawTowerMenu();
};

