#pragma once

#include "NDevTypes.h"

#include "_NDevNodesCollections.h"
#include "_NDevNodesExceptions.h"

namespace NDev::Nodes
{
    using namespace NDev::Types;
    using namespace NDev::Exceptions;

    template<class TypeParent>
    struct _TParentable {
        using FParent = TypeParent;
        using FParents = TList<TypeParent>;

        FBoolean _bThrowParentsUnsupported;

        _TParentable()
        {
            _bThrowParentsUnsupported = True;
        }

        virtual ~_TParentable() = 0 { };

        FVoid ThrowParentsUnsupported(FBoolean bTrue = True)
        {
            _bThrowParentsUnsupported = True;
        }

        virtual FParents Parents()
        {
            if (_bThrowParentsUnsupported)
            {
                throw FExceptionUnsupported();
            }
            return FParents();
        }

        virtual FBoolean HasParents()
        {
            return False;
        }

        virtual FVoid _Execute(FParent Parent) { };

        virtual FVoid _OnParentAdd(FParent Parent) { };

        virtual FVoid _OnParentRemove(FParent Parent) { };

        virtual FVoid _OnParentDestroy(FParent Parent, FBoolean bIsDestroy) { };
    };
}