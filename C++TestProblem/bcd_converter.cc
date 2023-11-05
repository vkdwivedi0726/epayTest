#include "bcd_converter.h"

#include <iostream>
#include <iomanip>

#define NIBBLE_SHIFT 4
#define DECIMAL_BASE 10

unsigned int convert_int_to_bcd(unsigned char* destination_buffer,
                                unsigned int buffer_length, 
                                unsigned int value) {
    unsigned int num_of_digits = 0;
    unsigned int temp_val = value;

    while(temp_val > 0) {
        temp_val /= DECIMAL_BASE;
        ++num_of_digits;
    }

    //rval = used buffer length
    unsigned int rval = (num_of_digits + 1) / 2;
    if(buffer_length < rval) {
        return 0;
    }

    for(unsigned int i = 0; i < buffer_length; i++) {
        destination_buffer[i] = 0;
    }

    for(int i = rval - 1; i >= 0 && value > 0; i--) {
        destination_buffer[i] = value % DECIMAL_BASE;
        value /= DECIMAL_BASE;
        if(value > 0) {
            destination_buffer[i] |= (value % DECIMAL_BASE) << NIBBLE_SHIFT;
            value /= DECIMAL_BASE;
        }
    }

    return rval;

}

//Test Program
int main() {
    unsigned int input = 9873432;
    unsigned int buffer_length = 4;
    unsigned char dest_buffer[4];
    unsigned int res = convert_int_to_bcd(dest_buffer, buffer_length, input);
    for (unsigned int i = 0; i < res; i++) {
            std::cout << "0x" << std::setfill('0') << std::setw(2) << std::hex 
                << static_cast<int>(dest_buffer[i]) << " ";
    }

    std::cout << std::endl;
}