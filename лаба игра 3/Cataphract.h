#pragma once
#include "Cavalry.h"

class Cataphract : public Cavalry {
public:
	Cataphract(int x, int y);

	std::unique_ptr<Unit> clone() const override;
	std::string getType() const override;
	char symbol() const override;
};
