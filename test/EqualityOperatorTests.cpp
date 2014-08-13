//!
//! @file 			EqualityOperatorTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014-08-13
//! @last-modified 	2014-08-13
//! @brief 			Contains unit tests that makes sure the equality (and inequality) operator overloads work correctly.
//! @details
//!					See README.rst in root dir for more info.

#include <stdio.h>

#include "../api/StringApi.hpp"

#include "../lib/UnitTest++/src/UnitTest++.h"

namespace StringTestsNs
{
	SUITE(EqualityOperatorTests)
	{

		TEST(ShouldEqualTest)
		{
			StringNs::String myString1("Testing");

			StringNs::String myString2("Testing");

			// These should equal
			CHECK_EQUAL(true, myString1 == myString2);
		}

		TEST(ShouldntEqualTest)
		{
			StringNs::String myString1("Testing1");

			StringNs::String myString2("Testing2");

			// These should not equal
			CHECK_EQUAL(false, myString1 == myString2);
		}

		TEST(TwoEmptyStringsTest)
		{
			StringNs::String myString1;

			StringNs::String myString2;

			// These should be equal (both empty)
			CHECK_EQUAL(true, myString1 == myString2);
		}

		TEST(OneEmptyStringsTest)
		{
			StringNs::String myString1;

			StringNs::String myString2("This one is not empty");

			// These should NOT be equal (one is empty)
			CHECK_EQUAL(false, myString1 == myString2);
		}

		TEST(InequalityTest1)
		{
			StringNs::String myString1("Testing1");

			StringNs::String myString2("Testing2");

			// These should equal
			CHECK_EQUAL(true, myString1 != myString2);
		}

		TEST(InequalityTest2)
		{
			StringNs::String myString1("Testing");

			StringNs::String myString2("Testing");

			// These should equal
			CHECK_EQUAL(false, myString1 != myString2);
		}

		TEST(EqualityWorksWithCStringTest1)
		{
			StringNs::String myString1("Testing");

			// These should equal
			CHECK_EQUAL(true, myString1 == "Testing");
		}

		TEST(EqualityWorksWithCStringTest2)
		{
			StringNs::String myString1("Testing1");

			// These should equal
			CHECK_EQUAL(false, myString1 == "Testing2");
		}

		TEST(InequalityWorksWithCStringTest1)
		{
			StringNs::String myString1("Testing");

			// These should equal
			CHECK_EQUAL(false, myString1 != "Testing");
		}

		TEST(InequalityWorksWithCStringTest2)
		{
			StringNs::String myString1("Testing1");

			// These should equal
			CHECK_EQUAL(true, myString1 != "Testing2");
		}

	} // SUITE(EqualityOperatorTests)
} // namespace StringTestsNs
