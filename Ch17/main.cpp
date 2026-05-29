#include "ConfigReader.h"

#include <iostream>

int main()
{
    ConfigReader config;

    if (!config.load("app.conf"))
    {
        std::cout << "failed to load app.conf" << std::endl;
        return 1;
    }

    std::cout << "all config values:" << std::endl;
    config.print_all();

    std::cout << "app_name = " << config.get("app_name") << std::endl;
    std::cout << "port = " << config.get_int("port") << std::endl;

    return 0;
}
