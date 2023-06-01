#include "src/aquarium.h"

int main(void)
{
    // Создаем экземпляр класса Aquarium и запускаем метод инициализации
    Aquarium::getInstance().Init();
    // Возвращаем 0 в качестве результата выполнения функции main
    return 0;
}