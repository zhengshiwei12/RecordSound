/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        isEnd=false;
        memset(next,0,sizeof(next));

    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {

    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {

    }
private：
    WordDictionary* next[26];
    bool isend;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

