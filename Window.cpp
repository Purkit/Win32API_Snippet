#include "Window.hpp"
#include <windowsx.h>

Window::Window(unsigned int width, unsigned int height, const std::string& title)
    : m_width(width), m_height(height), m_defaultWindowName(title) {}

Window::~Window()
{

}

LRESULT CALLBACK handle_event(HWND handle, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_ERASEBKGND:
        {
            // * Notify the OS that the background erasing will be
            // * explicitely handled from within the application.
            // * This is needed to prevent flickering.
            return 1;
        }

        case WM_CLOSE:
        {
            // TODO : Push window close event to Application Event Queue.
            break;
        }

        case WM_DESTROY:
        {
            // TODO : Push window destroy event to Application Event Queue.
            PostQuitMessage(0);
            break;
        }

        case WM_SIZE:
        {
            // TODO : Push window resize event to Application Event Queue.
            break;
        }

        case WM_KEYDOWN:
        case WM_KEYUP:
        case WM_SYSKEYDOWN:
        case WM_SYSKEYUP:
        {
            bool is_it_a_key_press_event = (msg == WM_KEYDOWN || msg == WM_SYSKEYDOWN);
            // TODO : Push keyboard input event to the Application Event Queue.
            break;
        }

        case WM_MOUSEMOVE:
        {
            // TODO : Push mouse input event to the Application Event Queue.
            int32_t x_position = GET_X_LPARAM(lParam);
            int32_t y_position = GET_Y_LPARAM(lParam);
            break;
        }

        case WM_MOUSEWHEEL:
        {
            int32_t z_delta = GET_WHEEL_DELTA_WPARAM(wParam);
            if (z_delta != 0)
            {
                // Flatten the input to an OS independent range (-1, 1)
                z_delta = (z_delta < 0) ? -1 : 1;
            }
            // TODO : Push mouse scroll event to the Application Event Queue.
            break;
        }

        case WM_LBUTTONDOWN:
        case WM_MBUTTONDOWN:
        case WM_RBUTTONDOWN:
        case WM_LBUTTONUP:
        case WM_MBUTTONUP:
        case WM_RBUTTONUP:
        {
            // TODO : Push mouse butten event to the Application Queue.
            break;
        }


        default:
            return DefWindowProc(handle, msg, wParam, lParam);

    }

}

void Window::_register_window_class()
{
    WNDCLASSEXA wc = {0};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = &handle_event;
    wc.lpszClassName = "win32apitestclass";

    RegisterClassExA(&wc);
}

void Window::_create_window()
{
    RECT rc = { 0, 0    , m_width, m_height };
    AdjustWindowRect(&rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_SYSMENU, false);

    m_windowHandle = CreateWindowExA(
        0,
        "win32apitestclass",
        m_defaultWindowName.c_str(),
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_SYSMENU,
        CW_USEDEFAULT, CW_USEDEFAULT,
        rc.right - rc.left,
        rc.bottom - rc.top,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    );
}

void Window::Initialize()
{
    _register_window_class();
    _create_window();
}

void Window::Show()
{
    ShowWindow(m_windowHandle, SW_SHOW);
    UpdateWindow(m_windowHandle);
}

void Window::Clear()
{

}

void Window::Close()
{
    m_ShouldClose = true;
    DestroyWindow(m_windowHandle);
}

void Window::PumpEvent()
{    
    while( PeekMessageA(&m_message_queue, nullptr, 0, 0, PM_REMOVE) )
    {
        TranslateMessage(&m_message_queue);
        DispatchMessage(&m_message_queue);
    }
}

void Window::WaitForEvent()
{
    // Unclear how to implement
    // GetMessageA(&m_message_queue, m_windowHandle, 0, 0);
}