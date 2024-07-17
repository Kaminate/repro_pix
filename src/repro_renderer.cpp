#include "repro_renderer.h"

#include "repro_assert.h"
//#include "repro_globals.h"

//#include <dxgiformat.h>
//#include <dxgi1_6.h>
//#pragma comment( lib, "DXGI.lib" )
//

#include <d3d12.h>
#pragma comment( lib, "d3d12.lib" )

#include <WinPixEventRuntime/pix3.h>

namespace Repro
{
    //static PCom< IDXGIFactory4 >   sFactory;
    //static PCom< IDXGIAdapter1 >   sBestAdapter;
    //static PCom< ID3D12Device5 >   sDevice;


    //static void FindBestAdapter()
    //{
    //    PCom<IDXGIAdapter1> bestAdapter;
    //    DXGI_ADAPTER_DESC1 bestdesc{};

    //    UINT iAdapter{};
    //    for( ;; )
    //    {
    //        PCom<IDXGIAdapter1> currAdapter;
    //        if( S_OK != sFactory->EnumAdapters1( iAdapter++, currAdapter.CreateAddress() ) )
    //            break;

    //        DXGI_ADAPTER_DESC1 desc{};
    //        Assert( SUCCEEDED( currAdapter->GetDesc1( &desc ) ) );
    //        if( bestAdapter && desc.DedicatedVideoMemory < bestdesc.DedicatedVideoMemory )
    //            continue;

    //        bestdesc = desc;
    //        bestAdapter = currAdapter;
    //    }

    //    sBestAdapter = bestAdapter;
    //}

    //static void InitDXGI()
    //{
    //    const UINT flags{ DXGI_CREATE_FACTORY_DEBUG };
    //    PCom< IDXGIFactory2 > factory2;
    //    Assert( SUCCEEDED( CreateDXGIFactory2( flags, factory2.iid(), factory2.ppv() ) ) );
    //    Assert( factory2 );
    //    sFactory = factory2.QueryInterface< IDXGIFactory4 >();
    //    Assert( sFactory );
    //    FindBestAdapter();
    //}

    //static void CreateDevice()
    //{
    //    PCom<ID3D12Debug> dx12debug;
    //    Assert( SUCCEEDED( D3D12GetDebugInterface( dx12debug.iid(), dx12debug.ppv() ) ) );
    //    dx12debug->EnableDebugLayer();

    //    IDXGIAdapter* adapter{ sBestAdapter.Get() };
    //    PCom< ID3D12Device > device;
    //    Assert(SUCCEEDED( D3D12CreateDevice(
    //        adapter,
    //        D3D_FEATURE_LEVEL_12_1,
    //        device.iid(),
    //        device.ppv() ) ));
    //    sDevice = device.QueryInterface< ID3D12Device5 >();
    //    Assert( sDevice );

    //    PCom< ID3D12InfoQueue > infoQueue;
    //    infoQueue = device.QueryInterface<ID3D12InfoQueue>();
    //    Assert( infoQueue );
    //    infoQueue->SetBreakOnSeverity( D3D12_MESSAGE_SEVERITY_CORRUPTION, TRUE );
    //    infoQueue->SetBreakOnSeverity( D3D12_MESSAGE_SEVERITY_ERROR, TRUE );
    //    infoQueue->SetBreakOnSeverity( D3D12_MESSAGE_SEVERITY_WARNING, FALSE );
    //}

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
        ID3D12GraphicsCommandList* commandList{};
        SetMarker( commandList, "it's nullptr" );

        //InitDXGI();
        //CreateDevice();

        //ID3D12Device* device{ sDevice.Get() };

        //sCommandQueue.Create( device );
        //sCommandAllocatorPool.Init( device, &sCommandQueue );
    }

}


