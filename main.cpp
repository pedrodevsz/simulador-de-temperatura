#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>

class PID {
private:
    double kp, ki, kd;
    double integral;
    double prev_error;
public:
    PID(double p, double i, double d) : kp(p), ki(i), kd(d), integral(0), prev_error(0) {}

    double update(double setpoint, double measured, double dt) {
        double error = setpoint - measured;
        integral += error * dt;
        double derivative = (error - prev_error) / dt;
        prev_error = error;

        return kp * error + ki * integral + kd * derivative;
    }

    void reset() {
        integral = 0;
        prev_error = 0;
    }
};

double simulateOven(double temp, double power, double dt) {
    const double heating_rate = 0.1;
    const double cooling_rate = 0.02;
    temp += heating_rate * power * dt;
    temp -= cooling_rate * (temp - 25.0) * dt;
    return temp;
}

int main() {
    double time_minutes = 0;
    double setpoint = 0;

    do {
        std::cout << "Digite o tempo de controle em minutos (1 a 60): ";
        std::cin >> time_minutes;
        if (time_minutes <= 0 || time_minutes > 60) {
            std::cout << "Tempo inválido! Tente novamente.\n";
        }
    } while (time_minutes <= 0 || time_minutes > 60);


    double total_time = time_minutes * 60;

  
    do {
        std::cout << "Digite a temperatura desejada (em °C, maior que 25): ";
        std::cin >> setpoint;
        if (setpoint <= 25) {
            std::cout << "Temperatura inválida! Deve ser maior que 25°C.\n";
        }
    } while (setpoint <= 25);

    double temperature = 25.0;
    double power = 0.0;

    PID pid(2.0, 0.5, 1.0); 

    const double dt = 0.1; 
    int steps = static_cast<int>(total_time / dt);

    for (int i = 0; i < steps; ++i) {
        power = pid.update(setpoint, temperature, dt);

        if (power > 100) power = 100;
        else if (power < 0) power = 0;

        temperature = simulateOven(temperature, power, dt);

        std::cout << "Tempo: " << i * dt << "s, Temp: " << temperature << "°C, Potência: " << power << "%\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << "Simulação finalizada!\n";
    return 0;
}
