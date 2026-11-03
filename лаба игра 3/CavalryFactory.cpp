#include "CavalryFactory.h"

#include <stdexcept>
#include "Cataphract.h"
#include "HorseArcher.h"

std::unique_ptr<Unit> CavalryFactory::createUnit(UnitKind kind, int x, int y) const {
    if (kind == UnitKind::Cataphract) {
        return std::make_unique<Cataphract>(x, y);
    }
    if (kind == UnitKind::HorseArcher) {
        return std::make_unique<HorseArcher>(x, y);
    }
    throw std::invalid_argument("CavalryFactory cannot create this unit");
}