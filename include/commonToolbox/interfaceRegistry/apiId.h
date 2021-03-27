// This file defines a 128-Bit API ID Class.

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

	ApiId& operator=(const ApiId&) noexcept = default;
	ApiId& operator=(ApiId&&) noexcept = default;

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

template<typename T>
inline ApiId GetApiId()
{
	return ApiId{};
}
}