#pragma once
#include <iostream>

#include <string>
#include <vector>
#include <map>
#include <deque>

#include <algorithm>
#include <numeric>

#include "speaker.h"

class SpeechManager
{
public:
    /*成员属性*/
    std::vector<int> v1;              // 保存第一轮参赛选手编号
    std::vector<int> v2;              // 第一轮晋级6位选手编号
    std::vector<int> vVictory;        // 保存胜出前三名选手编号
    std::map<int, Speaker> m_Speaker; // 存放编号以及对应选手类的容器
    // 存放比赛容器
    int m_Index;

    /*成员函数*/
    // 构造函数
    SpeechManager();
    // 显示菜单
    void showMenu();
    // 退出系统
    void exitSystem();
    // 初始化属性
    void initSpeech();
    // 创建选手
    void speechManager();
    // 开始比赛
    void startSpeech();
    // 抽签
    void speechDraw();
    // 比赛正式开始
    void speechContest();
    // 析构函数
    ~SpeechManager();
    // 清屏
    void clearWindow()
    {
        system("read a");
        system("clear");
    }
};