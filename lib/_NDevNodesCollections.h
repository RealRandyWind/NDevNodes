#pragma once

#include "NDevTypes.h"

#include <list>
#include <array>
#include <stack>
#include <set>
#include <queue>
#include <map>

namespace NDev::Types
{
	struct FCollection
	{
		FCollection() { }
			
		virtual ~FCollection() = 0 { };
			
		virtual FSize Size() const = 0;

		virtual FSize SizeOf() const = 0;

		virtual FBoolean Full() const
		{
			return Size() > 0;
		}

		virtual FBoolean Empty() const
		{
			return Size() == 0;
		}
	};

	template<typename TypeKey, typename TypeValue>
	struct TEntry
	{
		using FKey = typename TypeKey;
		using FValue = typename TypeValue;

		FKey Key;
		FValue Value;
	};

	template<typename TypeValue>
	struct TCollection : FCollection
	{
		using FValue = typename TypeValue;

		TCollection() { }

		~TCollection() = 0 { }

		virtual FSize SizeOf() const
		{
			return sizeof(TypeValue) * this->Size();
		}

		virtual TypeValue Item() const
		{
			return  TypeValue();
		}

		virtual TypeValue* NewItem() const
		{
			return new TypeValue();
		}
	};


	template<typename TypeIterator, typename TypeConsIterator>
	struct _TIterable
	{
		virtual ~_TIterable() = 0 {}

		virtual TypeIterator begin() = 0;

		virtual TypeConsIterator begin() const = 0;

		virtual TypeIterator end() = 0;

		virtual TypeConsIterator end() const = 0;
	};

	template<typename TypeValue>
	struct TList : TCollection<TypeValue>, _TIterable<typename std::list<TypeValue>::iterator, typename std::list<TypeValue>::const_iterator>
	{
		using _FCollection = typename std::list<TypeValue>;
		using _FIterator = typename _FCollection::iterator;
		using _FConstIterator = typename _FCollection::const_iterator;

		_FCollection _Collection;

		TList(FSize ReserveSize = 0)
		{
			_Collection = _FCollection(ReserveSize);
		}

		~TList() {}

		FVoid Add(TypeValue Item)
		{
			_Collection.push_back(Item);
		}

		FVoid Remove(TypeValue Item)
		{
			_Collection.remove(Item);
		}

		FVoid Reset()
		{
			_Collection.clear();
		}

		virtual FSize Size() const {
			return _Collection.size();
		}

		virtual _FIterator begin()
		{
			return _Collection.begin();
		}

		virtual _FConstIterator begin() const
		{
			return _Collection.begin();
		}

		virtual _FIterator end()
		{
			return _Collection.end();
		}

		virtual _FConstIterator end() const
		{
			return _Collection.end();
		}

		template<class ClassPredicate>
		FVoid RemoveIf(ClassPredicate Predicate)
		{
			_Collection.remove_if(Predicate);
		}
			
	};

	template<typename TypeValue, FSize SizeArray>
	struct TArray : TCollection<TypeValue>, _TIterable<typename std::array<TypeValue, SizeArray>::iterator, typename std::array<TypeValue, SizeArray>::const_iterator>
	{
		using _FCollection = typename std::array<TypeValue, SizeArray>;
		using _FIterator = typename _FCollection::iterator;
		using _FConstIterator = typename _FCollection::const_iterator;

		_FCollection _Collection;

		TArray() { }

		~TArray() { }

		TypeValue& operator[](FSize Index)
		{
			return _Collection[Index];
		}

		const TypeValue& operator[](FSize Index) const
		{
			return _Collection[Index];
		}

		virtual FSize Size() const {
			return _Collection.size();
		}

		virtual _FIterator begin()
		{
			return _Collection.begin();
		}

		virtual _FConstIterator begin() const
		{
			return _Collection.begin();
		}

		virtual _FIterator end()
		{
			return _Collection.end();
		}

		virtual _FConstIterator end() const
		{
			return _Collection.end();
		}
	};

