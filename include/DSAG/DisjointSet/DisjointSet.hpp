#pragma once

#include <vector>

namespace DSAG {

/*!
 * @brief 서로소(Disjoint, 서로 겹치지 않는) 집합을 표현하는 Union-Find 자료구조
 */
class DisjointSet {
public:
  /*!
   * @brief 주어진 크기로 DisjointSet을 초기화. 처음에는 모든 요소가 자기 자신이 루트로 초기화된다.
   */
  DisjointSet(std::size_t size);

  /*!
   * @brief 해당 원소가 속한 집합의 루트를 찾는다.
   */
  std::size_t Find(std::size_t i);

  /*!
   * @brief 두 원소가 같은 집합에 속해 있는지 확인한다.
   */
  bool IsSameSet(std::size_t l, std::size_t r);

  /*!
   * @brief 두 원소가 속한 집합을 합친다.
   */
  void UniteSets(std::size_t l, std::size_t r);

private:
  std::vector<std::size_t> parent_;
};

}
