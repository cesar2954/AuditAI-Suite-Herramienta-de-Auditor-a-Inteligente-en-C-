#  AuditAI Suite: Herramienta de Auditoría Inteligente en C++

![C++](https://img.shields.io/badge/Plataforma-C%2B%2B17-blue)
![Role](https://img.shields.io/badge/Perfil-Auditor%20Financiero%20/%20Data%20Engineer-green)

AuditAI es una suite de herramientas avanzadas diseñada para automatizar el control interno y la detección de riesgos en departamentos financieros. Esta solución migra el análisis tradicional de hojas de cálculo a un entorno de **alto rendimiento (High-Performance Computing)**.

##  Módulos de la Suite

### 1. Detector de Anomalías (Anomalies Engine)
Utiliza el algoritmo estadístico **Z-Score** para identificar transacciones fuera de lo común. 
- **Aplicación:** Detección de fraude y errores de digitación.
- **Técnica:** Desviación estándar y cálculo de media en tiempo real.

### 2. Motor de Conciliación (Matching Engine)
Cruza datos masivos de libros mayores (ERP) contra extractos bancarios.
- **Eficiencia:** Búsqueda $O(n)$ mediante **Hash Maps**, procesando miles de registros en milisegundos.
- **Resultado:** Genera un informe de discrepancias e ítems no conciliados automáticamente.

### 3. Predictor de Riesgo (Risk Forecasting)
Implementa **Regresión Lineal** para proyectar el flujo de caja y tendencias de gasto.
- **IA Base:** Identifica si la tendencia de gasto es alcista (riesgo de liquidez) o estable.
- **Análisis:** Proyecta el comportamiento del próximo periodo basándose en el histórico de transacciones.

##  Instalación y Uso

1. **Clonar el repositorio:**
   ```bash
   git clone [https://github.com/tu-usuario/AuditAI-Suite.git](https://github.com/tu-usuario/AuditAI-Suite.git)
