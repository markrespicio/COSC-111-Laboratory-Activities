import serial
import time
import os

COM_PORT = 'COM3'  # Change to your Arduino COM port
BAUD_RATE = 9600

try:
    with serial.Serial(COM_PORT, BAUD_RATE, timeout=1) as ard:
        time.sleep(2)  # Allow Arduino to initialize

        while True:
            # Display menu
            print("[R] Red ON/OFF")
            print("[G] Green ON/OFF")
            print("[B] Blue ON/OFF")
            print("[A] All ON")
            print("[O] All OFF")
            print("[X] Exit\n")

            cmd = input("Enter choice: ").lower()

            if cmd in ['r', 'g', 'b', 'a', 'o', 'x']:
                ard.write(cmd.encode())  # Send byte to Arduino
                ard.flush()  # Ensure command is sent immediately
                print(f"Sent command: {cmd}")
                time.sleep(0.05)  # Short delay for stability
                if cmd == 'x':
                print("Exiting program...")
                break
                
            else:
                print("Invalid choice")
                time.sleep(1)

            os.system('cls' if os.name == 'nt' else 'clear')  # Clear menu for next input

except serial.SerialException as e:
    print(f"Serial exception: {e}")
except Exception as ex:
    print(f"Unexpected error: {ex}")
