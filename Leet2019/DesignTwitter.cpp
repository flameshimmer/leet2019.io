#include "stdafx.h"

//Design a simplified version of Twitter where users can post tweets,
//follow/unfollow another user and is able to see the 10 most recent tweets in
//the user's news feed. Your design should support the following methods:
//postTweet(userId, tweetId): Compose a new tweet.
//getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news
//feed. Each item in the news feed must be posted by users who the user followed
//or by the user herself. Tweets must be ordered from most recent to least
//recent.
//follow(followerId, followeeId): Follower follows a followee.
//unfollow(followerId, followeeId): Follower unfollows a followee.
//
//Example:
//Twitter twitter = new Twitter();
//// User 1 posts a new tweet (id = 5).
//twitter.postTweet(1, 5);
//// User 1's news feed should return a list with 1 tweet id -> [5].
//twitter.getNewsFeed(1);
//// User 1 follows user 2.
//twitter.follow(1, 2);
//// User 2 posts a new tweet (id = 6).
//twitter.postTweet(2, 6);
//// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
//// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
//twitter.getNewsFeed(1);
//// User 1 unfollows user 2.
//twitter.unfollow(1, 2);
//// User 1's news feed should return a list with 1 tweet id -> [5],
//// since user 1 is no longer following user 2.
//twitter.getNewsFeed(1);

namespace Solution2019
{
	namespace DesignTwitter
	{
		class Twitter {
			unordered_map<int, set<int>> followMap;
			unordered_map<int, vector<pair<int, int>>> tweets;
			int id;
		public:
			/** Initialize your data structure here. */
			Twitter() {
				id = 0;
			}

			/** Compose a new tweet. */
			void postTweet(int userId, int tweetId) {
				tweets[userId].push_back({ id, tweetId });
				id++;
			}

			/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
			vector<int> getNewsFeed(int userId) {
				set<pair<int, int>, greater<pair<int, int>>> mySet;
				vector<pair<int, int>>& userTweet = tweets[userId];
				for (int i = userTweet.size() - 1; i >= max(0, (int)(userTweet.size() - 10)); i--) {
					mySet.insert(userTweet[i]);
				}
				for (int f : followMap[userId]) {
					vector<pair<int, int>>& userTweet = tweets[f];
					for (int i = userTweet.size() - 1; i >= max(0, (int)(userTweet.size() - 10)); i--) {
						mySet.insert(userTweet[i]);
					}
				}
				vector<int> result;
				for (auto& p : mySet) {
					result.push_back(p.second);
					if (result.size() == 10) { break; }
				}
				return result;
			}

			/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
			void follow(int followerId, int followeeId) {
				followMap[followerId].insert(followeeId);
			}

			/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
			void unfollow(int followerId, int followeeId) {
				followMap[followerId].erase(followeeId);
			}
		};

		/**
		 * Your Twitter object will be instantiated and called as such:
		 * Twitter* obj = new Twitter();
		 * obj->postTweet(userId,tweetId);
		 * vector<int> param_2 = obj->getNewsFeed(userId);
		 * obj->follow(followerId,followeeId);
		 * obj->unfollow(followerId,followeeId);
		 */
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

