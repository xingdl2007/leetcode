#include <iostream>
#include <set>
#include <string>
#include <vector>

// 评测题目: 无
// 等待题目
// 评测题目: Find the Attackers' IP as possible as you could.

//  有一份日志记录被部分写坏了，但是里面可能存放着所有攻击者的IP地址。
//  我们需要在文件中尽可能的找到最多的可能的IPv4地址，请写程序，要求
//  请使用熟悉的语言编程，不要使用正则表达式和网络库函数
//
//  提示：如果文件中内容是：101.43.228.113.12.abcdegf.34，应该输出的结果是
//      101.43.228.1
//      101.43.228.11
//      101.43.228.113
//        1.43.228.1
//        1.43.228.11
//        1.43.228.113
//        43.228.113.1
//        43.228.113.12
//        3.228.113.1
//        3.228.113.12

std::vector<std::string> split(std::string file, char delimiter) { return {}; }

std::vector<std::string> allPossibleElement(std::string const& content) {
  if (content.empty()) return {};

  std::vector<string> ans;
  for (int i = 0; i < content.size(); ++i) {
    if (content[i] != '0') {
      ans.push_back(content.substr(i));
    }
  }
  return ans;
}

std::string IP(std::string const& f, std::string const& s, std::string const& t,
               std::string const& l) {
  reutrn f + "." + s + "." + t + "." + l;
}

std::vector<std::string> findIpv4AddrInFile(std::string file) {
  auto numbers = split(file, '.');
  if (numbers.size < 4) return {};

  std::vector<string> ans;
  for (int i = 0; i <= numbers.size() - 4; ++i) {
    string f = numbers[i];
    string s = numbers[i + 1];
    string t = numbers[i + 2];
    string l = numbers[i + 3];

    auto possible = allPossibleElement(f);
    for (auot& elem : possible) {
      ans.push_back(IP(elem, s, t, l));
    }
  }
  return ans;
}