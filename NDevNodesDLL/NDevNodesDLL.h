#pragma once

#ifdef NDEVNODESDLL_EXPORTS
#define NDEVNODESDLL_EXPORTS __declspec(dllexport)
#else
#define NDEVNODESDLL_EXPORTS __declspec(dllimport)
#endif

#include "NDevNodes.h"

namespace NDev::Nodes
{
	struct NDEVNODESDLL_EXPORTS FObject;

	struct NDEVNODESDLL_EXPORTS FNode;

	struct NDEVNODESDLL_EXPORTS FComponent;

	struct NDEVNODESDLL_EXPORTS FCompute;
		
	template struct NDEVNODESDLL_EXPORTS _TParentable<FNode*>;
}