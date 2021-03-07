#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "NDevNodes.h"

namespace NDev
{
	namespace Test {
		using namespace NDev;
		using namespace NDev::Types;
		using namespace NDev::Nodes;

		TEST_CLASS(UnitTestNDevNodesComputes)
		{
		public:
			TEST_METHOD(TestSimplify)
			{
				auto Compute = new Computes::FSimplify();
				delete Compute;
			}
		};
	}
}
