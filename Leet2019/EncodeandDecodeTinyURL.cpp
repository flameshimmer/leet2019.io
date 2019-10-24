#include "stdafx.h"

//Note: This is a companion problem to the System Design problem: Design TinyURL.
//TinyURL is a URL shortening service where you enter a URL such as 
//https://leetcode.com/problems/design-tinyurl and it returns a short URL
//such as http://tinyurl.com/4e9iAk.
//
//Design the encode and decode methods for the TinyURL service. There is no 
//restriction on how your encode/decode algorithm should work. You just need 
//to ensure that a URL can be encoded to a tiny URL and the tiny URL can be 
//decoded to the original URL.

namespace Solution2019
{
	namespace EncodeandDecodeTinyURL
	{
		namespace Random {
			const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
			map<string, string> url_code;
			map<string, string> code_url;
			random_device rd;

			// Encodes a URL to a shortened URL.
			string encode(string longUrl) {
				string code;
				if (url_code.find(longUrl) == url_code.end()) {
					int len = charset.size();
					for (int i = 0; i < 6; i++) {
						code.push_back(charset[rd() % len]);
					}
					url_code[longUrl] = code;
					code_url[code] = longUrl;
				}
				else {
					code = url_code[longUrl];
				}
				return "http://tinyurl.com/" + code;
			}

			// Decodes a shortened URL to its original URL.
			string decode(string shortUrl) {
				if (shortUrl.size() != 25 || !code_url.count(shortUrl.substr(19, 6))) { return ""; }
				return code_url[shortUrl.substr(19, 6)];
			}
		}

		namespace Base64 {
			uint64_t id;
			unordered_map<string, string>map;
			string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-";

			// Encodes a URL to a shortened URL.
			string encode(string longUrl) {
				string code;
				id++;
				uint64_t newId = id;
				while (newId) {
					code += charset[newId % 64];
					newId >>= 6;
				}
				map[code] = longUrl;
				return code;
			}

			// Decodes a shortened URL to its original URL.
			string decode(string shortUrl) {
				return map[shortUrl];
			}
		}


		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

