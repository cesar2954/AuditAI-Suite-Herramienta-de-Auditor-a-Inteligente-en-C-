#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <numeric>
#include <cmath>
#include <iomanip>

struct Transaction {
    int id;
    double monto;
};

class RiskEngine {
public:
    // 1. Cargar datos desde el CSV
    std::vector<double> cargarMontos(std::string nombreArchivo) {
        std::vector<double> montos;
        std::ifstream archivo(nombreArchivo);
        std::string linea;

        if (!archivo.is_open()) {
            std::cerr << "Error: No se encontro " << nombreArchivo << std::endl;
            return montos;
        }

        std::getline(archivo, linea); // Saltar encabezado

        while (std::getline(archivo, linea)) {
            std::stringstream ss(linea);
            std::string temp;
            
            std::getline(ss, temp, ','); // Leer ID (no lo usamos para el calculo)
            std::getline(ss, temp, ','); // Leer Fecha
            std::getline(ss, temp, ','); // Leer Monto
            
            if (!temp.empty()) {
                montos.push_back(std::stod(temp));
            }
        }
        archivo.close();
        return montos;
    }

    // 2. Calcular Regresion Lineal (Tendencia)
    void analizarTendencia(const std::vector<double>& datos) {
        int n = datos.size();
        if (n == 0) return;

        double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

        for (int i = 0; i < n; ++i) {
            double x = i + 1; // El tiempo (1, 2, 3...)
            double y = datos[i];
            sumX += x;
            sumY += y;
            sumXY += x * y;
            sumX2 += x * x;
        }

        // Formula de la pendiente: m = (nΣxy - ΣxΣy) / (nΣx² - (Σx)²)
        double pendiente = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
        double interseccion = (sumY - pendiente * sumX) / n;

        std::cout << "==========================================" << std::endl;
        std::cout << "   ANALISIS DE TENDENCIA FINANCIERA       " << std::endl;
        std::cout << "==========================================" << std::endl;
        std::cout << "Registros analizados: " << n << std::endl;
        std::cout << "Pendiente de gasto: " << std::fixed << std::setprecision(2) << pendiente << std::endl;

        // 3. Pronostico y Alerta de Riesgo
        double siguientePrediccion = pendiente * (n + 1) + interseccion;
        std::cout << "Pronostico proxima transaccion: $" << siguientePrediccion << std::endl;

        if (pendiente > 0.5) {
            std::cout << "[ALERTA DE RIESGO] Tendencia alcista detectada. Posible fuga de capital o inflacion de costos." << std::endl;
        } else if (pendiente < -0.5) {
            std::cout << "[INFO] Tendencia bajista. Optimizacion de gastos detectada." << std::endl;
        } else {
            std::cout << "[OK] Flujo de caja estable." << std::endl;
        }
    }
};

int main() {
    RiskEngine engine;
    
    // Leemos directamente del archivo que generaste antes
    std::vector<double> misDatos = engine.cargarMontos("datos.csv");

    if (!misDatos.empty()) {
        engine.analizarTendencia(misDatos);
    }

    return 0;
}