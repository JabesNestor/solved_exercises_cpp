#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

template <typename T>
class TADConjunto {
private:
    std::vector<T> elementos;

public:
    // Constructor
    TADConjunto() {}
    
    // Constructor con lista de inicialización
    TADConjunto(std::initializer_list<T> lista) : elementos(lista) {}
    
    // Operación alta (agregar elemento)
    void alta(const T& elemento) {
        // Verificar si el elemento ya existe para evitar duplicados
        if (!existe(elemento)) {
            elementos.push_back(elemento);
        }
    }
    
    // Operación baja (eliminar elemento)
    bool baja(const T& elemento) {
        auto it = std::find(elementos.begin(), elementos.end(), elemento);
        if (it != elementos.end()) {
            elementos.erase(it);
            return true;
        }
        return false;
    }
    
    // Operación búsqueda
    bool busqueda(const T& elemento) const {
        return std::find(elementos.begin(), elementos.end(), elemento) != elementos.end();
    }
    
    // Método auxiliar para verificar existencia
    bool existe(const T& elemento) const {
        return busqueda(elemento);
    }
    
    // Operación unión (con duplicados posibles)
    TADConjunto<T> unionCon(const TADConjunto<T>& otro) const {
        TADConjunto<T> resultado = *this;
        for (const auto& elemento : otro.elementos) {
            resultado.elementos.push_back(elemento);
        }
        return resultado;
    }
    
    // Operación unión distinct (sin duplicados)
    TADConjunto<T> unionDistinct(const TADConjunto<T>& otro) const {
        TADConjunto<T> resultado = *this;
        for (const auto& elemento : otro.elementos) {
            if (!resultado.existe(elemento)) {
                resultado.elementos.push_back(elemento);
            }
        }
        return resultado;
    }
    
    // Operaciones adicionales útiles
    
    // Intersección
    TADConjunto<T> interseccion(const TADConjunto<T>& otro) const {
        TADConjunto<T> resultado;
        for (const auto& elemento : elementos) {
            if (otro.existe(elemento)) {
                resultado.alta(elemento);
            }
        }
        return resultado;
    }
    
    // Diferencia
    TADConjunto<T> diferencia(const TADConjunto<T>& otro) const {
        TADConjunto<T> resultado;
        for (const auto& elemento : elementos) {
            if (!otro.existe(elemento)) {
                resultado.alta(elemento);
            }
        }
        return resultado;
    }
    
    // Tamaño
    size_t tamano() const {
        return elementos.size();
    }
    
    // Verificar si está vacío
    bool vacio() const {
        return elementos.empty();
    }
    
    // Limpiar todos los elementos
    void limpiar() {
        elementos.clear();
    }
    
    // Mostrar elementos
    void mostrar() const {
        std::cout << "{ ";
        for (size_t i = 0; i < elementos.size(); ++i) {
            std::cout << elementos[i];
            if (i < elementos.size() - 1) std::cout << ", ";
        }
        std::cout << " }" << std::endl;
    }
    
    // Obtener todos los elementos
    std::vector<T> obtenerElementos() const {
        return elementos;
    }
    
    // Operador de acceso por índice
    T& operator[](size_t indice) {
        if (indice >= elementos.size()) {
            throw std::out_of_range("Índice fuera de rango");
        }
        return elementos[indice];
    }
    
    const T& operator[](size_t indice) const {
        if (indice >= elementos.size()) {
            throw std::out_of_range("Índice fuera de rango");
        }
        return elementos[indice];
    }
};


int main() {
    // Crear conjuntos
    TADConjunto<int> conjunto1{1, 2, 3, 4};
    TADConjunto<int> conjunto2{3, 4, 5, 6};
    
    std::cout << "Conjunto 1: ";
    conjunto1.mostrar();
    
    std::cout << "Conjunto 2: ";
    conjunto2.mostrar();
    
    // Operaciones básicas
    std::cout << "\n=== Operaciones Básicas ===" << std::endl;
    
    // Alta
    conjunto1.alta(7);
    std::cout << "Después de alta(7): ";
    conjunto1.mostrar();
    
    // Búsqueda
    std::cout << "¿Existe 3 en conjunto1? " << (conjunto1.busqueda(3) ? "Sí" : "No") << std::endl;
    std::cout << "¿Existe 8 en conjunto1? " << (conjunto1.busqueda(8) ? "Sí" : "No") << std::endl;
    
    // Baja
    if (conjunto1.baja(2)) {
        std::cout << "Elemento 2 eliminado correctamente" << std::endl;
    }
    std::cout << "Después de baja(2): ";
    conjunto1.mostrar();
    
    // Operaciones de conjuntos
    std::cout << "\n=== Operaciones de Conjuntos ===" << std::endl;
    
    // Unión
    auto unionNormal = conjunto1.unionCon(conjunto2);
    std::cout << "Unión (con posibles duplicados): ";
    unionNormal.mostrar();
    
    // Unión distinct
    auto unionDist = conjunto1.unionDistinct(conjunto2);
    std::cout << "Unión distinct (sin duplicados): ";
    unionDist.mostrar();
    
    // Intersección
    auto intersec = conjunto1.interseccion(conjunto2);
    std::cout << "Intersección: ";
    intersec.mostrar();
    
    // Diferencia
    auto diff = conjunto1.diferencia(conjunto2);
    std::cout << "Diferencia (conjunto1 - conjunto2): ";
    diff.mostrar();
    return 0;
}