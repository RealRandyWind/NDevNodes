#include "pch.h"

#include "NDevNodesConstruct.h"

using namespace NDev;
using namespace NDev::Types;
using namespace NDev::Nodes;

FConstruct::FConstruct() : FObject()
{

}

FConstruct::~FConstruct()
{

}

FConstruct::FComponents FConstruct::Components()
{
	return _Components;
}

const FConstruct::FComponents FConstruct::Components() const
{
	return _Components;
}

FConstruct::FNodes FConstruct::Nodes()
{
	return _Nodes;
}

const FConstruct::FNodes FConstruct::Nodes() const
{
	return _Nodes;
}