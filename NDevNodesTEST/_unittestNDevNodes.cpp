#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "NDevNodes.h"
#include "_NDevNodesCollections.h"

namespace NDev
{
	namespace Test {
		using namespace NDev;
		using namespace NDev::Types;
		using namespace NDev::Nodes;

		TEST_CLASS(_UnitTestNDevNodes)
		{
		public:
			TEST_METHOD(_TestList)
			{
				const FSize N = 11, K = 42, M = 1, L = 2, Zero = 0;
				auto Collection = TList<FSize>(N);
				Assert::AreEqual(N, Collection.Size(), NullPtr, LINE_INFO());
				Assert::AreEqual(N * sizeof(FSize), Collection.SizeOf(), NullPtr, LINE_INFO());
				for (auto& Item : Collection)
				{
					Item = L;
				}
				for (FSize Index = 0; Index < K; ++Index)
				{
					Collection.Add(Index);
				}
				Assert::AreEqual(N + K, Collection.Size(), NullPtr, LINE_INFO());
				Collection.Remove(M);
				Assert::AreEqual(N + K - 1, Collection.Size(), NullPtr, LINE_INFO());
				for (const auto Item : Collection)
				{
					Assert::AreNotEqual(M, Item, NullPtr, LINE_INFO());
				}
				Assert::IsTrue(Collection.Full(), NullPtr, LINE_INFO());
				Assert::IsFalse(Collection.Empty(), NullPtr, LINE_INFO());
				Collection.Reset();
				Assert::AreEqual(Zero, Collection.Size(), NullPtr, LINE_INFO());
				Assert::IsFalse(Collection.Full(), NullPtr, LINE_INFO());
				Assert::IsTrue(Collection.Empty(), NullPtr, LINE_INFO());
			}

			TEST_METHOD(_TestArray)
			{
				const FSize N = 42, K = 11, Zero = 0;
				auto Collection = TArray<FSize, N>();
				Assert::AreEqual(N, Collection.Size(), NullPtr, LINE_INFO());
				for (auto& Item : Collection)
				{
					Item = Zero;
				}
				Collection[K] = K;
				Assert::AreEqual(K, Collection[K], NullPtr, LINE_INFO());
				for (const auto Item : Collection)
				{
					if (Item != K) { Assert::AreEqual(Zero, Item, NullPtr, LINE_INFO()); }
				}
			}

			TEST_METHOD(_TestStack)
			{
				const FSize N = 11, K = 42, Zero = 0;
				auto Collection = TStack<FSize>();
				Assert::AreEqual(Zero, Collection.Size(), NullPtr, LINE_INFO());
				Assert::IsFalse(Collection.Full(), NullPtr, LINE_INFO());
				Assert::IsTrue(Collection.Empty(), NullPtr, LINE_INFO());
				for (FSize Index = 0; Index < K; ++Index)
				{
					Collection.Push(Index);
					Assert::AreEqual(Index, Collection.Peek());
				}
				Assert::AreEqual(K * sizeof(FSize), Collection.SizeOf(), NullPtr, LINE_INFO());
				Assert::IsTrue(Collection.Full(), NullPtr, LINE_INFO());
				Assert::IsFalse(Collection.Empty(), NullPtr, LINE_INFO());
				for (FSize Index = 0; Index < K; ++Index)
				{
					auto Item = Collection.Pop();
					if (Collection.Full()) { Assert::AreEqual(Item - 1, Collection.Peek(), NullPtr, LINE_INFO()); }
				}
			}

			TEST_METHOD(_TestSet)
			{
				const FSize N = 11, K = 42, L = 7, Zero = 0;
				auto Collection = TSet<FSize>();
				Assert::AreEqual(Zero, Collection.Size(), NullPtr, LINE_INFO());
				for (FSize Index = 0; Index < K; ++Index)
				{
					Collection.Add(Index);
				}
				Assert::AreEqual(K * sizeof(FSize), Collection.SizeOf(), NullPtr, LINE_INFO());
				Assert::AreEqual(K, Collection.Size(), NullPtr, LINE_INFO());
				Collection.Remove(N);
				Assert::AreEqual(K - 1, Collection.Size(), NullPtr, LINE_INFO());
				for (const auto Item : Collection)
				{
					Assert::AreNotEqual(N, Item, NullPtr, LINE_INFO());
				}
				Collection.Add(L);
				Assert::AreEqual(K - 1, Collection.Size(), NullPtr, LINE_INFO());
				Collection.Add(L);
				Assert::AreEqual(K - 1, Collection.Size(), NullPtr, LINE_INFO());
				Assert::IsTrue(Collection.Full(), NullPtr, LINE_INFO());
				Assert::IsFalse(Collection.Empty(), NullPtr, LINE_INFO());
				Collection.Reset();
				Assert::AreEqual(Zero, Collection.Size(), NullPtr, LINE_INFO());
				Assert::IsFalse(Collection.Full(), NullPtr, LINE_INFO());
				Assert::IsTrue(Collection.Empty(), NullPtr, LINE_INFO());
			}

			TEST_METHOD(_TestQueue)
			{
				const FSize N = 11, K = 42, Zero = 0;
				auto Collection = TQueue<FSize>();
				Assert::AreEqual(Zero, Collection.Size(), NullPtr, LINE_INFO());
				Assert::IsFalse(Collection.Full(), NullPtr, LINE_INFO());
				Assert::IsTrue(Collection.Empty(), NullPtr, LINE_INFO());
				for (FSize Index = 0; Index < K; ++Index)
				{
					Collection.Queue(Index);
					Assert::AreEqual(Zero, Collection.Peek());
				}
				Assert::AreEqual(K * sizeof(FSize), Collection.SizeOf(), NullPtr, LINE_INFO());
				Assert::IsTrue(Collection.Full(), NullPtr, LINE_INFO());
				Assert::IsFalse(Collection.Empty(), NullPtr, LINE_INFO());
				for (FSize Index = 0; Index < K; ++Index)
				{
					auto Item = Collection.Dequeue();
					if (Collection.Full()) { Assert::AreEqual(Item + 1, Collection.Peek(), NullPtr, LINE_INFO()); }
				}
			}

			TEST_METHOD(_TestMap)
			{
				const FSize N = 11, K = 42, Zero = 0, Three = 3;
				auto Collection = TMap<FSize, FSize>();
				Assert::AreEqual(Zero, Collection.Size(), NullPtr, LINE_INFO());
				Assert::IsFalse(Collection.Full(), NullPtr, LINE_INFO());
				Assert::IsTrue(Collection.Empty(), NullPtr, LINE_INFO());
				for (FSize Index = 0; Index < K; ++Index)
				{
					Collection.Install(Index, Index);
				}
				Assert::AreEqual(K * sizeof(FSize), Collection.SizeOf(), NullPtr, LINE_INFO());
				Assert::IsTrue(Collection.Full(), NullPtr, LINE_INFO());
				Assert::IsFalse(Collection.Empty(), NullPtr, LINE_INFO());
				for (auto Pair : Collection) {
					Assert::AreEqual(Pair.first, Pair.second, NullPtr, LINE_INFO());
				}
				for (FSize Index = 0; Index < K/2; ++Index)
				{
					Assert::AreEqual(Index, Collection[Index], NullPtr, LINE_INFO());
					Collection.Uninstall(Index);
				}
				Assert::IsTrue(Collection.Full(), NullPtr, LINE_INFO());
				Assert::IsFalse(Collection.Empty(), NullPtr, LINE_INFO());
				Collection.Reset();
				Assert::AreEqual(Zero, Collection.Size(), NullPtr, LINE_INFO());
				Assert::IsFalse(Collection.Full(), NullPtr, LINE_INFO());
				Assert::IsTrue(Collection.Empty(), NullPtr, LINE_INFO());

				auto AnotherCollection = TMap<FString, FString>();
				Assert::IsTrue(AnotherCollection.Empty(), NullPtr, LINE_INFO());
				AnotherCollection.Install("OneKey", "OneValue");
				AnotherCollection.Install("TwoKey", "TwoValue");
				AnotherCollection.Install("ThreeKey", "ThreeValue");
				Assert::IsTrue(AnotherCollection.Full(), NullPtr, LINE_INFO());
				Assert::AreEqual(Three, AnotherCollection.Size(), NullPtr, LINE_INFO());
				Assert::IsTrue(Equal("TwoValue", AnotherCollection["TwoKey"]), NullPtr, LINE_INFO());
				AnotherCollection.Reset();

			}
			
		};
	}
}
