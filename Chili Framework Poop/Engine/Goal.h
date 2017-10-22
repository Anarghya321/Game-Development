#pragma once
#include "Graphics.h"
#include "Dude.h"

class Goal
{
public:
	Goal(int in_x, int in_y);
	void Draw(Graphics& gfx) const;
	bool isCollect(Dude& d) const;
	void Respawn(int r_x, int r_y);
	void UpdateColor();
private:
	Color c = (0, 0, 127);
	static constexpr int dim = 20;
	int x;
	int y;
	bool ChangeColor = true;
};