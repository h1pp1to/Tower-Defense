#include "TowerUpdateMenu.h"


TowerUpdateMenu::TowerUpdateMenu(){}
TowerUpdateMenu::~TowerUpdateMenu(){}

//TODO - All coordinates to be automaticly calculate by Window Width and Height
void TowerUpdateMenu::Init()
{
	m_HealthButton.CreateButton(500, 40, Visualize::Instance().WINDOW_WIDTH - 530, 50);
	m_DamageButton.CreateButton(500, 100, Visualize::Instance().WINDOW_WIDTH - 530, 50);
	m_RangeButton.CreateButton(500, 160, Visualize::Instance().WINDOW_WIDTH - 530, 50);
	m_ASpeedButton.CreateButton(500, 220, Visualize::Instance().WINDOW_WIDTH - 530, 50);
}

void TowerUpdateMenu::HandleButtons(int xMouse, int yMouse)
{
	if (m_HealthButton.IsClicked(xMouse, yMouse)) 
	{
		Tower::Instance().UpdateHealth();
	}
	
	if (m_DamageButton.IsClicked(xMouse, yMouse))
	{
		Tower::Instance().UpdateDamage();
	}

	if (m_RangeButton.IsClicked(xMouse, yMouse))
	{
		Tower::Instance().UpdateRange();
	}

	if (m_ASpeedButton.IsClicked(xMouse, yMouse))
	{
		Tower::Instance().UpdateAtackSpeed();
	}
}

void TowerUpdateMenu::DrawTowerMenu()
{
	m_Doodle.SetColor(120, 200, 30);
	m_Doodle.DrawRect(490, 20,
		Visualize::Instance().WINDOW_WIDTH - 510,
		Visualize::Instance().WINDOW_HEIGHT - 40);
	
	m_Doodle.SetColor(255, 40, 40);
	m_Doodle.DrawRect(m_HealthButton.GetRect());
	m_Doodle.DrawRect(m_DamageButton.GetRect());
	m_Doodle.DrawRect(m_RangeButton.GetRect());
	m_Doodle.DrawRect(m_ASpeedButton.GetRect());
	m_Doodle.DrawRect(500, 280, Visualize::Instance().WINDOW_WIDTH - 530, 50);
}

