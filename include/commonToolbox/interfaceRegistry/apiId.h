// This file defines a 128-Bit API ID Class.

#pragma once

// C/C++ Includes
#include <stdint.h>
#include <array>

namespace commonToolbox::interfaceRegistry
{
class ApiId
{
public:
    ApiId() noexcept = default;
    ~ApiId() noexcept = default;

    ApiId(const ApiId&) noexcept = default;
    ApiId(ApiId&&) noexcept = default;

    ApiId& operator=(const ApiId&) = default;
    ApiId& operator=(ApiId&&) = default;

    bool operator==(const ApiId& other) const noexcept
    {
        return v1_ == other.v1_ &&
               v2_ == other.v2_ &&
               v3_ == other.v3_ &&
               v4_ == other.v4_;
    }

    bool operator!=(const ApiId& other) const noexcept { return !operator==(other); }

    bool operator<(const ApiId& other) const noexcept
    {
        return v1_ < other.v1_ ||
            v2_ < other.v2_ ||
            v3_ < other.v3_ ||
            v4_[0u] < other.v4_[0u] ||
            v4_[1u] < other.v4_[1u] ||
            v4_[2u] < other.v4_[2u] ||
            v4_[3u] < other.v4_[3u] ||
            v4_[4u] < other.v4_[4u] ||
            v4_[5u] < other.v4_[5u] ||
            v4_[6u] < other.v4_[6u] ||
            v4_[7u] < other.v4_[7u];
    }

    bool operator>(const ApiId& other) const noexcept
    {
        return v1_ > other.v1_ ||
               v2_ > other.v2_ ||
               v3_ > other.v3_ ||
               v4_[0u] > other.v4_[0u] ||
               v4_[1u] > other.v4_[1u] ||
               v4_[2u] > other.v4_[2u] ||
               v4_[3u] > other.v4_[3u] ||
               v4_[4u] > other.v4_[4u] ||
               v4_[5u] > other.v4_[5u] ||
               v4_[6u] > other.v4_[6u] ||
               v4_[7u] > other.v4_[7u];
    }

    bool operator>=(const ApiId& other) const noexcept { return (operator>(other) || operator==(other)); }

    bool operator<=(const ApiId& other) const noexcept { return (operator<(other) || operator==(other)); }

protected:

private:
    static constexpr size_t V4_SIZE_{8u};

    uint32_t v1_{0u};
    uint16_t v2_{0u};
    uint16_t v3_{0u};
    std::array<uint8_t, V4_SIZE_> v4_{0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u};

public:
    ApiId(
        const uint32_t v1, 
        const uint16_t v2,
        const uint16_t v3, 
        const std::array<uint8_t, V4_SIZE_>& v4)
        : v1_{v1},
          v2_{v2},
          v3_{v3},
          v4_{v4}
    {}
};

static constexpr ApiId Invalid_Api_Id;

template<typename T>
inline ApiId GetApiId()
{
    return Invalid_Api_Id;
}
}