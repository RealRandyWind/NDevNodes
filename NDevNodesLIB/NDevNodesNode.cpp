#include "pch.h"

#include "NDevNodesNode.h"

using namespace NDev;
using namespace NDev::Types;
using namespace NDev::Nodes;

FNode::FNode() : FObject(), _TParentable<FNode*>()
{
	_bClearComponentsOnDesrtoy = True;
	_bClearNodesOnDestroy = False;
}

FNode::~FNode()
{
	for (auto Component : _Components)
	{
		if (Component)
		{
			Component->_OnParentDestroy(this, _bClearComponentsOnDesrtoy);
			if(_bClearComponentsOnDesrtoy) { delete Component; };
		}
	}

	if (_bClearNodesOnDestroy)
	{
		for (auto Node : _Nodes)
		{
			Node->_OnParentDestroy(this, _bClearNodesOnDestroy);
			if (Node && !Node->IsProtected()) { delete Node; }
		}
	}
}

FVoid FNode::Add(FComponent* Component)
{
	_Components.Add(Component);
	Component->_OnParentAdd(this);
}

FVoid FNode::Remove(FComponent* Component)
{
	_Components.Remove(Component);
	Component->_OnParentRemove(this);
}

FVoid FNode::Add(FNode* Node)
{
	_Nodes.Add(Node);
	Node->_OnParentAdd(this);
}

FVoid FNode::Remove(FNode* Node)
{
	_Nodes.Remove(Node);
	Node->_OnParentRemove(this);
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

FVoid FNode::Execute(FNode* Parent)
{
	for (auto Component : _Components) { Component->Execute(this); }
	for (auto Node : _Nodes) { Node->Execute(this); }
}