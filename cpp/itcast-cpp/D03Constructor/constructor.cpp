#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace D03Constructor
{		

	class Person
	{
	public:
		int age;

		Person()
		{
			age = 0;
		}


	};

	TEST_CLASS(ConstructorTest)
	{
	public:
		
		TEST_METHOD(NoParamTest)
		{
			Person p1;
			Assert::AreEqual(0, p1.age);
		}

	};
}