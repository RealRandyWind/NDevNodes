#pragma once

#ifdef NDEVNODESDLL_EXPORTS
#define NDEVNODESDLL_EXPORTS __declspec(dllexport)
#else
#define NDEVNODESDLL_EXPORTS __declspec(dllimport)
#endif

#include "NDevNodes.h"

namespace NDev
{
	namespace Nodes
	{
		class NDEVNODESDLL_EXPORTS FObject;

		class NDEVNODESDLL_EXPORTS FNode;

		class NDEVNODESDLL_EXPORTS FComponent;

		class NDEVNODESDLL_EXPORTS FConstruct;

		class NDEVNODESDLL_EXPORTS FCompute;
	}
}