//!
//! @file 			ShiftIntegerTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-25
//! @last-modified 	2014-09-13
//! @brief 			Contains unit tests which makes sure that the shift ('<<') operator works correctly with integers.
//! @details
//!					See README.rst in root dir for more info.

//===== SYSTEM LIBRARIES =====//
#include <cstdint>	// uint32_t, e.t.c

//====== USER LIBRARIES =====//
#include "MUnitTest/api/MUnitTestApi.hpp"

//===== USER SOURCE =====//
#include "../api/MStringApi.hpp"

namespace StringTestsNs
{

	MTEST(ShiftUint8RandomTest)
	{
		MbeddedNinja::MString myString("uint8 = ");

		myString << (uint8_t)200u;

		CHECK_EQUAL("uint8 = 200", myString);
	}

	MTEST(ShiftUint8MaxTest)
	{
		MbeddedNinja::MString myString("uint8 = ");

		myString << (uint8_t)255u;

		CHECK_EQUAL("uint8 = 255", myString);
	}

	MTEST(ShiftUint8MinTest)
	{
		MbeddedNinja::MString myString("uint8 = ");

		myString << (uint8_t)0u;

		CHECK_EQUAL("uint8 = 0", myString);
	}

	MTEST(ShiftInt8RandomTest)
	{
		MbeddedNinja::MString myString("int8 = ");

		myString << (int8_t)-72;

		CHECK_EQUAL("int8 = -72", myString);
	}

	MTEST(ShiftInt8MaxTest)
	{
		MbeddedNinja::MString myString("int8 = ");

		myString << (int8_t)127;

		CHECK_EQUAL("int8 = 127", myString);
	}

	MTEST(ShiftInt8MinTest)
	{
		MbeddedNinja::MString myString("int8 = ");

		myString << (int8_t)-127;

		CHECK_EQUAL("int8 = -127", myString);
	}

	MTEST(ShiftUint16RandomTest)
	{
		MbeddedNinja::MString myString("uint16 = ");

		myString << (uint16_t)1087u;

		CHECK_EQUAL("uint16 = 1087", myString);
	}

	MTEST(ShiftUint16MaxTest)
	{
		MbeddedNinja::MString myString("uint16 = ");

		myString << (uint16_t)65535u;

		CHECK_EQUAL("uint16 = 65535", myString);
	}

	MTEST(ShiftUint16MinTest)
	{
		MbeddedNinja::MString myString("uint16 = ");

		myString << (uint16_t)0;

		CHECK_EQUAL("uint16 = 0", myString);
	}

	MTEST(ShiftInt16RandomTest)
	{
		MbeddedNinja::MString myString("int16 = ");

		myString << (int16_t)-8788l;

		CHECK_EQUAL("int16 = -8788", myString);
	}

	MTEST(ShiftInt16MaxTest)
	{
		MbeddedNinja::MString myString("int16 = ");

		myString << (int16_t)32767;

		CHECK_EQUAL("int16 = 32767", myString);
	}

	MTEST(ShiftInt16MinTest)
	{
		MbeddedNinja::MString myString("int16 = ");

		myString << (int16_t)-32767;

		CHECK_EQUAL("int16 = -32767", myString);
	}

	MTEST(ShiftUint32RandomTest)
	{
		MbeddedNinja::MString myString("uint = ");

		myString << (uint32_t)5u;

		CHECK_EQUAL("uint = 5", myString);
	}

	MTEST(ShiftUint32MaxTest)
	{
		MbeddedNinja::MString myString("uint = ");

		myString << (uint32_t)4294967295u;

		CHECK_EQUAL("uint = 4294967295", myString);
	}

	MTEST(ShiftUint32MinTest)
	{
		MbeddedNinja::MString myString("uint = ");

		myString << (uint32_t)0;

		CHECK_EQUAL("uint = 0", myString);
	}

	MTEST(ShiftInt32RandomTest)
	{
		MbeddedNinja::MString myString("int = ");

		myString << (int32_t)-46l;

		CHECK_EQUAL("int = -46", myString);
	}

	MTEST(ShiftInt32MaxTest)
	{
		MbeddedNinja::MString myString("int = ");

		myString << (int32_t)2147483647l;

		CHECK_EQUAL("int = 2147483647", myString);
	}

	MTEST(ShiftInt32MinTest)
	{
		MbeddedNinja::MString myString("int = ");

		myString << (int32_t)-2147483647l;

		CHECK_EQUAL("int = -2147483647", myString);
	}

	MTEST(ShiftUint64RandomTest)
	{
		MbeddedNinja::MString myString("uint64 = ");

		// 6 giga is higher than 2^32
		myString << (uint64_t)6000000000llu;

		CHECK_EQUAL("uint64 = 6000000000", myString);
	}

	MTEST(ShiftUint64MaxTest)
	{
		MbeddedNinja::MString myString("uint64 = ");

		myString << (uint64_t)18446744073709551615llu;

		CHECK_EQUAL("uint64 = 18446744073709551615", myString);
	}

	MTEST(ShiftUint64MinTest)
	{
		MbeddedNinja::MString myString("uint64 = ");

		myString << (uint64_t)0llu;

		CHECK_EQUAL("uint64 = 0", myString);
	}

	MTEST(ShiftInt64RandomTest)
	{
		MbeddedNinja::MString myString("int64 = ");

		myString << (int64_t)-6000000000ll;

		CHECK_EQUAL("int64 = -6000000000", myString);
	}

	MTEST(ShiftInt64MaxTest)
	{
		MbeddedNinja::MString myString("int64 = ");

		myString << (int64_t)9223372036854775807ll;

		CHECK_EQUAL("int64 = 9223372036854775807", myString);
	}

	MTEST(ShiftInt64MinTest)
	{
		MbeddedNinja::MString myString("int64 = ");

		myString << (int64_t)-9223372036854775807ll;

		CHECK_EQUAL("int64 = -9223372036854775807", myString);
	}

} // namespace StringTestsNs
