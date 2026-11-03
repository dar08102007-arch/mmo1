#include <iostream>
#include <utility>
#include "GameField.h"
#include "InfantryFactory.h"
#include "ArcherFactory.h"
#include "CavalryFactory.h"


void fillField(GameField& field) {
    InfantryFactory infantryFactory;
    ArcherFactory archerFactory;
    CavalryFactory cavalryFactory;

    field.spawn(infantryFactory, UnitKind::Swordsman, 1, 1);
    field.spawn(infantryFactory, UnitKind::Spearman, 2, 1);
    field.spawn(archerFactory, UnitKind::LightArcher, 10, 5);
    field.spawn(archerFactory, UnitKind::HeavyArcher, 20, 10);
    field.spawn(cavalryFactory, UnitKind::Cataphract, 5, 2);
    field.spawn(cavalryFactory, UnitKind::HorseArcher, 30, 15);
}

void scenario1() {
    std::cout << "      Scenario 1: field, factories, limits      " << std::endl;
    InfantryFactory infantryFactory;

    GameField field(40, 20, 6);
    fillField(field);
    std::cout << "size = " << field.size() << "/" << field.getMaxUnits() << std::endl;
    field.print();

    std::cout << "spawn when limit reached: "
        << field.spawn(infantryFactory, UnitKind::Swordsman, 0, 0) << std::endl;
    std::cout << "remove (1,1): " << field.removeUnit(1, 1) << std::endl;
    std::cout << "move (2,1)->(1,1): " << field.moveUnit(2, 1, 1, 1) << std::endl;
    std::cout << "move to outside the field: " << field.moveUnit(1, 1, -1, 1) << std::endl;
    field.print();
}


void scenario2() {
    std::cout << "      Scenario 2: deep copy      " << std::endl;
    GameField original(40, 20, 6);
    fillField(original);

    GameField copy = original;
    copy.getUnit(1, 1)->takeDamage(50);
    copy.removeUnit(5, 2);

    std::cout << "original (1,1) HP: " << original.getUnit(1, 1)->getHealth().getValue()
        << ", copy (1,1) HP: " << copy.getUnit(1, 1)->getHealth().getValue() << std::endl;
    std::cout << "original size = " << original.size()
        << ", copy size = " << copy.size() << std::endl;

    GameField assigned(2, 2, 1);
    assigned = original;
    std::cout << "assigned size = " << assigned.size()
        << ", width = " << assigned.getWidth() << std::endl;
}


void scenario3() {
    std::cout << "      Scenario 3: move      " << std::endl;
    GameField source(40, 20, 6);
    fillField(source);

    GameField moved = std::move(source);
    std::cout << "moved size = " << moved.size()
        << ", source size = " << source.size() << std::endl;

    GameField target(1, 1, 1);
    target = std::move(moved);
    std::cout << "target size = " << target.size()
        << ", moved size = " << moved.size() << std::endl;
}


void scenario4() {
    std::cout << "      Scenario 4: iterator      " << std::endl;
    GameField field(40, 20, 6);
    fillField(field);

    std::cout << "all units:" << std::endl;
    for (Unit& u : field) {
        std::cout << "  " << u.getType() << " at (" << u.getX() << "," << u.getY() << ")" << std::endl;
    }

    std::cout << "mass damage 70:" << std::endl;
    for (Unit& u : field) {
        u.takeDamage(70);
        std::cout << "  " << u.getType() << " HP " << u.getHealth().getValue() << std::endl;
    }

    std::cout << "removing dead during iteration:" << std::endl;
    for (GameFieldIterator i = field.begin(); i != field.end(); ) {
        if (!i->isAlive()) {
            std::cout << "  " << i->getType() << " removed" << std::endl;
            GameFieldIterator next = i;
            ++next;
            field.removeUnitByIndex(i.cellIndex());
            i = next;
        }
        else {
            ++i;
        }
    }
    std::cout << "size = " << field.size() << std::endl;
    field.print();
}

int main() {
    scenario1();
    scenario2();
    scenario3();
    scenario4();
    return 0;
}