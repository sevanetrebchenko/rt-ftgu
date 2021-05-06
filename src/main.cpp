
#include <iostream>
#include <rt/application.h>

#include <rt/utilities/random.h>


int main() {
    RT::Application* application = new RT::Application("test", 200, 200);

    try {
        application->Init();
    }
    catch (std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
        return 1;
    }

    application->Run();
    application->Shutdown();

    return 0;
}