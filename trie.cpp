#include "util.h"

class TrieNode {
public:
  // Initialize your data structure here.
  TrieNode() {}

  bool hasTerminal() { return hasTerminal_; }
  void insertTerminal() { hasTerminal_ = true; }

  TrieNode* get(char c) {
    auto it = m_.find(c);
    return (it != m_.end() ? it->second : nullptr);
  }

  TrieNode* insert(char c) {
    TrieNode *n = get(c);
    if (n) return n;
    return m_[c] = new TrieNode();
  }

  bool hasTerminal_ = false;
  unordered_map<char, TrieNode*> m_;
};

class Trie {
public:
  Trie() { root = new TrieNode(); }

  // Inserts a word into the trie.
  void insert(string word) {
    TrieNode *s = root;
    for (int i = 0; i < word.size(); i++) {
      s = s->insert(word[i]);
    }
    s->insertTerminal();
  }

  TrieNode* exists(string word) {
    TrieNode* s = root;
    for (int i = 0; i < word.size(); i++) {
      s = s->get(word[i]);
      if (!s) break;
    }
    return s;
  }

  // Returns if the word is in the trie.
  bool search(string word) {
    TrieNode* s = exists(word);
    return (s ? s->hasTerminal() : false);
  }

  // Returns if there is any word in the trie
  // that starts with the given prefix.
  bool startsWith(string prefix) {
    return exists(prefix);
  }

private:
  TrieNode *root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main() {
  Trie t;
  EXPECT_EQ(false, t.search("foo"));
  EXPECT_EQ(false, t.search(""));

  t.insert("foobarbaz");
  EXPECT_EQ(true, t.startsWith("f"));
  EXPECT_EQ(true, t.startsWith("f"));
  EXPECT_EQ(true, t.startsWith("fo"));
  EXPECT_EQ(true, t.startsWith("foo"));
  EXPECT_EQ(false, t.startsWith("fob"));
  EXPECT_EQ(false, t.startsWith("foobarbazf"));
  EXPECT_EQ(true, t.startsWith("foobarbaz"));
  EXPECT_EQ(true, t.search("foobarbaz"));
  EXPECT_EQ(false, t.search("foo"));

  t.insert("foo");
  EXPECT_EQ(true, t.search("foo"));
  EXPECT_EQ(true, t.startsWith("foo"));
  return 0;
}
