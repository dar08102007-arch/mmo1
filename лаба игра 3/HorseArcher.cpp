#include "HorseArcher.h"

HorseArcher::HorseArcher(int x, int y)
	: Cavalry(Health(90), Armor(4), Attack(16), x, y) {
}

std::unique_ptr<Unit> HorseArcher::clone() const {
	return std::make_unique<HorseArcher>(*this);
}

std::string HorseArcher::getType() const {
	return "HorseArcher";
}

char HorseArcher::symbol() const {
	return 'h';
}