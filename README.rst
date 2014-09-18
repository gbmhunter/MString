=======
MString
=======

---------------------------------------------------------------------------------------------
A microcontroller friendly C++ string object specifically designed for embedded applications.
---------------------------------------------------------------------------------------------

.. image:: https://api.travis-ci.org/mbedded-ninja/MString.png?branch=master   
	:target: https://travis-ci.org/mbedded-ninja/MString

- Author: gbmhunter <gbmhunter@gmail.com> (www.mbedded.ninja)
- First Ever Commit: 2014-08-12
- Last Modified: 2014-09-18
- Version: v2.2.1.0
- Company: mbedded.ninja
- Project: MToolkit Module
- Language: C++
- Compiler: GCC	
- uC Model: n/a
- Computer Architecture: n/a
- Operating System: n/a
- Documentation Format: Doxygen
- License: GPLv3

Description
===========

MString is a C++ string object specifically designed for embedded applications.

Features:

- Dynamic allocation and resize capabilities (with data preservation)
- Embedded (microcontroller) support
- Small flash/RAM memory footprint (no depedance on the C++ std::string class)
- Unit tests
- Doxygen-style well-documented API.
- Portability

Automatic Memory Management
---------------------------

The automatic memory management of the MString object means that you will get far less buffer overflows and memory leaks.

::

	#include "MString/api/MStringApi.h"
	using MbeddedNinja;
	
	function MyFunc()
	{
		MString myStr;				// Empty string created, 1-byte of RAM used (don't worry, it's still null-terminated!)
		
		MString myStr = "abc";		// Memory automatically expanded to 4 bytes, no overflow occurs!
		
		return;						// String is now out-of-scope, memory automatically freed
	}
	
Concatenating Strings
---------------------

Concatenating (appending) strings onto the end of one another is easy! Follows the same behaviour as std::string.

::

	#include "MString/api/MStringApi.h"
	using MbeddedNinja;
	
	MString myStr1("Hello");
	myStr1 += ", World!";
	
	// myStr1 now equals "Hello, World!"
	
	MString myStr2;
	myStr2 = myStr1 + "With love from mbedded.ninja.";
	
	// myStr2 now equals "Hello, World! With love from mbedded.ninja."

Appending Integers And Doubles (std::stringstream like bahaviour)
-----------------------------------------------------------------

Integers (both signed and unsigned) as well as doubles can easily be appended to the end of a string with the left-shift ('<<') operator, similar to std::stringstream behaviour.::

::

	#include "MString/api/MStringApi.h"
	using MbeddedNinja;
	
	MString myStr;
	myStr = "This integer = " << 6;
	
	// myStr now equals "This integer = 6"
	

External Dependencies
=====================

Nothing here yet.

Issues
======

See GitHub Issues.

Limitations
===========

Nothing here yet.

Usage
=====

See the unit tests in the 'test/' directory for basic examples.
	
Changelog
=========

