#include "repro_window.h"
#include "repro_assert.h"

namespace Repro
{
    static const char* sClassName{ "my class" };
    static bool        sQuitRequested{};

    LRESULT CALLBACK WindowProc( const HWND hwnd,
                                         const UINT uMsg,
                                         const WPARAM wParam,
                                         const LPARAM lParam )
    {
        if( uMsg == WM_CLOSE )
          sQuitRequested = true;

        return DefWindowProc( hwnd, uMsg, wParam, lParam );
    }


    bool Window::QuitRequested()
    {
      return sQuitRequested;
    }

    void Window::Register( HINSTANCE hInstance )
    {
        const WNDCLASSEX wc
        {
          .cbSize        { sizeof( WNDCLASSEX ) },
          .style         { CS_HREDRAW | CS_VREDRAW },
          .lpfnWndProc   { WindowProc },
          .hInstance     { hInstance },
          .hbrBackground { ( HBRUSH )GetStockObject( BLACK_BRUSH ) },
          .lpszClassName { sClassName },
        };

        Assert( RegisterClassEx( &wc ) );
    }

    void Window::Create( const char* name, Params params )
    {
        const DWORD style{ WS_POPUP };
        RECT rect{ 0, 0, params.mW, params.mH };
        Assert( AdjustWindowRect( &rect, style, FALSE ) );
        mX = params.mX;
        mY = params.mY;
        mW = rect.right - rect.left;
        mH = rect.bottom - rect.top;
        mHWND = CreateWindowA( sClassName,
                               name,
                               style,
                               mX, mY, mW, mH,
                               nullptr, nullptr, nullptr, nullptr );
        ShowWindow( mHWND, SW_SHOW );
    }
};



