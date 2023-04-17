#include "fish.h"
#include <math.h>
#include <iostream>

constexpr int MAX_DIST = 50; // Максимальное расстояние для обнаружения препятствий
constexpr int MIN_DIST = 3; // Минимальное расстояние для обнаружения препятствий
constexpr float RAD90 = 90 * DEG2RAD; // Угол поворота в радианах
constexpr int MAX_MASS = 4; // Максимальная масса рыбы
constexpr int MAX_SIZE = MAX_MASS * 10; // Максимальный размер рыбы
constexpr int ROCKCOLOR = 2189591295; // Цвет препятствия "скала"

// Конструктор с указанием массы и позиции рыбы
Fish::Fish(unsigned int m, Vector2 pos) : mass((m % (MAX_MASS - 1)) + 1)
{
    this->size = this->mass * 10; // Установка размера рыбы на основе массы
    this->Coord = pos; // Установка позиции рыбы
    this->choose_color(); // Вызов метода выбора цвета рыбы
}

// Конструктор по умолчанию
Fish::Fish() : mass(GetRandomValue(1, MAX_MASS - 1))
{
    this->size = mass * 10; // Установка размера рыбы на основе массы
    this->Coord = {(float)GetRandomValue(MAX_SIZE, AQUARIUM_WIDTH - MAX_SIZE),
                   (float)GetRandomValue(MAX_SIZE, ZONA_ROCK_MIN - MAX_SIZE)}; // Установка случайной позиции рыбы
    this->choose_color(); // Вызов метода выбора цвета рыбы
}

void Fish::choose_color()
{
    switch (this->size)
    {
        case 10:
            this->colorbody = VIOLET; // Устанавливаем фиолетовый цвет для массы 1
            break;
        case 20:
            this->colorbody = RED; // Устанавливаем красный цвет для массы 2
            break;
        default:
            this->colorbody = BLACK; // Устанавливаем черный цвет для всех остальных масс
            break;
    }
}

Vector2 Fish::get_Coord()
{
    return this->Coord;
}

void Fish::Init()
{
    // Обновляем скорость на основе массы
    this->speed = MAX_MASS - mass;

    // Вычисляем синусы и косинусы углов для повышения производительности
    float rad = this->rotate;
    float sin_rad = sinf(rad); // Синус угла поворота
    float cos_rad = cosf(rad); // Косинус угла поворота
    float cos_rad_minus_rad60 = cosf(rad - RAD60); // Косинус разницы угла поворота и 60 градусов
    float sin_rad_minus_rad60 = sinf(rad - RAD60); // Синус разницы угла поворота и 60 градусов
    float cos_rad_plus_rad60 = cosf(rad + RAD60); // Косинус суммы угла поворота и 60 градусов
    float sin_rad_plus_rad60 = sinf(rad + RAD60); // Синус суммы угла поворота и 60 градусов

    // Вычисляем координаты точек для отрисовки тела рыбы
    float posx = this->Coord.x, posy = this->Coord.y; // Координаты центра рыбы
    float r = static_cast<float>(this->size); // Радиус тела рыбы
    float hight = r / 5.0f;
    this->pfd[0] = {
        posx + (hight * sin_rad), // Координаты вершины рыбы на основе синуса и косинуса угла поворота
        posy - (hight * cos_rad)};
    this->pfd[1] = {
        posx - (r * cos_rad_minus_rad60), // Координаты левой боковой рыбы на основе косинуса разницы угла поворота и 60 градусов
        posy - (r * sin_rad_minus_rad60)}; 
    this->pfd[2] = {
        posx - (hight * sin_rad), // Координаты нижней точки рыбы на основе синуса и косинуса угла поворота
        posy + (hight * cos_rad)};
    this->pfd[3] = {
        posx + (r * cos_rad_plus_rad60), // Координаты правой рыбы точки на основе косинуса суммы угла поворота и 60 градусов
        posy + (r * sin_rad_plus_rad60)};

    // Вызываем метод Draw() для отрисовки рыбы
    this->Draw();
}

bool lineLine(float current_pointx, float current_pointy, float next_pointx, float next_pointy,
              float start_linex, float start_liney, float end_linex, float end_liney, int &dist)
{
    // Вычисление разностей координат для улучшения читаемости кода
    float dx1 = next_pointx - current_pointx;
    float dy1 = next_pointy - current_pointy;
    float dx2 = end_linex - start_linex;
    float dy2 = end_liney - start_liney;

    // Вычисление знаменателя для определения точек пересечения
    float gamma = dy1 * dx2 - dx1 * dy2;

    // Проверка на деление на ноль
    if (gamma == 0)
    {
        return false;
    }

    // Вычисление параметров uA и uB для определения точек пересечения
    float uA = ((dx1) * (start_liney - current_pointy) - (dy1) * (start_linex - current_pointx)) / gamma;
    float uB = ((dx2) * (start_liney - current_pointy) - (dy2) * (start_linex - current_pointx)) / gamma;

    // Проверка на нахождение точек пересечения на отрезках
    if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1)
    {
        // Вычисление расстояния между точками пересечения и текущей точкой
        float distX = uA * dx2;
        float distY = uA * dy2;
        dist = (int)floor(sqrt((distX * distX) + (distY * distY)));
        return true;
    }

    return false;
}

