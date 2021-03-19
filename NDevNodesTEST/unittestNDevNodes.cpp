#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "NDevNodes.h"

#include <list>
#include <array>

namespace NDev::Test
{
	using namespace NDev;
	using namespace NDev::Types;
	using namespace NDev::Nodes;

	TEST_CLASS(UnitTestNDevNodes)
	{
	public:
		TEST_METHOD(TestNode)
		{
			auto Object = new FNode();
			delete Object;
		}

		TEST_METHOD(TestNodeAddRemove)
		{
			const FSize N = 42;
			std::array<FNode*, N> Nodes;
			std::array<FComponent*, N> Components;
			auto Object = new FNode();
			for (FSize Index = 0; Index < N; Index++)
			{
				Nodes[Index] = new FNode();
				Object->Add(Nodes[Index]);
				Components[Index] = new FComponent();
				Object->Add(Components[Index]);
			}
			Assert::AreEqual(N, Object->Nodes().Size());
			Assert::AreEqual(N, Object->Components().Size());
			for (auto Item : Object->Nodes()) { Assert::IsNotNull(Item, NullPtr, LINE_INFO()); }
			for (auto Item : Object->Components()) { Assert::IsNotNull(Item, NullPtr, LINE_INFO()); }
			for (auto &Item : Nodes) { Object->Remove(Item); delete Item; Item = Null; }
			for (auto &Item : Components) { Object->Remove(Item); delete Item; Item = Null; }
			for (auto Item : Nodes) { Assert::IsNull(Item, NullPtr, LINE_INFO()); }
			for (auto Item : Components) { Assert::IsNull(Item, NullPtr, LINE_INFO()); }
			delete Object;
		}

		TEST_METHOD(TestComponent)
		{
			auto Object = new FComponent();
			delete Object;
		}

		TEST_METHOD(TestCompute)
		{
			auto Object = new FCompute();
			delete Object;
		}
	};
}
