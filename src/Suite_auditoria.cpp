#include <iostream>
#include <vector>
#include <string>

// Simulación de inclusión de tus clases (Logic Integration)
// Nota: Para este ejemplo, el menú llamará a las funciones principales.

void mostrarMenu() {
    std::cout << "\n==========================================" << std::endl;
    std::cout << "      AUDIT-AI: SUITE DE AUDITORIA IA     " << std::endl;
    std::cout << "==========================================" << std::endl;
    std::cout << "1. Detector de Anomalias (Z-Score)" << std::endl;
    std::cout << "2. Conciliacion Bancaria (Matching Engine)" << std::endl;
    std::cout << "3. Pronostico de Riesgo (Forecasting)" << std::endl;
    std::cout << "4. Salir" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Seleccione una opcion: ";
}

int main() {
    int opcion = 0;

    while (opcion != 4) {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "\n[INFO] Ejecutando Detector de Anomalias..." << std::endl;
                // Aquí el sistema llama al ejecutable o función del detector
                system("detector.exe"); 
                break;
            case 2:
                std::cout << "\n[INFO] Iniciando Motor de Conciliacion..." << std::endl;
                system("conciliador.exe");
                break;
            case 3:
                std::cout << "\n[INFO] Generando Analisis de Riesgo..." << std::endl;
                system("predictor_riesgo.exe");
                break;
            case 4:
                std::cout << "Cerrando Suite Profesional. Hasta luego." << std::endl;
                break;
            default:
                std::cout << "Opcion no valida." << std::endl;
        }
    }
    return 0;
}