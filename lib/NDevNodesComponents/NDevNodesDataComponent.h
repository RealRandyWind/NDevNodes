#pragma once

#include "NDevNodesComponent.h"

namespace NDev::Nodes::Components
{
	using namespace Types;

	struct FData : public FComponent
	{
		FData() : FComponent() { }

		virtual ~FData() { }
	};
}