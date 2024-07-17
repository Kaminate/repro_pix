#include "repro_assert.h"

import std; // abort

void Repro::Assert( bool b )
{
    if( !b )
    {
        std::abort();
    }
}

