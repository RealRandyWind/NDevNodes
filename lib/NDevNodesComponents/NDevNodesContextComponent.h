#pragma once

#include "NDevNodesComponent.h"
#include "NDevNodesNode.h"

namespace NDev
{
	namespace Nodes
	{
		namespace Components
		{
			using namespace Types;

			class FContext : public FComponent
			{
			private:
				FBoolean _bEnable;

			public:
				FContext() : FComponent() { }

				virtual ~FContext() { }

				virtual FVoid Execute(FNode* Node) { } ;
			
			private:
				FVoid _Execute(FNode* Node) { if (_bEnable) { this->Execute(Node); } };

			};
		}
	}
}