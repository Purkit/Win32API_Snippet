#include "app.hpp"

void Application::Update()
{

}

void Application::Initialize()
{
    m_Window = Window::Create(1000, 800, "This is a Window :)");
    m_Window->Initialize();
    m_Window->Show();
}

void Application::Release()
{
    // Release resources.
}

void Application::Run()
{
    while ( !m_Window->ShouldClose() )
    {
        m_Window->PumpEvent();
        std::cout << "Running !!";  

    }
}