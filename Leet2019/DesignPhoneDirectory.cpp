#include "stdafx.h"
//Design a Phone Directory which supports the following operations:
//
//get: Provide a number which is not assigned to anyone.
//check: Check if a number is available or not.
//release: Recycle or release a number.
//Example:
//
//// Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
//PhoneDirectory directory = new PhoneDirectory(3);
//
//// It can return any available phone number. Here we assume it returns 0.
//directory.get();
//
//// Assume it returns 1.
//directory.get();
//
//// The number 2 is available, so return true.
//directory.check(2);
//
//// It returns 2, the only number that is left.
//directory.get();
//
//// The number 2 is no longer available, so return false.
//directory.check(2);
//
//// Release number 2 back to the pool.
//directory.release(2);
//
//// Number 2 is available again, return true.
//directory.check(2); 

namespace Solution2019
{
	namespace DesignPhoneDirectory
	{
		class PhoneDirectoryTooSlow {
			map<int, bool> book;
			PhoneDirectoryTooSlow(int maxNumbers) {
				for (int i = 0; i < maxNumbers; i++) {
					book.emplace(i, true);
				}
			}

			/** Provide a number which is not assigned to anyone.
				@return - Return an available number. Return -1 if none is available. */
			int get() {
				for (auto it = book.begin(); it != book.end(); it++) {
					if (it->second) { it->second = false; return it->first; }
				}
				return -1;
			}

			/** Check if a number is available or not. */
			bool check(int number) {
				return book[number];
			}

			/** Recycle or release a number. */
			void release(int number) {
				book[number] = true;
			}
		};

		class PhoneDirectoryStillTooSlow {
		public:
			/** Initialize your data structure here
				@param maxNumbers - The maximum numbers that can be stored in the phone directory. */  
			  bool* book;
			  int size;
			  
			  PhoneDirectoryStillTooSlow(int maxNumbers) {
				  size = maxNumbers;
				  book = new bool[maxNumbers];
				  memset(book, true, sizeof(bool)*size);
			  }

			  /** Provide a number which is not assigned to anyone.
				  @return - Return an available number. Return -1 if none is available. */
			  int get() {
				  for (int i = 0; i < size; i++) {
					  if (book[i]) {
						  book[i] = false;
						  return i;
					  }
				  }
				  return -1;
			  }

			  /** Check if a number is available or not. */
			  bool check(int number) {
				  return book[number];
			  }

			  /** Recycle or release a number. */
			  void release(int number) {
				  book[number] = true;
			  }
		};

		class PhoneDirectoryCanBeFaster {
		public:
			struct ListNode {
				int val;
				ListNode* next;
				ListNode(int x) { val = x; next = nullptr; }
			};
			ListNode* head = nullptr;
			ListNode* tail = nullptr;
			/** Initialize your data structure here
				@param maxNumbers - The maximum numbers that can be stored in the phone directory. */
			PhoneDirectoryCanBeFaster(int maxNumbers) {
				for (int i = 0; i < maxNumbers; i++) {
					ListNode* cur = new ListNode(i);
					if (!head) { head = cur; }
					else { tail->next = cur; }
					tail = cur;
				}
			}

			/** Provide a number which is not assigned to anyone.
				@return - Return an available number. Return -1 if none is available. */
			int get() {
				if (!head) { return -1; }
				ListNode* tmp = head;
				head = head->next;
				int result = tmp->val;
				delete tmp;
				if (!head) { tail = nullptr; }
				return result;
			}

			/** Check if a number is available or not. */
			bool check(int number) {
				ListNode* cur = head;//-----------------------> Note that don't operate on head pointer directly!!!
				while (cur) {
					if (cur->val == number) { return true; }
					cur = cur->next;
				}
				return false;
			}

			/** Recycle or release a number. */
			void release(int number) {
				if (check(number)) { return; } ///-----------------------> Note that to check this first!
				ListNode* newNode = new ListNode(number);
				if (!head) { head = newNode; }
				else { tail->next = newNode; }
				tail = newNode;
			}
		};

		class PhoneDirectory {
		public:
			/** Initialize your data structure here
				@param maxNumbers - The maximum numbers that can be stored in the phone directory. */
			struct ListNode {
				int val;
				ListNode* next;
				ListNode(int x) { val = x; next = nullptr; }
			};

			unordered_set<int> book;
			ListNode* head = nullptr;
			ListNode* tail = nullptr;
			PhoneDirectory(int maxNumbers) {
				for (int i = 0; i < maxNumbers; i++) {
					ListNode* cur = new ListNode(i);
					if (!head) { head = cur; }
					else { tail->next = cur; }
					tail = cur;
					book.insert(i);
				}

			}

			/** Provide a number which is not assigned to anyone.
				@return - Return an available number. Return -1 if none is available. */
			int get() {
				if (!head) { return -1; }
				int result = head->val;
				ListNode* tmp = head;
				head = head->next;
				if (!head) { tail = nullptr; }
				delete tmp;
				book.erase(result);
				return result;
			}

			/** Check if a number is available or not. */
			bool check(int number) {
				return (book.find(number) != book.end());
			}

			/** Recycle or release a number. */
			void release(int number) {
				if (book.find(number) != book.end()) { return; }
				ListNode* newNode = new ListNode(number);
				if (!head) { head = newNode; }
				else { tail->next = newNode; }
				tail = newNode;
				book.insert(number);
			}
		};
		void Main() {
			
			PhoneDirectory* obj = new PhoneDirectory(2);
			print(obj->get());
			print(obj->get());
			print(obj->check(0));
			print(obj->check(1));			
		}
	}
}
