# 🔥 Simulação de Controle PID de Temperatura em C++

Este projeto implementa uma simulação em C++ de um sistema de controle PID para regular a temperatura de duas plantas térmicas virtuais:

- **Forno** (`Oven`)
- **Tanque térmico** (`Tank`)

O objetivo é demonstrar o comportamento de um controle em malha fechada usando modelos térmicos simplificados e um controlador PID.

---

## 📋 Descrição

O sistema permite que o usuário escolha entre simular:

1. 🔥 **Um forno aquecido por resistência**
2. 💧 **Um tanque aquecido com entrada de calor**

Para ambas as simulações, o processo é semelhante:

- O usuário fornece:
  - O **tempo total de simulação** (em minutos) – entre 1 e 60.
  - A **temperatura desejada (setpoint)** – acima de 25 °C.
  - A planta desejada: **forno** ou **tanque**.
- A simulação calcula, a cada 0.1s:
  - A temperatura atual com base na dinâmica térmica e potência aplicada.
  - A ação de controle PID (potência entre 0 e 100%) com base no erro.
  - A impressão dos dados no terminal em tempo real.

---

## ⚙️ Como compilar

### Requisitos:
- Compilador `g++` com suporte a C++11 ou superior.
- Estrutura de diretórios:
├── main.cpp
├── Makefile
├── temperatureOven/
│ ├── temperatureOven.cpp
│ └── temperatureOven.h
└── temperatureTank/
├── temperatureTank.cpp
└── temperatureTank.h

### 🚀 Melhorias futuras

Exportação de dados para CSV

Gráficos em tempo real com Python/Matplotlib

Interface gráfica (GUI)

Suporte a múltiplos tipos de controladores (PI, ON/OFF)

Configuração por arquivo externo (ex: JSON)

### Compilação com `make` (recomendado):

#### ou manualmente

g++ -ItemperatureOven -ItemperatureTank \
    main.cpp \
    temperatureOven/temperatureOven.cpp \
    temperatureTank/temperatureTank.cpp \
    -o pidControl

./pidControl

