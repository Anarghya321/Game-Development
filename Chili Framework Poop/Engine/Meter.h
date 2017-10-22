#pragma once
#include "Graphics.h"

class Meter
{
public:
	Meter(int in_x,int in_y);
	void IncreaseLevel();
	int GetLevel() const;
	void Draw(Graphics& gfx) const;
private:
	static constexpr int grith = 12;
	static constexpr int scale = 4;
	int level = 0;
	int x;
	int y;
	static constexpr Color c = Colors::Blue;
};