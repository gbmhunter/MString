//!
//! @file 			ABitOfEverythingTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-20
//! @last-modified 	2014-09-13
//! @brief 			Includes units tests that test a wide range of String object functionality all at once.
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

	MTEST(ABitOfEverythingTest1)
	{
		//std::cerr << "ABitOfEverythingTest1() called." << std::endl;
		MbeddedNinja::MString myStr1("Hello, world!");

		// Erase everything after "Hello"
		myStr1.Erase(5);

		CHECK_EQUAL(myStr1, (const char *)"Hello");

		// Copy to new string
		MbeddedNinja::MString myStr2 = myStr1;

		CHECK_EQUAL(myStr2, "Hello");
		CHECK_EQUAL(myStr2.GetLength(), 5);

		// Add some more letters
		myStr2 = myStr2 + ", you!";

		CHECK_EQUAL(myStr2.GetLength(), 11);
		CHECK_EQUAL(myStr2, "Hello, you!");
	}

	MTEST(ABitOfEverythingTest2)
	{
		MbeddedNinja::MString myStr1("Hello, world!");

		CHECK_EQUAL(myStr1, "Hello, world!");

		// Erase everything after "Hello"
		myStr1.Append(" And hello you!");

		CHECK_EQUAL(myStr1, "Hello, world! And hello you!");

	}

	MTEST(ABitOfEverythingTest3)
	{
		MbeddedNinja::MString myStr1("Hello, world!");

		CHECK_EQUAL(myStr1, "Hello, world!");

		// Erase everything after "Hello"
		myStr1 = myStr1 + " And hello you!";

		CHECK_EQUAL(myStr1, "Hello, world! And hello you!");

		MbeddedNinja::MString myStr2;

		myStr2 = myStr1 + " And hello me!";

		CHECK_EQUAL(myStr2, "Hello, world! And hello you! And hello me!");

		MbeddedNinja::MString * myStr3;

		myStr3 = &myStr2;

		CHECK_EQUAL(*myStr3, "Hello, world! And hello you! And hello me!");

		myStr3->Erase(2);

		CHECK_EQUAL(myStr2, "He");
		CHECK_EQUAL(*myStr3, "He");

		*myStr3 = "";

		CHECK_EQUAL(myStr2, "");
		CHECK_EQUAL(*myStr3, "");

		MbeddedNinja::MString myStr4;

		myStr4 = *myStr3;

		CHECK_EQUAL(myStr4, "");

		myStr4 = MbeddedNinja::MString("A replacement.");

		CHECK_EQUAL(*myStr3, "");
		CHECK_EQUAL(myStr4, "A replacement.");

	}

	MTEST(ABitOfEverythingTest4)
	{
		// This performs tests to simulate an AT command decoding scenario

		MbeddedNinja::MString rxBuffStr = "blahblahATE1\r\nTestPayload\r\nOK\r\nblahblah";

		uint32_t startOfEcho = rxBuffStr.Find("ATE1");

		CHECK_EQUAL(startOfEcho, 8);

		uint32_t endOfEcho = rxBuffStr.Find("\n", startOfEcho);

		CHECK_EQUAL(endOfEcho, 13);

		uint32_t startOfResponseCode = rxBuffStr.Find("OK", endOfEcho);

		CHECK_EQUAL(startOfResponseCode, 27);

		rxBuffStr.Erase(0, endOfEcho + 1);

		CHECK_EQUAL(rxBuffStr, "TestPayload\r\nOK\r\nblahblah");

		//std::cerr << "Erase start pos = '" << startOfResponseCode - endOfEcho - 1 << "'." << std::endl;

		// Erase response code and everything after it
		rxBuffStr.Erase(startOfResponseCode - endOfEcho - 1);

		CHECK_EQUAL(rxBuffStr, "TestPayload\r\n");

	}

	MTEST(ABitOfEverythingTest5)
	{
		MbeddedNinja::MString myStr1;

		myStr1 += "a";

		CHECK_EQUAL(myStr1, "a");

		myStr1 << 1 << "b" << 2;

		CHECK_EQUAL(myStr1, "a1b2");

		myStr1 = "c";

		CHECK_EQUAL(myStr1, "c");

		myStr1 << "=" << 2.314;

		CHECK_EQUAL(myStr1, "c=2.314");
	}

} // namespace StringTestsNs
