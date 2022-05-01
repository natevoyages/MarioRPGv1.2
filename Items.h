#ifndef ITEMS_H
#define ITEMS_H

class Items
{
public:
	Items();

	void PrintMenuItems();

	void UseRedMushroom();

	void UseMegaRedMushroom();

	void UseGreenMushroom();

	void UseStar();

	void UsePowBlock();



private:
	int redMushroom;
	int megaRedMushroom;
	int star;
	int greenMushroom;
	int powBlock;

};
#endif