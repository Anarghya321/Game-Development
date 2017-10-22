#include "Goal.h"

Goal::Goal(int in_x, int in_y)
{
	x = in_x;
	y = in_y;
}

void Goal::Draw(Graphics & gfx) const
{
	gfx.DrawRectDim(x, y, dim, dim, c);
}

bool Goal::isCollect(Dude & d) const
{
	const int dright = d.GetX() + d.Getw();
	const int dbottom = d.GetY() + d.Geth();
	const int pright = x + dim;
	const int pbottom = y + dim;

	return (dright >= x && d.GetX() <= pright && dbottom >= y && d.GetY() <= pbottom);
}

void Goal::Respawn(int r_x, int r_y)
{
	x = r_x;
	y = r_y;
}

void Goal::UpdateColor()
{
	if (ChangeColor)
	{
		if (c.GetB() >= 253)
		{
			ChangeColor = false;
		}
		else
		{
			c = Color(c.GetR() + 4, c.GetG() + 4, c.GetB() + 2);
		}
	}
	else
	{
		if (c.GetB() <= 127)
		{
			ChangeColor = true;
		}
		else
		{
			c = Color(c.GetR() - 4, c.GetG() - 4, c.GetB() - 2);
		}
	}
}
