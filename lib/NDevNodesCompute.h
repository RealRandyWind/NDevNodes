#pragma once

#include "NDev.h"
#include "NDevObject.h"

namespace NDev::Nodes
{
	using namespace Types;

	struct FCompute : FObject
	{
		FCompute();
		virtual ~FCompute();
	};
}