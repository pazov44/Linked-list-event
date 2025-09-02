#include "pch.h"
#include "CppUnitTest.h"
#include "create.h"
#include "find.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestAccess
{
	TEST_CLASS(TestAccess)
	{
	public:
		
		TEST_METHOD(TestCreateUser)
		{
			//Arrange
			User testUser;
			testUser.username = "Daniel";
			testUser.password = "password123";
			int actual;
			int expected = Error::SUCCESSFUL;

			//Act
			actual = Create::CreateUser(testUser, "");

			//Assert
			Assert::AreEqual(expected, actual);
			
		}
		TEST_METHOD(TestInitRelease)
		{
			// Arrange
			bool expected = 0; // events ptr should be null when released
			bool actual;

			//Act
			Global::Init(); // init global event list
			Global::Release(); // release global event list
			auto events = Global::GetEvents();
			actual = events.get(); // actual is either 1 or 0 depending if events is freeed or no

			//Assert
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TestFindUser)
		{
			//Arrange
			User testUser;
			testUser.username = "Daniel";
			testUser.password = "password123";
			bool actual;
			bool expected = true; // user is expected to be found

			//Act
			Create::CreateUser(testUser, "");
			actual = Find::FindUser(testUser);

			//Assert
			Assert::AreEqual(expected, actual);
		}
	};
}
