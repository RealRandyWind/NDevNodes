#pragma once

#include "NDevNodesComponent.h"
#include "NDevNodesNode.h"

namespace NDev::Nodes::Components
{
	using namespace Types;

	struct FContext : public FComponent
	{
		FContext() : FComponent() { }

		virtual ~FContext() { }

	};
}