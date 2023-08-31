#include "app.hpp"

int main()
{
    {
        Application app{};
        app.Initialize();
        app.Run();
    }

    return 0;
}