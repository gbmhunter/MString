//!
//! @file 			EqualityOperatorTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-13
//! @last-modified 	2014-08-21
//! @brief 			Contains unit tests that makes sure the equality (and inequality) operator overloads work correctly.
//! @details
//!					See README.rst in root dir for more info.

// User libraries
#include "../lib/UnitTest++/src/UnitTest++.h"

// User source
#include "../api/MStringApi.hpp"

namespace StringTestsNs
{
	SUITE(EqualityOperatorTests)
	{

		TEST(ShouldEqualTest)
		{
			MbeddedNinja::MString myString1("Testing");

			MbeddedNinja::MString myString2("Testing");

			// These should equal
			CHECK_EQUAL(true, myString1 == myString2);
		}

		TEST(ShouldntEqualTest)
		{
			MbeddedNinja::MString myString1("Testing1");

			MbeddedNinja::MString myString2("Testing2");

			// These should not equal
			CHECK_EQUAL(false, myString1 == myString2);
		}

		TEST(TwoEmptyStringsTest)
		{
			MbeddedNinja::MString myString1;

			MbeddedNinja::MString myString2;

			// These should be equal (both empty)
			CHECK_EQUAL(true, myString1 == myString2);
		}

		TEST(OneEmptyStringsTest)
		{
			MbeddedNinja::MString myString1;

			MbeddedNinja::MString myString2("This one is not empty");

			// These should NOT be equal (one is empty)
			CHECK_EQUAL(false, myString1 == myString2);
		}

		TEST(InequalityTest1)
		{
			MbeddedNinja::MString myString1("Testing1");

			MbeddedNinja::MString myString2("Testing2");

			// These should equal
			CHECK_EQUAL(true, myString1 != myString2);
		}

		TEST(InequalityTest2)
		{
			MbeddedNinja::MString myString1("Testing");

			MbeddedNinja::MString myString2("Testing");

			// These should equal
			CHECK_EQUAL(false, myString1 != myString2);
		}

		TEST(EqualityWorksWithCStringTest1)
		{
			MbeddedNinja::MString myString1("Testing");

			// These should equal
			CHECK_EQUAL(true, myString1 == "Testing");
		}

		TEST(EqualityWorksWithCStringTest2)
		{
			MbeddedNinja::MString myString1("Testing1");

			// These should equal
			CHECK_EQUAL(false, myString1 == "Testing2");
		}

		TEST(InequalityWorksWithCStringTest1)
		{
			MbeddedNinja::MString myString1("Testing");

			// These should equal
			CHECK_EQUAL(false, myString1 != "Testing");
		}

		TEST(InequalityWorksWithCStringTest2)
		{
			MbeddedNinja::MString myString1("Testing1");

			// These should equal
			CHECK_EQUAL(true, myString1 != "Testing2");
		}

	} // SUITE(EqualityOperatorTests)
} // namespace StringTestsNs
