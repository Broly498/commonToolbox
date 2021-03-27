// This is the base class for all APIs.
// Candidate APIs should inherit from this class in order to be registered by the API Provider class.

#pragma once

namespace commonToolbox::interfaces
{
class IRegistrableApi
{
public:
    ~IRegistrableApi() noexcept = default;

    IRegistrableApi(const IRegistrableApi&) noexcept = default;
    IRegistrableApi(IRegistrableApi&&) noexcept = default;

    IRegistrableApi& operator=(const IRegistrableApi&) noexcept = default;
    IRegistrableApi& operator=(IRegistrableApi&&) noexcept = default;

protected:
    IRegistrableApi() noexcept = default;

private:
};
}