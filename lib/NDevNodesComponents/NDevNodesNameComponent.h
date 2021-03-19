#pragma once

#include "NDevNodesComponent.h"

namespace NDev::Nodes::Components
{
	using namespace Types;

	struct FName : public FComponent
	{
		FString _Alias;

		FName() : FComponent() { _Alias = NullPtr;  }

		virtual ~FName() { }
	};
}