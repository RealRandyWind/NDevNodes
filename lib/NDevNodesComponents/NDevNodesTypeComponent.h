#pragma once

#include "NDevNodesComponent.h"

namespace NDev
{
	namespace Nodes
	{
		namespace Components
		{
			using namespace Types;

			class FType : public FComponent
			{
			public:
				FType() : FComponent() { }

				virtual ~FType() { }
			};
		}
	}
}