	template<typename TypeValue>
	struct TStack : TCollection<TypeValue>
	{
		using _FCollection = typename std::stack<TypeValue>;

		_FCollection _Collection;

		TStack()
		{
			_Collection = _FCollection();
		}

		~TStack() {}

		FVoid Push(TypeValue Item)
		{
			_Collection.push(Item);
		}

		TypeValue Pop()
		{
			auto Item = _Collection.top();
			_Collection.pop();
			return Item;
		}

		TypeValue& Peek()
		{
			return _Collection.top();
		}

		const TypeValue& Peek() const
		{
			return _Collection.top();
		}

		virtual FSize Size() const {
			return _Collection.size();
		}
	};

	template<typename TypeValue, class ClassCompare = std::less<TypeValue>>
	struct TSet : TCollection<TypeValue>, _TIterable<typename std::set<TypeValue, ClassCompare>::iterator, typename std::set<TypeValue, ClassCompare>::const_iterator>
	{
		using _FCollection = typename std::set<TypeValue, ClassCompare>;
		using _FIterator = typename _FCollection::iterator;
		using _FConstIterator = typename _FCollection::const_iterator;

		_FCollection _Collection;

		TSet()
		{
			_Collection = _FCollection();
		}

		~TSet() {}

		FVoid Add(TypeValue Item)
		{
			_Collection.insert(Item);
		}

		FVoid Remove(TypeValue Item)
		{
			_Collection.erase(Item);
		}

		FVoid Reset()
		{
			_Collection.clear();
		}

		virtual FSize Size() const {
			return _Collection.size();
		}

		virtual _FIterator begin()
		{
			return _Collection.begin();
		}

		virtual _FConstIterator begin() const
		{
			return _Collection.begin();
		}

		virtual _FIterator end()
		{
			return _Collection.end();
		}

		virtual _FConstIterator end() const
		{
			return _Collection.end();
		}
	};

	template<typename TypeValue>
	struct TQueue : TCollection<TypeValue>
	{
		using _FCollection = typename std::queue<TypeValue>;

		_FCollection _Collection;

		TQueue()
		{
			_Collection = _FCollection();
		}

		~TQueue() {}

		FVoid Queue(TypeValue Item)
		{
			_Collection.push(Item);
		}

		TypeValue Dequeue()
		{
			auto Item = _Collection.front();
			_Collection.pop();
			return Item;
		}

		TypeValue& Peek()
		{
			return _Collection.front();
		}

		const TypeValue& Peek() const
		{
			return _Collection.front();
		}

		virtual FSize Size() const {
			return _Collection.size();
		}
	};

	template<typename TypeKey, typename TypeValue>
	struct TMap : TCollection<TypeValue>, _TIterable<typename std::map<TypeKey, TypeValue>::iterator, typename std::map<TypeKey, TypeValue>::const_iterator>
	{
		using _FCollection = typename std::map<TypeKey, TypeValue>;
		using _FIterator = typename _FCollection::iterator;
		using _FConstIterator = typename _FCollection::const_iterator;
		using _FEntry = typename std::pair<TypeKey, TypeValue>;

		_FCollection _Collection;

		TMap()
		{
			_Collection = _FCollection();
		}

		~TMap() {}

		FVoid Install(TypeKey Key, TypeValue Item)
		{
			_Collection.insert(_FEntry(Key, Item));
		}

		FVoid Uninstall(TypeKey Key)
		{
			_Collection.erase(Key);
		}

		FVoid Reset()
		{
			_Collection.clear();
		}

		virtual FSize Size() const {
			return _Collection.size();
		}

		virtual _FIterator begin()
		{
			return _Collection.begin();
		}

		virtual _FConstIterator begin() const
		{
			return _Collection.begin();
		}

		virtual _FIterator end()
		{
			return _Collection.end();
		}

		virtual _FConstIterator end() const
		{
			return _Collection.end();
		}

		TypeValue& operator[](TypeKey Key)
		{
			return _Collection[Key];
		}

		const TypeValue& operator[](TypeKey Key) const
		{
			return _Collection[Key];
		}

	};
}