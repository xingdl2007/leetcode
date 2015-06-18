#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x):val(x),next(NULL){}
};

/*
 * unfortunately  _s.cc has no speedup.
 */
//#include "addtwonumbers.cc"
#include "addtwonumbers_s.cc"

void printlist(ListNode *l){
  if(l==NULL) return;
  while(l){
    cout << l->val << " -> ";
    l = l->next;
  }
  cout<<endl;
}

int main(int argc, char* argv[])
{
  ListNode *l1 = NULL, *l2 = NULL;

  l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);
  printlist(l1);

  l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);
  printlist(l2);

  printlist((new Solution())->addTwoNumbers(l2,l1));
  
  return 0;
}
