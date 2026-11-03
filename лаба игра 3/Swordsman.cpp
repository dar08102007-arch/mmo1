#include "Swordsman.h"

Swordsman::Swordsman(int x, int y)
	: Infantry(Health(100), Armor(5), Attack(15), x, y) {
}

std::unique_ptr<Unit> Swordsman::clone() const {
	return std::make_unique<Swordsman>(*this);
}

std::string Swordsman::getType() const {
	return "Swordsman";
}

char Swordsman::symbol() const {
	return 'S';
}