#include "pch.h"

#include "NDevNodesComponent.h"

using namespace NDev;
using namespace NDev::Types;
using namespace NDev::Exceptions;
using namespace NDev::Nodes;

FComponent::FComponent() : FObject(), _TParentable<FNode*>()
{
    _bEnable = True;
}

FComponent::~FComponent()
{

}

FVoid FComponent::Enable(FBoolean bTrue)
{
    _bEnable = bTrue;
}


FVoid FComponent::Execute(FNode* Parent)
{
    if (_bEnable) { _Execute(Parent); }
}

FVoid FComponent::_Execute(FNode* Parent)
{
    
}