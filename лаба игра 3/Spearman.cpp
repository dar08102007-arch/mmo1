#include "Spearman.h"

Spearman::Spearman(int x, int y)
	: Infantry(Health(90), Armor(8), Attack(12), x, y) {
}

std::unique_ptr<Unit> Spearman::clone() const {
	return std::make_unique<Spearman>(*this);
}

std::string Spearman::getType() const {
	return "Spearman";
}

char Spearman::symbol() const {
	return 'P';
}