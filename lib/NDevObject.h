#pragma once

#include "NDev.h"

namespace NDev
{
	using namespace Types;

	struct FObject
	{
		FBoolean  _bProtect;

		FObject();

		virtual ~FObject() = 0;

		FVoid Protect(FBoolean bTrue = True);
		
		FBoolean IsProtected();
	};
}