#include "screenBuffer.h"

// ������, �Ҹ���
screenBuffer::screenBuffer() { // ��ũ�� ���۸� �����ϸ鼭 ���۸� �ʱ�ȭ
	nBufferIndex = 0;
}
screenBuffer::~screenBuffer() {
}

// �Լ�
void screenBuffer::CreateBuffer() { // ��ũ�� ���� ����
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
void screenBuffer::BufferWrite(int x, int y, char *string) { // ���ۿ� ����Ϸ��� ���ڸ� ����� �д�.
    DWORD dw;
    COORD CursorPosition = { x, y };
    SetConsoleCursorPosition(hBuffer[nBufferIndex], CursorPosition);
    WriteFile(hBuffer[nBufferIndex], string, strlen(string), &dw, NULL);
}
void screenBuffer::Flipping() { // ������ ���۸� ȭ�鿡 ����� �ش�.
    SetConsoleActiveScreenBuffer(hBuffer[nBufferIndex]);
    nBufferIndex = !nBufferIndex;
}
void screenBuffer::BufferClear() { // ���۸� �����ش�.
    COORD Coor = { 0, 0 };
    DWORD dw;
    FillConsoleOutputCharacter(hBuffer[nBufferIndex], ' ', 200 * 55, Coor, &dw);
}
void screenBuffer::Release() { // ���۸� �������ش�.
    CloseHandle(hBuffer[0]);
    CloseHandle(hBuffer[1]);
}