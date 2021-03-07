#pragma once

#include "NDevNodesComponent.h"

namespace NDev
{
	namespace Nodes
	{
		namespace Components
		{
			using namespace Types;

			class FData : public FComponent
			{
			public:
				FData() : FComponent() { }

				virtual ~FData() { }
			};
		}
	}
}