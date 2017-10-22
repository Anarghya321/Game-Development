#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Mouse.h"

class Dude
{
public:
	void Move();
	void Draw(Graphics& gfx) const;
	void Update(const Keyboard& kbd);
	void UpdateMouse(const Mouse& m);
	int GetX() const;
	int GetY() const;
    int Getw() const;
	int Geth() const;
private:
	int x=0;
	int y = 0;
	static constexpr int v = 3;
	static constexpr int w = 20;
	static constexpr int h = 20;

};