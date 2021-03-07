#pragma once

#include "NDev.h"
#include "NDevObject.h"

namespace NDev
{
	namespace Nodes
	{
		using namespace Types;

		class FComponent : FObject
		{
		public:
			FComponent();
			virtual ~FComponent();
		};

	}
}