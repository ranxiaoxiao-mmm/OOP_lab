#include <map>
#include <iostream>
#include <algorithm>
#include <cassert>

#include "ns_common.h"
#include "split.h"

using namespace std;

namespace EXP4 {

using VNS = std::map< std::string, unsigned int >; 
static const int REPORT_INTERVAL = 20000; // 报告进程
static VNS vns; 

void create(std::istream& in){
    string line;
    int count = 0;
    while(getline(in, line))
    {
        vector<string> parts = split(line);
        assert(parts.size() == 2);
        string hostname =parts[0];
        IPAddress ipaddress = std::stoi(parts[1]); // 字符串转整数
        if (!contain(hostname))
        {
            insert(hostname,ipaddress);
            ++count;
        }
        if (count%REPORT_INTERVAL == 0) cout << ".";
    }
    cout<<"done!\n";
}

bool contain(const HostName& hostname){
    auto it = vns.find(hostname); // 使用map的find方法查找,根据键值hostname，查找效率更高
    return it != vns.end();
}

void insert(const HostName& hostname, const IPAddress& ipaddress){
    vns.emplace(hostname, ipaddress);
}

bool remove(const HostName& hostname){
    //auto it = vns.find(hostname);
    //if (it != vns.end()) {
    //    vns.erase(it); // 删除元素
    //    return true;
    //}
    //return false;

    return vns.erase(hostname); // 使用erase直接删除键值的方法-->返回删除数量：成功删除=1，失败删除=0
}


IPAddress lookup(const HostName& hostname){
    auto it = vns.find(hostname);
    if (it != vns.end()) {
        return it->second; // 返回对应的IP地址
    }
    return NON_EXISTING_ADDRESS; // 如果没有找到，返回非现有地址
}

};