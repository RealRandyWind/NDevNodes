#pragma once

#include "NDevNodesCompute.h"

namespace NDev::Nodes::Computes
{
	using namespace Types;

	struct FSimplify : public FCompute
	{
		FSimplify() : FCompute() { }
		virtual ~FSimplify() { }
	};
}