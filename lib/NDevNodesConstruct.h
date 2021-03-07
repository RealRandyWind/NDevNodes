#pragma once

#include "NDev.h"
#include "NDevObject.h"
#include "NDevNodesNode.h"
#include "NDevNodesComponent.h"

#include <set>

namespace NDev
{
	namespace Nodes
	{
		using namespace Types;

		class FConstruct : FObject
		{
		public:
			using FNodes = std::set<FNode*>;
			using FComponents = std::set<FComponent*>;

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