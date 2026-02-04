#include <iostream>
#include <fstream>
#include <windows.h>

int main() {
    const char* filename = "C:\\Windows\\Tasks\\donut_success.txt";
    const char* content = "Hello! Successfully ran donut shellcode in powershell.";

    std::ofstream outfile(filename);
    if (outfile.is_open()) {
        outfile << content;
        outfile.close();
        std::cout << "File written successfully.\n";
    }
    else {
        std::cerr << "Error: Could not create file.\n";
        return 1;
    }

    ShellExecuteA(NULL, "open", "notepad.exe", filename, NULL, SW_SHOWNORMAL);

    return 0;
}