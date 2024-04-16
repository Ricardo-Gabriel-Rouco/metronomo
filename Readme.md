# Metronomo

## Descripción

Este repositorio contiene el código fuente para un proyecto de Arduino que simplemente es un metronomo realizado en una protoboard con el fin de practicar el uso de un shift register y poder emitir datos al usuario y mostrarlos al mismo.

## Contenido del Repositorio

- `metronomo.ino`: Archivo principal que contiene el código de Arduino.
- `README.md`: Este archivo que proporciona información sobre el proyecto.

## Requisitos

Para cargar y ejecutar el código en tu placa Arduino, necesitarás lo siguiente:

- Una placa Arduino compatible.
- El IDE de Arduino instalado en tu computadora.
- La libreria LiquidCrystal_I2C con el fin de controlar la pantalla lcd.

## Materiales

| Cantidad | Componente                                     |
|----------|------------------------------------------------|
| 1        | Arduino Uno R3                                 |
| 3        | Pulsador                                       |
| 1        | LCD 16 x 2 (I2C)*  |
| 3        | Resistencia de 10 kΩ                           |
| 1        | Buzzer pasivo                                  |
| 1        | Shift register 74HC595N                        |
| 3        | LED Rojo*                                      |
| 3        | LED Amarillo*                                  |
| 2        | LED Verde*                                     |
| 8        | Resistencia de 220 Ω                           |

Componentes opcionales:

- LED Rojo, LED Amarillo, LED Verde: Se pueden usar de cualquier color, utilize estos ya que me venian en el kit.
- LCD 16 x 2 (I2C): use con adapdator I2C ya que estos utilizan solo 4 cables en vez de 16 como los que no tienen este adaptador.

## Instrucciones de Uso

1. Abre el archivo `metronomo.ino` en el IDE de Arduino.
2. Recorda descargar la libreria LiquidCrystal_I2C desde el gestor del arduino IDE.
3. Conecta tu placa Arduino a tu computadora mediante un cable USB.
4. Selecciona el tipo de placa y el puerto serie correctos en el IDE de Arduino.
5. Haz clic en el botón "Cargar" para compilar y cargar el código en la placa Arduino.

## Circuito

<img src="./Brave Jaban-Robo.png" alt="Texto alternativo" width="700" height="300">

## Contribuciones

Si deseas contribuir a este proyecto, siéntete libre de hacerlo. Puedes enviar solicitudes de extracción (pull requests) para proponer cambios o mejoras.

## Problemas

Si encuentras algún problema o tienes alguna pregunta sobre este proyecto, por favor, abre un nuevo issue en este repositorio.
