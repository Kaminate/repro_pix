#include "repro_renderer.h"
#include "repro_assert.h"

#define IMPORT_STD_PRE() true // when true, causes error C2733: '_mm_add_ss': you cannot overload a function with 'extern "C"' linkage
#define IMPORT_STD_POST() false

#include <d3d12.h>
#pragma comment( lib, "d3d12.lib" )

#if IMPORT_STD_PRE()
import std;
#endif

#include <WinPixEventRuntime/pix3.h>

#if IMPORT_STD_POST()
import std;
#endif


namespace Repro
{

    void EndEvent( ID3D12GraphicsCommandList* commandList )
    {
      PIXEndEvent( commandList );
    }

    void BeginEvent( ID3D12GraphicsCommandList* commandList, const char* str )
    {
        PIXBeginEvent( commandList, PIX_COLOR_DEFAULT, str );
    }

    void SetMarker( ID3D12GraphicsCommandList* commandList, const char* str )
    {
      PIXSetMarker( commandList, PIX_COLOR_DEFAULT, str );
    }


    void Renderer::Init()
    {
#if IMPORT_STD_PRE() || IMPORT_STD_POST()
        std::cout << "Renderer::Init" << std::endl;
#endif
        ID3D12GraphicsCommandList* commandList{};
        SetMarker( commandList, "null ref exception" );
    }

}


