# Exp 5: Automation (Cron Relay) & LAN Web Interface for Remote Bulb Status
# Crontab example to turn relay ON daily at 06:30:
# 30 6 * * * /usr/bin/python3 /home/pi/relay_on.py
from http.server import BaseHTTPRequestHandler, HTTPServer

BULB_STATE = {"on": False}

class BulbHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        if self.path == "/toggle":
            BULB_STATE["on"] = not BULB_STATE["on"]
        status = "ON" if BULB_STATE["on"] else "OFF"
        html = f"<h1>LAN Smart Bulb</h1><p>Status: <b>{status}</b></p><a href='/toggle'>Toggle Bulb</a>"
        self.send_response(200)
        self.send_header("Content-Type", "text/html")
        self.end_headers()
        self.wfile.write(html.encode())

if __name__ == "__main__":
    print("Run server on http://0.0.0.0:8000 (Ctrl+C to stop)")
    # HTTPServer(("0.0.0.0", 8000), BulbHandler).serve_forever()
