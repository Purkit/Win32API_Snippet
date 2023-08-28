#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>

class Window
{
    public:
        Window(unsigned int width, unsigned int height, const std::string& title);
        ~Window();

    public:
        void Initialize();

        void Show();
        void Clear();
        void SetTitle(const std::string& title);
        void Close();

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
        const unsigned int m_heigth;
        std::string m_defaultWindowName;
        bool m_ShouldClose = false;

        bool broderless = false;
        bool fullscreen = false;
};

#endif // ! WINDOW_HPP