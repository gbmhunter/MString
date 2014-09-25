//!
//! @file 			EqualityOperatorTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-13
//! @last-modified 	2014-09-13
//! @brief 			Contains unit tests that makes sure the equality (and inequality) operator overloads work correctly.
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

	MTEST(ShouldEqualTest)
	{
		MbeddedNinja::MString myString1("Testing");

		MbeddedNinja::MString myString2("Testing");

		// These should equal
		CHECK_EQUAL(myString1 == myString2, true);
	}

	MTEST(ShouldntEqualTest)
	{
		MbeddedNinja::MString myString1("Testing1");

		MbeddedNinja::MString myString2("Testing2");

		// These should not equal
		CHECK_EQUAL(myString1 == myString2, false);
	}

	MTEST(TwoEmptyStringsTest)
	{
		MbeddedNinja::MString myString1;

		MbeddedNinja::MString myString2;

		// These should be equal (both empty)
		CHECK_EQUAL(myString1 == myString2, true);
	}

	MTEST(OneEmptyStringsTest)
	{
		MbeddedNinja::MString myString1;

		MbeddedNinja::MString myString2("This one is not empty");

		// These should NOT be equal (one is empty)
		CHECK_EQUAL(myString1 == myString2, false);
	}

	MTEST(InequalityTest1)
	{
		MbeddedNinja::MString myString1("Testing1");

		MbeddedNinja::MString myString2("Testing2");

		// These should equal
		CHECK_EQUAL(myString1 != myString2, true);
	}

	MTEST(InequalityTest2)
	{
		MbeddedNinja::MString myString1("Testing");

		MbeddedNinja::MString myString2("Testing");

		// These should equal
		CHECK_EQUAL(myString1 != myString2, false);
	}

	MTEST(EqualityWorksWithCStringTest1)
	{
		MbeddedNinja::MString myString1("Testing");

		// These should equal
		CHECK_EQUAL(myString1 == "Testing", true);
	}

	MTEST(EqualityWorksWithCStringTest2)
	{
		MbeddedNinja::MString myString1("Testing1");

		// These should equal
		CHECK_EQUAL(myString1 == "Testing2", false);
	}

	MTEST(InequalityWorksWithCStringTest1)
	{
		MbeddedNinja::MString myString1("Testing");

		// These should equal
		CHECK_EQUAL(myString1 != "Testing", false);
	}

	MTEST(InequalityWorksWithCStringTest2)
	{
		MbeddedNinja::MString myString1("Testing1");

		// These should equal
		CHECK_EQUAL(myString1 != "Testing2", true);
	}

} // namespace StringTestsNs
