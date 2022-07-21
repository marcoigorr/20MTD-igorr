#pragma once

class MyMenu
{
public:
	float WIDTH = 600;
	float HEIGHT = 800;

	static void SetStyle();
	static void Draw();
};

extern MyMenu* Menu;


