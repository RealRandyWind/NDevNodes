#include "pch.h"

#include "NDevNodesComponent.h"

using namespace NDev;
using namespace NDev::Types;
using namespace NDev::Nodes;

FComponent::FComponent() : FObject()
{
    _bThrowParentsUnsupported = True;
}

FComponent::~FComponent()
{

}

TList<FNodes*> FComponent::Parents()
{
    {
        if (_bThrowParentsUnsupported)
        {
            throw FExceptionUnsupported();
        }
        return TList<FNode*>();
    }
}

FVoid FComponent::ThrowParentsUnsupported(FBoolean bTrue)
{
    _bThrowParentsUnsupported = bTrue;
}

FBoolean FComponent::HasParents()
{
    return False;
}

FVoid FComponent::_OnParentAdd(FNode* Parent)
{

}

FVoid FComponent::_OnParentRemove(FNode* Parent)
{

}

FVoid FComponent::_OnParentDestroy(FNode* Parent, FBoolean bIsComponentDestroy)
{

}