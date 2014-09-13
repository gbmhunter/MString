//!
//! @file 			AppendTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-13
//! @last-modified 	2014-09-13
//! @brief 			Makes sure the String::Append() method works as expected.
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

	MTEST(BasicAppendTest)
	{
		MbeddedNinja::MString myString("Hello");

		myString.Append(", world!");

		CHECK_EQUAL("Hello, world!", myString);
	}

	MTEST(AppendNothingTest)
	{
		MbeddedNinja::MString myString("Hello");

		myString.Append("");

		CHECK_EQUAL("Hello", myString);
	}

	MTEST(AppendLengthCorrectCheckTest)
	{
		MbeddedNinja::MString myString("Hello");

		myString.Append(", world!");

		CHECK_EQUAL(13, myString.GetLength());
	}

	MTEST(BasicAppendThroughPlusOperatorTest)
	{
		MbeddedNinja::MString myString1("Hello");

		MbeddedNinja::MString myString2(", world!");

		MbeddedNinja::MString myString3 = myString1 + myString2;

		CHECK_EQUAL("Hello, world!", myString3);
	}

	MTEST(LongChainTest)
	{
		MbeddedNinja::MString myString1("Hello");

		MbeddedNinja::MString myString2(", world!");

		MbeddedNinja::MString myString3 =
				(myString1 + myString2) + " And some more stuff!" + " Even more stuff!";

		CHECK_EQUAL("Hello, world! And some more stuff! Even more stuff!", myString3);
	}

	MTEST(LongChainLotsOfEmptyStringsTest)
	{
		MbeddedNinja::MString myString1("Hello");

		MbeddedNinja::MString myString2(", world!");

		MbeddedNinja::MString myString3 =
				myString1 + myString2 + "" + "" + "";

		CHECK_EQUAL("Hello, world!", myString3);
	}

	MTEST(AppendThroughCompoundAssignmentOperatorWithStringTest)
	{
		MbeddedNinja::MString myString1("Hello");

		MbeddedNinja::MString myString2(", world!");

		myString1 += myString2;

		CHECK_EQUAL("Hello, world!", myString1);
	}

	MTEST(AppendThroughCompoundAssignmentOperatorWithConstCharTest)
	{
		MbeddedNinja::MString myString1("Hello");

		myString1 += ", world!";

		CHECK_EQUAL("Hello, world!", myString1);
	}

} // namespace StringTestsNs
