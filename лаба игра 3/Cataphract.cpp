#include "Cataphract.h"

Cataphract::Cataphract(int x, int y)
	: Cavalry(Health(150), Armor(15), Attack(20), x, y) {
}

std::unique_ptr<Unit> Cataphract::clone() const {
	return std::make_unique<Cataphract>(*this);
}

std::string Cataphract::getType() const {
	return "Cataphract";
}

char Cataphract::symbol() const {
	return 'C';
}