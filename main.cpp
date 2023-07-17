#include "src/aquarium.h"

#ifdef WIN32
int WinMain(void*)
#else
int main(void*)
#endif
{
    // Создаем экземпляр класса Aquarium и запускаем метод инициализации
    Aquarium::getInstance().Init();
    // Возвращаем 0 в качестве результата выполнения функции main
    return 0;
}