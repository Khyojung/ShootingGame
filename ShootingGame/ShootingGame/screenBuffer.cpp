#include "screenBuffer.h"

// 생성자, 소멸자
screenBuffer::screenBuffer() { // 스크린 버퍼를 생성하면서 버퍼를 초기화
	nBufferIndex = 0;
}
screenBuffer::~screenBuffer() {
}

// 함수
void screenBuffer::CreateBuffer() { // 스크린 버퍼 생성
    CONSOLE_CURSOR_INFO cci;
    COORD size = { 200, 55 };
    SMALL_RECT rect;

    rect.Left = 0;
    rect.Right = 200 - 1;
    rect.Top = 0;
    rect.Bottom = 55 - 1;

    hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleScreenBufferSize(hBuffer[0], size);
    SetConsoleWindowInfo(hBuffer[0], TRUE, &rect);
    hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleScreenBufferSize(hBuffer[1], size);
    SetConsoleWindowInfo(hBuffer[1], TRUE, &rect);

    cci.dwSize = 1;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hBuffer[0], &cci);
    SetConsoleCursorInfo(hBuffer[1], &cci);
}
void screenBuffer::BufferWrite(int x, int y, char *string) { // 버퍼에 출력하려는 문자를 적어놔 둔다.
    DWORD dw;
    COORD CursorPosition = { x, y };
    SetConsoleCursorPosition(hBuffer[nBufferIndex], CursorPosition);
    WriteFile(hBuffer[nBufferIndex], string, strlen(string), &dw, NULL);
}
void screenBuffer::Flipping() { // 생성된 버퍼를 화면에 출력해 준다.
    SetConsoleActiveScreenBuffer(hBuffer[nBufferIndex]);
    nBufferIndex = !nBufferIndex;
}
void screenBuffer::BufferClear() { // 버퍼를 지워준다.
    COORD Coor = { 0, 0 };
    DWORD dw;
    FillConsoleOutputCharacter(hBuffer[nBufferIndex], ' ', 200 * 55, Coor, &dw);
}
void screenBuffer::Release() { // 버퍼를 제거해준다.
    CloseHandle(hBuffer[0]);
    CloseHandle(hBuffer[1]);
}