// Используется для проверки на пересечение между переданной линией и контуром объекта на основе массива точек, представляющих контур.
void CheckCollisionLines(Vector2 *line, Vector2 *points, int points_count, Obstacle &obstacle)
{
    int dist = obstacle.distance; // Текущее значение расстояния до препятствия
    int next = 0; // Индекс следующей точки в массиве points
    float end_liney = line[1].y; // Координата y конечной точки линии
    float end_linex = line[1].x; // Координата x конечной точки линии
    float start_liney = line[0].y; // Координата y начальной точки линии
    float start_linex = line[0].x; // Координата x начальной точки линии

    // Проходим по каждому отрезку, заданному массивом точек
    for (int current = 0; current < points_count; current++)
    {
        next = (current + 1) % points_count; // Получаем индекс следующей точки в массиве points с использованием операции остатка
        // Это позволяет обрабатывать случай, когда текущая точка является последней 
        // в массиве, и следующая точка должна быть первой в массиве, чтобы сформировать замкнутый контур из точек.

        // Извлекаем координаты текущей и следующей точек
        float current_pointx = points[current].x; // Координата x текущей точки
        float current_pointy = points[current].y; // Координата y текущей точки
        float next_pointx = points[next].x; // Координата x следующей точки
        float next_pointy = points[next].y; // Координата y следующей точки

        // Проверяем пересечение текущего отрезка с линией, используя функцию lineLine()
        if (lineLine(current_pointx, current_pointy, next_pointx, next_pointy, start_linex, start_liney, end_linex, end_liney, dist))
        {
            obstacle.isdetected = true; // Обнаружено пересечение, устанавливаем флаг
            if (dist < obstacle.distance)
            {
                obstacle.distance = dist; // Обновляем значение расстояния до препятствия, если оно меньше текущего значения
            }
        }
    }
}

// Метод для поиска препятствий впереди рыбы
Obstacle Fish::Look(Rock *rock)
{
    Obstacle danger = {0, WHITE, this->distance}; // Инициализируем объект Obstacle с начальными значениями
    Vector2 line_dir[2]; // Создаем массив для хранения точек начала и конца линии обзора

    line_dir[0] = Coord; // Устанавливаем начальную точку линии обзора равной текущим координатам рыбы

    line_dir[1] = {Coord.x + (direction.x * this->distance), Coord.y + (direction.y * this->distance)}; // Рассчитываем конечную точку линии обзора на основе направления и расстояния

    for (int i = 0; i < MAX_ROCK; i++) // Проходим по массиву скал
    {
        Vector2 *rock_pfd = rock[i].get_pfd(); // Получаем указатель на массив точек контура текущей скалы

        // Вызываем функцию CheckCollisionLines() с текущими точками линии обзора и точками контура текущей скалы
        CheckCollisionLines(line_dir, rock_pfd, MAX_POINTS, danger);

        if (danger.isdetected) // Если обнаружено препятствие
        {
            danger.color = rock[i].get_colorbody(); // Обновляем цвет опасности в объекте Obstacle с цветом тела текущей скалы
        }
    }

    return danger; // Возвращаем объект Obstacle с информацией о ближайшем препятствии
}

// Генерирует случайный вектор в двумерном пространстве
Vector2 GetRandomVector()
{
    int x, y;
    do {
        x = GetRandomValue(-1, 1); // Генерируем случайное значение x из диапазона [-1, 1]
        y = GetRandomValue(-1, 1); // Генерируем случайное значение y из диапазона [-1, 1]
    } while (x == 0 && y == 0); // Проверяем, чтобы оба значения не были равны 0, иначе генерируем новые значения
    return {(float)x, (float)y}; // Возвращаем случайно сгенерированный вектор (x, y) в формате (float, float)
}

// Метод для установки нового маршрута движения рыбы
void Fish::set_route()
{
    this->direction = GetRandomVector(); // Устанавливаем случайное направление движения рыбы
    this->distance = GetRandomValue(MIN_DIST, MAX_DIST) * this->speed; // Устанавливаем случайное расстояние для движения рыбы, учитывая её скорость
    this->rotate = atan2f(direction.y, direction.x) + RAD90; // Вычисляем угол поворота рыбы на основе её направления, смещенный на 90 градусов
}

// Метод для проверки столкновения с границами аквариума
bool Fish::CheckWall()
{
    int posx = static_cast<int>(this->Coord.x + (this->size * this->direction.x)); // Вычисляем новую позицию рыбы по оси X
    int posy = static_cast<int>(this->Coord.y + (this->size * this->direction.y)); // Вычисляем новую позицию рыбы по оси Y
    bool a = posx > AQUARIUM_WIDTH || posx < 0; // Проверяем, находится ли рыба за пределами аквариума по оси X
    bool b = posy > AQUARIUM_HEIGHT || posy < 0; // Проверяем, находится ли рыба за пределами аквариума по оси Y
    return a || b; // Возвращаем true, если рыба находится за пределами аквариума по одной из осей
}

void Fish::Run(Rock *rock)
{
    // Проверяем, есть ли еще оставшееся расстояние для плавания и не достигли ли стены
    if (this->distance > 0 && !this->CheckWall())
    {
        // Получаем информацию о ближайшем объекте
        Obstacle obstacle = this->Look(rock);
        // Если объект обнаружен
        if (obstacle.isdetected)
        {
            // Проверяем тип объекта
            switch (ColorToInt(obstacle.color))
            {
            case ROCKCOLOR:
                // Если ближайший объект - скала и расстояние до нее меньше или равно размеру рыбы,
                // меняем направление движения и выходим из функции
                if (obstacle.distance - size <= size)
                {
                    this->set_route();
                    return;
                }
                break;
            }
        }
        // Обновляем расстояние и координаты с учетом скорости и направления движения
        this->distance -= this->speed;
        this->Coord.x += this->direction.x * this->speed;
        this->Coord.y += this->direction.y * this->speed;
    }
    else
    {
        // Если оставшееся расстояние для плавания равно 0 или достигнута стена,
        // меняем направление движения
        this->set_route();
    }
}