========= ========== ===================================================================================================
Version   Date       Comment
========= ========== ===================================================================================================
v2.2.1.0  2014-09-18 Fixed up header guard names in header files, closes #54. 
v2.2.0.0  2014-09-13 Updated README name to MString. Switched from using UnitTestCpp to MUnitTest, deleted UnitTest library from '/lib' (got rid of the '/lib' library entirely), closes #51. Updated Makefile to download and build dependencies automatically, closes #53. Added 'const' qualifier to quality operator overloads. All unit test checks now pass in the String object directly for comparison.
v2.1.1.0  2014-08-30 Renamed module to MStringCpp, closes #46. Renamed string class to MString, closes #47.
v2.1.0.0  2014-08-25 Added support for concatenating two strings with the left-shift operator, closes #45.
v2.0.0.1  2014-08-25 Added information to the README concerning 'Automatic Memory Management', 'String Concatenation' and 'Appending Integers And Doubles', closes #42, closes #43, closes #44.
v2.0.0.0  2014-08-25 Added operator overloads for the left-shift operator ('<<') so that integers and doubles can be added to the end of strings with the syntax 'String() << myInt', similar to stringsteams in the standard C++ library, closes #41. Added appropriate unit tests.
v1.10.3.0 2014-08-22 Moved enumeration 'EndsToTrim' inside String class, closes #40.
v1.10.2.0 2014-08-22 Renamed namespace from 'mNinja' to 'MbeddedNinja', closes #39.
v1.10.1.0 2014-08-22 Renamed namespace from 'StringNs' to 'mNinja', closes #38.
v1.10.0.0 2014-08-22 Added type conversion overload from 'String' to 'const char *' and added relevant unit tests, closes #29.
v1.9.2.0  2014-08-22 Added compount assignment operator overload ('+=') for String class, closes #34. Modified the '+' overload so that chaining is supported, added associated unit tests, closes #37.
v1.9.1.0  2014-08-22 Renamed 'String::cStringPtr' to 'String::cStr', which is faster to type and drops the pointer qualification as this is implicit, closes #24.
v1.9.0.0  2014-08-22 Added 'String::Trim()' method which can be used to trim characters from the beginning/end of the string (including whitespace, which is what it does by default), and added associated unit tests, closes #35.
v1.8.0.0  2014-08-22 Added overload for subscript operator, providing access to the individual chars in the string, and added associated unit tests, closes #36.
v1.7.1.2  2014-08-21 Changed link in README from 'www.cladlab.com' to 'www.mbedded.ninja', closes #33.
v1.7.1.1  2014-08-21 Fixed link to TravisCI image in README, closes #32.
v1.7.1.0  2014-08-21 Added 'test/ABitOfEverythingTests.cpp' which performes tests all functionality at once, closes #26. Got rid of 'if(other.cStringPtr)' in String assignment operator overload, this could potentially make C string ptr equal nullptr, closes #27. Fixed bug in assignment operator which cause the resultant C-string not to be null terminated. Fixed bug in 'String::Erase()' which meant that invalid memory was overwritten, closes #25. Added more unit tests to 'test/EraseTests.cpp' which insert negative numbers, closes #30. Updated URL from 'www.cladlab.com' to 'www.mbedded.ninja', closes #31.
v1.7.0.0  2014-08-13 Added equality and inequaltiy operator overloads so that we can compare two string objects with one another and also compare one string object to one C-style string, closes #20. Also added associated unit tests.
v1.6.0.0  2014-08-13 Added 'String::Erase()' method and associated unit tests, closes #15. Changed 'delete' to 'delete[]' in 'String::Append()', closes #16. Add no-parameter constructor which creates a string with just a null char present, closes #17. Added unit tests that make sure String constructors work correctly, closes #18.
v1.5.0.0  2014-08-13 Added 'String::Append()' method. Added overloaded '+' operator so that it concatenates two strings together, closes #11. Added 'String::GetLength()' method, closes #13. Added 'const' qualifier to String variable reference passed into 'String::Find()', closes #12.
v1.4.1.0  2014-08-13 Added startPos variable to 'int32_t Find(char charToFind, uint32_t startPos = 0)', closes #10.
v1.4.0.0  2014-08-13 Added ability to search for a string within string using overloads of the 'Find()' method and associated unit tests, closes #9. Renamed 'test/FindTests.cpp' to 'test/FindCharTests.cpp'. 
v1.3.5.0  2014-08-13 Added copy-assignment unit test in 'test/CopyTests.cpp', closes #5. Replaced memcpy() in String constructor with strncpy(), closes #8. Made sure memory for string is null terminated in constructor, closes #7.
v1.3.4.0  2014-08-12 Fifth attempt at fixing TravisCI issue.
v1.3.3.0  2014-08-12 Fourth attempt at fixing TravisCI issue.
v1.3.2.0  2014-08-12 Third attempt at fixing TravisCI issue.
v1.3.1.0  2014-08-12 Second attempt at fixing TravisCI issue.
v1.3.0.0  2014-08-12 Added assignment operator overload for String class, and added associated unit test, closes #4. Modified .travis.yml file in the hope of compiling with GCC version v4.7 or later to fix TravisCI bug.
v1.2.0.0  2014-08-12 Added copy constructor for String class, and added associated unit test that makes sure the deep copy works correctly, closes #3.
v1.1.0.0  2014-08-12 Added 'String::Find()' method which allows you to search for a particular character in the sting, and added associated unit tests, closes #1. Destructor now deletes memory that was allocated in the constructor, closes #2.
v1.0.0.0  2014-08-12 Initial commit, basic constructor of string object from C-style string has been implemented with one unit test.
========= ========== ===================================================================================================