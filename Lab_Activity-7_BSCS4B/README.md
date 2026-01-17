This activity shows how an Arduino can be controlled remotely using Python and a web interface. The Arduino manages three LEDs—red, green, and blue—and listens for commands sent from Python over the serial port. Each command can toggle an individual LED or turn all of them on or off. The program keeps track of each LED’s state, making control reliable and easy to follow.

On the Python side, FastAPI provides simple web endpoints. By visiting these endpoints, a user can turn LEDs on or off or toggle specific colors. Python then sends the corresponding command to the Arduino, which executes the action in real time.

This setup demonstrates how hardware and software can work together, combining embedded systems, Python programming, and web-based control. It’s a practical example of real-time hardware control and a simple IoT application.
