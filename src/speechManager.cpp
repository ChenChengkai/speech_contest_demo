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
    this->speechContest();
    // 3.显示比赛结果
    this->showScore();
    // 第二轮比赛开始
    this->m_Index++;
    // 1.抽签
    this->speechDraw();
    // 2.比赛
    this->speechContest();
    // 3.显示最终结果
    this->showScore();
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

void SpeechManager::speechContest()
{
    std::cout << "第<<" << this->m_Index << ">>轮比赛开始！" << std::endl;
    // 准备临时map,存放小组程序
    std::multimap<double, int, std::greater<double>> groupScore;
    int num = 0;            // 记录人员个数，6人一组
    std::vector<int> v_Src; // 比赛选手容器
    if (this->m_Index == 1)
    {
        v_Src = v1;
    }
    else
    {
        v_Src = v2;
    }
    // 遍历所有比赛选手
    for (std::vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
    {
        num++;
        // 评委打分
        std::deque<double> d;
        for (int i = 0; i < 10; i++)
        {
            double score = (rand() % 401 + 600) / 10.0f;
            std::cout << score << " ";
            d.push_back(score);
        }
        std::cout << std::endl;
        std::sort(d.begin(), d.end(), std::greater<double>());
        d.pop_back();
        d.pop_front();
        double avg = std::accumulate(d.begin(), d.end(), 0.0) / d.size();
        this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;
        // 将打分数据，放到临时小组中
        groupScore.insert(std::make_pair(avg, *it)); // key is avg score,value is No.
        // 每组取出前三名
        if (num % 6 == 0)
        {
            std::cout << "第" << num / 6 << "小组成绩如下：" << std::endl;
            for (std::multimap<double, int, std::greater<double>>::iterator mit = groupScore.begin(); mit != groupScore.end(); mit++)
            {
                std::cout << "编号：" << mit->second << " 姓名：" << this->m_Speaker[mit->second].m_Name << " 得分：" << this->m_Speaker[mit->second].m_Score[this->m_Index - 1] << std::endl;
            }
            // 取走前三名
            int count = 0;
            for (std::multimap<double, int, std::greater<double>>::iterator mit = groupScore.begin(); mit != groupScore.end() && count < 3; mit++, count++)
            {
                if (this->m_Index == 1)
                {
                    v2.push_back(mit->second);
                }
                else
                {
                    vVictory.push_back(mit->second);
                }
            }
            groupScore.clear();
        }
    }
    std::cout << "第<<" << this->m_Index << ">>轮比赛结束！" << std::endl;
    this->clearWindow();
}

void SpeechManager::showScore()
{
    std::cout << "第<<" << this->m_Index << ">>轮晋级选手如下：" << std::endl;
    std::vector<int> v;
    if (this->m_Index == 1)
    {
        v = this->v2;
    }
    else
    {
        v = this->vVictory;
    }
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        std::cout << "选手编号：" << *it << " 姓名：" << this->m_Speaker[*it].m_Name << " 得分：" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << std::endl;
    }
    this->clearWindow();
    this->showMenu();
}