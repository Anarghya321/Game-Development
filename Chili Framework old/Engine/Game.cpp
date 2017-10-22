/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (SlowUp)
		{
		}
		else
		{
			vy -= 1;
			SlowUp = true;
		}
	}
	else
	{
		SlowUp = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (SlowDown)
		{
		}
		else
		{
			vy += 1;
			SlowDown = true;
		}
	}
	else
	{
		SlowDown = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if (SlowRight)
		{
		}
		else
		{
			vx += 1;
			SlowRight = true;
		}
	}
	else
	{
		SlowRight = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (SlowLeft)
		{
		}
		else
		{
			vx -= 1;
			SlowLeft = true;
		}
	}
	else
	{
		SlowLeft = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		vx = vy = 0;
	}
	y += vy;
	x += vx;
	if (x - 5 < 0)
	{
		x = 0;
		vx = -vx;
	}
	if (y + 5 >= gfx.ScreenHeight)
	{
		y = gfx.ScreenHeight - 6;
		vy = -vy;
	}
	if (y - 5 < 0)
	{
		y = 0;
		vy = -vy;
	}
	gb = 255;
	if (isColliding(z,200,x,y) || isColliding(x2, y2, x, y) || isColliding(x3, y3, x, y))
	{
		gb = 0;
		vx = -vx;
		vy = -vy;
		BoxMode = true;
	}
	
	//BoxMode = wnd.kbd.KeyIsPressed(VK_CONTROL);
}

void Game::ComposeFrame()
{
	CreateBox(x1, y1, 0, 0, 255);
	CreateBox(x2, y2, 255, 0, 0);
	CreateBox(x3, y3, 0, 255, 0);
	CreateBox(x, y, 255, gb, gb);
}

void Game::CreateBox(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x, y, r, g, b);
	gfx.PutPixel(x + 1, y, r, g, b);
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 3, y, r, g, b);
	gfx.PutPixel(x + 4, y, r, g, b);
	gfx.PutPixel(x + 5, y, r, g, b);
	gfx.PutPixel(x, y + 1, r, g, b);
	gfx.PutPixel(x, y + 2, r, g, b);
	gfx.PutPixel(x, y + 3, r, g, b);
	gfx.PutPixel(x, y + 4, r, g, b);
	gfx.PutPixel(x, y + 5, r, g, b);
	gfx.PutPixel(x + 1, y + 5, r, g, b);
	gfx.PutPixel(x + 2, y + 5, r, g, b);
	gfx.PutPixel(x + 3, y + 5, r, g, b);
	gfx.PutPixel(x + 4, y + 5, r, g, b);
	gfx.PutPixel(x + 5, y + 5, r, g, b);
	gfx.PutPixel(x + 5, y + 1, r, g, b);
	gfx.PutPixel(x + 5, y + 2, r, g, b);
	gfx.PutPixel(x + 5, y + 3, r, g, b);
	gfx.PutPixel(x + 5, y + 4, r, g, b);
	gfx.PutPixel(x + 5, y + 5, r, g, b);
}

void Game::CreateTarget(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(-5 + x, y, r, g, b);
	gfx.PutPixel(-4 + x, y, r, g, b);
	gfx.PutPixel(-3 + x, y, r, g, b);
	gfx.PutPixel(x + 5, y, r,  g, b);
	gfx.PutPixel(x + 4, y, r,  g, b);
	gfx.PutPixel(x + 3, y, r,  g, b);
	gfx.PutPixel(x, y - 5, r,  g, b);
	gfx.PutPixel(x, y - 4, r,  g, b);
	gfx.PutPixel(x, y - 3, r,  g, b);
	gfx.PutPixel(x, y + 3, r,  g, b);
	gfx.PutPixel(x, y + 4, r,  g, b);
	gfx.PutPixel(x, y + 5, r,  g, b);
}

bool Game::isColliding(int x1,int y1,int  x2,int  y2)
{
	const int xL = x1 - 5;
	const int xR = x1 + 5;
	const int yT = y1 - 5;
	const int yB = y1 + 5;

	const int x1L = x2 - 5;
	const int x1R = x2 + 5;
	const int y1T = y2 - 5;
	const int y1B = y2 + 5;

	return (xL < x1R && xR > x1L && yT < y1B && yB > y1T);
}