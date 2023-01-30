#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);

int main() {

    vector<int> v1 = { 1,2,3,0,0,0 };
    vector<int> v2 = { 2,5,6 };

    merge(v1,3,v2, 3);
    //cout << insert(v, 2);

	return 0;
}
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    vector<int> v;
    int x = m + n;
    for (int i = 0; i < x; i++) {

        if (m > 0 && n > 0) {
            if (nums1.front() > nums2.front()) {
                v.push_back(nums2.front());
                nums2.erase(nums2.begin());
                n--;
            }
            else {
                v.push_back(nums1.front());
                nums1.erase(nums1.begin());
                m--;
            }
        }
        else {
            if (m) {
                v.push_back(nums1.front());
                nums1.erase(nums1.begin());
                m--;
            }
            else {
                v.push_back(nums2.front());
                nums2.erase(nums2.begin());
                n--;
            }
        }

    }

    nums1 = v;

}