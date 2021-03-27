// This file contain's an API registry.
// The class register's candidate APIs and return's registered APIs.

#pragma once

// C/C++ Includes
#include <map>
#include <memory>
#include <stdexcept>
#include <iostream>

// Common Toolbox Includes
#include "commonToolbox/interfaces/iRegistrableApi.h"
#include "commonToolbox/interfaceRegistry/apiId.h"

namespace commonToolbox::interfaceRegistry
{
class ApiProvider
{
public:
    template<typename T>
    void Register(std::shared_ptr<T>& ptr) noexcept
    {
        try
        {
            auto apiId{GetApiId<T>()};

            if (apiId == interfaceRegistry::Invalid_Api_Id)
                throw std::runtime_error{"API Provider::Register() : Invalid API ID"};

            if (!ptr)
                throw std::runtime_error{"API Provider::Register() : API is null"};

            auto it{registry_.find(apiId)};

            if (it != registry_.end())
                throw std::runtime_error{"API Provider::Register() : API has already been registered"};

            registry_.insert(std::make_pair(apiId, ptr));
        }
        catch (const std::exception& e)
        {
            std::cout << "\nApiProvider::Register() : An error occurred...";
            std::cout << "\nError Descriptor: " << e.what() << std::endl;

            ptr = nullptr;
        }
        catch (...)
        {
            std::cout << "\nApiProvider::Register() : An unknown occurred...";

            ptr = nullptr;
        }
    }

    template<typename T>
    std::shared_ptr<T> GetApi() noexcept
    {
        std::shared_ptr<T> api;

        try
        {
            auto apiId{GetApiId<T>()};
    
            if (apiId == interfaceRegistry::Invalid_Api_Id)
                throw std::runtime_error{"API Provider::GetApi() : Invalid API ID"};
    
            auto it{registry_.find(apiId)};

            if (it == registry_.end())
                throw std::runtime_error{"API Provider::GetApi() : API has not been previously registered"};

            api = std::static_pointer_cast<T>(it->second);
        }
        catch (const std::exception& e)
        {
            std::cout << "\nApiProvider::Register() : An error occurred...";
            std::cout << "\nError Descriptor: " << e.what() << std::endl;
        }
        catch (...)
        {
            std::cout << "\nApiProvider::Register() : An unknown error occurred...";
        }

        return api;
    }

protected:

private:
    std::map<ApiId, std::shared_ptr<interfaces::IRegistrableApi>> registry_;
};
}