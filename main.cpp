#include "speechManager.h"

int main()
{
    SpeechManager sm;
    int select = 0;
    while (true)
    {
        sm.showMenu();
        std::cout << "请选择一项：" << std::endl;
        std::cin >> select;
        switch (select)
        {
        case 1:
            sm.startSpeech();
            break;
        case 2:
            sm.showRecord();
            break;
        case 3:
            sm.clearRecord();
            break;
        case 0:
            sm.exitSystem();
            break;
        default:
            break;
        }
    }
    return 0;
}
