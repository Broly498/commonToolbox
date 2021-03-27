// This file contains Interface Registry Test Fixtures.

#pragma once

// Google Test Includes
#include "gtest/gtest.h"

// Common Toolbox Includes
#include "commonToolbox/interfaceRegistry/apiId.h"
#include "commonToolbox/interfaceRegistry/apiProvider.h"

namespace commonToolbox::unitTest::fixtures
{
class ApiIdTest : public ::testing::Test
{
public:

protected:
    virtual void SetUp() override {}
    
    virtual void TearDown() override {}

    static constexpr interfaceRegistry::ApiId emptyApiId_{};

private:
};

class ApiProviderTest : public ::testing::Test
{
public:

protected:
    virtual void SetUp() override {}
    
    virtual void TearDown() override {}

    interfaceRegistry::ApiProvider apiProvider_;
private:
};

class InvalidApi : public interfaces::IRegistrableApi
{
public:
    InvalidApi() noexcept = default;
    ~InvalidApi() noexcept = default;

    InvalidApi(const InvalidApi&) noexcept = default;
    InvalidApi(InvalidApi&&) noexcept = default;

    InvalidApi& operator=(const InvalidApi&) noexcept = default;
    InvalidApi& operator=(InvalidApi&&) noexcept = default;

protected:

private:
};

class ValidApi : public interfaces::IRegistrableApi
{
public:
    ValidApi() noexcept = default;
    ~ValidApi() noexcept = default;

    ValidApi(const ValidApi&) noexcept = default;
    ValidApi(ValidApi&&) noexcept = default;

    ValidApi& operator=(const ValidApi&) noexcept = default;
    ValidApi& operator=(ValidApi&&) noexcept = default;

protected:

private:
};
}

namespace commonToolbox::interfaceRegistry
{
template<>
inline ApiId GetApiId<unitTest::fixtures::ValidApi>()
{
    return {0x76d111c6, 0x93f2, 0x49cc, {0x9e, 0xf, 0x51, 0x2, 0x71, 0x65, 0x3b, 0xb1}};
}
}