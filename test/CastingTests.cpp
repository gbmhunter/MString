//!
//! @file 			CastingTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-22
//! @last-modified 	2014-09-13
//! @brief 			Makes sure the casting overloads for String work as expected.
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

	MTEST(CastTest)
	{
		MbeddedNinja::MString myString1("Testing");

		// myString2 should not be affected by above change to myString1!
		CHECK_EQUAL("Testing", (const char *)myString1);
	}

	MTEST(CastTest2)
	{
		MbeddedNinja::MString myString1("Testing");

		const char * myCStr;

		myCStr = myString1;

		// myString2 should not be affected by above change to myString1!
		CHECK_EQUAL("Testing", myCStr);

	}

} // namespace StringTestsNs
