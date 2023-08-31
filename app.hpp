#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <memory>
#include "Window.hpp"

class Application
{
    public:

        virtual void Initialize();
        virtual void Release();

        void Run();
    
    private:
        void Update();
    
    private:
        std::shared_ptr<Window> m_Window;

};

#endif // ! end of APPLICATION_HPP