//!
//! @file 			AppendTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-13
//! @last-modified 	2014-08-22
//! @brief 			Makes sure the String::Append() method works as expected.
//! @details
//!					See README.rst in root dir for more info.

// User libraries
#include "../lib/UnitTest++/src/UnitTest++.h"

// User source
#include "../api/MStringApi.hpp"

namespace StringTestsNs
{
	SUITE(AppendTests)
	{

		TEST(BasicAppendTest)
		{
			MbeddedNinja::MString myString("Hello");

			myString.Append(", world!");

			CHECK_EQUAL("Hello, world!", myString.cStr);
		}

		TEST(AppendNothingTest)
		{
			MbeddedNinja::MString myString("Hello");

			myString.Append("");

			CHECK_EQUAL("Hello", myString.cStr);
		}

		TEST(LengthCorrectCheckTest)
		{
			MbeddedNinja::MString myString("Hello");

			myString.Append(", world!");

			CHECK_EQUAL(13, myString.GetLength());
		}

		TEST(BasicAppendThroughPlusOperatorTest)
		{
			MbeddedNinja::MString myString1("Hello");

			MbeddedNinja::MString myString2(", world!");

			MbeddedNinja::MString myString3 = myString1 + myString2;

			CHECK_EQUAL("Hello, world!", myString3.cStr);
		}

		TEST(LongChainTest)
		{
			MbeddedNinja::MString myString1("Hello");

			MbeddedNinja::MString myString2(", world!");

			MbeddedNinja::MString myString3 =
					(myString1 + myString2) + " And some more stuff!" + " Even more stuff!";

			CHECK_EQUAL("Hello, world! And some more stuff! Even more stuff!", myString3.cStr);
		}

		TEST(LongChainLotsOfEmptyStringsTest)
		{
			MbeddedNinja::MString myString1("Hello");

			MbeddedNinja::MString myString2(", world!");

			MbeddedNinja::MString myString3 =
					myString1 + myString2 + "" + "" + "";

			CHECK_EQUAL("Hello, world!", myString3.cStr);
		}

		TEST(AppendThroughCompoundAssignmentOperatorWithStringTest)
		{
			MbeddedNinja::MString myString1("Hello");

			MbeddedNinja::MString myString2(", world!");

			myString1 += myString2;

			CHECK_EQUAL("Hello, world!", myString1.cStr);
		}

		TEST(AppendThroughCompoundAssignmentOperatorWithConstCharTest)
		{
			MbeddedNinja::MString myString1("Hello");

			myString1 += ", world!";

			CHECK_EQUAL("Hello, world!", myString1.cStr);
		}

	} // SUITE(AppendTests)
} // namespace StringTestsNs
