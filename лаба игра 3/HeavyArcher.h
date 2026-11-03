#pragma once
#include "Archer.h"

class HeavyArcher : public Archer {
public:
	HeavyArcher(int x, int y);

	std::unique_ptr<Unit> clone() const override;
	std::string getType() const override;
	char symbol() const override;
};
