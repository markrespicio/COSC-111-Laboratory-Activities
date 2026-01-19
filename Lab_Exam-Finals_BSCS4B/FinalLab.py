import threading

import requests
import serial
import time

import fastapi
app = fastapi.FastAPI()

# --- Connect to Arduino ---
arduino = serial.Serial("COM3", 9600, timeout=1)
time.sleep(2)  # wait for Arduino to be ready



# --- Function to call API ---
def call_api(number):
    try:
    
        response = requests.get(f"http://172.20.10.3:8000/led/group/{number}/toggle")
        print("Endpoint Called")
        if response.status_code == 200:
            print("[SUCCESS] Status Code:", response.text)
        else:
            print("[ERROR] Status Code:", response.text)
    except Exception as error:
        print("Failed to call API :", error)

# --- Listen to button presses ---
def listen_button():
    while True:
        line = arduino.readline().decode().strip()

        if line == "1":
            print("Group Number Received")
            call_api(line)


# --- Run listener in background ---
threading.Thread(target=listen_button, daemon=True).start()

