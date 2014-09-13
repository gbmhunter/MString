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
		CHECK_EQUAL(true, myString1 == myString2);
	}

	MTEST(ShouldntEqualTest)
	{
		MbeddedNinja::MString myString1("Testing1");

		MbeddedNinja::MString myString2("Testing2");

		// These should not equal
		CHECK_EQUAL(false, myString1 == myString2);
	}

	MTEST(TwoEmptyStringsTest)
	{
		MbeddedNinja::MString myString1;

		MbeddedNinja::MString myString2;

		// These should be equal (both empty)
		CHECK_EQUAL(true, myString1 == myString2);
	}

	MTEST(OneEmptyStringsTest)
	{
		MbeddedNinja::MString myString1;

		MbeddedNinja::MString myString2("This one is not empty");

		// These should NOT be equal (one is empty)
		CHECK_EQUAL(false, myString1 == myString2);
	}

	MTEST(InequalityTest1)
	{
		MbeddedNinja::MString myString1("Testing1");

		MbeddedNinja::MString myString2("Testing2");

		// These should equal
		CHECK_EQUAL(true, myString1 != myString2);
	}

	MTEST(InequalityTest2)
	{
		MbeddedNinja::MString myString1("Testing");

		MbeddedNinja::MString myString2("Testing");

		// These should equal
		CHECK_EQUAL(false, myString1 != myString2);
	}

	MTEST(EqualityWorksWithCStringTest1)
	{
		MbeddedNinja::MString myString1("Testing");

		// These should equal
		CHECK_EQUAL(true, myString1 == "Testing");
	}

	MTEST(EqualityWorksWithCStringTest2)
	{
		MbeddedNinja::MString myString1("Testing1");

		// These should equal
		CHECK_EQUAL(false, myString1 == "Testing2");
	}

	MTEST(InequalityWorksWithCStringTest1)
	{
		MbeddedNinja::MString myString1("Testing");

		// These should equal
		CHECK_EQUAL(false, myString1 != "Testing");
	}

	MTEST(InequalityWorksWithCStringTest2)
	{
		MbeddedNinja::MString myString1("Testing1");

		// These should equal
		CHECK_EQUAL(true, myString1 != "Testing2");
	}

} // namespace StringTestsNs
