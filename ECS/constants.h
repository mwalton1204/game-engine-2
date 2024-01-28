#pragma once

#include <cstdint>
#include <bitset>

using Entity = uint32_t;
const Entity MAX_ENTITIES = 50;

using Component = uint8_t;
const Component MAX_COMPONENTS = 10;

using ComponentSet = std::bitset<MAX_COMPONENTS>;