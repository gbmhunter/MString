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

		CHECK_EQUAL(myString, "uint8 = 200");
	}

	MTEST(ShiftUint8MaxTest)
	{
		MbeddedNinja::MString myString("uint8 = ");

		myString << (uint8_t)255u;

		CHECK_EQUAL(myString, "uint8 = 255");
	}

	MTEST(ShiftUint8MinTest)
	{
		MbeddedNinja::MString myString("uint8 = ");

		myString << (uint8_t)0u;

		CHECK_EQUAL(myString, "uint8 = 0");
	}

	MTEST(ShiftInt8RandomTest)
	{
		MbeddedNinja::MString myString("int8 = ");

		myString << (int8_t)-72;

		CHECK_EQUAL(myString, "int8 = -72");
	}

	MTEST(ShiftInt8MaxTest)
	{
		MbeddedNinja::MString myString("int8 = ");

		myString << (int8_t)127;

		CHECK_EQUAL(myString, "int8 = 127");
	}

	MTEST(ShiftInt8MinTest)
	{
		MbeddedNinja::MString myString("int8 = ");

		myString << (int8_t)-127;

		CHECK_EQUAL(myString, "int8 = -127");
	}

	MTEST(ShiftUint16RandomTest)
	{
		MbeddedNinja::MString myString("uint16 = ");

		myString << (uint16_t)1087u;

		CHECK_EQUAL(myString, "uint16 = 1087");
	}

	MTEST(ShiftUint16MaxTest)
	{
		MbeddedNinja::MString myString("uint16 = ");

		myString << (uint16_t)65535u;

		CHECK_EQUAL(myString, "uint16 = 65535");
	}

	MTEST(ShiftUint16MinTest)
	{
		MbeddedNinja::MString myString("uint16 = ");

		myString << (uint16_t)0;

		CHECK_EQUAL(myString, "uint16 = 0");
	}

	MTEST(ShiftInt16RandomTest)
	{
		MbeddedNinja::MString myString("int16 = ");

		myString << (int16_t)-8788l;

		CHECK_EQUAL(myString, "int16 = -8788");
	}

	MTEST(ShiftInt16MaxTest)
	{
		MbeddedNinja::MString myString("int16 = ");

		myString << (int16_t)32767;

		CHECK_EQUAL(myString, "int16 = 32767");
	}

	MTEST(ShiftInt16MinTest)
	{
		MbeddedNinja::MString myString("int16 = ");

		myString << (int16_t)-32767;

		CHECK_EQUAL(myString, "int16 = -32767");
	}

	MTEST(ShiftUint32RandomTest)
	{
		MbeddedNinja::MString myString("uint = ");

		myString << (uint32_t)5u;

		CHECK_EQUAL(myString, "uint = 5");
	}

	MTEST(ShiftUint32MaxTest)
	{
		MbeddedNinja::MString myString("uint = ");

		myString << (uint32_t)4294967295u;

		CHECK_EQUAL(myString, "uint = 4294967295");
	}

	MTEST(ShiftUint32MinTest)
	{
		MbeddedNinja::MString myString("uint = ");

		myString << (uint32_t)0;

		CHECK_EQUAL(myString, "uint = 0");
	}

	MTEST(ShiftInt32RandomTest)
	{
		MbeddedNinja::MString myString("int = ");

		myString << (int32_t)-46l;

		CHECK_EQUAL(myString, "int = -46");
	}

	MTEST(ShiftInt32MaxTest)
	{
		MbeddedNinja::MString myString("int = ");

		myString << (int32_t)2147483647l;

		CHECK_EQUAL(myString, "int = 2147483647");
	}

	MTEST(ShiftInt32MinTest)
	{
		MbeddedNinja::MString myString("int = ");

		myString << (int32_t)-2147483647l;

		CHECK_EQUAL(myString, "int = -2147483647");
	}

	MTEST(ShiftUint64RandomTest)
	{
		MbeddedNinja::MString myString("uint64 = ");

		// 6 giga is higher than 2^32
		myString << (uint64_t)6000000000llu;

		CHECK_EQUAL(myString, "uint64 = 6000000000");
	}

	MTEST(ShiftUint64MaxTest)
	{
		MbeddedNinja::MString myString("uint64 = ");

		myString << (uint64_t)18446744073709551615llu;

		CHECK_EQUAL(myString, "uint64 = 18446744073709551615");
	}

	MTEST(ShiftUint64MinTest)
	{
		MbeddedNinja::MString myString("uint64 = ");

		myString << (uint64_t)0llu;

		CHECK_EQUAL(myString, "uint64 = 0");
	}

	MTEST(ShiftInt64RandomTest)
	{
		MbeddedNinja::MString myString("int64 = ");

		myString << (int64_t)-6000000000ll;

		CHECK_EQUAL(myString, "int64 = -6000000000");
	}

	MTEST(ShiftInt64MaxTest)
	{
		MbeddedNinja::MString myString("int64 = ");

		myString << (int64_t)9223372036854775807ll;

		CHECK_EQUAL(myString, "int64 = 9223372036854775807");
	}

	MTEST(ShiftInt64MinTest)
	{
		MbeddedNinja::MString myString("int64 = ");

		myString << (int64_t)-9223372036854775807ll;

		CHECK_EQUAL(myString, "int64 = -9223372036854775807");
	}

} // namespace StringTestsNs
