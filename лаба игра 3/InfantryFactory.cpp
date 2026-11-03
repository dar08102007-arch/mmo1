#include "InfantryFactory.h"

#include <stdexcept>
#include "Swordsman.h"
#include "Spearman.h"

std::unique_ptr<Unit> InfantryFactory::createUnit(UnitKind kind, int x, int y) const {
    if (kind == UnitKind::Swordsman) {
        return std::make_unique<Swordsman>(x, y);
    }
    if (kind == UnitKind::Spearman) {
        return std::make_unique<Spearman>(x, y);
    }
    throw std::invalid_argument("InfantryFactory cannot create this unit");
}