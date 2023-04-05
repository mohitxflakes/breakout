#include <windows.h>

typedef int b32;
#define true 1 
#define false 0

#define global_varible static 
#define internal static 

global_varible b32 running = true;

internal LRESULT window_callback(HWND window,UINT message,WPARAM w_paran,LPARAM l_param)
{
  LRESULT result = 0 ;    
  switch (message)
  { 
    case WM_CLOSE :
    case WM_DESTROY : {
      running = false ;
    } break ; 
  
  default:  
    result = DefWindowProcA(window,message,w_paran,l_param);
  }
  return result ;

}

int WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd
)
{
  WNDCLASSA window_class = {0};
  window_class.style = CS_HREDRAW|CS_VREDRAW;
  window_class.lpfnWndProc = window_callback;

  window_class.lpszClassName  = "Game_window_class";

  RegisterClassA(&window_class); //passing an pointer

  HWND window = CreateWindowExA(0,window_class.lpszClassName,"breakout",
  WS_VISIBLE|WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,
  CW_USEDEFAULT,1280,720,0,0,0,0);


  while(running)
  {
    MSG message;
    while(PeekMessageA(&message,window,0,0,PM_REMOVE))
    {
      TranslateMessage(&message);
      DispatchMessage(&message);
    }
  }

}