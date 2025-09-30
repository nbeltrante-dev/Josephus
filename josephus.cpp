////////////////////////////////////////////////////////////////////////////////
// Name: Nicoletta Beltrante
// Date: September 24, 2025
// Assignment: CSCI 362: The Josephus Problem
// Description: Simulate the Josephus problem using std::list within the C++ Standard Library.
//
////////////////////////////////////////////////////////////////////////////////

#include <list>
#include <iterator>
#include "Josephus.h"

/* Simulate the Josephus problem modeled as a std::list.
 * This function will modify the passed list with only a
 * single survivor remaining.
 *
 * @param circle -- the linked list of people
 * @param k -- skip amount. NOTE: k > 0
 *
 * @return a list of those who are executed in chronological order
 */
template <typename T>
std::list<T>
execute (std::list<T>& circle, int k)
{
  std::list<T> killed;
  typename std::list<T>::iterator it1, it2;
  it1 = circle.begin();
  it2 = circle.end();
  while(circle.size() > 1){
    for(int i = 1; i < k; i++){
      ++it1;
      if(it1 == it2){
        it1 = circle.begin();
      }
  }
    killed.push_back(*it1);
    it1 = circle.erase(it1);
    if(it1 == it2){
        it1 = circle.begin();
      }
  }
  
  return killed;
}

/* entry point to the Josephus problem from the autograder / main
 *
 * @param n -- number of people in the circle
 * @param k -- skip amount. NOTE: k > 0
 */
int
josephus (int n, int k)
{
  std::list<int> participants;
  for(int i = 1; i <= n; i++){
    participants.push_back(i);
  }
  execute(participants, k);
  return participants.front();
}
