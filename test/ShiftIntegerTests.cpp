//!
//! @file 			ShiftIntegerTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-25
//! @last-modified 	2014-08-25
//! @brief 			Contains unit tests which makes sure that the shift ('<<') operator works correctly with integers.
//! @details
//!					See README.rst in root dir for more info.

// User libraries
#include "../lib/UnitTest++/src/UnitTest++.h"

// User source
#include "../api/StringApi.hpp"

namespace StringTestsNs
{
	SUITE(ShiftIntegerTests)
	{

		TEST(ShiftUint8RandomTest)
		{
			MbeddedNinja::String myString("uint8 = ");

			myString << (uint8_t)200u;

			// Check capacity is calculated correctly
			CHECK_EQUAL("uint8 = 200", myString.cStr);
		}

		TEST(ShiftUint8MaxTest)
		{
			MbeddedNinja::String myString("uint8 = ");

			myString << (uint8_t)255u;

			// Check capacity is calculated correctly
			CHECK_EQUAL("uint8 = 255", myString.cStr);
		}

		TEST(ShiftUint8MinTest)
		{
			MbeddedNinja::String myString("uint8 = ");

			myString << (uint8_t)0u;

			// Check capacity is calculated correctly
			CHECK_EQUAL("uint8 = 0", myString.cStr);
		}

		TEST(ShiftInt8RandomTest)
		{
			MbeddedNinja::String myString("int8 = ");

			myString << (int8_t)-72;

			// Check capacity is calculated correctly
			CHECK_EQUAL("int8 = -72", myString.cStr);
		}

		TEST(ShiftInt8MaxTest)
		{
			MbeddedNinja::String myString("int8 = ");

			myString << (int8_t)127;

			// Check capacity is calculated correctly
			CHECK_EQUAL("int8 = 127", myString.cStr);
		}

		TEST(ShiftInt8MinTest)
		{
			MbeddedNinja::String myString("int8 = ");

			myString << (int8_t)-127;

			// Check capacity is calculated correctly
			CHECK_EQUAL("int8 = -127", myString.cStr);
		}

		TEST(ShiftUint16RandomTest)
		{
			MbeddedNinja::String myString("uint16 = ");

			myString << (uint16_t)1087u;

			// Check capacity is calculated correctly
			CHECK_EQUAL("uint16 = 1087", myString.cStr);
		}

		TEST(ShiftUint16MaxTest)
		{
			MbeddedNinja::String myString("uint16 = ");

			myString << (uint16_t)65535u;

			// Check capacity is calculated correctly
			CHECK_EQUAL("uint16 = 65535", myString.cStr);
		}

		TEST(ShiftUint16MinTest)
		{
			MbeddedNinja::String myString("uint16 = ");

			myString << (uint16_t)0;

			// Check capacity is calculated correctly
			CHECK_EQUAL("uint16 = 0", myString.cStr);
		}

		TEST(ShiftInt16RandomTest)
		{
			MbeddedNinja::String myString("int16 = ");

			myString << (int16_t)-8788l;

			// Check capacity is calculated correctly
			CHECK_EQUAL("int16 = -8788", myString.cStr);
		}

		TEST(ShiftInt16MaxTest)
		{
			MbeddedNinja::String myString("int16 = ");

			myString << (int16_t)32767;

			// Check capacity is calculated correctly
			CHECK_EQUAL("int16 = 32767", myString.cStr);
		}

		TEST(ShiftInt16MinTest)
		{
			MbeddedNinja::String myString("int16 = ");

			myString << (int16_t)-32767;

			// Check capacity is calculated correctly
			CHECK_EQUAL("int16 = -32767", myString.cStr);
		}

		TEST(ShiftUint32RandomTest)
		{
			MbeddedNinja::String myString("uint = ");

			myString << (uint32_t)5u;

			// Check capacity is calculated correctly
			CHECK_EQUAL("uint = 5", myString.cStr);
		}

		TEST(ShiftUint32MaxTest)
		{
			MbeddedNinja::String myString("uint = ");

			myString << (uint32_t)4294967295u;

			// Check capacity is calculated correctly
			CHECK_EQUAL("uint = 4294967295", myString.cStr);
		}

		TEST(ShiftUint32MinTest)
		{
			MbeddedNinja::String myString("uint = ");

			myString << (uint32_t)0;

			// Check capacity is calculated correctly
			CHECK_EQUAL("uint = 0", myString.cStr);
		}

		TEST(ShiftInt32RandomTest)
		{
			MbeddedNinja::String myString("int = ");

			myString << (int32_t)-46l;

			// Check capacity is calculated correctly
			CHECK_EQUAL("int = -46", myString.cStr);
		}

		TEST(ShiftInt32MaxTest)
		{
			MbeddedNinja::String myString("int = ");

			myString << (int32_t)2147483647l;

			// Check capacity is calculated correctly
			CHECK_EQUAL("int = 2147483647", myString.cStr);
		}

		TEST(ShiftInt32MinTest)
		{
			MbeddedNinja::String myString("int = ");

			myString << (int32_t)-2147483647l;

			// Check capacity is calculated correctly
			CHECK_EQUAL("int = -2147483647", myString.cStr);
		}

		TEST(ShiftUint64RandomTest)
		{
			MbeddedNinja::String myString("uint64 = ");

			// 6 giga is higher than 2^32
			myString << (uint64_t)6000000000llu;

			// Check capacity is calculated correctly
			CHECK_EQUAL("uint64 = 6000000000", myString.cStr);
		}

		TEST(ShiftUint64MaxTest)
		{
			MbeddedNinja::String myString("uint64 = ");

			myString << (uint64_t)18446744073709551615llu;

			// Check capacity is calculated correctly
			CHECK_EQUAL("uint64 = 18446744073709551615", myString.cStr);
		}

		TEST(ShiftUint64MinTest)
		{
			MbeddedNinja::String myString("uint64 = ");

			myString << (uint64_t)0llu;

			// Check capacity is calculated correctly
			CHECK_EQUAL("uint64 = 0", myString.cStr);
		}

		TEST(ShiftInt64RandomTest)
		{
			MbeddedNinja::String myString("int64 = ");

			myString << (int64_t)-6000000000ll;

			// Check capacity is calculated correctly
			CHECK_EQUAL("int64 = -6000000000", myString.cStr);
		}

		TEST(ShiftInt64MaxTest)
		{
			MbeddedNinja::String myString("int64 = ");

			myString << (int64_t)9223372036854775807ll;

			// Check capacity is calculated correctly
			CHECK_EQUAL("int64 = 9223372036854775807", myString.cStr);
		}

		TEST(ShiftInt64MinTest)
		{
			MbeddedNinja::String myString("int64 = ");

			myString << (int64_t)-9223372036854775807ll;

			// Check capacity is calculated correctly
			CHECK_EQUAL("int64 = -9223372036854775807", myString.cStr);
		}

	} // SUITE(ShiftIntegerTests)
} // namespace StringTestsNs
