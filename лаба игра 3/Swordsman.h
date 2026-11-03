#pragma once
#include "Infantry.h"

class Swordsman : public Infantry {
public:
	Swordsman(int x, int y);

	std::unique_ptr<Unit> clone() const override;
	std::string getType() const override;
	char symbol() const override;
};