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
#include "../api/StringApi.hpp"

namespace StringTestsNs
{
	SUITE(EqualityOperatorTests)
	{

		TEST(ShouldEqualTest)
		{
			mNinja::String myString1("Testing");

			mNinja::String myString2("Testing");

			// These should equal
			CHECK_EQUAL(true, myString1 == myString2);
		}

		TEST(ShouldntEqualTest)
		{
			mNinja::String myString1("Testing1");

			mNinja::String myString2("Testing2");

			// These should not equal
			CHECK_EQUAL(false, myString1 == myString2);
		}

		TEST(TwoEmptyStringsTest)
		{
			mNinja::String myString1;

			mNinja::String myString2;

			// These should be equal (both empty)
			CHECK_EQUAL(true, myString1 == myString2);
		}

		TEST(OneEmptyStringsTest)
		{
			mNinja::String myString1;

			mNinja::String myString2("This one is not empty");

			// These should NOT be equal (one is empty)
			CHECK_EQUAL(false, myString1 == myString2);
		}

		TEST(InequalityTest1)
		{
			mNinja::String myString1("Testing1");

			mNinja::String myString2("Testing2");

			// These should equal
			CHECK_EQUAL(true, myString1 != myString2);
		}

		TEST(InequalityTest2)
		{
			mNinja::String myString1("Testing");

			mNinja::String myString2("Testing");

			// These should equal
			CHECK_EQUAL(false, myString1 != myString2);
		}

		TEST(EqualityWorksWithCStringTest1)
		{
			mNinja::String myString1("Testing");

			// These should equal
			CHECK_EQUAL(true, myString1 == "Testing");
		}

		TEST(EqualityWorksWithCStringTest2)
		{
			mNinja::String myString1("Testing1");

			// These should equal
			CHECK_EQUAL(false, myString1 == "Testing2");
		}

		TEST(InequalityWorksWithCStringTest1)
		{
			mNinja::String myString1("Testing");

			// These should equal
			CHECK_EQUAL(false, myString1 != "Testing");
		}

		TEST(InequalityWorksWithCStringTest2)
		{
			mNinja::String myString1("Testing1");

			// These should equal
			CHECK_EQUAL(true, myString1 != "Testing2");
		}

	} // SUITE(EqualityOperatorTests)
} // namespace StringTestsNs
