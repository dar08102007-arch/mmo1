#include "LightArcher.h"

LightArcher::LightArcher(int x, int y)
	: Archer(Health(60), Armor(2), Attack(14), x, y) {
}

std::unique_ptr<Unit> LightArcher::clone() const {
	return std::make_unique<LightArcher>(*this);
}

std::string LightArcher::getType() const {
	return "LightArcher";
}

char LightArcher::symbol() const {
	return 'L';
}