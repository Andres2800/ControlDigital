# Proyectos de Arduino con PlatformIO

Este repositorio contiene dos proyectos de Arduino creados utilizando la plataforma PlatformIO. Cada proyecto aborda una problemática específica y ofrece una solución mediante programación en Arduino.

## Proyectos

### 1. Control de Secuencia de Leds

Este proyecto controla una secuencia de cuatro LEDs utilizando cuatro pulsadores:
- Dos pulsadores controlan el sentido de la secuencia (hacia adelante o hacia atrás).
- Los otros dos pulsadores controlan la velocidad de encendido de los LEDs.

#### Características:
- Control de secuencia de LEDs.
- Control de dirección (adelante y atrás).
- Control de velocidad de la secuencia.

### 2. Mecanismo Anti Rebotes

Este proyecto implementa un mecanismo anti rebotes mediante software, utilizando la arquitectura de máquinas de estados finitos (FSM, por sus siglas en inglés).

#### Características:
- Eliminación de rebotes en los pulsadores.
- Implementación de una máquina de estados finitos para el control del debounce.

## Requisitos

Para ejecutar estos proyectos, necesitarás:
- [PlatformIO](https://platformio.org/) instalado en tu sistema.
- Un microcontrolador compatible con Arduino.

