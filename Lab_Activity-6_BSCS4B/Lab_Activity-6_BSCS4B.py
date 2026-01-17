import time

import serial

COM_PORT = "COM7"          # Change to your Arduino COM port
BAUD_RATE = 9600
STARTUP_DELAY = 1         # Seconds to wait for Arduino reset

# Button-to-command mapping
BUTTON_COMMANDS = {
    "r": b"1",
    "g": b"2",
    "b": b"3"
}

def main():
    try:
        with serial.Serial(COM_PORT, BAUD_RATE, timeout=1) as arduino:
            time.sleep(STARTUP_DELAY)

            print("Listening for button presses...\n")

            while True:
                handle_serial_input(arduino)
                time.sleep(0.01)  # Prevent CPU overuse

    except serial.SerialException as err:
        print(f"[ERROR] Serial connection failed: {err}")

    except KeyboardInterrupt:
        print("\n[INFO] Program terminated by user.")

    except Exception as err:
        print(f"[ERROR] Unexpected error: {err}")


def handle_serial_input(arduino):
    """Read and process incoming serial data from Arduino."""
    if arduino.in_waiting == 0:
        return

    message = arduino.readline().decode(errors="ignore").strip().lower()

    if message in BUTTON_COMMANDS:
        command = BUTTON_COMMANDS[message]

        print(f"[RECEIVED] Button: {message.upper()}")
        arduino.write(command)
        arduino.flush()
        print(f"[SENT]     Command: {command.decode()}\n")


if __name__ == "__main__":
    main()
