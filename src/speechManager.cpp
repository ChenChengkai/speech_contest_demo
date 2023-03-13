#include "speechManager.h"

// 构造函数
SpeechManager::SpeechManager()
{
    // 初始化容器
    this->initSpeech();
    // 创建选手
    this->speechManager();
}

// 析构函数
SpeechManager::~SpeechManager()
{
}

void SpeechManager::showMenu()
{
    std::cout << "**********************" << std::endl;
    std::cout << "***欢迎参加演讲比赛***" << std::endl;
    std::cout << "****1.开始演讲比赛****" << std::endl;
    std::cout << "****2.查看往届记录****" << std::endl;
    std::cout << "****3.清空比赛记录****" << std::endl;
    std::cout << "****0.退出比赛程序****" << std::endl;
    std::cout << "**********************" << std::endl;
    std::cout << std::endl;
}

void SpeechManager::exitSystem()
{
    std::cout << "欢迎下次再使用！" << std::endl;
    exit(0);
}

void SpeechManager::initSpeech()
{
    // 容器全部置空
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_Speaker.clear();
    // 初始化比赛轮数
    this->m_Index = 1;
}

void SpeechManager::speechManager()
{
    std::string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); i++)
    {
        // 创建：姓名、得分、编号！
        Speaker sp;
        sp.m_Name = std::string("选手") + nameSeed[i];
        for (int j = 0; j < 2; j++)
        {
            sp.m_Score[j] = 0.0;
        }
        this->v1.push_back(i + 10001);
        this->m_Speaker.insert(std::make_pair(i + 10001, sp));
    }
}

void SpeechManager::startSpeech()
{
    // 第一轮比赛开始

    // 1.抽签
    this->speechDraw();
    // 2.比赛

    // 3.显示比赛结果

    // 第二轮比赛开始

    // 1.抽签

    // 2.比赛

    // 3.显示最终结果

    // 保存结果
}
void SpeechManager::speechDraw()
{
    std::cout << "第<<" << this->m_Index << ">>轮比赛选手正在抽签" << std::endl;
    std::cout << "---------------" << std::endl;
    std::cout << "抽签后的顺序如下：" << std::endl;
    if (this->m_Index == 1)
    {
        std::random_shuffle(this->v1.begin(), this->v1.end());
        for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    else // 第二轮
    {
        std::random_shuffle(this->v2.begin(), this->v2.end());
        for (std::vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "---------------" << std::endl;
    this->clearWindow();
}