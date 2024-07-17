#include <windows.h> // WinMain

#include "repro_globals.h"
#include "repro_renderer.h"


int CALLBACK WinMain( _In_     HINSTANCE hInstance,
                      _In_opt_ HINSTANCE,
                      _In_     LPSTR,
                      _In_     int )
{
    using namespace Repro;

    Window::Register( hInstance );

    const Window::Params windowParams{ []()
    {
      const int monitorW{ GetSystemMetrics( SM_CXSCREEN ) };
      const int monitorH{ GetSystemMetrics( SM_CYSCREEN ) };
      const int windowW{ monitorW / 2 };
      const int windowH{ monitorH / 2 };
      const int windowX{ ( monitorW - windowW ) / 2 };
      const int windowY{ ( monitorH - windowH ) / 2 };
      return Window::Params
      {
          .mW{ windowW },
          .mH{ windowH },
          .mX{ windowX },
          .mY{ windowY },
      };
    }( ) };

    gWindow.Create( "Repro", windowParams );
    Renderer::Init();

    while( !Window::QuitRequested() )
    {
        MSG msg{};
        while( PeekMessage( &msg, nullptr, 0, 0, PM_REMOVE ) )
        {
            TranslateMessage( &msg );
            DispatchMessage( &msg );
        }

        // update game loop
        Sleep( 1 );
    }

    return 0;
}

