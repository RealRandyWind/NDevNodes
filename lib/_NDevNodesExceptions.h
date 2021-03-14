#pragma once

#include "NDevTypes.h"

namespace NDev
{
    namespace Exceptions
    {
        struct _FExceptionNotImplemented : FException { };

        struct _FExceptionDebug : FException { };

        struct FExceptionUnsupported : FException { };
        
        struct FExceptionDeprecated : FException { };
        
        struct FExceptionExperimental : FException { };
        
        struct FExceptionCompromized : FException { };
    }
}