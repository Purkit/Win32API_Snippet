#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include <Windows.h>

class Window
{
    public:
        Window(unsigned int width, unsigned int height, const std::string& title);
        ~Window();

    public:
        void Initialize();

        void Show();
        void Clear();
        void Close();

        void SetTitle(const std::string& title);
        void SetIcon();

        void PumpEvent();
        void WaitForEvent();

        void OnUpdate();

        void MakeContextCurrent();
        void Present();

        void Toggle_FullScreenMode();
        void Toggle_Borderless_Mode();

        bool ShouldClose();

        unsigned int GetWidth();
        unsigned int GetHeight();
        void GetLocation(unsigned int& x, unsigned int& y);
    
    private:
        const unsigned int m_width;
        const unsigned int m_height;
        std::string m_defaultWindowName;
        bool m_ShouldClose = false;

        bool broderless = false;
        bool fullscreen = false;
        
        MSG m_message_queue; // * Event Queue
    
    private:
        HWND m_windowHandle;
        HICON m_Icon;
    
    private:
        void _register_window_class();
        void _create_window();
};

#endif // ! WINDOW_HPP