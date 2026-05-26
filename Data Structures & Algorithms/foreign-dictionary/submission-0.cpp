class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indeg;

        // Step 1: Initialize all characters
        for (string word : words) {
            for (char ch : word) {
                indeg[ch] = 0;
            }
        }

        // Step 2: Build graph
        for (int i = 0; i < words.size() - 1; i++) {

            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.size(), s2.size());

            // Invalid case
            if (s1.size() > s2.size() &&
                s1.substr(0, len) == s2) {
                return "";
            }

            for (int j = 0; j < len; j++) {

                if (s1[j] != s2[j]) {

                    adj[s1[j]].push_back(s2[j]);
                    indeg[s2[j]]++;

                    break;
                }
            }
        }

        // Step 3: Topological Sort
        queue<char> q;

        for (auto it : indeg) {
            if (it.second == 0) {
                q.push(it.first);
            }
        }

        string ans;

        while (!q.empty()) {

            char node = q.front();
            q.pop();

            ans += node;

            for (char nbr : adj[node]) {

                indeg[nbr]--;

                if (indeg[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        // Step 4: Cycle detection
        if (ans.size() != indeg.size()) {
            return "";
        }

        return ans;
    }
};