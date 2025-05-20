#pragma once

#include <string>

namespace DSAG {

/*!
 * @brief Trie 인터페이스
 */
class ITrie {
public:
  /*!
   * @brief 문자열을 Trie에 삽입
   */
  virtual void Insert(const std::string& word) = 0;

  /*!
   * @brief 문자열이 Trie에 정확히 존재하는지 검사
   */
  virtual bool Search(const std::string& word) const = 0;

  /*!
   * @brief 주어진 접두사로 시작하는 단어가 Trie에 존재하는지 검사
   */
  virtual bool StartsWith(const std::string& prefix) const  = 0;

public:
  /*!
   * @brief Trie에 저장된 모든 단어를 출력
   * @note 출력 순서는 구현체에 따라 상이
   */
  virtual void Print() const = 0;

  /*!
   * @brief Trie에 저장된 모든 단어를 계층 구조로 출력
   * @param[in] delim 계층 구조를 구분할 구분자
   */
  virtual void PrintTree(char delim) const = 0;
};

}