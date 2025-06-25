# Simulação de Controle PID de Temperatura em C++

Este projeto implementa uma simulação de um sistema de controle PID para regular a temperatura de um forno virtual, usando a linguagem C++. O objetivo é demonstrar o comportamento de um sistema de controle em malha fechada com um modelo térmico simplificado.

## 📋 Descrição

O sistema simula um forno cuja temperatura é controlada por um atuador (aquecedor) com potência de 0 a 100%. A cada passo da simulação:

- A temperatura atual é calculada com base na potência aplicada e na perda de calor natural.
- Um controlador PID calcula o valor de potência necessário para atingir e manter a temperatura desejada (setpoint).
- O usuário define dois parâmetros de entrada:
  - Tempo de simulação (em minutos), de 1 a 60 minutos.
  - Temperatura desejada (em °C), mínima de 26°C.

A simulação é executada em tempo real com passo de 0.1s e imprime a evolução da temperatura e da potência a cada iteração.

### melhorias futuras

- Geração de gráficos (ex: via Python ou exportação para CSV)

- Interface gráfica simples

- Simulação de diferentes tipos de plantas (ex: motor, tanque)

## ⚙️ Como compilar

Requisitos:
- Compilador `g++` com suporte a C++11 ou superior.

### Comando de compilação:

```bash
g++ -o pid_ov_


