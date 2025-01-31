﻿
#include "simplecs/c_api/c_core.hpp"
#include "simplecs/registry.h"

#include <cstdint>

struct traits
{
    using entity_type = size_t;
};

class dummy_impl
{
public:
    using traits = ::traits;

    constexpr traits::entity_type create_entity()
    {
        return 4;
    }

    void destroy_entity(const traits::entity_type&)
    {

    }
};

int main()
{
    struct with_traits
    {
        using traits [[maybe_unused]] = ::traits;
    };

    eld::generic::registry<dummy_impl> dummyRegistry{};
    dummyRegistry.destroy(dummyRegistry.create());


}