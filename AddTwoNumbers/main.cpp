#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Hello, World!" << endl;


    return 0;
}



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        ListNode* tmp = res;
        bool carry = false;
        while(l1!=nullptr || l2 != nullptr || carry) {

            int suma = 0;
            if(l1 != nullptr){suma += l1->val; l1 = l1->next;}
            if(l2 != nullptr){suma += l2->val; l2 = l2->next;}
            suma += carry;
            carry = false;
            if(suma>=10) {
                carry = true;
                suma %= 10;
            }
            tmp->val = suma;
            if(l1!= nullptr || l2 != nullptr || carry) {
                tmp->next = new ListNode();
                tmp = tmp->next;
            }
        }
        tmp->next = nullptr;
        return res;
    }
};
