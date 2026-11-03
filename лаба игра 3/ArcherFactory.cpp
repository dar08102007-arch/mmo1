#include "ArcherFactory.h"

#include <stdexcept>
#include "LightArcher.h"
#include "HeavyArcher.h"

std::unique_ptr<Unit> ArcherFactory::createUnit(UnitKind kind, int x, int y) const {
    if (kind == UnitKind::LightArcher) {
        return std::make_unique<LightArcher>(x, y);
    }
    if (kind == UnitKind::HeavyArcher) {
        return std::make_unique<HeavyArcher>(x, y);
    }
    throw std::invalid_argument("ArcherFactory cannot create this unit");
}