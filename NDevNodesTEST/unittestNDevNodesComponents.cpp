#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "NDevNodes.h"

namespace NDev::Test
{
	using namespace NDev;
	using namespace NDev::Types;
	using namespace NDev::Nodes;

	TEST_CLASS(UnitTestNDevNodesComponents)
	{
	public:

		TEST_METHOD(TestName)
		{
			auto Component = new Components::FName();
			delete Component;
		}

		TEST_METHOD(TestType)
		{
			auto Component = new Components::FType();
			delete Component;
		}

		TEST_METHOD(TestData)
		{
			auto Component = new Components::FData();
			delete Component;
		}

		TEST_METHOD(TestContext)
		{
			auto Component = new Components::FContext();
			delete Component;
		}
	};
}
