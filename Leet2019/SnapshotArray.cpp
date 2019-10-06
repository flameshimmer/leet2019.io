#include "stdafx.h"
//Implement a SnapshotArray that supports the following interface:
//
//SnapshotArray(int length) initializes an array-like data 
//structure with the given length.  Initially, each element equals 0.
//void set(index, val) sets the element at the given index 
//to be equal to val.
//int snap() takes a snapshot of the array and returns the 
//snap_id: the total number of times we called snap() minus 1.
//int get(index, snap_id) returns the value at the given 
//index, at the time we took the snapshot with the given snap_id
// 
//
//Example 1:
//Input: ["SnapshotArray","set","snap","set","get"]
//[[3],[0,5],[],[0,6],[0,0]]
//Output: [null,null,0,null,5]
//Explanation: 
//SnapshotArray snapshotArr = new SnapshotArray(3); // set the length to be 3
//snapshotArr.set(0,5);  // Set array[0] = 5
//snapshotArr.snap();  // Take a snapshot, return snap_id = 0
//snapshotArr.set(0,6);
//snapshotArr.get(0,0);  // Get the value of array[0] with snap_id = 0, return 5
// 
//
//Constraints:
//1 <= length <= 50000
//At most 50000 calls will be made to set, snap, and get.
//0 <= index < length
//0 <= snap_id < (the total number of times we call snap())
//0 <= val <= 10^9

namespace Solution2019
{
	namespace SnapshotArray
	{
		class SnapshotArray {
		private:
			unordered_map<int, vector<pair<int, int>>>snapshots;
			int curSnapIndex;
		public:
			SnapshotArray(int length) {
				curSnapIndex = 0;
			}

			void set(int index, int val) {
				if (snapshots[index].empty() || snapshots[index].back().first != curSnapIndex) {
					snapshots[index].push_back({ curSnapIndex, val });
				}
				else {
					snapshots[index].back().second = val;
				}
			}

			int snap() {
				curSnapIndex++;
				return curSnapIndex - 1;
			}

			int get(int index, int snap_id) {
				auto it = upper_bound(snapshots[index].begin(), snapshots[index].end(), make_pair(snap_id, INT_MAX));
				if (it == snapshots[index].begin()) { return 0; }
				else { return prev(it)->second; }
			}
		};

		/**
		 * Your SnapshotArray object will be instantiated and called as such:
		 * SnapshotArray* obj = new SnapshotArray(length);
		 * obj->set(index,val);
		 * int param_2 = obj->snap();
		 * int param_3 = obj->get(index,snap_id);
		 */
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

