#include "HeavyArcher.h"

HeavyArcher::HeavyArcher(int x, int y)
	: Archer(Health(80), Armor(5), Attack(18), x, y) {
}

std::unique_ptr<Unit> HeavyArcher::clone() const {
	return std::make_unique<HeavyArcher>(*this);
}

std::string HeavyArcher::getType() const {
	return "HeavyArcher";
}

char HeavyArcher::symbol() const {
	return 'H';
}