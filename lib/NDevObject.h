#pragma once

#include "NDev.h"

namespace NDev
{
	using namespace Types;

	class FObject
	{
	private:
		FBoolean  _bProtect;

	public:
		FObject();

		virtual ~FObject() = 0;

		FVoid Protect(FBoolean bTrue = True);
		
		FBoolean IsProtected();
	};
}