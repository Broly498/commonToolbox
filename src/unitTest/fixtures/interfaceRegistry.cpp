// Unit Test Includes
#include "unitTest/fixtures/interfaceRegistry.h"

namespace commonToolbox::unitTest::fixtures
{
TEST_F(ApiIdTest, OperatorEqual)
{
    try
    {
        // This comparison should fail since the two API IDs are not equal.

        ASSERT_FALSE((emptyApiId_ == interfaceRegistry::ApiId{0x1c54b95, 0x4c77, 0x4fe1, {0x8e, 0x51, 0x99, 0x9e, 0xcf, 0x8e, 0xa3, 0xa6}}));
        
        // This comparison should succeed since the two API IDs are equal.

        ASSERT_TRUE(emptyApiId_ == interfaceRegistry::ApiId{});
    }
    catch (std::exception& e)
    {
        std::cout << "\nApiIdTest::OperatorEqual() : An error occurred...";
        std::cout << "\nError Descriptor: " << e.what();
    
        ASSERT_TRUE(false);
    }
}

TEST_F(ApiIdTest, OperatorNotEqual)
{
    try
    {
        // This comparison should fail since the two API IDs are equal.

        ASSERT_FALSE(emptyApiId_ != interfaceRegistry::ApiId{});
        
        // This comparison should succeed since the two API IDs are not equal.

        ASSERT_TRUE((emptyApiId_ != interfaceRegistry::ApiId{0x1c54b95, 0x4c77, 0x4fe1, {0x8e, 0x51, 0x99, 0x9e, 0xcf, 0x8e, 0xa3, 0xa6}}));
    }
    catch (std::exception& e)
    {
        std::cout << "\nApiIdTest::OperatorNotEqual() : An error occurred...";
        std::cout << "\nError Descriptor: " << e.what();
    
        ASSERT_TRUE(false);
    }
}

TEST_F(ApiIdTest, GreaterThan)
{
    try
    {
        // This comparison should fail since the two API IDs are equal.

        ASSERT_FALSE(emptyApiId_ > interfaceRegistry::ApiId{});

        // This comparison should fail since the leftmost API ID is lesser than the rightmost API ID.

        ASSERT_FALSE((emptyApiId_ > interfaceRegistry::ApiId{0x1c54b95, 0x4c77, 0x4fe1, {0x8e, 0x51, 0x99, 0x9e, 0xcf, 0x8e, 0xa3, 0xa6}}));
        
        // This comparison should succeed since the leftmost API ID is greater than the rightmost API ID.

        ASSERT_TRUE((interfaceRegistry::ApiId{0x1c54b95, 0x4c77, 0x4fe1, {0x8e, 0x51, 0x99, 0x9e, 0xcf, 0x8e, 0xa3, 0xa6}} > emptyApiId_));
    }
    catch (std::exception& e)
    {
        std::cout << "\nApiIdTest::GreaterThan() : An error occurred...";
        std::cout << "\nError Descriptor: " << e.what();
    
        ASSERT_TRUE(false);
    }
}

TEST_F(ApiIdTest, LesserThan)
{
    try
    {
        // This comparison should fail since the two API IDs are equal.

        ASSERT_FALSE(emptyApiId_ < interfaceRegistry::ApiId{});

        // This comparison should fail since the leftmost API ID is greater than the rightmost API ID.

        ASSERT_FALSE((interfaceRegistry::ApiId{0x1c54b95, 0x4c77, 0x4fe1, {0x8e, 0x51, 0x99, 0x9e, 0xcf, 0x8e, 0xa3, 0xa6}} < emptyApiId_));

        // This comparison should succeed since the leftmost API ID is lesser than the rightmost API ID.

        ASSERT_TRUE((emptyApiId_ < interfaceRegistry::ApiId{0x1c54b95, 0x4c77, 0x4fe1, {0x8e, 0x51, 0x99, 0x9e, 0xcf, 0x8e, 0xa3, 0xa6}}));
    }
    catch (std::exception& e)
    {
        std::cout << "\nApiIdTest::LesserThan() : An error occurred...";
        std::cout << "\nError Descriptor: " << e.what();
    
        ASSERT_TRUE(false);
    }
}

TEST_F(ApiIdTest, GreaterThanOrEqual)
{
    try
    {
        // This comparison should succeed since the two API IDs are equal.

        ASSERT_TRUE(emptyApiId_ >= interfaceRegistry::ApiId{});

        // This comparison should succeed since the leftmost API ID is greater than the rightmost API ID.

        ASSERT_TRUE((interfaceRegistry::ApiId{0x1c54b95, 0x4c77, 0x4fe1, {0x8e, 0x51, 0x99, 0x9e, 0xcf, 0x8e, 0xa3, 0xa6}} >= emptyApiId_));

        // This comparison should fail since the leftmost API ID is lesser than the rightmost API ID.

        ASSERT_FALSE((emptyApiId_ >= interfaceRegistry::ApiId{0x1c54b95, 0x4c77, 0x4fe1, {0x8e, 0x51, 0x99, 0x9e, 0xcf, 0x8e, 0xa3, 0xa6}}));
    }
    catch (std::exception& e)
    {
        std::cout << "\nApiIdTest::GreaterThanOrEqual() : An error occurred...";
        std::cout << "\nError Descriptor: " << e.what();
    
        ASSERT_TRUE(false);
    }
}

TEST_F(ApiIdTest, LessThanOrEqual)
{
    try
    {
        // This comparison should succeed since the two API IDs are equal.

        ASSERT_TRUE(emptyApiId_ <= interfaceRegistry::ApiId{});

        // This comparison should fail since the leftmost API ID is greater than the rightmost API ID.

        ASSERT_FALSE((interfaceRegistry::ApiId{0x1c54b95, 0x4c77, 0x4fe1, {0x8e, 0x51, 0x99, 0x9e, 0xcf, 0x8e, 0xa3, 0xa6}} <= emptyApiId_));

        // This comparison should succeed since the leftmost API ID is lesser than the rightmost API ID.

        ASSERT_TRUE((emptyApiId_ <= interfaceRegistry::ApiId{0x1c54b95, 0x4c77, 0x4fe1, {0x8e, 0x51, 0x99, 0x9e, 0xcf, 0x8e, 0xa3, 0xa6}}));
    }
    catch (std::exception& e)
    {
        std::cout << "\nApiIdTest::LessThanOrEqual() : An error occurred...";
        std::cout << "\nError Descriptor: " << e.what();
    
        ASSERT_TRUE(false);
    }
}

TEST_F(ApiProviderTest, RegisterApi)
{
    try
    {
        // This call should fail since no API ID template specialization function was defined for the InvalidApi class.

        std::shared_ptr<InvalidApi> invalidApi;

        apiProvider_.Register(invalidApi);

        ASSERT_EQ(invalidApi, nullptr);

        // This call should fail since the API is null.

        std::shared_ptr<ValidApi> emptyApi;

        apiProvider_.Register(emptyApi);

        ASSERT_EQ(emptyApi, nullptr);

        // This call should succeed since the API is initialized.

        auto initializedApi{std::make_shared<ValidApi>()};

        apiProvider_.Register(initializedApi);

        ASSERT_NE(initializedApi, nullptr);

        // This call should fail since the API has already been initialized.

        auto duplicateApi{std::make_shared<ValidApi>()};

        apiProvider_.Register(duplicateApi);

        ASSERT_EQ(duplicateApi, nullptr);
    }
    catch (std::exception& e)
    {
        std::cout << "\nApiProviderTest::RegisterApi() : An error occurred...";
        std::cout << "\nError Descriptor: " << e.what();
    
        ASSERT_TRUE(false);
    }
    catch (...)
    {
        std::cout << "\nApiProviderTest::RegisterApi() : An unknown error occurred...";

        ASSERT_TRUE(false);
    }
}

TEST_F(ApiProviderTest, GetApi)
{
    try
    {
        // This call should fail since no API ID template specialization function was defined for the InvalidApi class.

        std::shared_ptr<InvalidApi> invalidApi{apiProvider_.GetApi<InvalidApi>()};

        ASSERT_EQ(invalidApi, nullptr);

        // This call should fail since no APIs have been registered.

        std::shared_ptr<ValidApi> validApi{apiProvider_.GetApi<ValidApi>()};

        ASSERT_EQ(validApi, nullptr);

        // These calls should succeed since an initialized API has been previously registered.

        std::shared_ptr<ValidApi> initializedApi{std::make_shared<ValidApi>()};

        apiProvider_.Register(initializedApi);

        constexpr size_t numberOfQueries{10u};

        for (size_t it = 0u; it < numberOfQueries; ++it)
            ASSERT_NE(apiProvider_.GetApi<ValidApi>(), nullptr);
    }
    catch (std::exception& e)
    {
        std::cout << "\nApiProviderTest::GetApi() : An error occurred...";
        std::cout << "\nError Descriptor: " << e.what();
    
        ASSERT_TRUE(false);
    }
    catch (...)
    {
        std::cout << "\nApiProviderTest::GetApi() : An unknown error occurred...";

        ASSERT_TRUE(false);
    }
}
}