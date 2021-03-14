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
		private:
			_bThrowParentsUnsupported;

		public:
			FComponent();

			virtual ~FComponent();

			virtual TList<FNode*> Parents();

			virtual FVoid ThrowParentsUnsupported(FBoolean bTrue = True);

			virtual FBoolean HasParents();

		protected:
			virtual FVoid _OnParentAdd(FNode* Parent);

			virtual FVoid _OnParentRemove(FNode* Parent);

			virtual FVoid _OnParentDestroy(FNode* Parent, FBoolean bIsComponentDestroy);

		};

	}
}