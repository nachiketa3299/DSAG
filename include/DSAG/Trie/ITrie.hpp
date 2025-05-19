#pragma once

#include <string>

namespace dsag {

class ITrie {
  virtual ~ITrie() = 0;
  virtual void Insert(const std::string& word) = 0;
  virtual bool Search(const std::string& word) const = 0;
  virtual bool StartsWith(const std::string& word) const = 0;
  virtual void PrintAll() const = 0;
  virtual void PrintAllInTree(char delim='-') const = 0;
};

}