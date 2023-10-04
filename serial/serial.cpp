#include <iostream>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

int main() {
    const char* portName = "/dev/ttyUSB0";
    int serialPort = open(portName, O_RDWR);

    if (serialPort == -1) {
        std::cerr << "Error opening the serial port." << std::endl;
        return 1;
    }

    struct termios tty;
    tcgetattr(serialPort, &tty);
    cfsetospeed(&tty, B115200);  // Set the baud rate to 115200
    cfsetispeed(&tty, B115200);

    tty.c_cflag |= (CLOCAL | CREAD);  // Enable reading and ignore modem control lines
    tty.c_cflag &= ~PARENB;           // Disable parity bit
    tty.c_cflag &= ~CSTOPB;           // Use one stop bit
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;               // 8 data bits

    tcsetattr(serialPort, TCSANOW, &tty);
    
    // Read data from the serial port here

    char buffer;
    while(1){
        ssize_t bytesRead = read(serialPort, &buffer, 1);

        if (bytesRead == -1) {
            std::cerr << "Error reading from the serial port." << std::endl;
            return 1;
        }

        if (bytesRead > 0) {
            std::cout << "Read " << bytesRead << " bytes: " << buffer << std::endl;
        }
    }
    
    close(serialPort);
    
    return 0;
}
