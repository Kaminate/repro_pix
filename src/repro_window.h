#pragma once

#include <windows.h> // HWND, HINSTANCE

namespace Repro
{
  struct Window
  {
      struct Params
      {
        int mW{}, mH{}, mX{}, mY{};
      };

      static void Register( HINSTANCE );
      static bool QuitRequested();
      void        Create( const char*, Params );

      HWND mHWND{};
      int  mW{}, mH{}, mX{}, mY{};
  };
}


