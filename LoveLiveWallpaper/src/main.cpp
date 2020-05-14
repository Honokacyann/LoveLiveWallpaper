#include "Application.h"

using namespace LLWP;

DWORD RenderThreadProc(LPVOID wnd);
void StartApplication(void* wnd);

HANDLE hApplication;
DWORD appThreadID;

int WINAPI wWinMain(
    _In_ HINSTANCE hInst,
    _In_opt_ HINSTANCE,
    _In_ LPWSTR pArgs,
    _In_ int)
{
    // ��ʼ��
    Application app(hInst, pArgs);

    // ����һ���߳���������Ⱦ
    StartApplication(&app);

    // ��Ϣѭ��
    while (app.wnd.ProcessMessage()) {}

    // �ȴ���Ⱦ�߳��˳�
    WaitForSingleObject(hApplication, 5000);

    return 0;
}

void StartApplication(void* app)
{
    SECURITY_ATTRIBUTES sa{ 0 };
    sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    sa.lpSecurityDescriptor = nullptr;
    sa.bInheritHandle = FALSE;
    hApplication = CreateThread(&sa, 0, RenderThreadProc, app, 0, &appThreadID);

    // Ϊ�˷�����ԣ���ʱ����������¼�
    ((Application*)app)->wnd.CaptureMouse();
}

DWORD RenderThreadProc(LPVOID app)
{
    ((Application*)app)->Run();
    return 0;
}