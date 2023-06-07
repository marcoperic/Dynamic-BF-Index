#include <iostream>
#include <string>
#include <sstream>

// Function to convert a hexadecimal digit to its decimal value
int hexToDecimal(char hexDigit) {
    if (hexDigit >= '0' && hexDigit <= '9') {
        return hexDigit - '0';
    }
    else if (hexDigit >= 'A' && hexDigit <= 'F') {
        return hexDigit - 'A' + 10;
    }
    else if (hexDigit >= 'a' && hexDigit <= 'f') {
        return hexDigit - 'a' + 10;
    }
    else {
        return -1; // Invalid hexadecimal digit
    }
}

// Function to convert a hex string to a decimal string
std::string hexToDecimalString(const std::string& hexString) {
    std::stringstream decimalStream;
    for (char hexDigit : hexString) {
        int decimalValue = hexToDecimal(hexDigit);
        if (decimalValue == -1) {
            std::cerr << "Invalid hexadecimal digit: " << hexDigit << std::endl;
            return "";
        }
        decimalStream << decimalValue;
    }
    return decimalStream.str();
}