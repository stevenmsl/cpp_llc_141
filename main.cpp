#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol141;

/*
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the second node.
*/

tuple<Node *, bool>
testFixture1()
{

  auto l = new Node(3);
  l->next = new Node(2);
  l->next->next = new Node(0);
  l->next->next->next = new Node(-4);
  l->next->next->next->next = l->next;

  return make_tuple(l, true);
}

void test1()
{
  auto f = testFixture1();
  Solution sol;

  cout << "Expect to see : " << get<1>(f) << endl;

  cout << sol.hasCycle(get<0>(f)) << endl;
}

main()
{
  test1();

  return 0;
}