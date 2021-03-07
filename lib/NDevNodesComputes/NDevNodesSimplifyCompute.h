#pragma once

#include "NDevNodesCompute.h"

namespace NDev
{
	namespace Nodes
	{
		namespace Computes 
		{
			using namespace Types;

			class FSimplify : public FCompute
			{
			public:
				FSimplify() : FCompute() { }
				virtual ~FSimplify() { }
			};
		}
	}
}