// This file will contain a true Unit Test once Google Test is Referenced.

#include "commonToolbox/interfaceRegistry/apiId.h"

namespace commonToolbox::interfaceRegistry
{
template<>
inline ApiId GetApiId<uint8_t>()
{
	return ApiId{0x6dece7b4, 0xb4b, 0x49b8, {0xad, 0xbb, 0x3a, 0xdc, 0x7a, 0xaa, 0xe, 0x3}};
}

template<>
inline ApiId GetApiId<uint16_t>()
{
	return ApiId{0x234d59a6, 0x264e, 0x4dc0, {0xa9, 0x56, 0xc0, 0x4, 0xa2, 0x3c, 0x87, 0x4c}};
}

template<>
inline ApiId GetApiId<uint32_t>()
{
	return ApiId{0xf107298f, 0x7c00, 0x430d, {0xaf, 0x41, 0xfa, 0xb6, 0xdc, 0x1d, 0x9e, 0xfe}};
}
}

int main()
{
	commonToolbox::interfaceRegistry::ApiId apiIdUint8{commonToolbox::interfaceRegistry::GetApiId<uint8_t>()};
	commonToolbox::interfaceRegistry::ApiId apiIdUint16{commonToolbox::interfaceRegistry::GetApiId<uint16_t>()};
	commonToolbox::interfaceRegistry::ApiId apiIdUint32{commonToolbox::interfaceRegistry::GetApiId<uint32_t>()};

	return 0;
}