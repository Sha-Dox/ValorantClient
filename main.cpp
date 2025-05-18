#include <iostream>
#include <stdio.h>
#include <string>
#include <Windows.h>
#include <TlHelp32.h>
#include <conio.h>
#include "curl/curl.h"
#include "uuid/uuid.h"


using namespace std;

bool birdefaazdimmi = false;

bool isValorantRunning() {
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE) {
        return false;
    }

    PROCESSENTRY32 processEntry;
    processEntry.dwSize = sizeof(processEntry);


    if (!Process32First(snapshot, &processEntry)) {
        CloseHandle(snapshot);
        return false;
    }

    do {
        if (strcmp(processEntry.szExeFile, "VALORANT.exe") == 0) {
            CloseHandle(snapshot);
            return true;
        }
    } while (Process32Next(snapshot, &processEntry));

    CloseHandle(snapshot);
    return false;
}


void programkapa(string program) {
    if (isValorantRunning()) {
        system(("taskkill /F /IM " + program + ".exe >nul 2>&1").c_str());
        cout << "Valorant has been succesfully closed";
        birdefaazdimmi = false;
    } else if (!birdefaazdimmi) {
        cout << "Please open Valorant";
        birdefaazdimmi = true;
    }
}


int main() {

    for (int i = 0; i < 2160; i++) {
        programkapa("VALORANT");
        Sleep(5000);
    }




}


