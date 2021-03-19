#pragma once

#include "NDev.h"
#include "NDevObject.h"
#include "NDevNodesComponent.h"

#include "_NDevNodesCollections.h"
#include "_NDevNodesDefinitions.h"

namespace NDev::Nodes
{
	using namespace Types;
		
	struct FComponent;

	struct FNode : FObject, _TParentable<FNode*>
	{
		using FComponents = TList<FComponent*>;
		using FNodes = TList<FNode*>;

		FBoolean _bClearNodesOnDestroy, _bClearComponentsOnDesrtoy;
		FComponents _Components;
		FNodes _Nodes;

		FNode();
			
		~FNode();

		FVoid Add(FComponent* Component);
			
		FVoid Remove(FComponent* Component);

		FVoid Add(FNode* Node);

		FVoid Remove(FNode* Node);
			
		FVoid ClearNodesOnDestory(FBoolean bTrue = True);

		FVoid ClearComponentsOnDesrtoy(FBoolean bTrue = True);

		FComponents Components();

		const FComponents Components() const;

		FNodes Nodes();

		const FNodes Nodes() const;

		FBoolean IsClearNodesOnDestory() const;

		FBoolean IsClearComponentsOnDesrtoy() const;

		FVoid Execute(FNode *Parent = NullPtr);

	};
}