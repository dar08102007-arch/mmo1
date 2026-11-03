#include "Unit.h"

Unit::Unit(const Health& health, const Armor& armor, const Attack& attack, int x, int y)
	: health_(health), armor_(armor), attack_(attack), x_(x), y_(y) {
}

bool Unit::move(int newX, int newY, int fieldWidth, int fieldHeight) {
	if (newX < 0 || newY < 0 || newX >= fieldWidth || newY >= fieldHeight) {
		return false;
	}
	x_ = newX;
	y_ = newY;
	return true;
}

int Unit::takeDamage(int rawDamage) {
	int real = armor_.reduceDamage(rawDamage);
	health_.decrease(real);
	return real;
}

void Unit::setPosition(int x, int y) {
	x_ = x;
	y_ = y;
}