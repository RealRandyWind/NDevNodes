#include "pch.h"

#include "NDevObject.h"

using namespace NDev;
using namespace NDev::Types;

FObject::FObject()
{
	_bProtect = False;
}

FObject::~FObject()
{
	if (_bProtect) { throw FException(); }
}

FVoid FObject::Protect(FBoolean bTrue)
{
	_bProtect = bTrue;
}

FBoolean FObject::IsProtected()
{
	return _bProtect;
}