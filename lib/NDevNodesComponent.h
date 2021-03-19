#pragma once

#include "NDev.h"
#include "NDevObject.h"
#include "NDevNodesNode.h"

#include "_NDevNodesDefinitions.h"

namespace NDev::Nodes
{
	using namespace Types;

	struct FNode;

	struct FComponent : FObject, _TParentable<FNode*>
	{
		FBoolean _bEnable;

		FComponent();

		virtual ~FComponent();

		FVoid Enable(FBoolean bTrue = True);

		FVoid Execute(FNode* Parent);

		virtual FVoid _Execute(FNode* Parent);

	};
}