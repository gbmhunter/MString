//!
//! @file 			TrimTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-22
//! @last-modified 	2014-09-13
//! @brief 			Makes sure the String::Trim() method works as expected.
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

	//======================== TRIM FROM LEFT TESTS ====================//

	MTEST(TrimJustSpacesFromStartTest)
	{
		MbeddedNinja::MString myString1("   There is white space before me.");

		// Trim white space
		myString1.Trim();

		CHECK_EQUAL("There is white space before me.", myString1);
	}

	MTEST(TrimJustCarriageReturnsFromStartTest)
	{
		MbeddedNinja::MString myString1("\r\r\rThere are carriage returns before me.");

		// Trim string
		myString1.Trim();

		CHECK_EQUAL("There are carriage returns before me.", myString1);
	}

	MTEST(TrimJustNewLinesFromStartTest)
	{
		MbeddedNinja::MString myString1("\n\n\nThere are new lines before me.");

		// Trim string
		myString1.Trim();

		CHECK_EQUAL("There are new lines before me.", myString1);
	}

	MTEST(TrimJustTabsFromStartTest)
	{
		MbeddedNinja::MString myString1("\t\t\tThere are tabs before me.");

		// Trim string
		myString1.Trim();

		CHECK_EQUAL("There are tabs before me.", myString1);
	}

	MTEST(TrimAMixtureOfWhiteSpaceFromStartTest)
	{
		MbeddedNinja::MString myString1("\r \n     \t There is a mixture of white-space chars before me.");

		// Trim string
		myString1.Trim();

		CHECK_EQUAL("There is a mixture of white-space chars before me.", myString1);
	}

	//======================== TRIM FROM END TESTS ====================//

	MTEST(TrimJustSpacesFromEndTest)
	{
		MbeddedNinja::MString myString1("There is white space after me.    ");

		// Trim white space
		myString1.Trim();

		CHECK_EQUAL("There is white space after me.", myString1);
	}

	MTEST(TrimJustCarriageReturnsFromEndTest)
	{
		MbeddedNinja::MString myString1("There are carriage returns after me.\r\r\r\r");

		// Trim string
		myString1.Trim();

		CHECK_EQUAL("There are carriage returns after me.", myString1);
	}

	MTEST(TrimJustNewLinesFromEndTest)
	{
		MbeddedNinja::MString myString1("There are new lines after me.\n\n\n\n\n");

		// Trim string
		myString1.Trim();

		CHECK_EQUAL("There are new lines after me.", myString1);
	}

	MTEST(TrimJustTabsFromEndTest)
	{
		MbeddedNinja::MString myString1("There are tabs after me.\t");

		// Trim string
		myString1.Trim();

		CHECK_EQUAL("There are tabs after me.", myString1);
	}

	MTEST(TrimAMixtureOfWhiteSpaceFromEndTest)
	{
		MbeddedNinja::MString myString1("There is a mixture of white-space chars after me.\r  \t\n\n ");

		// Trim string
		myString1.Trim();

		CHECK_EQUAL("There is a mixture of white-space chars after me.", myString1);
	}

	//======================== TRIM FROM BOTH ENDS TESTS ====================//

	MTEST(TrimAMixtureOfWhiteSpaceFromBothEndsTest)
	{
		MbeddedNinja::MString myString1("   \t \r\nThere is a mixture of white-space chars before and after me.\r  \t\n\n ");

		// Trim string
		myString1.Trim();

		CHECK_EQUAL("There is a mixture of white-space chars before and after me.", myString1);
	}

	//======================== DOESN'T TRIM FROM MIDDLE TESTS ====================//

	MTEST(DoesntTrimWhiteSpaceFromMiddleOfStringTest)
	{
		MbeddedNinja::MString myString1("\r \n     \t a\r b\t cdef gh");

		// Trim string
		myString1.Trim();

		//  String should now start the the 'a' char.
		CHECK_EQUAL("a\r b\t cdef gh", myString1);
	}

	//======================== ONLY TRIM WHAT I'M TOLD TO TESTS ====================//

	MTEST(OnlyTrimFromLeftTest)
	{
		MbeddedNinja::MString myString1(
				"   \t \r\nThere is a mixture of white-space chars before and after me.\r  \t\n\n ");

		// Trim string
		myString1.Trim(MbeddedNinja::MString::EndsToTrim::LEFT);

		CHECK_EQUAL(
			"There is a mixture of white-space chars before and after me.\r  \t\n\n ",
			myString1);
	}

	MTEST(OnlyTrimFromRightTest)
	{
		MbeddedNinja::MString myString1(
				"   \t \r\nThere is a mixture of white-space chars before and after me.\r  \t\n\n ");

		// Trim string
		myString1.Trim(MbeddedNinja::MString::EndsToTrim::RIGHT);

		CHECK_EQUAL(
			"   \t \r\nThere is a mixture of white-space chars before and after me.",
			myString1);
	}

	//======================== SPECIFYING WHAT TO TRIM TESTS ====================//

	MTEST(TrimSomeATest)
	{
		MbeddedNinja::MString myString1(
				"aaaaThere are some 'a' before and after me.\r  \t\n\n aaaa");

		// Trim string
		myString1.Trim(MbeddedNinja::MString("a"));

		CHECK_EQUAL(
			"There are some 'a' before and after me.\r  \t\n\n ",
			myString1);
	}

	//======================== EDGE-CASE TRIM TESTS ====================//

	MTEST(TrimEmptyStringTest)
	{
		MbeddedNinja::MString myString1("");

		// Trim string
		myString1.Trim();

		//  String should now be empty.
		CHECK_EQUAL("", myString1);
	}

	MTEST(TrimEmptyStringWithEmptyMatchingCharsTest)
	{
		MbeddedNinja::MString myString1("");

		// Trim string
		myString1.Trim(MbeddedNinja::MString());

		//  String should still be empty.
		CHECK_EQUAL("", myString1);
	}

	MTEST(TrimStringWithEmptyMatchingCharsTest)
	{
		MbeddedNinja::MString myString1("Please don't hurt me!");

		// Trim string
		myString1.Trim(MbeddedNinja::MString());

		//  String should of not been modified
		CHECK_EQUAL("Please don't hurt me!", myString1);
	}

	MTEST(AllWhiteSpaceTest)
	{
		MbeddedNinja::MString myString1("\r \n     \t  ");

		// Trim string
		myString1.Trim();

		//  String should now be empty.
		CHECK_EQUAL("", myString1);
	}

} // namespace StringTestsNs
