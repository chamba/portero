#!/usr/bin/env python
from BaseHTTPServer import BaseHTTPRequestHandler, HTTPServer
import urlparse

from time import sleep
import serial
#ser = serial.Serial('/dev/ttyACM0', 9600)

class S(BaseHTTPRequestHandler):
    def _set_headers(self):
        self.send_response(200)
        self.send_header('Content-type', 'text/html')
        self.end_headers()

    def do_GET(self):
        self._set_headers()
        parsed_path = urlparse.urlparse(self.path)
        if parsed_path.path == "/open":
            self.wfile.write("<html><body><h1>yes, my master</h1></body></html>")
#            ser.write('0')
        else:
            self.wfile.write("<html><body><h1>ah! ah! ah! No dijiste la palabra magica.</h1></body></html>")        
        
def run(server_class=HTTPServer, handler_class=S, port=80):
    server_address = ('127.0.0.1', port) # attached to local host as this is intendes to be internal only
    httpd = server_class(server_address, handler_class)
    print 'Starting httpd...'
    httpd.serve_forever()

if __name__ == "__main__":
    from sys import argv

    if len(argv) == 2:
        run(port=int(argv[1]))
    else:
        run()
