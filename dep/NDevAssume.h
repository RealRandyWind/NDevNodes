#pragma once

#include "NDevTypes.h"

namespace NDev
{
	using namespace Types;
	
	template<typename Type>
	struct TAssume
	{
		static Type Null() { return Null; }

		static Type Zero() { return 0.0L; }

		static Type Third() { return (1.0L / 3.0L); }

		static Type Half() { return 0.5L; }

		static Type One() { return 1.0L; }

		static Type Two() { return 2.0L; }

		static Type Three() { return 3.0L; }


	};
	
}