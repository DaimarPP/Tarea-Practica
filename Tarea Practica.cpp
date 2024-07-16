#include <iostream>
#include <cmath>

struct Dot {
    float x;
    float y;
    float z;

    Dot(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

float calcularDistancia(const Dot& p1, const Dot& p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    float dz = p2.z - p1.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

Dot sumarVectores(const Dot& v1, const Dot& v2) {
    return Dot(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

float productoEscalar(const Dot& v1, const Dot& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Dot productoCruz(const Dot& v1, const Dot& v2) {
    float x = v1.y * v2.z - v1.z * v2.y;
    float y = v1.z * v2.x - v1.x * v2.z;
    float z = v1.x * v2.y - v1.y * v2.x;
    return Dot(x, y, z);
}

void determinarPlano(const Dot& v) {
    if (v.x == 0 && v.y == 0)
        std::cout << "El vector esta en el plano Z." << std::endl;
    else if (v.x == 0 && v.z == 0)
        std::cout << "El vector esta en el plano Y." << std::endl;
    else if (v.y == 0 && v.z == 0)
        std::cout << "El vector esta en el plano X." << std::endl;
    else
        std::cout << "El vector no esta en un plano especifico." << std::endl;
}

int main() {
    // Ejemplo de uso
    Dot punto1(1.0, 2.0, 3.0);
    Dot punto2(4.0, 5.0, 6.0);

    // Calcular distancia entre los puntos
    float distancia = calcularDistancia(punto1, punto2);
    std::cout << "Distancia entre los puntos: " << distancia << std::endl;

    // Sumar dos vectores
    Dot sumaVectores = sumarVectores(punto1, punto2);
    std::cout << "Suma de vectores: (" << sumaVectores.x << ", "
              << sumaVectores.y << ", " << sumaVectores.z << ")" << std::endl;

    // Calcular producto escalar
    float escalar = productoEscalar(punto1, punto2);
    std::cout << "Producto escalar: " << escalar << std::endl;

    // Calcular producto cruz
    Dot cruzVectores = productoCruz(punto1, punto2);
    std::cout << "Producto cruz: (" << cruzVectores.x << ", "
              << cruzVectores.y << ", " << cruzVectores.z << ")" << std::endl;

    // Determinar el plano
    std::cout << "Vector: (" << punto1.x << ", " << punto1.y << ", "
              << punto1.z << ") ";
    determinarPlano(punto1);

    return 0;
}
