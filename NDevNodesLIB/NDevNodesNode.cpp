#include "pch.h"

#include "NDevNodesNode.h"

using namespace NDev;
using namespace NDev::Types;
using namespace NDev::Nodes;

FNode::FNode() : FObject()
{
	_bClearComponentsOnDesrtoy = True;
	_bClearNodesOnDestroy = False;
}

FNode::~FNode()
{
	if (_bClearComponentsOnDesrtoy)
	{
		for (auto Component : Components())
		{
			if (Component) { delete Component;  }
		}
	}

	if (_bClearNodesOnDestroy)
	{
		for (auto Node : Nodes())
		{
			if (Node && !Node->IsProtected()) { delete Node; }
		}
	}
}

FVoid FNode::Add(FComponent* Component)
{
	_Components.push_back(Component);
}

FVoid FNode::Remove(FComponent* Component)
{
	_Components.remove(Component);
}

FVoid FNode::Add(FNode* Node)
{
	_Nodes.push_back(Node);
}

FVoid FNode::Remove(FNode* Node)
{
	_Nodes.remove(Node);
}

FVoid FNode::ClearNodesOnDestory(FBoolean bTrue)
{
	_bClearNodesOnDestroy = bTrue;
}

FVoid FNode::ClearComponentsOnDesrtoy(FBoolean bTrue)
{
	_bClearComponentsOnDesrtoy = bTrue;
}

FNode::FComponents FNode::Components()
{
	return _Components;
}

const FNode::FComponents FNode::Components() const
{
	return _Components;
}


FNode::FNodes FNode::Nodes()
{
	return _Nodes;
}

const FNode::FNodes FNode::Nodes() const
{
	return _Nodes;
}

FBoolean FNode::IsClearNodesOnDestory() const
{
	return _bClearNodesOnDestroy;
}

FBoolean FNode::IsClearComponentsOnDesrtoy() const
{
	return _bClearComponentsOnDesrtoy;
}