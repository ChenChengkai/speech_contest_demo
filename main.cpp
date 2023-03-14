#include "speechManager.h"

int main()
{
    SpeechManager sm;
    for (std::map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
    {
        std::cout << "编号：" << it->first << " 姓名：" << it->second.m_Name << " 得分:" << it->second.m_Score[0] << std::endl;
    }
    // sm.showMenu();
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
