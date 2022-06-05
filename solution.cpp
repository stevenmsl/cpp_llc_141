#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <functional>
using namespace sol141;
using namespace std;

/*takeaways
  - if you use a hash table to store which node has appeared
    that the space complexity is O(n)
  - to achieve the space complexity O(1), we use two pointers
    - one moves twice faster as the other
    - if they are both circling around the cycle than we assume
      eventually the fast pointer will catch up the slow one
*/

bool Solution::hasCycle(Node *head)
{
  auto slow = head;
  auto fast = head;

  while (fast != nullptr)
  {
    if (fast->next == nullptr)
      return false;

    /* twice as fast as the slow */
    fast = fast->next->next;
    slow = slow->next;

    /* if there is a cycle, in theory
       fast will hit slow at some point
       while circling a cycle
    */
    if (fast == slow)
      return true;
  }

  /* you do have a tail if the code reaches here */
  return false;
}