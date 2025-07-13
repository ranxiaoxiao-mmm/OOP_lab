#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

#include "ns_common.h"
#include "split.h"

using namespace std;

namespace EXP4 {

using VNS = std::vector< std::pair<std::string, int> >;
static const int REPORT_INTERVAL = 20000; // 报告进程
static VNS vns; 

void create(std::istream& in)
{
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
    auto it = std::find_if(vns.begin(), vns.end(), [&](const auto& pair) {
        return pair.first == hostname;
    });
    return it != vns.end();
}

void insert(const HostName& hostname, const IPAddress& ipaddress){
    vns.emplace_back(hostname, ipaddress);
}

bool remove(const HostName& hostname){
    auto it = std::find_if(vns.begin(), vns.end(), [&](const auto& pair) {
        return pair.first == hostname;
    });
    if (it != vns.end()) {
        vns.erase(it); // 删除元素
        return true;
    }
    return false;
}

IPAddress lookup(const HostName& hostname){
    auto it = std::find_if(vns.begin(), vns.end(), [&](const auto& pair) {
        return pair.first == hostname;
    });
    if (it != vns.end()) {
        return it->second; //（*it).second;
    }
    return NON_EXISTING_ADDRESS;
}

};