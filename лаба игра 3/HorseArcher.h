#pragma once
#include "Cavalry.h"

class HorseArcher : public Cavalry {
public:
	HorseArcher(int x, int y);

	std::unique_ptr<Unit> clone() const override;
	std::string getType() const override;
	char symbol() const override;
};