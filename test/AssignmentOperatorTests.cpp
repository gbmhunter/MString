//!
//! @file 			AssignmentOperatorTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-12
//! @last-modified 	2014-09-13
//! @brief 			Makes sure the assignment operator overloads for String work as expected.
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

	MTEST(AssignmentOperatorTest)
	{
		MbeddedNinja::MString myString1("Testing");

		MbeddedNinja::MString myString2("Other stuff");

		myString2 = myString1;

		// myString2 should now be equal to myString1
		CHECK_EQUAL(myString2, "Testing");
	}

} // namespace StringTestsNs
