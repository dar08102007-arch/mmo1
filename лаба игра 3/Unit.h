#pragma once
#include <memory>
#include <string>
#include "Health.h"
#include "Armor.h"
#include "Attack.h"

class Unit {
public:
	Unit(const Health& health, const Armor& armor, const Attack& attack, int x, int y);
	virtual ~Unit(){}

	virtual std::unique_ptr<Unit> clone() const = 0;
	virtual std:: string getType() const = 0;
	virtual char symbol() const = 0;

	int getX() const { return x_; }
	int getY() const { return y_; }
	const Health& getHealth() const { return health_; }
	const Armor& getArmor() const { return armor_; }
	const Attack& getAttack() const { return attack_; }
	bool isAlive() const { return !health_.isZero(); }

	bool move(int newX, int newY, int fieldWidth, int fieldHeight);
	int takeDamage(int rawDamage);
	void setPosition(int x, int y);

private:
	Health health_;
	Armor armor_;
	Attack attack_;
	int x_;
	int y_;
};
