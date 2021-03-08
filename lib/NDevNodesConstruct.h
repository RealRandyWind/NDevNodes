#pragma once

#include "NDev.h"
#include "NDevObject.h"
#include "NDevNodesNode.h"
#include "NDevNodesComponent.h"

#include "_NDevNodesCollections.h"

namespace NDev
{
	namespace Nodes
	{
		using namespace Types;

		class FConstruct : FObject
		{
		public:
			using FNodes = TSet<FNode*>;
			using FComponents = TSet<FComponent*>;

		private:
			FNodes _Nodes;
			FComponents _Components;

		public:
			FConstruct();

			virtual ~FConstruct();

			FComponents Components();

			const FComponents Components() const;

			FNodes Nodes();

			const FNodes Nodes() const;
		};
	}
}