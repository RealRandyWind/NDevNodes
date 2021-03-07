#pragma once

#include "NDevNodesComponent.h"

namespace NDev
{
	namespace Nodes
	{
		namespace Components
		{
			using namespace Types;

			class FName : public FComponent
			{
			private:
				FString _Alias;

			public:
				FName() : FComponent() { }

				virtual ~FName() { }
			};
		}
	}
}